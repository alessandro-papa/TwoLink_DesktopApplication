#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H
#include <QMainWindow>
#include <QStackedWidget>
#include "CExperimentWidget.h"
#include "CCommunication.h"

class CMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    CMainWindow(const QVector<CExperimentWidget*>& experimentPtrVector);
    CMainWindow(const CMainWindow&) = delete;
    CMainWindow& operator=(const CMainWindow&) = delete;
    ~CMainWindow();
private:
    void createToolbar();
private:
    const QVector<CExperimentWidget*>& mExperimentPtrVector;
    QStackedWidget* mStackedWidgetPtr;

    CCommunication* mCommunicationPtr;

    QMetaObject::Connection mRxConnection;
    QMetaObject::Connection mTxConnection;
};

#endif // CMAINWINDOW_H
