//
// Created by Théo on 19/04/2020.
//

#include "MenuLevel.h"
#include "MenuWindow.h"
#include "Level1.h"
//ICI ON A BCP DE BOUTONS QUI VONT REDIRIGER VERS LES FENETRES DES NIVEAUX
MenuLevel::MenuLevel(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("Theo LOPEZ");
    this->setFixedSize(dw.width(),dw.height());

    QWidget* window = new QWidget(this);
    window->setFixedSize(dw.width(),dw.height());

    this->setCentralWidget(window);
    this->setCursor(Qt::CrossCursor);

    centralWidget()->setObjectName("window");
    centralWidget()->setStyleSheet("QWidget #window { background-image : url(../img/menu/MenuLevel.png);}");

    QPushButton* bMainMenu = new QPushButton(window);
    bMainMenu->setCursor(Qt::PointingHandCursor);
    bMainMenu->setFixedSize(162,142);
    bMainMenu->move(55,60);
    bMainMenu->setIcon(QIcon("../img/Bouton/MainPage.png"));
    bMainMenu->setIconSize(QSize(162,142));

    QPushButton* bLvl1 = new QPushButton(window);
    bLvl1->setCursor(Qt::PointingHandCursor);
    bLvl1->setFixedSize(775,147);
    bLvl1->move(105,389);
    bLvl1->setIcon(QIcon("../img/Bouton/Level1Bouton.png"));
    bLvl1->setIconSize(QSize(775,147));

    QPushButton* bLvl2 = new QPushButton(window);
    bLvl2->setCursor(Qt::PointingHandCursor);
    bLvl2->setFixedSize(775,147);
    bLvl2->move(105,587);
    bLvl2->setIcon(QIcon("../img/Bouton/Level2Bouton.png"));
    bLvl2->setIconSize(QSize(775,147));

    QPushButton* bLvl3 = new QPushButton(window);
    bLvl3->setCursor(Qt::PointingHandCursor);
    bLvl3->setFixedSize(775,147);
    bLvl3->move(105,790);
    bLvl3->setIcon(QIcon("../img/Bouton/Level3Bouton.png"));
    bLvl3->setIconSize(QSize(775,147));

    connect(bMainMenu, SIGNAL(clicked()), this, SLOT(pressMainPage()));
    connect(bLvl1, SIGNAL(clicked()), this, SLOT(presslvl1()));
    connect(bLvl2, SIGNAL(clicked()), this, SLOT(presslvl2()));
    connect(bLvl3, SIGNAL(clicked()), this, SLOT(presslvl3()));
}

void MenuLevel::pressMainPage() {
    MenuWindow* menu = new MenuWindow();
    menu->show();
    this->close();
}

void MenuLevel::presslvl1() {
    GameWindow1* gameWindow = new GameWindow1();
    gameWindow->show();
    this->close();

}
void MenuLevel::presslvl2(){
    GameWindow2* gameWindow = new GameWindow2();
    gameWindow->show();
    this->close();
}
void MenuLevel::presslvl3() {
    GameWindow3* gameWindow3 = new GameWindow3();
    gameWindow3->show();
    this->close();
}