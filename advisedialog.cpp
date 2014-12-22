#include "advisedialog.h"
#include "ui_advisedialog.h"

AdviseDialog::AdviseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdviseDialog)
{
    ui->setupUi(this);
//    ui->webView->setUrl("www.baidu.com");
}

AdviseDialog::~AdviseDialog()
{
    delete ui;
}
