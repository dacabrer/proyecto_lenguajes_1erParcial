#include "guardarsudoku.h"
#include "ui_guardarsudoku.h"
#include <math.h>


GuardarSudoku::GuardarSudoku(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuardarSudoku)
{
    ui->setupUi(this);
}
GuardarSudoku::~GuardarSudoku(){
    delete ui;
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

/**Boton salir del menu guardar sudoku*/
void GuardarSudoku::on_bsalirGuardaSudoku_clicked(){
     this->close();
}
/**ENCRIPTAR LA PARTIDA DE SUDOKU*/
void GuardarSudoku::encriptarSudoku(){
    int i = 0, j = 0, cont = 33, num1 = 0, numT = 0;

    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            num1 = (matriz[i][j].toInt()) * (matriz[i][j].toInt());

            if((matriz[i][j].toInt() % 2) == 0)     numT = (num1 / 2) + cont;
            else       numT = num1 + cont;

            matriz[i][j].setNum(numT);
        }
    }
}

/**Boton guardar del menu guardar sudoku*/
void GuardarSudoku::on_bguardarSudoku_clicked(){

    QString nomJugador = ui->nombreJugador->displayText();
    QString nivel= ui->nivelS->displayText();
    QString info = "";

    encriptarSudoku();
    for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                info = info+matriz[i][j]+",";
            }
    }
    QString mFilemane = "/home/josanvel/Escritorio/guardar.txt";
    QFile mFile(mFilemane);
    mFile.open(QIODevice::Text | QIODevice::Append);
    if(!mFile.isOpen()){return;}
    QTextStream txtstr(&mFile);
    txtstr << nomJugador+"/"+nivel+"/"+info+"\n";
    mFile.flush();
    mFile.close();

    QMessageBox::information(this, "Guardar-Sudoku", "La partida ha sido guardada \nEl nombre del jugador :"+nomJugador.toUpper(),"ACEPTAR");
    this->close();
}
