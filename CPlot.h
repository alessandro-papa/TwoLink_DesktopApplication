#ifndef CPLOT_H
#define CPLOT_H
#include "CPlotLine.h"
#include "QCustomPlot.h"

class CPlot
{
public:
    QCustomPlot* getPlotPtr();
    void addData(double time, const QVector<double>& data);
    void addFData(float time, const QVector<float>& data);
    void saveCSV(const QString& filename,
                 const QVector<std::string>& varNames);
    void reset();
public:
    CPlot(const QString& title,
            const QString& yLabel,
            const QVector<CPlotLine>& plotLines);
    CPlot(const CPlot&) = delete;
    CPlot& operator=(const CPlot&) = delete;
    ~CPlot();
private:
    void configureTitle(const QString& plotTitle);
    void configureLabels(const QString& yLabel);
    void createPlots(const QVector<CPlotLine>& plotLines);
    void appendData(double time, const QVector<double>& data);
    void updateDisplay();
private:
    static constexpr int sNumberOfPointsToDisplay = 1000;
    static constexpr int sDrawCounterLimit        = 2;

    QCustomPlot* mPlotPtr;

    const int mNumberOfLines;
    QVector<double>          mTimeVector;
    QVector<double>          mDisplayTimeVector;
    QVector<QVector<double>> mDataVectorVector;
    QVector<QVector<double>>   mDisplayDataVectorVector;

    int mDrawCounter;
};

#endif // CPlot_H
