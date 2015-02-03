#include "posturedialog.h"
#include "ui_posturedialog.h"
#include <QDesktopWidget>
#include <QDebug>
#include <Windows.h>
#include <QImage>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QMenu>
#include <QProcess>
#include "advisedialog.h"
#define DEBUGMODEL 0
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
PostureDialog::PostureDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PostureDialog)
{
    ui->setupUi(this);
    this->initResolution(ui->stackedWidget->children());
    this->haveDetectUpdade=false;
    this->times=0;
    this->standureY=0;
    connect(ui->beginScanBtn,SIGNAL(clicked()),this,SLOT(scanPosture()));
    connect(ui->reScanPostureBtn,SIGNAL(clicked()),this,SLOT(reScanPosture()));
    connect(ui->pauseBtn,SIGNAL(clicked()),this,SLOT(pauseBtnClick()));
    connect(&(this->detectThread),SIGNAL(getResult(Detectheadresult)),this,SLOT(getResult(Detectheadresult)));
    connect(&(this->timer),SIGNAL(timeout()),this,SLOT(playCamer()));
    connect(&(this->pauseTimer),SIGNAL(timeout()),this,SLOT(pauseDetectTimeout()));
    //获取摄像头
    pCapture = cvCreateCameraCapture(-1);
    this->timer.start(33);
    QDesktopWidget* desktopWidget = QApplication::desktop();
    int width = desktopWidget->screenGeometry().width();
    int height = desktopWidget->screenGeometry().height();

    this->notice1Dlg.setGeometry(width-this->notice1Dlg.width(),0,this->notice1Dlg.width(),this->notice1Dlg.height());
    ui->stackedWidget->setCurrentIndex(0);

    myTrayIcon = new QSystemTrayIcon(this);
    myTrayIcon->setIcon(QIcon("image/favicon.ico"));
    myTrayIcon->setToolTip("KeepPosture_V1.0");

    this->pauseAction = new QAction(tr("休息"),this);

    connect(pauseAction,SIGNAL(triggered()),this,SLOT(pauseBtnClick()));

    pauseHalfOneHoueAction = new QAction("休息半个小时",this);
    connect(pauseHalfOneHoueAction,SIGNAL(triggered()),this,SLOT(pauseHalfOneHoueActionClick()));
    pauseOneHoueAction = new QAction(tr("休息一个小时"),this);
    connect(pauseOneHoueAction,SIGNAL(triggered()),this,SLOT(pauseOneHoueActionClick()));
    rescanAction = new QAction("重新扫描坐姿",this);
    connect(rescanAction,SIGNAL(triggered()),this,SLOT(reScanPosture()));
    QAction *quitAction=new QAction("退出",this);

    //    connect( quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect( quitAction, SIGNAL(triggered()), this, SLOT(closeApp()));


    QMenu *myMenu = new QMenu((QWidget*)QApplication::desktop());
    myMenu->addAction(pauseAction);
    myMenu->addAction(this->pauseHalfOneHoueAction);
    myMenu->addAction(this->pauseOneHoueAction);
    myMenu->addSeparator();     //加入一个分离符
    myMenu->addAction(rescanAction);
    myMenu->addSeparator();     //加入一个分离符
    myMenu->addAction(quitAction);
    myTrayIcon->setContextMenu(myMenu);
    myTrayIcon->show();

    this->menubar=new QMenuBar(this);
    this->menubar->setGeometry(QRect(500, 0, 400, 41));
    this->adviseAction=new QAction("建议",this);
    connect(this->adviseAction,SIGNAL(triggered()),this,SLOT(reScanPosture()));

    //    this->menubar->addAction(this->adviseAction);
    //    this->menubar->show();
    this->changeActionShowStatus(this->STATUS_INIT);

}

void PostureDialog::closeApp(){
    this->detectThread.setRunFlag(false);
    qApp->quit();


}

