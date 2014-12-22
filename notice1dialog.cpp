#include "notice1dialog.h"
#include "ui_notice1dialog.h"

notice1Dialog::notice1Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::notice1Dialog)
{
    ui->setupUi(this);
}

notice1Dialog::~notice1Dialog()
{
    delete ui;
}
