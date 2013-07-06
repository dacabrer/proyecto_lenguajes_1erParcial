#include "sudoku.h"
#include "ui_sudoku.h"
#include <math.h>
#include <iostream>
const QString sudoku::plantilla1("7,8,4,9,5,2,3,1,6,9,2,6,1,4,3,8,5,7,3,5,1,8,6,7,9,4,2,4,7,8,5,2,1,6,9,3,1,6,5,3,7,9,2,8,4,2,9,3,6,8,4,1,7,5,6,4,9,2,1,5,7,3,8,5,1,2,7,3,8,4,6,9,8,3,7,4,9,6,5,2,1");
const QString sudoku::plantilla2("5,9,7,4,3,2,6,1,8,2,8,4,1,6,7,3,9,5,6,3,1,8,9,5,2,4,7,4,5,3,6,7,1,9,8,2,8,7,9,2,5,3,4,6,1,1,6,2,9,4,8,5,7,3,9,2,5,7,1,6,8,3,4,7,4,8,3,2,9,1,5,6,3,1,6,5,8,4,7,2,9");
const QString sudoku::plantilla3("1,7,4,6,8,3,2,9,5,9,5,3,4,1,2,8,6,7,2,8,6,7,9,5,3,4,1,8,6,5,2,7,9,1,3,4,4,3,2,8,6,1,7,5,9,7,1,9,5,3,4,6,8,2,3,9,8,1,4,7,5,2,6,5,4,1,3,2,6,9,7,8,6,2,7,9,5,8,4,1,3");


sudoku::sudoku(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sudoku)
{
    ui->setupUi(this);
    initGui();
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    //timer->start(1000);
}

sudoku::~sudoku(){
    delete ui;
}


void sudoku::initGui(){
    for(int i = 0;i < 9; i++){
        for(int j = 0; j < 9; j++){
            numbertext[i][j] = new QTextEdit(NULL);
            ui->numberPad->addWidget(numbertext[i][j], i, j);

            connect(numbertext[i][j],SIGNAL(textChanged()),this,SLOT(correccionInGame()));
        }
    }
}
/**funcion que valida numeros ingresados*/
void sudoku::correccionInGame(){
QTextEdit *numberTextTemp = ( QTextEdit *) sender();

 long inputNumber = numberTextTemp->toPlainText().toLong();
 if ((inputNumber>9 || inputNumber<1)&& inputNumber!=NULL){
     QMessageBox::information(this, "Advertencia", "El numero ingresado no es valido esta fuera del rango");
     numberTextTemp->setText("");
  }

 for(int i = 0; i < 9; i++){
     for(int j = 0; j < 9; j++){
         if(((getDisplayValue(i,j)!=0) && numbertext[i][j]->isEnabled())){
         CorreccionFila(i,j);
         CorreccionColumna(i,j);
         CorreccionCuadrante(i,j);
         }
     }
 }


}



void sudoku::CorreccionFila(int i,int j){
 int k=0;


    //validacion in game para filas
    for(int k = 0; k < 9; k++){
        if(k!=j){
          if(getDisplayValue(i,j)==getDisplayValue(i,k)){
              QPalette p = numbertext[i][j]->palette();
              p.setColor(QPalette::Base, QColor(255, 0, 0));
              numbertext[i][j]->setPalette(p);
              numbertext[i][k]->setPalette(p);
              QMessageBox::information(this, "Advertencia", "Este numero ya fue ingresado en la fila");
              return;
          }else{
              QPalette p = numbertext[i][j]->palette();
              p.setColor(QPalette::Base, QColor(255, 255,255));
              numbertext[i][j]->setPalette(p);
              numbertext[i][k]->setPalette(p);
          }
        }
    }



}


