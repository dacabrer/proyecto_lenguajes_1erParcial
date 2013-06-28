#ifndef SUDOKU_H
#define SUDOKU_H

#include <QMainWindow>
#include "cargarsudoku.h"
#include "guardarsudoku.h"
#include "cargarsudoku.h"
#include <QTextEdit>
#include <QMessageBox>
#include <QComboBox>
#include <QTime>
#include <QTimer>

namespace Ui {
class sudoku;
}
class QTextEdit;
class sudoku : public QMainWindow
{
    Q_OBJECT
    class QTimer *timer;
    
public:
    explicit sudoku(QWidget *parent = 0);
    ~sudoku();
    void setCargar(QString datos, QString nivel,QString nombre);
    void obtenerNombreNivel(QString nivel, QString nombre);


private slots:
    void setDisplayValue(int i,int j,long v);
    long getDisplayValue(int i,int j);
    void on_actionQuit_triggered();
    void on_nuevoJuego_clicked();
    void on_resolverJuego_clicked();
    void on_borrarJuego_clicked();
    void on_comprobar_clicked();
    void on_guardarJuego_clicked();
    void on_cargarJuego_clicked();
    void on_salir_clicked();
    void encriptarS();
    void update();

private:
    void initGui();
    Ui::sudoku *ui;
    QTextEdit *numbertext[9][9];
    //Plantillas del Sudoku
    static const QString plantilla1;
    static const QString plantilla2;
    static const QString plantilla3;
    QString matrizGuardar[9][9];
    //QComboBox *cb;

    QString datosCargados;
    QString nivelSudoku;
    QString nombreJugador;

};

#endif // SUDOKU_H