void PostureDialog::changeActionShowStatus(int flag){
    switch(flag){
    case this->STATUS_INIT://初始状态
        this->pauseHalfOneHoueAction->setVisible(false);
        this->pauseOneHoueAction->setVisible(false);
        this->pauseAction->setVisible(false);
        this->rescanAction->setText(tr("扫描坐姿"));
        break;


    case this->STATUS_DETACT://正常状态
        this->pauseHalfOneHoueAction->setVisible(true);
        this->pauseOneHoueAction->setVisible(true);

        this->pauseAction->setVisible(true);
        this->pauseAction->setText(tr("休息"));

        this->rescanAction->setText(tr("重新扫描坐姿"));
        break;


    case this->STATUS_STOP://暂停状态

        this->pauseHalfOneHoueAction->setVisible(false);
        this->pauseOneHoueAction->setVisible(false);
        this->pauseAction->setVisible(true);
        this->pauseAction->setText(tr("继续"));

        this->rescanAction->setText(tr("重新扫描坐姿"));
        break;

    }


}
void PostureDialog::traversalControl(const QObjectList& q)
{
    for(int i=0;i<q.length();i++)
    {

        if(!q.at(i)->children().empty())

        {

            traversalControl(q.at(i)->children());

        }

        else

        {

            QObject* o = q.at(i);
            if(o->isWidgetType()){
                QWidget* b = qobject_cast<QWidget*>(o);
                b->setGeometry(0,0,500,500);
            }
            //b->setGeometry(0,0,500,500);
            //b->width();
            if (o->inherits("QPushButton")) {

                //                QPushButton* b = qobject_cast<QPushButton*>(o);
                //b->setGeometry(0,0,100,100);
                //                             QWidget* b = qobject_cast<QWidget*>(o);
                //                b->setGeometry(0,0,100,100);
                //                b->setText("<>");
                //                qDebug()<<b->text();

            } //end if
        } //end for
    } //end function
}

void PostureDialog::initResolution(const QObjectList& q)
{
    double resolutionWidth= QApplication::desktop()->width();
    double resolutionHeight=QApplication::desktop()->height();
    double factorWidth=resolutionWidth/1366;
    double factorHeight=resolutionHeight/768;
    this->setGeometry(0,0,resolutionWidth,resolutionHeight);
    for(int i=0;i<q.length();i++)
    {

        if(!q.at(i)->children().empty())

        {

            initResolution(q.at(i)->children());

        }

        else

        {

            QObject* o = q.at(i);
            if(o->isWidgetType()){
                QWidget* b = qobject_cast<QWidget*>(o);
                b->setGeometry(b->x()*factorWidth,b->y()*factorHeight,b->width()*factorWidth,b->height()*factorHeight);
            }

            if (o->inherits("QPushButton")) {

            }

        }

    }
}
void PostureDialog::initResolution(){
    double resolutionWidth= QApplication::desktop()->width();
    double resolutionHeight=QApplication::desktop()->height();
    double factorWidth=resolutionWidth/1366;
    double factorHeight=resolutionHeight/768;
    this->setGeometry(0,0,resolutionWidth,resolutionHeight);
    qDebug()<<resolutionWidth<<resolutionHeight<<"adsf";
    qDebug()<<ui->page->x();
    qDebug()<<ui->page->width();
    qDebug()<<ui->pframeLable->x();
    qDebug()<<ui->pframeLable->width();


    ui->stackedWidget->setGeometry(ui->stackedWidget->x()*factorWidth,ui->stackedWidget->y()*factorHeight,ui->stackedWidget->width()*factorWidth,ui->stackedWidget->height()*factorHeight);

    ui->reScanPostureBtn->setGeometry(ui->reScanPostureBtn->x()*factorWidth,ui->reScanPostureBtn->y()*factorHeight,ui->reScanPostureBtn->width()*factorWidth,ui->reScanPostureBtn->height()*factorHeight);
    ui->pframeLable->setGeometry(ui->pframeLable->x()*factorWidth,ui->pframeLable->y()*factorHeight,ui->pframeLable->width()*factorWidth,ui->pframeLable->height()*factorHeight);
    ui->pauseBtn->setGeometry(ui->pauseBtn->x()*factorWidth,ui->pauseBtn->y()*factorHeight,ui->pauseBtn->width()*factorWidth,ui->pauseBtn->height()*factorHeight);
    ui->label_4->setGeometry(ui->label_4->x()*factorWidth,ui->label_4->y()*factorHeight,ui->label_4->width()*factorWidth,ui->label_4->height()*factorHeight);
    ui->label_3->setGeometry(ui->label_3->x()*factorWidth,ui->label_3->y()*factorHeight,ui->label_3->width()*factorWidth,ui->label_3->height()*factorHeight);
    ui->beginScanBtn->setGeometry(ui->beginScanBtn->x()*factorWidth,ui->beginScanBtn->y()*factorHeight,ui->beginScanBtn->width()*factorWidth,ui->beginScanBtn->height()*factorHeight);
    ui->label_2->setGeometry(ui->label_2->x()*factorWidth,ui->label_2->y()*factorHeight,ui->label_2->width()*factorWidth,ui->label_2->height()*factorHeight);
    qDebug()<<ui->page->x();
    qDebug()<<ui->page->width();
    qDebug()<<ui->pframeLable->x();
    qDebug()<<ui->pframeLable->width();



}
void PostureDialog::playCamer(){
    //声明IplImage指针
    IplImage* pFrame = NULL;
    pFrame=cvQueryFrame( pCapture );
    if(!pFrame){
        ui->pframeLable->setText(tr("camera can't use"));
        ui->beginScanBtn->setEnabled(false);
        this->disconnect(&(this->timer),SIGNAL(timeout()),this,SLOT(playCamer()));
        return;
    }
    QImage image((uchar *)pFrame->imageData,pFrame->width,pFrame->height,QImage::Format_RGB888);
    QPixmap pixmap=QPixmap::fromImage(image);
    ui->pframeLable->setPixmap(pixmap.scaled(ui->pframeLable->width(),ui->pframeLable->height(),Qt::KeepAspectRatio));


}

