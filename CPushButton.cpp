#include "CPushButton.h"
#include "CMessage.h"

CPushButton::CPushButton(const QString& name, EEvent event) : QPushButton{name}
{
    QObject::connect(this, &CPushButton::clicked,
                     this, [this, event]()
    {
        CMessage msg{event};
        emit transmitMessageSignal(msg);
    } );
}
