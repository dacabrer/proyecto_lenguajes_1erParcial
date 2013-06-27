#include "cargarsudoku.h"
#include "ui_cargarsudoku.h"
#include <sudoku.h>

CargarSudoku::CargarSudoku(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CargarSudoku)
{
    ui->setupUi(this);
}

CargarSudoku::~CargarSudoku(){
    delete ui;
}

void CargarSudoku::setCombo(QComboBox *comboC, int cont, QString nombreJ, QString nivelJ){
    nombreJugador = nombreJ;
    nivelJugador = nivelJ;
    for(int i=0; i < cont; i++){
        if(comboC->itemText(i) != "")
               ui->comboBoxCargar->addItem(comboC->itemText(i));
    }
}
void CargarSudoku::on_bcargarCargarJuego_clicked(){
    QStringList  valores;
    QString nomJugador, nivelC, datosSudoku, datos;

    QString mFilemane = "guardar.txt";
    QFile mFile(mFilemane);
    mFile.open(QIODevice::Text | QIODevice::ReadOnly);
    if(!mFile.isOpen()){return;}
    QTextStream txtstr(&mFile);

    while(!txtstr.atEnd()){
        datosSudoku = txtstr.readLine();
        mFile.flush();
        mFile.close();

        valores = datosSudoku.split("/");
        nomJugador = valores[0];
        nivelC = valores[1];
        datosSudoku = valores[2];

        if(nomJugador == ui->comboBoxCargar->currentText())
         {   datos = datosSudoku; }
    }this->close();
    sudoku *sdk = new sudoku();
    sdk->setCargar(datos,nivelC,nombreJugador);

}

/**Salir de menu CARGAR PARTIDA*/
void CargarSudoku::on_bsalirCargarJuego_clicked(){
    sudoku *volverSudoku = new sudoku();
    this->close();
    volverSudoku->obtenerNombreNivel(nombreJugador, nivelJugador);
    volverSudoku->show();
}
