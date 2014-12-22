#ifndef POSTUREDIALOG_H
#define POSTUREDIALOG_H
#include <QJsonDocument>
#include <QDialog>
#include <QUrl>
#include <QNetworkReply>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include <QSettings>
#include <QDir>
#include <QFile>
#include <QByteArray>
///////////////////////

#include "cv.h"
#include "highgui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <time.h>
#include <ctype.h>
#include <cxcore.h>
#include <iostream>
#ifdef _EiC
#define WIN32
#endif

void playCamer();

////////////////////////




#include "detectheadresult.h"
#include "detectthread.h"
#include "notice1dialog.h"
#include <QTimer>
#include <QMenuBar>
#include <QSystemTrayIcon>
using namespace  std;

namespace Ui {
class PostureDialog;
}

class PostureDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PostureDialog(QWidget *parent = 0);
    ~PostureDialog();

    void initResolution();
    void traversalControl(const QObjectList &q);
    void initResolution(const QObjectList &q);
    int readCurrentVersion();
    QString readIni(QString key);
    void writeIni(QString key,QString value);
    QString comareVersionProcess(QString json);

    void detectUpdate();
public slots:
    void scanPosture();
    void reScanPosture();
    void getResult(Detectheadresult rest);
    void playCamer();
    void moveLine();
    void pauseBtnClick( int time=0);
    void pauseDetectTimeout();
    void pauseHalfOneHoueActionClick();
    void pauseOneHoueActionClick();

    void httpReadyRead();
    void httpFinished();
    void submitAdvise();
private:
    Ui::PostureDialog *ui;
    DetectThread detectThread;
    notice1Dialog notice1Dlg;
    int times;
    QTimer timer;
    QTimer pauseTimer;
    QTimer scanLineTimer;
    CvCapture* pCapture;
    int standureY;
    QAction *pauseAction;
    QSystemTrayIcon *myTrayIcon;

    QAction *    pauseHalfOneHoueAction;
    QAction *    pauseOneHoueAction;






    QUrl url;
    QNetworkAccessManager qnam;

    QNetworkReply *reply;

    QString tempResult;
    QString result;
    int requestType;
    bool haveDetectUpdade;


    int installVersion;
    QMenuBar *menubar;
    QAction *adviseAction;



};

#endif // POSTUREDIALOG_H
