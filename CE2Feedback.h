#ifndef CE2FEEDBACK_H
#define CE2FEEDBACK_H
#include "CExperimentWidget.h"
#include "CPlot.h"
#include "CToggleButton.h"
#include "CPushButton.h"

class CE2Feedback : public CExperimentWidget
{
    Q_OBJECT
public slots:
    void dispatchMessageSlot(CMessage) override;
    void saveData();
public:
    void runExperiment() override;
public:
    CE2Feedback();
    CE2Feedback& operator=(const CE2Feedback&) = delete;
    CE2Feedback(const CE2Feedback&)            = delete;
    ~CE2Feedback()                             = default;
private:
    CPlot* mPhiPtr;
    CPlot* mPhiDPtr;

    CPlot* mTorquePtr;

    CToggleButton* mStartStopPtr;
    CToggleButton* mIntegralPtr;

    CPushButton*   mToggleOffsetPtr;
    CPushButton*   mReloadConfigPtr;
    CPushButton* mSaveDataPtr;
};

#endif // CE2FEEDBACK_H
