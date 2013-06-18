#include "sudoku.h"
#include "ui_sudoku.h"
#include <QApplication>
#include <QTextEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>
#include <QTime>

sudoku::sudoku(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sudoku)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Juvenil");
    ui->comboBox->addItem("Profesional");
    ui->comboBox->addItem("Experto");
    initGui();
}

sudoku::~sudoku(){
    delete ui;
}

void sudoku::initGui(){

    for(int i = 0;i < 9; i++){
        for(int j = 0; j < 9; j++){
            numbertext[i][j] = new QTextEdit(NULL);
            ui->numberPad->addWidget(numbertext[i][j], i, j);
        }
    }
}
//COMPRUEBA SI EL JUEGO ES CORRECTO
void sudoku::on_Validar_clicked(){

    long sumatoriah = 0;
    long productoh = 1;
    long sumatoriav = 0;
    long productov = 1;
    long sumatoriacuad = 0;
    long productocuad = 1;
    int despx=0,despy=0;
    int banderavalida=1;

    //Validacion numeros del 1 al 9 en las filas
    for(int i = 0;i < 9; i++){
        sumatoriah=0;
        productoh=1;
        for(int j = 0; j < 9; j++){
            sumatoriah+=getDisplayValue(i,j);
            productoh*=getDisplayValue(i,j);
        }
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
        for(int i = 0;i < 3; i++){
            for(int j = 0; j < 3; j++){
                sumatoriacuad+=getDisplayValue(i+despy,j+despx);
                productocuad*=getDisplayValue(i+despy,j+despx);
            }
        }
        if ((sumatoriacuad==45) && (productocuad==362880) )
            banderavalida=1;
        else
            banderavalida=0,x=10;//linea que rompe el ciclo en caso de no cumplir condicion
    }

    //comprobacion de validacion en general
    if (banderavalida==1){
        QMessageBox::information(this, "Respuesta", "La solucion es valida");
    }else{
        QMessageBox::information(this, "Respuesta", "La solucion no es valida");
    }

}
void sudoku::setDisplayValue(int i,int j,long v){
    numbertext[i][j]->setText( QString("%1").arg(v) );
    numbertext[i][j]->setAlignment(Qt::AlignRight);
}

long sudoku::getDisplayValue(int i,int j) {
    return numbertext[i][j]->toPlainText().toLong();
}
//SALIR DESDE EL MENU
void sudoku::on_actionQuit_triggered(){
    qApp->quit();
}



//BORRAR JUEGO
void sudoku::on_pushButton_clicked(){
    for(int i = 0;i < 9; i++){
        for(int j = 0; j < 9; j++){
            numbertext[i][j]->setText("");
        }
    }
}
//SALIR
void sudoku::on_pushButton_4_clicked(){
    this->close();
}

//JUEGO NUEVO
void sudoku::on_pushButton_3_clicked(){
    int i=0, j=0, k=0, aleatorio;
    QStringList  valores;

    //Semilla del aleatorio
    QTime *seed = new QTime;
    seed->start();
    qsrand(seed->msec());

    if(ui->comboBox->currentText() == "Juvenil"){//MODO JUVENIL(FACIL)}
        k=0;
        valores = plantilla1.split(",");

        for(i = 0;i < 9; i++){
            for(j = 0; j < 9; j++){
                aleatorio = rand() % 10;
                if (aleatorio <= 6){
                    numbertext[i][j]->setTextColor(Qt::red);
                    numbertext[i][j]->setText(valores[k]);
                    numbertext[i][j]->setDisabled(true);
                }else{
                    numbertext[i][j]->setDisabled(false);
                    numbertext[i][j]->setText("");
                }

                numbertext[i][j]->setAlignment(Qt::AlignRight);
                k++;
            }
        }
    }else if(ui->comboBox->currentText() == "Profesional"){//MODO PROFESIONAL(MEDIO)
        k=0;
        valores = plantilla2.split(",");

        for(i = 0;i < 9; i++){
            for(j = 0; j < 9; j++){
                aleatorio = rand() % 10;
                if (aleatorio <= 4){
                    numbertext[i][j]->setTextColor(Qt::blue);
                    numbertext[i][j]->setText(valores[k]);
                    numbertext[i][j]->setDisabled(true);
                }else{
                    numbertext[i][j]->setDisabled(false);
                    numbertext[i][j]->setText("");
                }

                numbertext[i][j]->setAlignment(Qt::AlignRight);
                k++;
            }
        }
    }else if(ui->comboBox->currentText() == "Experto"){//MODO EXPERTO(DIFICIL)
        k=0;
        valores = plantilla3.split(",");

        for(i = 0;i < 9; i++){
            for(j = 0; j < 9; j++){
                aleatorio = rand() % 10;
                if (aleatorio <= 2){
                    numbertext[i][j]->setTextColor(Qt::red);
                    numbertext[i][j]->setText(valores[k]);
                    numbertext[i][j]->setDisabled(true);
                }else{
                    numbertext[i][j]->setDisabled(false);
                    numbertext[i][j]->setText("");
                }

                numbertext[i][j]->setAlignment(Qt::AlignRight);
                k++;
            }
        }
    }
}

//RESOLVER JUEGO
void sudoku::on_pushButton_2_clicked(){
    int i=0, j=0, k=0;
    QStringList  valores;
    if(ui->comboBox->currentText() == "Juvenil"){
        k=0;
        valores = plantilla1.split(",");
        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                if(numbertext[i][j]->toPlainText() == ""){
                    numbertext[i][j]->setTextColor(Qt::black);
                    numbertext[i][j]->setText(valores[k]);
                    numbertext[i][j]->setAlignment(Qt::AlignRight);
                }
                k++;
            }
        }
    }else if(ui->comboBox->currentText() == "Profesional"){
        k=0;
        valores = plantilla2.split(",");
        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                if(numbertext[i][j]->toPlainText() == ""){
                    numbertext[i][j]->setTextColor(Qt::black);
                    numbertext[i][j]->setText(valores[k]);
                    numbertext[i][j]->setAlignment(Qt::AlignRight);
                }
                k++;
            }
        }
    }else if(ui->comboBox->currentText() == "Experto"){
        k=0;
        valores = plantilla3.split(",");
        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                if(numbertext[i][j]->toPlainText() == ""){
                    numbertext[i][j]->setTextColor(Qt::black);
                    numbertext[i][j]->setText(valores[k]);
                    numbertext[i][j]->setAlignment(Qt::AlignRight);
                }
                k++;
            }
        }
    }
}
