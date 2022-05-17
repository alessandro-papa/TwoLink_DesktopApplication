#ifndef CTOGGLEBUTTON_H
#define CTOGGLEBUTTON_H
#include <QPushButton>
#include "CMessage.h"

class CToggleButton : public QPushButton
{
    Q_OBJECT
signals:
    void transmitMessageSignal(const CMessage&);
public:
    CToggleButton(const QString& firstName,
                  const QString& secondName,
                  EEvent firstEvent,
                  EEvent secondEvent);
    CToggleButton(const CToggleButton&)            = delete;
    CToggleButton& operator=(const CToggleButton&) = delete;
    ~CToggleButton()                               = default;
private:
    bool mState;
};

#endif // CTOGGLEBUTTON_H
