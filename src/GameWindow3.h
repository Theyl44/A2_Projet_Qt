//
// Created by Théo on 22/04/2020.
//

#ifndef PROJETQT_GAMEWINDOW3_H
#define PROJETQT_GAMEWINDOW3_H


#include "Level3.h"

#include <QMainWindow>
#include <QGraphicsView>
#include <QDesktopWidget>
#include <QVector>
#include <QPushButton>
#include <QLabel>
#include <QString>

//MEME CHOSE QUE POUR LES NIVEAU 1 et 2
class GameWindow3 : public QMainWindow
{
Q_OBJECT

private :

    Level3* lvl3;
    QGraphicsView* mainView;
    QGraphicsView* playerView;
    QDesktopWidget dw;
    float time;
    QLabel* timeprint;
    QLabel* scoreprint;
public:
    GameWindow3(QWidget* parent = nullptr);
    virtual ~GameWindow3() {};

public slots:
    void Itswin();
    void Itsloose();
    void updatetime();
    void scrolling();

};


#endif //PROJETQT_GAMEWINDOW3_H
