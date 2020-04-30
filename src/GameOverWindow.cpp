//
// Created by Théo on 19/04/2020.
//

#include "GameOverWindow.h"
#include "GameWindow1.h"
#include "MenuWindow.h"

GameOverWindow::GameOverWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //INIT
    this->setWindowTitle("Théo LOPEZ");
    this->setFixedSize(dw.width(),dw.height());

    QWidget* window = new QWidget(this);
    window->setFixedSize(dw.width(),dw.height());

    this->setCentralWidget(window);
    this->setCursor(Qt::CrossCursor);

    centralWidget()->setObjectName("window");
    centralWidget()->setStyleSheet("QWidget #window { background-image : url(../img/menu/GameOver.png);}");


    // LES BOUTONS DU MENU
    QPushButton* bMainMenu = new QPushButton(window);
    bMainMenu->setCursor(Qt::PointingHandCursor);
    bMainMenu->setFixedSize(162,142);
    bMainMenu->move(563,769);
    bMainMenu->setIcon(QIcon("../img/Bouton/MainPage.png"));
    bMainMenu->setIconSize(QSize(162,142));

    QPushButton* bRestart = new QPushButton(window);
    bRestart->setCursor(Qt::PointingHandCursor);
    bRestart->setFixedSize(162,142);
    bRestart->move(782,769);
    bRestart->setIcon(QIcon("../img/Bouton/Restart.png"));
    bRestart->setIconSize(QSize(162,142));

    QPushButton* bQuit = new QPushButton(window);
    bQuit->setCursor(Qt::PointingHandCursor);
    bQuit->setFixedSize(162,142);
    bQuit->move(991,769);
    bQuit->setIcon(QIcon("../img/Bouton/quit.png"));
    bQuit->setIconSize(QSize(162,142));

    //LES CONNECT POUR ANIMER LA FENETRE
    connect(bQuit, SIGNAL(clicked()), this, SLOT(close()));
    connect(bRestart, SIGNAL(clicked()), this, SLOT(restart()));
    connect(bMainMenu, SIGNAL(clicked()), this, SLOT(pressMainPage()));
}
//POUR DEPLACER LE PERSONNAGE EST UTILISE POUR NE PAS OUVRIR PLUSIEURS FOIS LA FENETRE GAME OVER QUAND ON A PERDUS
void GameOverWindow::restart() {
    MenuLevel* menu = new MenuLevel();
    menu->show();
    this->close();
}

void GameOverWindow::pressMainPage() {
    MenuWindow* menu = new MenuWindow();
    menu->show();
    this->close();
}
