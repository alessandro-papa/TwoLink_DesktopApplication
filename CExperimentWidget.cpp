#include "CExperimentWidget.h"

CExperimentWidget::CExperimentWidget(const QString& experimentName,
                                     QWidget *parent) : QWidget(parent),
                                                        mPlotLayoutPtr{new QGridLayout},
                                                        mControlLayoutPtr{new QVBoxLayout},
                                                        mExperimentName(experimentName)
{
    auto centralLayoutPtr = new QHBoxLayout{};
    this->setLayout(centralLayoutPtr);

    auto plotWidgetPtr    = new QWidget{};
    QSizePolicy plotSizePolicy{QSizePolicy::Preferred, QSizePolicy::Preferred};
    plotSizePolicy.setHorizontalStretch(4);
    plotWidgetPtr->setSizePolicy(plotSizePolicy);
    plotWidgetPtr->setLayout(mPlotLayoutPtr);
    centralLayoutPtr->addWidget(plotWidgetPtr);

    auto controlWidgetPtr = new QWidget{};
    QSizePolicy controlSizePolicy{QSizePolicy::Preferred, QSizePolicy::Preferred};
    controlSizePolicy.setHorizontalStretch(1);
    controlWidgetPtr->setSizePolicy(controlSizePolicy);
    controlWidgetPtr->setLayout(mControlLayoutPtr);
    centralLayoutPtr->addWidget(controlWidgetPtr);
}
const QString& CExperimentWidget::getExperimentName()
{
    return mExperimentName;
}
void CExperimentWidget::stopExperiment()
{
    CMessage msg{EEvent::StopExperiment};
    emit transmitMessageSignal(msg);
}
