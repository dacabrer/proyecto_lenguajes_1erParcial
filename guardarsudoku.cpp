#include "guardarsudoku.h"
#include "ui_guardarsudoku.h"


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

QString GuardarSudoku::getStr(){
    return stringnivel;
}

void GuardarSudoku::setStr(QString snivel, QString m[9][9]){
    stringnivel = snivel;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            matriz[i][j] = m[i][j];
        }
    }
    ui->nivelS->setText(stringnivel);
    ui->nivelS->setEnabled(false);
}


//Boton salir del menu guardar sudoku
void GuardarSudoku::on_bsalirGuardaSudoku_clicked()
{
     this->close();
}
//Boton guardar del menu guardar sudoku

/* */

void GuardarSudoku::on_bguardarSudoku_clicked()
{
    QString nomJugador = ui->nombreJugador->displayText();
    QString nivel= ui->nivelS->displayText();


    QString info = "";

    for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                info = info+matriz[i][j]+";";
            }
        }
    QString mFilemane = "/home/josanvel/Escritorio/guaardar.txt";
    QFile mFile(mFilemane);
    //if(mFile.exists()) { return; }
    mFile.open(QIODevice::Text | QIODevice::ReadWrite);
    if(!mFile.isOpen()){return;}
    QTextStream txtstr(&mFile);
    txtstr << nomJugador+"/"+nivel+"/"+info;
    mFile.flush();
    mFile.close();



    QMessageBox::information(this, "Guardar-Sudoku", "La partida ha sido guardada \nEl nombre del jugador :"+nomJugador.toUpper(),"ACEPTAR");
    this->close();

}
