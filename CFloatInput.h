#ifndef CFLOATINPUT_H
#define CFLOATINPUT_H
#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QVBoxLayout>
#include <QFrame>
#include "CMessage.h"

class CFloatInput : public QFrame
{
    Q_OBJECT
signals:
    void transmitMessageSignal(const CMessage&);
public:
    CFloatInput(const QString& labelText,
                const QString& buttonText,
                const double& min,
                const double& max,
                const double& step,
                EEvent event,
                const double& initValue = 0.0);
    CFloatInput(const CFloatInput&)            = delete;
    CFloatInput& operator=(const CFloatInput&) = delete;
    ~CFloatInput()                             = default;
private:
    void configureFrame();
    void configureSpinBox(const double& min,
                          const double& max,
                          const double& step,
                          const double& initValue);
    void configureLayout();
private:
    QLabel*         mLabelPtr;
    QDoubleSpinBox* mSpinBoxPtr;
    QPushButton*    mButtonPtr;
};

#endif // CFLOATINPUT_H
