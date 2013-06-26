#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <QTimer>

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
    void on_entrar_clicked();
    void tiempoFuera();

private:
    Ui::VentanaPrincipal *ui;
};

#endif /**VENTANAPRINCIPAL_H*/
