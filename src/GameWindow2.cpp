#include "GameWindow2.h"
//MEME CHOSE QUE POUR LES NIVEAU 1 et 3
GameWindow2::GameWindow2(QWidget *parent)
        : QMainWindow(parent)
{
    time = 0 ;
    int dx=dw.width();
    int dy=dw.height();

    this->lvl2 = new Level2();
    mainView = new QGraphicsView();
    mainView->setScene(lvl2);
    mainView->scale(0.9,0.9);
    this->setCentralWidget(mainView);
    this->setWindowTitle("GameWindow2");
    this->setFixedSize(dx, dy);


    playerView = new QGraphicsView();
    playerView->setScene(lvl2);
    playerView->resize(300, 300);
    playerView->setWindowTitle(lvl2->getPlayer()->getDescription());
    playerView->centerOn(lvl2->getPlayer());
    playerView->show();


    connect(this->lvl2->getPlayer(), SIGNAL(Itswin()),this, SLOT(Itswin()));
    connect(this->lvl2->getPlayer(), SIGNAL(Itsloose()),this, SLOT(Itsloose()));

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
void GameWindow2::updatetime(){
    this->time += 0.1;
    scoreprint->setText("score = "+QString::number(this->lvl2->getPlayer()->getScore()));
    timeprint->setText("time = "+QString::number(this->time)+" sec");
}
void GameWindow2::Itswin() {
    VictoryWindow* victoryWindow = new VictoryWindow();
    victoryWindow->show();
    this->lvl2->writescore(this->time, this->lvl2->getPlayer()->getScore());
    this->playerView->close();
    this->close();
}
void GameWindow2::Itsloose() {
    GameOverWindow* gameover = new GameOverWindow();
    gameover->show();
    this->playerView->close();
    this->close();
}
void GameWindow2::scrolling() {
    playerView->centerOn(lvl2->getPlayer());
}

