#ifndef ADVISEDIALOG_H
#define ADVISEDIALOG_H

#include <QDialog>

namespace Ui {
class AdviseDialog;
}

class AdviseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdviseDialog(QWidget *parent = 0);
    ~AdviseDialog();

private:
    Ui::AdviseDialog *ui;
};

#endif // ADVISEDIALOG_H
