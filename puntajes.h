#ifndef PUNTAJES_H
#define PUNTAJES_H

#include <QWidget>
#include <ventanaprincipal.h>

namespace Ui {
class Puntajes;
}

class Puntajes : public QWidget
{
    Q_OBJECT
    
public:
    explicit Puntajes(QWidget *parent = 0);
    ~Puntajes();
    void setPuntajes();
    
private slots:
    void on_pushButton_clicked();


private:
    Ui::Puntajes *ui;
};

#endif // PUNTAJES_H
