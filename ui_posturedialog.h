/********************************************************************************
** Form generated from reading UI file 'posturedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSTUREDIALOG_H
#define UI_POSTUREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PostureDialog
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *noticeLable;
    QLabel *label;
    QPushButton *beginScanBtn;
    QLabel *pframeLable;
    QLabel *scanLineLable;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *submitAdviseBtn;
    QWidget *page_3;
    QLabel *label_4;
    QWidget *page_2;
    QLabel *label_2;
    QPushButton *reScanPostureBtn;
    QLabel *label_3;
    QPushButton *pauseBtn;

    void setupUi(QDialog *PostureDialog)
    {
        if (PostureDialog->objectName().isEmpty())
            PostureDialog->setObjectName(QStringLiteral("PostureDialog"));
        PostureDialog->resize(1366, 768);
        PostureDialog->setStyleSheet(QStringLiteral("background-color: #99CC66;"));
        stackedWidget = new QStackedWidget(PostureDialog);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1366, 768));
        QFont font;
        font.setPointSize(35);
        stackedWidget->setFont(font);
        stackedWidget->setAutoFillBackground(false);
        stackedWidget->setStyleSheet(QStringLiteral("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        noticeLable = new QLabel(page);
        noticeLable->setObjectName(QStringLiteral("noticeLable"));
        noticeLable->setGeometry(QRect(270, 120, 491, 51));
        QFont font1;
        font1.setPointSize(30);
        font1.setBold(true);
        font1.setWeight(75);
        noticeLable->setFont(font1);
        noticeLable->setStyleSheet(QStringLiteral("background-color: #FFCC99;"));
        noticeLable->setAlignment(Qt::AlignCenter);
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(270, 180, 491, 401));
        label->setPixmap(QPixmap(QString::fromUtf8(":/imgs/image/standardposture.jpg")));
        label->setScaledContents(true);
        beginScanBtn = new QPushButton(page);
        beginScanBtn->setObjectName(QStringLiteral("beginScanBtn"));
        beginScanBtn->setGeometry(QRect(770, 480, 440, 101));
        QFont font2;
        font2.setPointSize(30);
        beginScanBtn->setFont(font2);
        beginScanBtn->setStyleSheet(QStringLiteral("background-color: #99CCFF;"));
        pframeLable = new QLabel(page);
        pframeLable->setObjectName(QStringLiteral("pframeLable"));
        pframeLable->setGeometry(QRect(770, 120, 440, 331));
        pframeLable->setFont(font);
        pframeLable->setScaledContents(true);
        scanLineLable = new QLabel(page);
        scanLineLable->setObjectName(QStringLiteral("scanLineLable"));
        scanLineLable->setGeometry(QRect(770, 180, 440, 3));
        label_5 = new QLabel(page);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(470, 600, 111, 21));
        QFont font3;
        font3.setPointSize(15);
        label_5->setFont(font3);
        label_6 = new QLabel(page);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 0, 1366, 41));
        label_6->setStyleSheet(QStringLiteral("background-color:#996633;"));
        submitAdviseBtn = new QPushButton(page);
        submitAdviseBtn->setObjectName(QStringLiteral("submitAdviseBtn"));
        submitAdviseBtn->setGeometry(QRect(1280, 340, 75, 23));
        submitAdviseBtn->setStyleSheet(QStringLiteral("background-color: rgb(85, 0, 0);"));
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        label_4 = new QLabel(page_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(310, 290, 331, 111));
        QFont font4;
        font4.setPointSize(40);
        label_4->setFont(font4);
        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(200, 140, 551, 351));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/imgs/image/standardposture.jpg")));
        reScanPostureBtn = new QPushButton(page_2);
        reScanPostureBtn->setObjectName(QStringLiteral("reScanPostureBtn"));
        reScanPostureBtn->setGeometry(QRect(740, 140, 201, 101));
        QFont font5;
        font5.setPointSize(20);
        reScanPostureBtn->setFont(font5);
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(280, 500, 381, 81));
        label_3->setFont(font2);
        pauseBtn = new QPushButton(page_2);
        pauseBtn->setObjectName(QStringLiteral("pauseBtn"));
        pauseBtn->setGeometry(QRect(740, 270, 201, 101));
        pauseBtn->setFont(font5);
        stackedWidget->addWidget(page_2);

        retranslateUi(PostureDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PostureDialog);
    } // setupUi

    void retranslateUi(QDialog *PostureDialog)
    {
        PostureDialog->setWindowTitle(QApplication::translate("PostureDialog", "PostureDialog", 0));
        noticeLable->setText(QApplication::translate("PostureDialog", "\345\205\273\346\210\220\350\211\257\345\245\275\345\235\220\345\247\277\344\271\240\346\203\257", 0));
        label->setText(QString());
        beginScanBtn->setText(QApplication::translate("PostureDialog", "\345\274\200\345\247\213\346\211\253\346\217\217\346\255\243\347\241\256\345\235\220\345\247\277", 0));
        pframeLable->setText(QString());
        scanLineLable->setText(QString());
        label_5->setText(QApplication::translate("PostureDialog", "\346\255\243\347\241\256\347\232\204\345\235\220\345\247\277", 0));
        label_6->setText(QString());
        submitAdviseBtn->setText(QApplication::translate("PostureDialog", "\346\217\220\344\272\244", 0));
        label_4->setText(QApplication::translate("PostureDialog", "\345\235\220\345\247\277\346\211\253\346\217\217\345\256\214\346\210\220", 0));
        label_2->setText(QString());
        reScanPostureBtn->setText(QApplication::translate("PostureDialog", "\351\207\215\346\226\260\346\211\253\346\217\217\345\235\220\345\247\277", 0));
        label_3->setText(QApplication::translate("PostureDialog", "\345\235\220\346\255\243\345\220\216\346\210\221\344\274\232\350\207\252\345\212\250\346\266\210\345\244\261", 0));
        pauseBtn->setText(QApplication::translate("PostureDialog", "\344\274\221\346\201\257\344\270\200\344\274\232\345\204\277", 0));
    } // retranslateUi

};

namespace Ui {
    class PostureDialog: public Ui_PostureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSTUREDIALOG_H
