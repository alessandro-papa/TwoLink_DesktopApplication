#include "CExperimentWidget.h"
#include "CMessage.h"
#include <QApplication>
#include "CMainWindow.h"
#include "CE1Calibration.h"
#include "CE2Feedback.h"
#include "CE3ILC.h"

int main(int argc, char *argv[])
{
    qRegisterMetaType<CMessage>("CMessage");

    QApplication a(argc, argv);

    CMainWindow mainWindow{  { new CE2Feedback{} } };

//    CMainWindow mainWindow{  { new CE1Calibration{},
//            new CE2Feedback{},
//            new CE3ILC{} } };
    mainWindow.showMaximized();
    return a.exec();
}
