#ifndef CCOMMUNICATION_H
#define CCOMMUNICATION_H
#include <QThread>
#include "CMessage.h"
#include "CClient.h"

class CCommunication : public QThread
{
    Q_OBJECT
public:
    void run() override;
    bool connectToServer();
    bool disconnectFromServer();
signals:
    void messageReceivedSignal(CMessage);
public slots:
    void transmitMessageSlot(CMessage);
public:
    CCommunication();
    CCommunication(const CCommunication&) = delete;
    CCommunication& operator=(const CCommunication&) = delete;
    ~CCommunication() = default;
private:
    bool mConnectedFlag;
    CClient mClient;
};

#endif // CCOMMUNICATION_H
