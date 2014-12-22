/********************************************************************************
** Form generated from reading UI file 'advisedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVISEDIALOG_H
#define UI_ADVISEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_AdviseDialog
{
public:

    void setupUi(QDialog *AdviseDialog)
    {
        if (AdviseDialog->objectName().isEmpty())
            AdviseDialog->setObjectName(QStringLiteral("AdviseDialog"));
        AdviseDialog->resize(400, 300);

        retranslateUi(AdviseDialog);

        QMetaObject::connectSlotsByName(AdviseDialog);
    } // setupUi

    void retranslateUi(QDialog *AdviseDialog)
    {
        AdviseDialog->setWindowTitle(QApplication::translate("AdviseDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class AdviseDialog: public Ui_AdviseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVISEDIALOG_H