void sudoku::CorreccionColumna(int i,int j){
 int k=0;



    //validacion in game para columnas
    for(int k = 0; k < 9; k++){
        if(k!=i){
          if(getDisplayValue(i,j)==getDisplayValue(k,j)){
              QPalette p = numbertext[i][j]->palette();
              p.setColor(QPalette::Base, QColor(255, 0, 0));
              numbertext[i][j]->setPalette(p);
              numbertext[k][j]->setPalette(p);
              QMessageBox::information(this, "Advertencia", "Este numero ya fue ingresado en la columna");
              return;
          }else{
              QPalette p = numbertext[i][j]->palette();
              p.setColor(QPalette::Base, QColor(255, 255,255));
              numbertext[i][j]->setPalette(p);
              numbertext[k][j]->setPalette(p);
          }
        }

    }


}

void sudoku::CorreccionCuadrante(int i,int j){


   int despy=(i/3) *3;
   int despx=(j/3) *3;

    //validacion in game para cuadrantes
    for(int y = despy; y < despy+3; y++){
        for(int x =despx ; x < despx+3; x++){


            if(((y!=i) && (x!=j))){
              if(getDisplayValue(i,j)==getDisplayValue(y,x)){
                  QPalette p = numbertext[i][j]->palette();
                  p.setColor(QPalette::Base, QColor(255, 0, 0));
                  numbertext[i][j]->setPalette(p);
                  numbertext[y][x]->setPalette(p);
                  QMessageBox::information(this, "Advertencia", "Este numero ya fue ingresado en el cuadrante");
                  return;
              }else{
                  QPalette p = numbertext[i][j]->palette();
                  p.setColor(QPalette::Base, QColor(255, 255,255));
                  numbertext[i][j]->setPalette(p);
                  numbertext[y][x]->setPalette(p);
              }
            }
        }
    }

}
/**Actualizar Cronometro*/
void sudoku::update(){

      ui->lcdseg->display(seg);
      ui->lcdmsg->display(miliseg);
      ui->lcdmin->display(min);
      miliseg++;
      if(seg <  60){
          if(miliseg >= 100){
              miliseg = 0;
              seg++;
          }
      }else{
          seg=0;
          min++;
      }
}

void sudoku::setCargar(QString datos, QString nivel, QString cronometro, QString nombre){
   QStringList  valor;
   datosCargados = datos;
   QStringList  valores;
   int i,j,k=0;
   double cont =33, opera;
   valores = datosCargados.split(",");
   for(i = 0; i < 9; i++){
       for(j = 0; j < 9; j++){
           if(valores[k].toInt() == 33){
               numbertext[i][j]->setDisabled(false);
               numbertext[i][j]->setText("");
           }else{
               /**DESENCRIPTAR PANTILLA DEL SUDOKU*/
               if((valores[k].toInt())%2 == 0){
                   opera = sqrt(valores[k].toDouble()-cont);
               }else{
                   opera = sqrt(2*(valores[k].toDouble()-cont));
               }
               numbertext[i][j]->setTextColor(Qt::blue);
               numbertext[i][j]->setText(QString::number(opera));
               numbertext[i][j]->setDisabled(true);
           }
           numbertext[i][j]->setAlignment(Qt::AlignRight);
           k++;
       }
   }
   ui->textJugador->setText(nombre);
   ui->textJugador->setEnabled(false);
   ui->textNivel->setText(nivel);
   ui->textNivel->setEnabled(false);


   valor = cronometro.split(":");
   int minutos=valor[0].toDouble(), segundos = valor[1].toDouble(), milisegundos = valor[2].toDouble();
   min = minutos;
   seg = segundos;
   miliseg = milisegundos;

   timer->start(10);
   this->show();
}

/**COMPRUEBA SI EL JUEGO ES CORRECTO*/
void sudoku::on_comprobar_clicked(){
    long sumatoriah = 0;
    long productoh = 1;
    long sumatoriav = 0;
    long productov = 1;
    long sumatoriacuad = 0;
    long productocuad = 1;
    int despx=0,despy=0;
    int banderavalida=1;

    /**Validacion numeros del 1 al 9 en las filas*/
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
            banderavalida=0,i=10;/**linea que rompe el ciclo en caso de no cumplir condicion*/
    }

     /**Validacion numeros del 1 al 9 en las columnas*/
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
            banderavalida=0,j=10;/**linea que rompe el ciclo en caso de no cumplir condicion*/
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
            banderavalida=0,x=10;/**linea que rompe el ciclo en caso de no cumplir condicion*/
    }

    /**comprobacion de validacion en general*/
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

