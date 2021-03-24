#include <QApplication>
#include "tictactoemain.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tictactoemain w;
    w.show();

    return a.exec();
}
