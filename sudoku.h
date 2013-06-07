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
private:
    void initGui();
    Ui::sudoku *ui;
    QTextEdit *numbertext[9][9];
};

#endif // SUDOKU_H

