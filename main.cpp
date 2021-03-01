//include "Game.h"
#include "windowmanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WindowManager w;
    w.init();
    //w.show();

    return a.exec();
}
