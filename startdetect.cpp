#include "startdetect.h"
#include <QCoreApplication>
#include <QSettings>
#include <QProcess>
#include <QDebug>
void startDetect::detect()
{
    this->detectNewVersion();
    qDebug()<<"detect";
}

startDetect::startDetect()
{

}
void startDetect::detectNewVersion(){
    QSettings *configIniRead = new QSettings("conf.ini", QSettings::IniFormat);
    //将读取到的ini文件保存在QString中，先取值，然后通过toString()函数转换成QString类型
    int readyInstallNewVersion = configIniRead->value("/action/readyInstallNewVersion").toInt();
    //读入入完成后删除指针

    delete configIniRead;
    if(readyInstallNewVersion==1){
        QProcess p;
        QString path=QCoreApplication::applicationDirPath ();//获取当前应用程序路径
        path=path +"/updatesys.exe";
        p.execute(path);
        QCoreApplication::exit(0);
    }else{
        dlg->show();
    }
}
PostureDialog *startDetect::getDlg() const
{
    return dlg;
}

void startDetect::setDlg(PostureDialog *value)
{
    dlg = value;
}


