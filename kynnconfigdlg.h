#ifndef KYNNCONFIGDLG_H
#define KYNNCONFIGDLG_H

#include <QDialog>

namespace Ui {
class KynnConfigDlg;
}

class KynnConfigDlg : public QDialog
{
    Q_OBJECT

public:
    explicit KynnConfigDlg(QWidget *parent = 0);
    ~KynnConfigDlg();

private:
    Ui::KynnConfigDlg *ui;
};

#endif // KYNNCONFIGDLG_H
