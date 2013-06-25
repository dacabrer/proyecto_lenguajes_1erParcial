#ifndef SUDOKU_H
#define SUDOKU_H

#include <QMainWindow>
#include <cargarsudoku.h>
#include <guardarsudoku.h>
#include <cargarsudoku.h>
#include <QTextEdit>
#include <QMessageBox>
#include <QComboBox>

namespace Ui {
class sudoku;
}
class QTextEdit;
class sudoku : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit sudoku(QWidget *parent = 0);
    ~sudoku();
    void setCargar(QString datos, QString nivel);


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

private:
    void initGui();
    Ui::sudoku *ui;
    QTextEdit *numbertext[9][9];
    //Plantillas del Sudoku
    QString plantilla1 = "7,8,4,9,5,2,3,1,6,9,2,6,1,4,3,8,5,7,3,5,1,8,6,7,9,4,2,4,7,8,5,2,1,6,9,3,1,6,5,3,7,9,2,8,4,2,9,3,6,8,4,1,7,5,6,4,9,2,1,5,7,3,8,5,1,2,7,3,8,4,6,9,8,3,7,4,9,6,5,2,1";
    QString plantilla2 = "5,9,7,4,3,2,6,1,8,2,8,4,1,6,7,3,9,5,6,3,1,8,9,5,2,4,7,4,5,3,6,7,1,9,8,2,8,7,9,2,5,3,4,6,1,1,6,2,9,4,8,5,7,3,9,2,5,7,1,6,8,3,4,7,4,8,3,2,9,1,5,6,3,1,6,5,8,4,7,2,9";
    QString plantilla3 = "1,7,4,6,8,3,2,9,5,9,5,3,4,1,2,8,6,7,2,8,6,7,9,5,3,4,1,8,6,5,2,7,9,1,3,4,4,3,2,8,6,1,7,5,9,7,1,9,5,3,4,6,8,2,3,9,8,1,4,7,5,2,6,5,4,1,3,2,6,9,7,8,6,2,7,9,5,8,4,1,3";
    QString matrizGuardar[9][9];
    //QComboBox *cb;
    QComboBox *comboB = new QComboBox();
    QString datosCargados ="";

};

#endif // SUDOKU_H

