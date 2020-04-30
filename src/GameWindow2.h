//
// Created by Théo on 21/04/2020.
//

#ifndef PROJETQT_GAMEWINDOW2_H
#define PROJETQT_GAMEWINDOW2_H

#include "Level2.h"

#include <QMainWindow>
#include <QGraphicsView>
#include <QDesktopWidget>
#include <QVector>
#include <QPushButton>
#include <QLabel>
#include <QString>

//MEME CHOSE QUE POUR LES NIVEAU 1 et 3
class GameWindow2 : public QMainWindow
{
Q_OBJECT

private :
//    GameScene* gameScene;
    Level2* lvl2;
    QGraphicsView* mainView;
    QGraphicsView* playerView;
    QDesktopWidget dw;
    float time;
    QLabel* timeprint;
    QLabel* scoreprint;
public:
    GameWindow2(QWidget* parent = nullptr);

public slots:
    void Itswin();
    void Itsloose();
    void updatetime();
    void scrolling();

};

#endif //PROJETQT_GAMEWINDOW2_H