/**SALIR DESDE EL MENU*/
void sudoku::on_actionQuit_triggered(){
    qApp->quit();
}
/**BORRAR JUEGO*/
void sudoku::on_borrarJuego_clicked(){
    for(int i = 0;i < 9; i++){
        for(int j = 0; j < 9; j++){
            numbertext[i][j]->setText("");
        }
    }
}
/**SALIR*/
void sudoku::on_salir_clicked(){
    this->close();
}
/**JUEGO NUEVO*/
void sudoku::on_nuevoJuego_clicked(){
    int i=0, j=0, k=0, aleatorio;
    QStringList  valores;

    /**Semilla del aleatorio*/
    QTime *seed = new QTime;
    seed->start();
    qsrand(seed->msec());

    QString niveles = ui->textNivel->text();

    /**MODO JUVENIL(FACIL)*/
    if(niveles == "Juvenil"){
        k=0;
        valores = plantilla1.split(",");

        for(i = 0;i < 9; i++){
            for(j = 0; j < 9; j++){
                aleatorio = rand() % 10;
                if (aleatorio <= 6){
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

        /**MODO PROFESIONAL(MEDIO)*/
    }else if(niveles == "Profesional"){
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

        /**MODO EXPERTO(DIFICIL)*/
    }else if(niveles == "Experto"){
        k=0;
        valores = plantilla3.split(",");

        for(i = 0;i < 9; i++){
            for(j = 0; j < 9; j++){
                aleatorio = rand() % 10;
                if (aleatorio <= 2){
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
    }
    /**Comenzar el cronometro*/
    timer->start(10);
}
/**RESOLVER JUEGO*/
void sudoku::on_resolverJuego_clicked(){
    int i=0, j=0, k=0;
    QStringList  valores;

    QString niveles = ui->textNivel->text();
    k=0;
    if(niveles == "Juvenil"){
        valores = plantilla1.split(",");
        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                if(numbertext[i][j]->isEnabled()){
                    numbertext[i][j]->setTextColor(Qt::black);
                    numbertext[i][j]->setText(valores[k]);
                    numbertext[i][j]->setAlignment(Qt::AlignRight);
                }
                k++;
            }
        }
    }else if(niveles == "Profesional"){
        valores = plantilla2.split(",");
        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                if(numbertext[i][j]->isEnabled()){
                    numbertext[i][j]->setTextColor(Qt::black);
                    numbertext[i][j]->setText(valores[k]);
                    numbertext[i][j]->setAlignment(Qt::AlignRight);
                }
                k++;
            }
        }
    }else if(niveles == "Experto"){
        valores = plantilla3.split(",");
        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                if(numbertext[i][j]->isEnabled()){
                    numbertext[i][j]->setTextColor(Qt::black);
                    numbertext[i][j]->setText(valores[k]);
                    numbertext[i][j]->setAlignment(Qt::AlignRight);
                }
                k++;
            }
        }
    }
}
/**CARGAR JUEGO*/
void sudoku::on_cargarJuego_clicked(){

    QComboBox *comboB = new QComboBox();
    CargarSudoku *cargarJuego = new CargarSudoku(this);
    QStringList  valores;

    //QString nomJugador, nivelC, datosSudoku;
    QString nomJugador, nivelC, crono, datosSudoku;

    QString mFilemane = "guardar.txt";
    QFile mFile(mFilemane);
    mFile.open(QIODevice::Text | QIODevice::ReadOnly);
    if(!mFile.isOpen()){return;}
    QTextStream txtstr(&mFile);
    int cont=0;

    while(!txtstr.atEnd()){
        datosSudoku = txtstr.readLine();
        mFile.flush();
        mFile.close();

        valores = datosSudoku.split("/");
        nomJugador = valores[0];
        nivelC = valores[1];
        crono = valores[2];
        datosSudoku = valores[3];
        if(ui->textNivel->text() == nivelC){
            comboB->addItem(nomJugador);
        }
        cont++;
    }

    this->close();
    QString jugador = ui->textJugador->text(), level = ui->textNivel->text();
    cargarJuego->setCombo(comboB, cont,jugador, level);
    cargarJuego->show();
}

