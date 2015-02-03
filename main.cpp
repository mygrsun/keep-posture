#include "posturedialog.h"
#include <QApplication>
#include <QSettings>
#include <QString>
#include <QProcess>
#include "startdetect.h"
#include <QTextCodec>
#include <QLabel>
void detectNewVersion();
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    startDetect t;
    QTimer::singleShot(0, &t, SLOT(detect()));
    QApplication::addLibraryPath("./plugins");

    qRegisterMetaType<Detectheadresult>("Detectheadresult");

    PostureDialog w;
    t.setDlg(&w);

    return a.exec();
}

