#include "sudoku.h"
#include "ventanaprincipal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.setStyle("fusion");
    //VentanaPrincipal w;
    sudoku w;
    w.show();
    
    return a.exec();
}
