//
// Created by Théo on 22/04/2020.
//

#include "GameWindow3.h"

GameWindow3::GameWindow3(QWidget *parent)
        : QMainWindow(parent)
{
    time = 0 ;
    int dx=dw.width();
    int dy=dw.height();

    this->lvl3 = new Level3();
    mainView = new QGraphicsView();
    mainView->setScene(lvl3);
    mainView->scale(0.9,0.9);
    this->setCentralWidget(mainView);
    this->setWindowTitle("GameWindow3");
    this->setFixedSize(dx, dy);

    playerView = new QGraphicsView();
    playerView->setScene(lvl3);
    playerView->resize(300, 300);
    playerView->setWindowTitle(lvl3->getPlayer()->getDescription());
    playerView->centerOn(lvl3->getPlayer());
    playerView->show();

    connect(this->lvl3->getPlayer(), SIGNAL(Itswin()),this, SLOT(Itswin()));
    connect(this->lvl3->getPlayer(), SIGNAL(Itsloose()),this, SLOT(Itsloose()));

    QTimer* time = new QTimer();
    time->start(100);
    connect(time, SIGNAL(timeout()), this, SLOT(updatetime()));
    connect(time, SIGNAL(timeout()), this, SLOT(scrolling()));

    timeprint = new QLabel(mainView);
    timeprint->setFixedSize(100,10);
    timeprint->move(20, 950);

    scoreprint = new QLabel(mainView);
    scoreprint->setFixedSize(100,10);
    scoreprint->move(20, 925);
}
void GameWindow3::updatetime(){
    this->time += 0.1;
    scoreprint->setText("score = "+QString::number(this->lvl3->getPlayer()->getScore()));
    timeprint->setText("time = "+QString::number(this->time)+" sec");
}
void GameWindow3::Itswin() {
    VictoryWindow* victoryWindow = new VictoryWindow();
    victoryWindow->show();
    this->lvl3->writescore(this->time, this->lvl3->getPlayer()->getScore());
    this->playerView->close();
    this->close();
}
void GameWindow3::Itsloose() {
    GameOverWindow* gameover = new GameOverWindow();
    gameover->show();
    this->playerView->close();
    this->close();
}
void GameWindow3::scrolling() {
    playerView->centerOn(lvl3->getPlayer());
}


