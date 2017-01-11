#ifndef KYNNCONFIGDLG_H
#define KYNNCONFIGDLG_H

#include <QtCore>
#include <QtGui>
#include <QtWidgets>


namespace Ui {
class KynnConfigDlg;
}

class configsnapshot;
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
    configsnapshot *takeSnapshot();
    void restoreSnapshot(configsnapshot *conf);

public slots:
    //Override from QDialog
    virtual void accept();
    virtual void reject();
    void addBtnClicked();

protected:
    virtual void showEvent(QShowEvent* event);

private:
    Ui::KynnConfigDlg *ui;
    QStringListModel stringlistmodel;
    QStringList stringlist;
    filt *fo;
    configsnapshot *snapshot;
    void updateSettings();
};

class filt : public QObject
{
    Q_OBJECT
public:
    filt(QListView *qlv, const KynnConfigDlg *dlg);

protected:
    bool eventFilter(QObject *obj, QEvent *event);

private:
    QListView *qlv;
    KynnConfigDlg *dlg;
};

class configsnapshot
{
public:
    QStringList list;
    bool echoChecked;
    bool confChecked;
};

#endif // KYNNCONFIGDLG_H
