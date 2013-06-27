#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <QTimer>
#include <sudoku.h>
#include <QMessageBox>

namespace Ui {
class VentanaPrincipal;
}

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT
    class QTimer *timer;
    
public:
    VentanaPrincipal(QWidget *parent = 0);
    ~VentanaPrincipal();

protected:
    void changeEvent(QEvent *e);

private slots:
    void tiempoFuera();
    void on_bEntrar_clicked();
    void on_bPuntajes_clicked();

private:
    Ui::VentanaPrincipal *ui;
};

#endif /**VENTANAPRINCIPAL_H*/
