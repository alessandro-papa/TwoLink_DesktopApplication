#include "CE2Feedback.h"
//#include "CStateData.h"
#include "CExperimentData.h"

CE2Feedback::CE2Feedback() :
    CExperimentWidget{"Feedback Experiment"},
    // plots
    mPhiPtr{new CPlot{"angle", "angle [rad]",
{{"Theta", QPen(Qt::blue)}}}},
    mPhiDPtr{new CPlot{"angular velocity", "velocity [rad/sec]",
{{"ThetaD", QPen(Qt::blue)}}}},
    mTorquePtr{new CPlot{"torque", "uT [Nm]",
{{"uT", QPen(Qt::blue)}}}},
    // buttons
    mStartStopPtr{new CToggleButton{"Enable Controller", "Disable Controller",
                                    EEvent::EnableController, EEvent::DisableController}},
    mIntegralPtr{new CToggleButton{"Enable Integral Feedback", "Disable Integral Feedback",
                                    EEvent::EnableIntegralFeedback, EEvent::DisableIntegralFeedback}},
    mToggleOffsetPtr{new CPushButton{"Toggle Offset", EEvent::ToggleOffset}},
    mReloadConfigPtr{new CPushButton{"Reload Configuration", EEvent::ReloadConfiguration}},
    mSaveDataPtr{new CPushButton{"Save Data", EEvent::SaveData}}
{
    mPlotLayoutPtr->addWidget(mPhiPtr->getPlotPtr(), 0, 0);
    mPlotLayoutPtr->addWidget(mPhiDPtr->getPlotPtr(), 0, 1);

    mPlotLayoutPtr->addWidget(mTorquePtr->getPlotPtr(), 2, 0);

    mControlLayoutPtr->addWidget(mStartStopPtr);
    // mControlLayoutPtr->addWidget(mIntegralPtr);
    mControlLayoutPtr->addWidget(mToggleOffsetPtr);
    mControlLayoutPtr->addWidget(mReloadConfigPtr);
    mControlLayoutPtr->addWidget(mSaveDataPtr);
    mControlLayoutPtr->addStretch();

    QObject::connect(mStartStopPtr, &CToggleButton::transmitMessageSignal,
                     this, &CE2Feedback::transmitMessageSignal);

    QObject::connect(mIntegralPtr, &CToggleButton::transmitMessageSignal,
                     this, &CE2Feedback::transmitMessageSignal);

    QObject::connect(mToggleOffsetPtr, &CPushButton::transmitMessageSignal,
                     this, &CE2Feedback::transmitMessageSignal);

    QObject::connect(mReloadConfigPtr, &CPushButton::transmitMessageSignal,
                     this, &CE2Feedback::transmitMessageSignal);

    QObject::connect(mSaveDataPtr, &CPushButton::transmitMessageSignal,
                     this, &CE2Feedback::saveData);
}
void CE2Feedback::dispatchMessageSlot(CMessage msg)
{
    auto event{msg.getEvent()};
    if(EEvent::ExperimentData == event)
    {
        const auto& data{msg.getData<CExperimentData>()};
        auto t{data.mTime};

        mPhiPtr->addFData(t, {data.mPhi});
        mPhiDPtr->addFData(t, {data.mPhiD});

        mTorquePtr->addFData(t, {data.mU});
    }
}
void CE2Feedback::runExperiment()
{
    CMessage msg{EEvent::RunE2FeedbackControl};
    emit transmitMessageSignal(msg);

    mPhiPtr->reset();
    mPhiDPtr->reset();

    mTorquePtr->reset();
}
void CE2Feedback::saveData()
{
    mPhiPtr->saveCSV("data/feedback/phi.csv", {"theta"});
    mPhiDPtr->saveCSV("data/feedback/phiD.csv", {"theta_d"});
    mTorquePtr->saveCSV("data/feedback/uT.csv", {"uT", "uT1", "uT2"});
}
