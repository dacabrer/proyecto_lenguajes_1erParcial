#ifndef SUDOKU_H
#define SUDOKU_H

#include <QMainWindow>

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
    
private slots:
    void setDisplayValue(int i,int j,long v);
    long getDisplayValue(int i,int j);
    void on_Validar_clicked();
    void on_actionQuit_triggered();
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();
    void leerArchivo(const QString &nombre_archivo, QString &datos_salida);

    void on_comboBox_activated(const QString &arg1);

private:
    void initGui();
    Ui::sudoku *ui;
    QTextEdit *numbertext[9][9];
    QTextEdit *pantilla[9][9];
    const QString nombreArchivo = "D:/Home/Prueba.txt";
    QString salida;
    QString nivel;

};

#endif // SUDOKU_H

