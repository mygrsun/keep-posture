#ifndef STARTDETECT_H
#define STARTDETECT_H
#include "posturedialog.h"
#include <QObject>
#include <QApplication>
class startDetect:public QObject {
    Q_OBJECT
public slots:
    void detect();
public:
    startDetect();
    void detectNewVersion();

    PostureDialog *getDlg() const;
    void setDlg(PostureDialog *value);



private:
    PostureDialog *dlg;

};

#endif // STARTDETECT_H
