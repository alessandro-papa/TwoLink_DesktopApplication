#include "CToggleButton.h"

CToggleButton::CToggleButton(const QString& firstName,
                             const QString& secondName,
                             EEvent firstEvent,
                             EEvent secondEvent) : QPushButton{firstName},
                                                   mState{true}
{
    QObject::connect(this, &QPushButton::clicked,
                     this, [this, firstName, secondName, firstEvent, secondEvent]()
                    {
                        if(mState == true)
                        {
                            mState = false;
                            QPushButton::setText(secondName);
                            CMessage msg{firstEvent};
                            emit transmitMessageSignal(msg);
                        }
                        else
                        {
                            mState = true;
                            QPushButton::setText(firstName);
                            CMessage msg{secondEvent};
                            emit transmitMessageSignal(msg);
                        }
                    });
}
