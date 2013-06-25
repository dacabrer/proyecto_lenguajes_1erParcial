#ifndef GUARDARSUDOKU_H
#define GUARDARSUDOKU_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QTextStream>

namespace Ui {
class GuardarSudoku;
}

class GuardarSudoku : public QMainWindow
{
    Q_OBJECT
public:
    explicit GuardarSudoku(QWidget *parent = 0);
    ~GuardarSudoku();
    void setStr(QString snivel, QString m[9][9]);
    void encriptarSudoku();

private slots:
    void on_bsalirGuardaSudoku_clicked();
    void on_bguardarSudoku_clicked();

private:
    Ui::GuardarSudoku *ui;
    QString stringnivel;
    QString matriz[9][9];
};

#endif // GUARDARSUDOKU_H
