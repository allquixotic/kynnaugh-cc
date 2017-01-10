#include "kynnconfigdlg.h"
#include "ui_kynnconfigdlg.h"

KynnConfigDlg::KynnConfigDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KynnConfigDlg)
{
    ui->setupUi(this);
}

KynnConfigDlg::~KynnConfigDlg()
{
    delete ui;
}
