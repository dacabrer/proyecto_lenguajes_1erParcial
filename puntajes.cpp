#include "puntajes.h"
#include "ui_puntajes.h"
#include <QString>

Puntajes::Puntajes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Puntajes)
{
    ui->setupUi(this);
}

Puntajes::~Puntajes()
{
    delete ui;
}

void Puntajes::setPuntajes(){
    int bandera=0;
    QStringList  valores;

    QString nomJugador, nivelC, crono, datosSudoku;
    QString mFilemane = "guardar.txt";
    QFile mFile(mFilemane);

    if(mFile.exists()){

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

            QStringList valor;
            valor = crono.split(":");
            int min = valor[0].toDouble(), seg = valor[1].toDouble(), mseg = valor[2].toDouble();
            int puntaje = 0;
            if (nivelC == "Juvenil"){
                puntaje = 90*(min+seg+mseg)/3;
            }else if(nivelC == "Profesional"){
                puntaje = 90*(min+seg+mseg)/2;
            }else if(nivelC == "Experto"){
                puntaje = 90*(min+seg+mseg);
            }
            QString str = QString::number(puntaje);
            ui->textPuntajes->insertPlainText(nomJugador.toUpper()+"\t"+nivelC+"\t"+str+"\n");
            bandera = 1;

        }
    }
    if(bandera == 0){
        ui->textPuntajes->setDisabled(true);
        QMessageBox::information(this, "MENSAJE", "No existe Puntajes\nGuardados","ACEPTAR");

    }
}

void Puntajes::on_pushButton_clicked()
{

    //Cierro la Ventana Puntajes
    this->close();
    //Llamo a la Ventana de Principal
    VentanaPrincipal *vp = new VentanaPrincipal();
    vp->show();
}
