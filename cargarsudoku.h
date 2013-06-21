#ifndef CARGARSUDOKU_H
#define CARGARSUDOKU_H

#include <QMainWindow>
#include <QComboBox>

namespace Ui {
class CargarSudoku;
}

class CargarSudoku : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CargarSudoku(QWidget *parent = 0);
    ~CargarSudoku();
    
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::CargarSudoku *ui;
};

#endif // CARGARSUDOKU_H
