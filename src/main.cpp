#include "MenuWindow.h"
#include <QApplication>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MenuWindow menu;
    menu.show();

    return app.exec();
}
