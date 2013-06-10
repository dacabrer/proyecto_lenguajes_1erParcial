#include "sudoku.h"
#include "ventanaprincipal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //sudoku w;
    a.setStyle("fusion");
    VentanaPrincipal w;
    w.show();
    
    return a.exec();
}
