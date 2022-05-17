#include "CE3ILC.h"
#include "CILCData.h"

CE3ILC::CE3ILC() :
    CExperimentWidget{"ILC Experiment"},
    mThetaPtr{new CPlot{"pitch angle", "pitch angle [rad]",
{{"Theta", QPen(Qt::blue)},
 {"r_Theta", QPen(Qt::red)}}}},
    mThetaDPtr{new CPlot{"angular velocity", "velocity [rad/sec]",
{{"ThetaD", QPen(Qt::blue)}}}},

    mSPtr{new CPlot{"position", "position[m]",
{{"s", QPen(Qt::blue)}, {"r_s", QPen(Qt::red)}}}},

    mSDPtr{new CPlot{"speed", "speed [m/s]",
{{"s", QPen(Qt::blue)}}}},

    mAlphaPtr{new CPlot{"orientation", "angle [rad]",
{{"alpha", QPen(Qt::blue)}}}},
    mAlphaDPtr{new CPlot{"orientation speed", "spped [rad/sec]",
{{"alphaD", QPen(Qt::blue)}}}},

    mPsiDPtr{new CPlot{"flywheel velocity", "rotation [rad/sec]",
{{"psiD", QPen(Qt::blue)}}}},

    mTiresTorquePtr{new CPlot{"tires torque", "uT [Nm]",
{{"uT", QPen(Qt::blue)}}}},
    mFlywheelTorquePtr{new CPlot{"flywheel torque", "uF [Nm]",
{{"uF", QPen(Qt::blue)}}}},

    mStartExperimentPtr{new CPushButton{"Start Experiment", EEvent::RunILCExperiment}},
    mStartTrialPtr{new CPushButton{"Start Trial", EEvent::RunILCTrial}},
    mDemoTrialPtr{new CPushButton{"Play Current Trajectory", EEvent::RunILCDemoTrial}},
    mSaveDataPtr{new CPushButton{"Save Data", EEvent::SaveData}},
    mOrientationControlPtr{new CToggleButton{"Enable Orientation Control", "Disable Orientation Control",
                           EEvent::EnableOrientationController, EEvent::DisableOrientationController}},
    mSoftTransitionPtr{new CToggleButton{"Enable Soft Transition", "Disable Soft Transition",
                       EEvent::EnableSoftTransition, EEvent::DisableSoftTransition}},
    mSamplesPtr{new CFloatInput{"Number of Samples:", "Update Number of Samples", 1.0, 1000.0, 1.0, EEvent::SetNumberOfSamplesPerTrial, 100.0}},
    mTrialsPtr{new CFloatInput{"Number of Trials:" , "Update Number of Trials", 1.0, 1000.0, 1.0, EEvent::SetNumberOfTrials, 11.0}}
{
    mPlotLayoutPtr->addWidget(mThetaPtr->getPlotPtr(), 0, 0);
    mPlotLayoutPtr->addWidget(mThetaDPtr->getPlotPtr(), 0, 1);


    mPlotLayoutPtr->addWidget(mSPtr->getPlotPtr(), 1, 0);
    mPlotLayoutPtr->addWidget(mSDPtr->getPlotPtr(), 1, 1);

    mPlotLayoutPtr->addWidget(mAlphaPtr->getPlotPtr(), 0, 2);
    mPlotLayoutPtr->addWidget(mAlphaDPtr->getPlotPtr(), 1, 2);

    mPlotLayoutPtr->addWidget(mTiresTorquePtr->getPlotPtr(), 2, 0);
    mPlotLayoutPtr->addWidget(mFlywheelTorquePtr->getPlotPtr(), 2, 1);

    mPlotLayoutPtr->addWidget(mPsiDPtr->getPlotPtr(), 2, 2);

    mControlLayoutPtr->addWidget(mSamplesPtr);
    mControlLayoutPtr->addWidget(mTrialsPtr);
    mControlLayoutPtr->addWidget(mStartExperimentPtr);
    mControlLayoutPtr->addWidget(mOrientationControlPtr);
    mControlLayoutPtr->addWidget(mSoftTransitionPtr);
    mControlLayoutPtr->addWidget(mStartTrialPtr);
    mControlLayoutPtr->addWidget(mDemoTrialPtr);
    mControlLayoutPtr->addWidget(mSaveDataPtr);
    mControlLayoutPtr->addStretch();

    QObject::connect(mSamplesPtr, &CFloatInput::transmitMessageSignal,
                     this, &CE3ILC::transmitMessageSignal);

    QObject::connect(mTrialsPtr, &CFloatInput::transmitMessageSignal,
                     this, &CE3ILC::transmitMessageSignal);

    QObject::connect(mStartExperimentPtr, &CPushButton::transmitMessageSignal,
                     this, &CE3ILC::transmitMessageSignal);

    QObject::connect(mOrientationControlPtr, &CToggleButton::transmitMessageSignal,
                     this, &CE3ILC::transmitMessageSignal);

    QObject::connect(mSoftTransitionPtr, &CToggleButton::transmitMessageSignal,
                     this, &CE3ILC::transmitMessageSignal);

    QObject::connect(mStartTrialPtr, &CPushButton::transmitMessageSignal,
                     this, &CE3ILC::transmitMessageSignal);

    QObject::connect(mDemoTrialPtr, &CPushButton::transmitMessageSignal,
                     this, &CE3ILC::transmitMessageSignal);

    QObject::connect(mSaveDataPtr, &CPushButton::transmitMessageSignal,
                     this, &CE3ILC::saveData);
}
void CE3ILC::dispatchMessageSlot(CMessage msg)
{
    auto event{msg.getEvent()};
    if(EEvent::ExperimentData == event)
    {
        const auto& data{msg.getData<CILCData>()};
        auto t{data.mState.mTime};

        mThetaPtr->addFData(t, {data.mState.mTheta, data.mR_Pitch});
        mThetaDPtr->addFData(t, {data.mState.mTheta_d});

        mSPtr->addFData(t, {data.mState.mS, data.mR_Position});
        mSDPtr->addFData(t, {data.mState.mS_d});

        mAlphaPtr->addFData(t, {data.mState.mAlpha});
        mAlphaDPtr->addFData(t, {data.mState.mAlpha_d});

        mPsiDPtr->addFData(t, {data.mState.mPsi_d});

        mTiresTorquePtr->addFData(t, {data.mState.mUT});
        mFlywheelTorquePtr->addFData(t, {data.mState.mUF});
    }
}
void CE3ILC::runExperiment()
{
    CMessage msg{EEvent::RunE3ILC};
    emit transmitMessageSignal(msg);

    mThetaPtr->reset();
    mThetaDPtr->reset();

    mSPtr->reset();
    mSDPtr->reset();

    mAlphaPtr->reset();
    mAlphaDPtr->reset();

    mPsiDPtr->reset();

    mTiresTorquePtr->reset();
    mFlywheelTorquePtr->reset();
}
void CE3ILC::saveData()
{
    mThetaPtr->saveCSV("data/ilc/theta.csv", {"theta", "r_theta"});
    mThetaDPtr->saveCSV("data/ilc/theta_d.csv", {"theta_d"});

    mSPtr->saveCSV("data/ilc/s.csv", {"s", "r_s"});
    mSDPtr->saveCSV("data/ilc/s_d.csv", {"s_d"});

    mAlphaPtr->saveCSV("data/ilc/alpha.csv", {"alpha"});
    mAlphaPtr->saveCSV("data/ilc/alpha_d.csv", {"alpha_d"});

    mPsiDPtr->saveCSV("data/ilc/psi_d.csv", {"psi_d"});

    mTiresTorquePtr->saveCSV("data/ilc/uT.csv", {"uT"});
    mFlywheelTorquePtr->saveCSV("data/ilc/uF.csv", {"uF"});
}
