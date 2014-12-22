#ifndef NOTICE1DIALOG_H
#define NOTICE1DIALOG_H

#include <QDialog>

namespace Ui {
class notice1Dialog;
}

class notice1Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit notice1Dialog(QWidget *parent = 0);
    ~notice1Dialog();

private:
    Ui::notice1Dialog *ui;
};

#endif // NOTICE1DIALOG_H
