#include "guardarsudoku.h"
#include "ui_guardarsudoku.h"
#include <QComboBox>


GuardarSudoku::GuardarSudoku(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuardarSudoku)
{
    ui->setupUi(this);
}
GuardarSudoku::~GuardarSudoku()
{
    delete ui;
}



void GuardarSudoku::on_pushButton_2_clicked()
{
    this->close();
}

void GuardarSudoku::on_lineEdit_2_textEdited(const QString &arg1)
{

}
