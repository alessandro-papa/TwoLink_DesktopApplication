#ifndef IEVENTCREATOR_H
#define IEVENTCREATOR_H
#include "CMessage.h"
#include <QWidget>

class IEventCreator : public QWidget
{
    Q_OBJECT
signals:
    void transmitMessageSignal(const CMessage&);
public:
    IEventCreator()                                = default;
    IEventCreator(const IEventCreator&)            = delete;
    IEventCreator& operator=(const IEventCreator&) = delete;
    virtual ~IEventCreator()                       = default;
};

#endif // IEVENTCREATOR_H
