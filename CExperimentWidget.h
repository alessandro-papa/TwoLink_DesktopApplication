#ifndef CEXPERIMENTWIDGET_H
#define CEXPERIMENTWIDGET_H
#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "CMessage.h"

class CExperimentWidget : public QWidget
{
    Q_OBJECT
public:
    const QString& getExperimentName();
    void stopExperiment();
    virtual void runExperiment() = 0;
signals:
    void transmitMessageSignal(CMessage);
public slots:
    virtual void dispatchMessageSlot(CMessage) = 0;
public:
    explicit CExperimentWidget(const QString& experimentName,
                               QWidget *parent = nullptr);
    CExperimentWidget(const CExperimentWidget&) = delete;
    CExperimentWidget& operator=(const CExperimentWidget&) = delete;
    ~CExperimentWidget() = default;
protected:
    QGridLayout* mPlotLayoutPtr;
    QVBoxLayout* mControlLayoutPtr;
    QString mExperimentName;

};

#endif // CEXPERIMENTWIDGET_H
