#include <algorithm>
#include "kynnconfigdlg.h"
#include "ui_kynnconfigdlg.h"
#include "dbg.h"
#include "constants.h"
#include "settings.h"

//This filter class intercepts "Delete"/"Backspace" key events on the list and removes selected item(s).
filt::filt(QListView *qlv, const KynnConfigDlg *dlg)
    : qlv(qlv), dlg(const_cast<KynnConfigDlg*>(dlg))
{}

bool filt::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if(keyEvent->key() == Qt::Key_Backspace || keyEvent->key() == Qt::Key_Delete)
        {
            const QModelIndexList qmil = this->qlv->selectionModel()->selectedIndexes();
            QModelIndex qmi;
            QList<int> intlist;
            foreach(qmi, qmil)
            {
                //Build a list of indices to delete from the model
                intlist.append(qmi.row());
            }
            //Actually remove them without iterating
            dlg->removeStringsAt(intlist);
            return true;
        }
    }

    return QObject::eventFilter(obj, event);
}

KynnConfigDlg::KynnConfigDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KynnConfigDlg), snapshot(nullptr)
{
    ui->setupUi(this);
    ui->listHints->setModel(&this->stringlistmodel);
    this->fo = new filt(ui->listHints, this);
    ui->listHints->installEventFilter(fo);

    connect(ui->btnAdd, &QPushButton::clicked, this, &KynnConfigDlg::addBtnClicked);

    auto sett = settings::getSettings();
    ui->checkConfidence->setChecked(sett->value(CONFIDENCE_FLAG, true).toBool());
    ui->checkEcho->setChecked(sett->value(ECHO_FLAG, true).toBool());
    QStringList origHints = sett->value(HINTS_SETTING).toStringList();
    stringlist = origHints;
    stringlistmodel.setStringList(stringlist);
}

void KynnConfigDlg::showEvent(QShowEvent* event)
{
    QDialog::showEvent(event);
    snapshot = takeSnapshot();
}

void KynnConfigDlg::addBtnClicked()
{
    //Add the text in the `txtAdd` to the end of the `listHints`.
    QString txtAddText = ui->txtAdd->text().trimmed();
    if(txtAddText.length() > 0)
    {
        addString(txtAddText);
    }
}

void KynnConfigDlg::accept()
{
    //Here we don't rollback, since we optimistically update our model on the fly and only revert if we hit cancel.
    //We still have to update QSettings though.
    updateSettings();
    if(snapshot != nullptr)
    {
        delete snapshot;
        snapshot = nullptr;
    }
    QDialog::accept();
}

void KynnConfigDlg::reject()
{
    //Here we need to roll back the settings to the state they were in when the dialog was last displayed.
    restoreSnapshot(snapshot);
    snapshot = nullptr;
    QDialog::reject();
}

void KynnConfigDlg::updateSettings()
{
    auto sett = settings::getSettings();
    sett->setValue(CONFIDENCE_FLAG, ui->checkConfidence->isChecked());
    sett->setValue(ECHO_FLAG, ui->checkEcho->isChecked());
    sett->setValue(HINTS_SETTING, stringlist);
}

KynnConfigDlg::~KynnConfigDlg()
{
    delete ui;
    if(fo)
    {
        delete fo;
    }
}

configsnapshot *KynnConfigDlg::takeSnapshot()
{
    configsnapshot *retval = new configsnapshot();
    retval->confChecked = this->ui->checkConfidence->isChecked();
    retval->echoChecked = this->ui->checkEcho->isChecked();
    retval->list = this->stringlist;
    return retval;
}

void KynnConfigDlg::restoreSnapshot(configsnapshot *conf)
{
    if(conf != nullptr)
    {
        ui->checkConfidence->setChecked(conf->confChecked);
        ui->checkEcho->setChecked(conf->echoChecked);
        stringlist = conf->list;
        stringlistmodel.setStringList(stringlist);
        delete conf;
    }
}

void KynnConfigDlg::addString(QString s)
{
    stringlist.append(s);
    QSet<QString> fset = stringlist.toSet();
    stringlist.clear();
    stringlist.append(fset.toList());
    stringlistmodel.setStringList(stringlist);
}

void KynnConfigDlg::removeString(QString s)
{
    stringlist.removeOne(s);
    stringlistmodel.setStringList(stringlist);
}

void KynnConfigDlg::removeStringAt(int i)
{
    if(i >= 0 && stringlist.size() > 0)
    {
        stringlist.removeAt(i);
        stringlistmodel.setStringList(stringlist);
    }
}

void KynnConfigDlg::removeStringsAt(QList<int> i)
{
    //We have to remove the highest indices first, and we don't want dupes, but we need to be able to access elements by indices
    //So we have to go:
    //Convert to QSet to eliminate duplicates
    //Sort with the reverse iterators to list them in descending order
    //Convert back to a QList so we can access elements by index
    QSet<int> mySet = i.toSet();
    //std::sort(mySet.rbegin(), mySet.rend());
    QList<int> backToList = mySet.toList();
    qSort(backToList.rbegin(), backToList.rend());
    for(int i = 0; i < backToList.size(); i++)
    {
        stringlist.removeAt(backToList.at(i));
    }
    stringlistmodel.setStringList(stringlist);
}

void KynnConfigDlg::updateString(QString orig, QString replacement)
{
    QRegExp qre(QRegExp::escape(orig));
    int idx = stringlist.indexOf(qre);
    if(idx < 0)
    {
        dbg::qStdOut() << "KynnConfigDgl::updateString(): WARNING: Tried to update non-existent string " << orig << "!\n";
    }
    else
    {
        stringlist.replace(idx, replacement);
    }
    stringlistmodel.setStringList(stringlist);
}
