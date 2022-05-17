#include "CPlot.h"
#include "Assertion.h"
#include <limits>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
using namespace std;

CPlot::CPlot(const QString& title,
                 const QString& yLabel,
                 const QVector<CPlotLine>& plotLines) : mPlotPtr{new QCustomPlot},
                                                        mNumberOfLines{plotLines.size()},
                                                        mTimeVector{},
                                                        mDisplayTimeVector{},
                                                        mDataVectorVector{},
                                                        mDisplayDataVectorVector{},
                                                        mDrawCounter{0}
{
    this->configureTitle(title);
    this->configureLabels(yLabel);
    this->createPlots(plotLines);
}
CPlot::~CPlot()
{
    delete mPlotPtr;
}
void CPlot::reset()
{
    mTimeVector.clear();
    mDisplayTimeVector.clear();
    for(auto& vec : mDataVectorVector)
    {
        vec.clear();
    }
    for(auto& vec : mDisplayDataVectorVector)
    {
        vec.clear();
    }
}
void CPlot::configureLabels(const QString& yLabel)
{
    mPlotPtr->xAxis->setLabel("Time in seconds");
    mPlotPtr->yAxis->setLabel(yLabel);
}
void CPlot::configureTitle(const QString& plotTitle)
{
    auto title = new QCPPlotTitle(mPlotPtr);
    title->setText(plotTitle);
    title->setFont(QFont("sans", 12, QFont::Bold));
    mPlotPtr->plotLayout()->insertRow(0);
    mPlotPtr->plotLayout()->addElement(0,0, title);
    mPlotPtr->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft|Qt::AlignTop);
}
void CPlot::createPlots(const QVector<CPlotLine>& plotLines)
{
    for(const auto& line : plotLines)
    {
        auto graphPtr = mPlotPtr->addGraph();
        graphPtr->setName(line.mLabel);
        graphPtr->addToLegend();
        graphPtr->setPen(line.mLineColor);
        mDataVectorVector.push_back(QVector<double>{});
        mDisplayDataVectorVector.push_back(QVector<double>{});
    }
    mPlotPtr->legend->setVisible(true);
}
QCustomPlot* CPlot::getPlotPtr()
{
    return mPlotPtr;
}
void CPlot::addData(double time, const QVector<double>& data)
{
    this->appendData(time, data);
    this->updateDisplay();
}
void CPlot::appendData(double time, const QVector<double>& data)
{
    sAssertion(mNumberOfLines == data.size(),
               "CPlot::addData(): Number of lines does not match vector-size!", true);

    //Append the time value
    mTimeVector.push_back(time);
    mDisplayTimeVector.push_back(time);
    if(mDisplayTimeVector.size() > sNumberOfPointsToDisplay)
    {
        mDisplayTimeVector.erase(mDisplayTimeVector.begin());
    }

    //Append the data values
    auto dataVectorIterator        = mDataVectorVector.begin();
    auto displayDataVectorIterator = mDisplayDataVectorVector.begin();
    for(const auto& value : data)
    {
        dataVectorIterator->push_back(value);
        ++dataVectorIterator;

        displayDataVectorIterator->push_back(value);
        ++displayDataVectorIterator;
    }

    if(mDisplayDataVectorVector[0].size() > sNumberOfPointsToDisplay)
    {
        for(auto& dataVector : mDisplayDataVectorVector)
        {
            dataVector.erase(dataVector.begin());
        }
    }
}
void CPlot::updateDisplay()
{
    ++mDrawCounter;
    if(mDrawCounter > sDrawCounterLimit)
    {
        mDrawCounter = 0;

        //Configure the Range of the Y-Axis
        auto global_min = std::numeric_limits<double>::max(),
             global_max = std::numeric_limits<double>::min();
        for(auto& dataVector : mDisplayDataVectorVector)
        {
            auto max_value = *std::max_element(dataVector.begin(), dataVector.end());
            global_max     = max_value > global_max ? max_value : global_max;

            auto min_value = *std::min_element(dataVector.begin(), dataVector.end());
            global_min     = min_value < global_min ? min_value : global_min;
        }
        global_min = global_min > 0.0 ? global_min / 1.05 : global_min * 1.05;
        global_max = global_max > 0.0 ? global_max * 1.05 : global_max / 1.05;
        mPlotPtr->yAxis->setRange(global_min, global_max);

        //Configure the Range of the X-Axis
        mPlotPtr->xAxis->setRange(*mDisplayTimeVector.begin(), mDisplayTimeVector.back());

        //Configure the Graph-Data
        for(auto k = 0; k < mNumberOfLines; ++k)
        {
            mPlotPtr->graph(k)->setData(mDisplayTimeVector, mDisplayDataVectorVector[k]);
        }
        mPlotPtr->replot();
    }
}
void CPlot::saveCSV(const QString& filename,
                      const QVector<std::string>& varNames)
{
    ofstream stream;
    stream.open(filename.toStdString());
    stream << "t";
    for(auto k{0}; k < mNumberOfLines; ++k)
    {
        stream << ", " << varNames[k];
    }
    stream << "\n";

    for(auto k{0}; k < mTimeVector.length(); ++k)
    {
        auto tmp = to_string(mTimeVector[k]);
        auto place = tmp.find(",",0);
        if(place != string::npos)
        {
            tmp.replace(place, 1, ".");
        }
        stream << tmp;
        for(auto dataVector : mDataVectorVector)
        {
            tmp = to_string(dataVector[k]);
            auto place = tmp.find(",");
            if(place != string::npos)
            {
                tmp.replace(place, 1, ".");
            }
            stream << ", " << tmp;
        }
        stream << "\n";
    }
    stream.close();
}
void CPlot::addFData(float time, const QVector<float> &data)
{
    QVector<double> double_data;
    QVectorIterator<float> dataIterator{data};
    while(dataIterator.hasNext())
    {
        double_data.append(static_cast<double>(dataIterator.next()));
    }
    this->addData(static_cast<double>(time), double_data);
}
