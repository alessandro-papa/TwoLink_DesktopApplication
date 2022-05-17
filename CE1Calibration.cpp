/* @date        19.08.2020
 * @author      Alessandro Papa
 * @project     Chabo
 */
#include "CE1Calibration.h"
#include "CSensorData.h"

CE1Calibration::CE1Calibration():
    CExperimentWidget{"Calibration Experiment"},
    mA1xPtr{new CPlot{"X1_dd", "Acceleration",
{{"x1dd", QPen(Qt::blue)}}}},
    mA1yPtr{new CPlot{"Y1_dd", "Acceleration in 2k",
{{"y1dd", QPen(Qt::blue)}}}},

    mW1Ptr{new CPlot{"w1", "angular velocity in 2k",
{{"w1", QPen(Qt::blue)}}}},

    mA2xPtr{new CPlot{"X2_dd", "Acceleration in 2k",
{{"x2dd", QPen(Qt::blue)}}}},

    mA2yPtr{new CPlot{"Y2_dd", "Acceleration in 2k",
{{"y2dd", QPen(Qt::blue)}}}},

    mW2Ptr{new CPlot{"w2", "angular velocity in 2k",
{{"w2", QPen(Qt::blue)}}}},

    mA3xPtr{new CPlot{"X3_dd", "Acceleration in 2k",
{{"x3dd", QPen(Qt::blue)}}}},

    mA3yPtr{new CPlot{"Y3dd", "Acceleration in 2k",
{{"y3dd", QPen(Qt::blue)}}}},

    mW3Ptr{new CPlot{"w3", "angular velocity in 2k",
{{"w3", QPen(Qt::blue)}}}},

    mADCPtr{new CPlot{"ADC", "angular velocity in 2k",
{{"ADC", QPen(Qt::blue)}}}},
    mEQEP1Ptr{new CPlot{"EQEP1", "EQEP signal in pulses",
{{"EQEP1", QPen(Qt::blue)}}}},
    mEQEP2Ptr{new CPlot{"EQEP2", "EQEP signal in pulses",
{{"EQEP2", QPen(Qt::blue)}}}},

    mStartStopPtr{new CToggleButton{"Start Measurement", "Stop Measurement",
                                    EEvent::StartMeasurement, EEvent::StopMeasurement}}

