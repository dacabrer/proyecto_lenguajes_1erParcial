#ifndef GUARDARSUDOKU_H
#define GUARDARSUDOKU_H

#include <QComboBox>
#include <QMainWindow>

namespace Ui {
class GuardarSudoku;
}

class GuardarSudoku : public QMainWindow
{
    Q_OBJECT
private:
    QComboBox *cb;
public:
    explicit GuardarSudoku(QWidget *parent = 0);
    ~GuardarSudoku();
    void guardarNivel(QComboBox *combo){
        cb = combo;
    }

private slots:
    void on_pushButton_2_clicked();
    void on_lineEdit_2_textEdited(const QString &arg1);

private:
    Ui::GuardarSudoku *ui;
};

#endif // GUARDARSUDOKU_H
