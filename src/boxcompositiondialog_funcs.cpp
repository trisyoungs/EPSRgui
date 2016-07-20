#include "boxcompositiondialog.h"
#include "epsrproject.h"

#include <QDialog>
#include <QWidget>
#include <QTableWidget>
#include <QPushButton>

BoxCompositionDialog::BoxCompositionDialog(MainWindow *parent) : QDialog(parent)
{
    ui.setupUi(this);
    mainWindow_ = parent;

    int rows = mainWindow_->atomLabels().count();
    QStringList atomLabels = mainWindow_->atomLabels();
    QVector<int> numberOfAtoms = mainWindow_->numberOfEachAtomLabel();
    ui.boxCompositionTable->setRowCount(rows);
    for (int i = 0; i < rows; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem(atomLabels.at(i));
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        ui.boxCompositionTable->setItem(i,0, item);
        QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(numberOfAtoms.at(i)));
        item2->setFlags(item->flags() & ~Qt::ItemIsEditable);
        ui.boxCompositionTable->setItem(i,1, item2);
    }

    connect(ui.closeButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void BoxCompositionDialog::on_closeButton_clicked(bool checked)
{

}