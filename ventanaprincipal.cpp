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
    timer->start(30);
}

void VentanaPrincipal::on_bPuntajes_clicked()
{

}
