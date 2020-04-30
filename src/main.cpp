#include "MenuWindow.h"
#include <QApplication>
#include <fstream>

//MAIN DE BASE OU ON AFFICHE LE MENU DU JEUX AU DEBUT
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MenuWindow menu;
    menu.show();
//    GameWindow2* gameWindow = new GameWindow2();
//    gameWindow->show();

    return app.exec();
}
