#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include "sudoku.h"


VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Juvenil");
    ui->comboBox->addItem("Profesional");
    ui->comboBox->addItem("Experto");
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(tiempoFuera()));
}

VentanaPrincipal::~VentanaPrincipal(){
    delete ui;
}

void VentanaPrincipal::changeEvent(QEvent *e){
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:    break;
    }
}

void VentanaPrincipal::tiempoFuera(){
    static short valor = 0;
    ui->barra->setValue(valor);
    ++valor;

    if(valor == 101){
        timer->stop();
        this->close();
        sudoku *sudo = new sudoku();
        QString sd = ui->comboBox->currentText();
        QString nom = ui->nombreJug->text();
        sudo->obtenerNombreNivel(sd,nom);
        sudo->show();
    }
}

void VentanaPrincipal::on_bEntrar_clicked(){
    int bandera=0;
    QStringList  valores;

    QString nomJugador, nivelC, crono, datosSudoku;
    QString mFilemane = "guardar.txt";
    QFile mFile(mFilemane);
    if(mFile.exists())
    {

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
            crono = valores[2];
            datosSudoku = valores[3];
            if(ui->nombreJug->displayText() == nomJugador){
                bandera =1;
                break;
            }
        }
    }

    if(ui->nombreJug->text() == ""){
        QMessageBox::information(this, "MENSAJE", "Por favor agregue el\nnombre del JUGADOR","ACEPTAR");
    }else if (bandera == 1){
        QMessageBox::information(this, "MENSAJE", "Por favor ingrese otro \nnombre de JUGADOR","ACEPTAR");
        ui->nombreJug->setText("");
    }else
        timer->start(30);
}

void VentanaPrincipal::on_bPuntajes_clicked(){
   /**Cierro la Ventana Principal*/
    QString mFilemane = "guardar.txt";
    QFile mFile(mFilemane);

    if(mFile.exists()){
        /**Llamo a la Ventana de PUNTAJES*/
        this->close();
        Puntajes *puntajes = new Puntajes();
        puntajes->show();
        puntajes->setPuntajes();
    }else
        QMessageBox::information(this, "MENSAJE", "No existen Puntajes Guardados","ACEPTAR");
}