{
    mPlotLayoutPtr->addWidget(mA1xPtr->getPlotPtr(), 0, 0);
    mPlotLayoutPtr->addWidget(mA2xPtr->getPlotPtr(), 1, 0);
    mPlotLayoutPtr->addWidget(mA1yPtr->getPlotPtr(), 0, 1);
    mPlotLayoutPtr->addWidget(mA2yPtr->getPlotPtr(), 1, 1);
    mPlotLayoutPtr->addWidget(mW1Ptr->getPlotPtr(), 0, 2);
    mPlotLayoutPtr->addWidget(mW2Ptr->getPlotPtr(), 1, 2);

    mPlotLayoutPtr->addWidget(mA3xPtr->getPlotPtr(), 2, 0);
    mPlotLayoutPtr->addWidget(mA3yPtr->getPlotPtr(), 2, 1);
    mPlotLayoutPtr->addWidget(mW3Ptr->getPlotPtr(), 2, 2);

    mPlotLayoutPtr->addWidget(mADCPtr->getPlotPtr(), 0, 3);
    mPlotLayoutPtr->addWidget(mEQEP1Ptr->getPlotPtr(), 1, 3);
    mPlotLayoutPtr->addWidget(mEQEP2Ptr->getPlotPtr(), 2, 3);


    mControlLayoutPtr->addWidget(mStartStopPtr);
    mControlLayoutPtr->addStretch();

    QObject::connect(mStartStopPtr, &CToggleButton::transmitMessageSignal,
                     this, &CE1Calibration::transmitMessageSignal);
    QObject::connect(mStartStopPtr, &CToggleButton::transmitMessageSignal,
                     this, &CE1Calibration::saveData);
}
void CE1Calibration::dispatchMessageSlot(CMessage msg)
{
    auto event{msg.getEvent()};
    if(EEvent::ExperimentData == event)
    {
        const auto& data{msg.getData<CSensorData>()};
        auto t{data.mTime};

        // raw data

        mA1xPtr->addFData(t, {static_cast<float>(data.mIMU1Data.mA_x)});
        mA1yPtr->addFData(t, {static_cast<float>(data.mIMU1Data.mA_y)});
        mW1Ptr->addFData(t, {static_cast<float>(data.mIMU1Data.mW_z)});

        mA2xPtr->addFData(t, {static_cast<float>(data.mIMU2Data.mA_x)});
        mA2yPtr->addFData(t, {static_cast<float>(data.mIMU2Data.mA_y)});
        mW2Ptr->addFData(t, {static_cast<float>(data.mIMU2Data.mW_z)});

        mA3xPtr->addFData(t, {static_cast<float>(data.mIMU3Data.mA_x)});
        mA3yPtr->addFData(t, {static_cast<float>(data.mIMU3Data.mA_y)});
        mW3Ptr->addFData(t, {static_cast<float>(data.mIMU3Data.mW_z)});

        mADCPtr->addData(t, {static_cast<float>(data.mADCData.mADC3Value)});
        mEQEP1Ptr->addData(t, {static_cast<float>(data.mEncoder1Data.mNumberOfTicks)});
        mEQEP2Ptr->addData(t, {static_cast<float>(data.mEncoder2Data.mNumberOfTicks)});

        // calibrated data

//        mA1xPtr->addFData(t, {static_cast<float>(data.mCalibData.mA1_x)});
//        mA1yPtr->addFData(t, {static_cast<float>(data.mCalibData.mA1_y)});
//        mW1Ptr->addFData(t, {static_cast<float>(data.mCalibData.mW1_z)});

//        mA2xPtr->addFData(t, {static_cast<float>(data.mCalibData.mA2_x)});
//        mA2yPtr->addFData(t, {static_cast<float>(data.mCalibData.mA2_y)});
//        mW2Ptr->addFData(t, {static_cast<float>(data.mCalibData.mW2_z)});

//        mA3xPtr->addFData(t, {static_cast<float>(data.mCalibData.mA3_x)});
//        mA3yPtr->addFData(t, {static_cast<float>(data.mCalibData.mA3_y)});
//        mW3Ptr->addFData(t, {static_cast<float>(data.mCalibData.mW3_z)});

//        mADCPtr->addData(t, {static_cast<float>(data.mADCData.mADC3Value)});
//        mEQEP1Ptr->addData(t, {static_cast<float>(data.mEncoder1Data.mNumberOfTicks)});
//        mEQEP2Ptr->addData(t, {static_cast<float>(data.mEncoder2Data.mNumberOfTicks)});


    }
}
void CE1Calibration::runExperiment()
{
    CMessage msg{EEvent::RunE1Calibration};
    emit transmitMessageSignal(msg);

    mA1xPtr->reset();
    mA1yPtr->reset();
    mW1Ptr->reset();

    mA2xPtr->reset();
    mA2yPtr->reset();
    mW2Ptr->reset();

    mA3xPtr->reset();
    mA3yPtr->reset();
    mW3Ptr->reset();

    mADCPtr->reset();
    mEQEP1Ptr->reset();
    mEQEP2Ptr->reset();
}
void CE1Calibration::saveData()
{
    mA1xPtr->saveCSV("data/calibration/x1dd.csv", {"x1dd"});
    mA2xPtr->saveCSV("data/calibration/x2dd.csv", {"x2dd"});
    mA3xPtr->saveCSV("data/calibration/x3dd.csv", {"x3dd"});

    mA1yPtr->saveCSV("data/calibration/y1dd.csv", {"y1dd"});
    mA2yPtr->saveCSV("data/calibration/y2dd.csv", {"y2dd"});
    mA3yPtr->saveCSV("data/calibration/y3dd.csv", {"y3dd"});

    mW1Ptr->saveCSV("data/calibration/w1.csv", {"w1"});
    mW2Ptr->saveCSV("data/calibration/w2.csv", {"w2"});
    mW3Ptr->saveCSV("data/calibration/w3.csv", {"w3"});

    mADCPtr->saveCSV("data/calibration/phiD.csv", {"phiD"});
}