void PostureDialog::moveLine()
{


    int x=ui->scanLineLable->x();
    int y=ui->scanLineLable->y()+3;
    int width=ui->scanLineLable->width();
    int height=ui->scanLineLable->height();
    if(y>ui->pframeLable->y()+ui->pframeLable->height()){
        y=ui->pframeLable->y();
    }

    ui->scanLineLable->setGeometry(x,y,width,height);

}


void PostureDialog::pauseBtnClick(int time)
{
    if(time!=0){
        this->pauseTimer.start(time*60000);
    }


    if(this->detectThread.getRunFlag()==true)
    {
        this->pauseAction->setText(tr("继续"));

        ui->pauseBtn->setText(tr("继续"));
        this->detectThread.setRunFlag(false);

        this->pauseHalfOneHoueAction->setVisible(false);
        this->pauseOneHoueAction->setVisible(false);
        this->changeActionShowStatus(this->STATUS_STOP);
        this->myTrayIcon->show();
    }else{
        this->detectThread.setRunFlag(true);
        ui->pauseBtn->setText(tr("休息"));
        this->pauseAction->setText(tr("休息"));
        this->pauseHalfOneHoueAction->setVisible(true);
        this->pauseOneHoueAction->setVisible(true);
        this->pauseTimer.stop();
        this->detectThread.start();
        this->changeActionShowStatus(this->STATUS_DETACT);
        this->myTrayIcon->show();
    }

}

void PostureDialog::pauseDetectTimeout()
{
    this->detectThread.setRunFlag(true);
    ui->pauseBtn->setText(tr("休息"));
    this->pauseHalfOneHoueAction->setVisible(true);
    this->pauseOneHoueAction->setVisible(true);
    this->detectThread.start();
    this->myTrayIcon->show();
}

void PostureDialog::pauseHalfOneHoueActionClick()
{
    this->pauseBtnClick(30);

}

void PostureDialog::pauseOneHoueActionClick()
{

    this->pauseBtnClick(60);

}
void PostureDialog::scanPosture(){
    disconnect(&(this->timer),SIGNAL(timeout()),this,SLOT(playCamer()));

//    ui->scanLineLable->setPixmap(QPixmap("image/scanline.jpg"));
    connect(&(this->scanLineTimer),SIGNAL(timeout()),this,SLOT(moveLine()));
    this->scanLineTimer.start(10);
    ui->beginScanBtn->setText(tr("重新扫描正确坐姿"));
    this->detectThread.setRunFlag(true);
    this->detectThread.start();
    this->changeActionShowStatus(this->STATUS_DETACT);

}

