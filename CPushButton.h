#ifndef CPUSHBUTTON_H
#define CPUSHBUTTON_H
#include <QPushButton>
#include "EEvent.h"
#include "CMessage.h"

class CPushButton : public QPushButton
{
    Q_OBJECT
signals:
    void transmitMessageSignal(const CMessage&);
public:
    CPushButton(const QString&, EEvent);
    CPushButton(const CPushButton&)            = delete;
    CPushButton& operator=(const CPushButton&) = delete;
    ~CPushButton()                             = default;
};

#endif // CPUSHBUTTON_H
