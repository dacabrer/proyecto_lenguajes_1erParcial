#include "cargarsudoku.h"
#include "ui_cargarsudoku.h"

CargarSudoku::CargarSudoku(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CargarSudoku)
{
    ui->setupUi(this);
}

CargarSudoku::~CargarSudoku()
{
    delete ui;
}

void CargarSudoku::on_pushButton_2_clicked()
{
    this->close();
}