void PostureDialog::reScanPosture()
{
    ui->scanLineLable->show();
    connect(&(this->timer),SIGNAL(timeout()),this,SLOT(playCamer()));
    this->detectThread.setRunFlag(false);
    ui->stackedWidget->setCurrentIndex(0);
    this->show();


}

void PostureDialog::getResult(Detectheadresult rest)
{
    if(this->standureY==0){
        this->standureY=rest.getCenterY();
        ui->stackedWidget->setCurrentIndex(1);
        qDebug()<<"scanOver!";
        return;
    }
    if(rest.getCenterY()>(this->standureY+20)){
        qDebug()<<"bad!";
        this->detectThread.setIntervalTime(30);
        if(this->detectThread.getRunFlag()==false)
            return;
        ui->stackedWidget->setCurrentIndex(2);
        this->times++;
        if(this->times<5){
            this->notice1Dlg.show();

        }else{
            this->notice1Dlg.hide();
            this->show();
        }

    }else{
        qDebug()<<"good!";
        this->detectThread.setIntervalTime(3000);
        this->times=0;
        this->notice1Dlg.hide();
        this->hide();
        if(this->haveDetectUpdade==false){
            this->detectUpdate();
            this->haveDetectUpdade=true;
        }

    }

}



PostureDialog::~PostureDialog()
{
    delete ui;
}


QString PostureDialog::comareVersionProcess(QString json)
{
    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(json.toUtf8(), &error);
    if (error.error == QJsonParseError::NoError) {
        if (jsonDocument.isObject()) {
            QVariantMap result = jsonDocument.toVariant().toMap();
            int version= result["version_num"].toInt();
            int currentVersion=this->readCurrentVersion();
            this->installVersion=version;
            if(version>currentVersion){
                return result["download_link"].toString();
            }else{
                return "";
            }

        }
    } else {
        return "";
    }
}

QString PostureDialog::readIni(QString  key)
{
    QSettings *configIniRead = new QSettings("conf.ini", QSettings::IniFormat);
    //将读取到的ini文件保存在QString中，先取值，然后通过toString()函数转换成QString类型
    QString value = configIniRead->value(key).toString();
    //读入入完成后删除指针

    delete configIniRead;
    return value;
}

void PostureDialog::writeIni(QString key, QString value)
{
    QSettings *configIniWrite = new QSettings("conf.ini", QSettings::IniFormat);
    configIniWrite->setValue(key,value);
    delete configIniWrite;
}

int PostureDialog::readCurrentVersion()
{
    int currentVersion= this->readIni("/version/currentVersion").toInt();
    return currentVersion;
}

void PostureDialog::httpReadyRead()
{
    this->tempResult.append(QString::fromUtf8(this->reply->readAll()));
}

void PostureDialog::httpFinished()
{
    this->result=this->tempResult;
    this->tempResult="";
    qDebug()<<this->result;
    switch(this->requestType){
    case 1:
        QString link=this->comareVersionProcess(this->result);

        if(link!=""){
            QProcess p;
            QString path=QCoreApplication::applicationDirPath ();//获取当前应用程序路径
            path=path +"/updatesys.exe";
            p.execute(path);
        }
        break;

    }

}

void PostureDialog::submitAdvise()
{
    AdviseDialog *dlg=new AdviseDialog(this);

    dlg->show();

}
void PostureDialog::detectUpdate()
{

    this->url=QUrl("http://managerverison.sinaapp.com/index.php/Index/checklatestversion?projectid=1");


    this->requestType=1;
    this->reply = qnam.get(QNetworkRequest(url));
    connect(reply, SIGNAL(finished()), this, SLOT(httpFinished()));
    connect(reply, SIGNAL(readyRead()), this, SLOT(httpReadyRead()));
}
