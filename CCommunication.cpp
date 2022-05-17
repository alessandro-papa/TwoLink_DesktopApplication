#include "CCommunication.h"

CCommunication::CCommunication()
{

}
void CCommunication::run()
{
    while(true)
    {
        CMessage rxMsg;
        if(mClient.readMessage(rxMsg))
        {
            emit messageReceivedSignal(rxMsg);
        }
    }
}
bool CCommunication::connectToServer()
{
    return mClient.connectToServer();
}
bool CCommunication::disconnectFromServer()
{
    mClient.disconnect();
    return true;
}
void CCommunication::transmitMessageSlot(CMessage msg)
{
    mClient.writeMessage(msg);
}
