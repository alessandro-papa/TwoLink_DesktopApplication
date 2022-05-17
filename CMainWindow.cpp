#include "CMainWindow.h"
#include "Assertion.h"
#include <QMenuBar>

CMainWindow::CMainWindow(const QVector<CExperimentWidget*>& experimentPtrVector)
                            : QMainWindow{nullptr},
                              mExperimentPtrVector{experimentPtrVector},
                              mStackedWidgetPtr{new QStackedWidget},
                              mCommunicationPtr{new CCommunication}
{
    this->createToolbar();

    for(auto& experimentPtr : mExperimentPtrVector)
    {
        mStackedWidgetPtr->addWidget(experimentPtr);
    }

    this->setCentralWidget(mStackedWidgetPtr);

    mRxConnection = QObject::connect(mCommunicationPtr, SIGNAL(messageReceivedSignal(CMessage)),
                                     mStackedWidgetPtr->currentWidget(), SLOT(dispatchMessageSlot(CMessage)));
    mTxConnection = QObject::connect(mStackedWidgetPtr->currentWidget(), SIGNAL(transmitMessageSignal(CMessage)),
                                     mCommunicationPtr, SLOT(transmitMessageSlot(CMessage)));
    bool connectionSucceeded = mCommunicationPtr->connectToServer();
    sAssertion(connectionSucceeded, "CMainWindow(): Failed to Connect to the Server!", true);
    mCommunicationPtr->start();

    reinterpret_cast<CExperimentWidget*>(mStackedWidgetPtr->currentWidget())->runExperiment();
}
void CMainWindow::createToolbar()
{
    auto menuBarPtr = menuBar();
    auto menuPtr    = menuBarPtr->addMenu("Select Experiment");

    for(auto& experimentPtr : mExperimentPtrVector)
    {
        auto actionPtr = new QAction(experimentPtr->getExperimentName());
        menuPtr->addAction(actionPtr);
        QObject::connect(actionPtr, &QAction::triggered,
                         this, [this, experimentPtr]
            {
                reinterpret_cast<CExperimentWidget*>(mStackedWidgetPtr->currentWidget())->stopExperiment();

                QObject::disconnect(mRxConnection);
                QObject::disconnect(mTxConnection);

                this->mStackedWidgetPtr->setCurrentWidget(experimentPtr);

                mRxConnection = QObject::connect(mCommunicationPtr, SIGNAL(messageReceivedSignal(CMessage)),
                                                 mStackedWidgetPtr->currentWidget(), SLOT(dispatchMessageSlot(CMessage)));
                mTxConnection = QObject::connect(mStackedWidgetPtr->currentWidget(), SIGNAL(transmitMessageSignal(CMessage)),
                                                 mCommunicationPtr, SLOT(transmitMessageSlot(CMessage)));


                reinterpret_cast<CExperimentWidget*>(mStackedWidgetPtr->currentWidget())->runExperiment();
            } );
    }
}

CMainWindow::~CMainWindow()
{
    mCommunicationPtr->disconnectFromServer();
}
