/* @date        19.08.2020
 * @author      Alessandro Papa
 * @project     Chabo
 */

#ifndef CE1CALIBRATION_H
#define CE1CALIBRATION_H
#include "CExperimentWidget.h"
#include "CPlot.h"
#include "CToggleButton.h"
#include "CPushButton.h"

class CE1Calibration : public CExperimentWidget
{
    Q_OBJECT
public slots:
    void dispatchMessageSlot(CMessage) override;
    void saveData();
public:
    void runExperiment() override;
public:
    CE1Calibration();
    CE1Calibration& operator=(const CE1Calibration&) = delete;
    CE1Calibration(const CE1Calibration&)            = delete;
    ~CE1Calibration()                                = default;
private:
    CPlot* mA1xPtr;
    CPlot* mA1x_calibPtr;
    CPlot* mA1yPtr;
    CPlot* mA1y_calibPtr;
    CPlot* mW1Ptr;
    CPlot* mW1_calibPtr;

    CPlot* mA2xPtr;
    CPlot* mA2x_calibPtr;
    CPlot* mA2yPtr;
    CPlot* mA2y_calibPtr;
    CPlot* mW2Ptr;
    CPlot* mW2_calibPtr;

    CPlot* mA3xPtr;
    CPlot* mA3x_calibPtr;
    CPlot* mA3yPtr;
    CPlot* mA3y_calibPtr;
    CPlot* mW3Ptr;
    CPlot* mW3_calibPtr;

    CPlot* mADCPtr;

    CPlot* mEQEP1Ptr;
    CPlot* mEQEP2Ptr;

    CToggleButton* mStartStopPtr;
};

#endif // CE1CALIBRATION_H
