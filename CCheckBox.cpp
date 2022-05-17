#include "CCheckBox.h"

CCheckBox::CCheckBox(const QString& name, EEvent event) : QCheckBox{name}
{
    QObject::connect(this, &CCheckBox::clicked,
                     this, [this, event]()
    {
        CMessage msg{event};
        msg.setData<bool>(this->isChecked());
        emit transmitMessageSignal(msg);
    });
}