/**ENCRIPTAR LA PARTIDA DE SUDOKU*/
void sudoku::encriptarS(){
    int i = 0, j = 0, cont = 33, num1 = 0, numT = 0;

    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            num1 = (matrizGuardar[i][j].toInt()) * (matrizGuardar[i][j].toInt());

            if((matrizGuardar[i][j].toInt() % 2) == 0)     numT = (num1 / 2) + cont;
            else       numT = num1 + cont;

            matrizGuardar[i][j].setNum(numT);
        }
    }
}
/**GUARDAR JUEGO*/
void sudoku::on_guardarJuego_clicked(){
    timer->stop();
    QString nomJugador = ui->textJugador->text();
    QString nivel= ui->textNivel->text();
    QString sMin = QString::number(ui->lcdmin->intValue());
    QString sSeg = QString::number(ui->lcdseg->intValue());
    QString sMiliseg = QString::number(ui->lcdmsg->intValue());

    QString info = "";

    /**Actualizar la matriz*/
    for(int i = 0;i < 9; i++){
        for(int j = 0; j < 9; j++){ matrizGuardar[i][j] = numbertext[i][j]->toPlainText(); }
    }

    encriptarS();
    for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                info = info+matrizGuardar[i][j]+",";
            }
    }
    QString mFilemane = "guardar.txt";
    QFile mFile(mFilemane);
    mFile.open(QIODevice::Text | QIODevice::Append);
    if(!mFile.isOpen()){return;}
    QTextStream txtstr(&mFile);
   // txtstr << nomJugador+"/"+nivel+"/"+info+"\n";
   txtstr << nomJugador+"/"+nivel+"/"+sMin+":"+sSeg+":"+sMiliseg+"/"+info+"\n";
    mFile.flush();
    mFile.close();

    QMessageBox::information(this, "Guardar-Sudoku", "La partida ha sido guardada \nJUGADOR: "+nomJugador.toUpper(),"ACEPTAR");
    this->close();
}

/**Funcion de enviar nombre y nivel*/
void sudoku::obtenerNombreNivel(QString nivel, QString nombre){
    nivelSudoku = nivel;
    nombreJugador = nombre;
    
    ui->textJugador->setText(nombre);
    ui->textJugador->setEnabled(false);
    ui->textNivel->setText(nivel);
    ui->textNivel->setEnabled(false);
}


//funcion para hacer trampa comparar valores con la solucion y marcar los que no coincidan

void sudoku::on_verificar_clicked()
{
    int k=0;
    QStringList  valores;

    QString niveles = ui->textNivel->text();
    k=0;

    if(niveles == "Juvenil")
        valores = plantilla1.split(",");

    if(niveles == "Profesional")
        valores = plantilla2.split(",");

    if(niveles == "Experto")
         valores = plantilla3.split(",");

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                //si coincide la respuesta se pintara azul sino coincide se pintara de rojo el cuadro
                if((numbertext[i][j]->isEnabled()) && (getDisplayValue(i,j)!=0) && (getDisplayValue(i,j)!=valores[k].toLong())){
                    QPalette p = numbertext[i][j]->palette();
                    p.setColor(QPalette::Base, QColor(255, 0, 0));
                    numbertext[i][j]->setPalette(p);
                }
                if((numbertext[i][j]->isEnabled()) && (getDisplayValue(i,j)!=0) && (getDisplayValue(i,j)==valores[k].toLong())){

                    QPalette p = numbertext[i][j]->palette();
                    p.setColor(QPalette::Base, QColor(120, 120, 255));
                    numbertext[i][j]->setPalette(p);
                }
                k++;
            }
        }




}
