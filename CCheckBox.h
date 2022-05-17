#ifndef CCHECKBOX_H
#define CCHECKBOX_H
#include <QCheckBox>
#include "EEvent.h"
#include "CMessage.h"

class CCheckBox : public QCheckBox
{
    Q_OBJECT
signals:
    void transmitMessageSignal(const CMessage&);
public:
    CCheckBox(const QString&, EEvent);
    CCheckBox& operator=(const CCheckBox&) = delete;
    CCheckBox(const CCheckBox&)            = delete;
    ~CCheckBox()                           = default;
};

#endif // CCHECKBOX_H
