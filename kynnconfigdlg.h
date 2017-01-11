#ifndef KYNNCONFIGDLG_H
#define KYNNCONFIGDLG_H

#include <QtCore>
#include <QtGui>
#include <QtWidgets>


namespace Ui {
class KynnConfigDlg;
}

class filt;

class KynnConfigDlg : public QDialog
{
    Q_OBJECT

public:
    explicit KynnConfigDlg(QWidget *parent = 0);
    ~KynnConfigDlg();
    void addString(QString s);
    void removeString(QString s);
    void removeStringAt(int i);
    void removeStringsAt(QList<int> i);
    void updateString(QString orig, QString replacement);

public slots:
    //Override from QDialog
    virtual void accept();
    virtual void reject();

private:
    Ui::KynnConfigDlg *ui;
    QStringListModel stringlistmodel;
    QStringList stringlist;
    filt *fo;
};

#endif // KYNNCONFIGDLG_H
