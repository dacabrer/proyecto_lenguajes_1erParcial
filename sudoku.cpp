#include "sudoku.h"
#include "ui_sudoku.h"
#include <QApplication>
#include <QTextEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <iostream>

sudoku::sudoku(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sudoku)
{
    ui->setupUi(this);
    initGui();
}

sudoku::~sudoku()
{
    delete ui;
}

void sudoku::initGui(){

    for(int i = 0;i < 9; i++){
        for(int j = 0; j < 9; j++){
            numbertext[i][j] = new QTextEdit( QString(" ").arg(i) );
            ui->numberPad->addWidget(numbertext[i][j], i, j);
        }
    }
}

void sudoku::on_Validar_clicked(){

    long sumatoriah = 0;
    long productoh = 1;
    long sumatoriav = 0;
    long productov = 1;
    long sumatoriacuad = 0;
    long productocuad = 1;
    int despx=0,despy=0;
    int banderavalida=1;

    //long inputValue = getDisplayValue();
    //setDisplayValue(inputValue);

    //Validacion numeros del 1 al 9 en las filas

    for(int i = 0;i < 9; i++){
        sumatoriah=0;
        productoh=1;
        for(int j = 0; j < 9; j++){
            sumatoriah+=getDisplayValue(i,j);
            productoh*=getDisplayValue(i,j);
        }
        //std::cout << sumatoriah<< std::endl;
        //std::cout << productoh<< std::endl;
        if ((sumatoriah==45) && (productoh==362880))
            banderavalida=1;
        else
            banderavalida=0,i=10;//linea que rompe el ciclo en caso de no cumplir condicion
    }

     //Validacion numeros del 1 al 9 en las columnas
    for(int j = 0;j < 9; j++){
        sumatoriav=0;
        productov=1;
        for(int i = 0; i < 9; i++){
            sumatoriav+=getDisplayValue(i,j);
            productov*=getDisplayValue(i,j);

        }
        //std::cout << sumatoriav<< std::endl;
        //std::cout << productov<< std::endl;
        if ((sumatoriav==45) && (productov==362880) )
            banderavalida=1;
        else
            banderavalida=0,j=10;//linea que rompe el ciclo en caso de no cumplir condicion
    }

    for(int x = 0;x < 9; x++){
        sumatoriacuad=0;
        productocuad=1;
        despy=(x/3) *3;
        despx=(x%3) *3;
        //std::cout << despx<< std::endl;
        //std::cout << despy<< std::endl;
        for(int i = 0;i < 3; i++){
            for(int j = 0; j < 3; j++){
                sumatoriacuad+=getDisplayValue(i+despy,j+despx);
                productocuad*=getDisplayValue(i+despy,j+despx);
            }
        }
        //std::cout << sumatoriacuad<< std::endl;
        //std::cout << productocuad<< std::endl;
        if ((sumatoriacuad==45) && (productocuad==362880) )
            banderavalida=1;
        else
            banderavalida=0,x=10;//linea que rompe el ciclo en caso de no cumplir condicion
    }

    //comprobacion de validacion en general
    if (banderavalida==1){
        QMessageBox::information(this, "Respuesta", "La solucion es valida");
        ui->estado->setText("La Solucion es Valida");
    }else{
        QMessageBox::information(this, "Respuesta", "La solucion no es valida");
        ui->estado->setText("La Solucion no es Valida");
    }

}
void sudoku::setDisplayValue(int i,int j,long v){

    numbertext[i][j]->setText( QString("%1").arg(v) );
    numbertext[i][j]->setAlignment(Qt::AlignRight);
}
long sudoku::getDisplayValue(int i,int j){

    return numbertext[i][j]->toPlainText().toLong();
}

void sudoku::on_actionQuit_triggered(){

   qApp->quit();
}
