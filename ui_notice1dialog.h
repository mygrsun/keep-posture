/********************************************************************************
** Form generated from reading UI file 'notice1dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTICE1DIALOG_H
#define UI_NOTICE1DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_notice1Dialog
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *notice1Dialog)
    {
        if (notice1Dialog->objectName().isEmpty())
            notice1Dialog->setObjectName(QStringLiteral("notice1Dialog"));
        notice1Dialog->resize(400, 155);
        label = new QLabel(notice1Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 361, 91));
        QFont font;
        font.setPointSize(30);
        label->setFont(font);
        label_2 = new QLabel(notice1Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 100, 141, 31));

        retranslateUi(notice1Dialog);

        QMetaObject::connectSlotsByName(notice1Dialog);
    } // setupUi

    void retranslateUi(QDialog *notice1Dialog)
    {
        notice1Dialog->setWindowTitle(QApplication::translate("notice1Dialog", "Dialog", 0));
        label->setText(QApplication::translate("notice1Dialog", "\345\205\273\346\210\220\350\211\257\345\245\275\347\232\204\345\235\220\345\247\277\344\271\240\346\203\257", 0));
        label_2->setText(QApplication::translate("notice1Dialog", "\345\247\277\345\212\277\345\235\220\346\255\243\345\220\216\346\210\221\344\274\232\350\207\252\345\212\250\346\266\210\345\244\261", 0));
    } // retranslateUi

};

namespace Ui {
    class notice1Dialog: public Ui_notice1Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTICE1DIALOG_H
