#ifndef CE3ILC_H
#define CE3ILC_H
#include "CExperimentWidget.h"
#include "CPlot.h"
#include "CPushButton.h"
#include "CFloatInput.h"
#include "CToggleButton.h"

class CE3ILC : public CExperimentWidget
{
    Q_OBJECT
public slots:
    void dispatchMessageSlot(CMessage) override;
    void saveData();
public:
    void runExperiment() override;
public:
    CE3ILC();
    CE3ILC& operator=(const CE3ILC&) = delete;
    CE3ILC(const CE3ILC&)            = delete;
    ~CE3ILC()                        = default;
private:
    CPlot* mThetaPtr;
    CPlot* mThetaDPtr;

    CPlot* mSPtr;
    CPlot* mSDPtr;

    CPlot* mAlphaPtr;
    CPlot* mAlphaDPtr;

    CPlot* mPsiDPtr;

    CPlot* mTiresTorquePtr;
    CPlot* mFlywheelTorquePtr;

    CPushButton* mStartExperimentPtr;
    CPushButton* mStartTrialPtr;
    CPushButton* mDemoTrialPtr;
    CPushButton* mSaveDataPtr;

    CToggleButton* mOrientationControlPtr;
    CToggleButton* mSoftTransitionPtr;

    CFloatInput* mSamplesPtr;
    CFloatInput* mTrialsPtr;
};

#endif // CE3ILC_H
