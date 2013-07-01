#ifndef CARGARSUDOKU_H
#define CARGARSUDOKU_H


#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <QComboBox>
#include "sudoku.h"

/**CARGARSUDOKU_H*/

namespace Ui {
class CargarSudoku;
}

class CargarSudoku : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CargarSudoku(QWidget *parent = 0);
    ~CargarSudoku();
    void setCombo(QComboBox *comboC, int cont, QString nombreJ, QString nivelJ);
private slots:
    void on_bcargarCargarJuego_clicked();
    void on_bsalirCargarJuego_clicked();

private:
    Ui::CargarSudoku *ui;
    QComboBox *comboCargar;
    QString selecCombo, pantillaCargada;
    QString nombreJugador, nivelJugador;
};

#endif
