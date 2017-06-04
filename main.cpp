#include "game_window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game_Window w;

    w.resize(1000, 700);
    w.show();


    Game_Window game_window;

    return a.exec();
}
