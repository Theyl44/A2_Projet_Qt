//
// Created by Théo on 21/04/2020.
//

#ifndef PROJETQT_TUTO2_H
#define PROJETQT_TUTO2_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QDesktopWidget>
//MEME CHOSE QUE POUR LE TUTO DE LA PAGE 1
class tuto2 : public QMainWindow {
Q_OBJECT

public:
    tuto2(QWidget *parent = nullptr);
    QDesktopWidget dw;

public slots:
    void pressMainMenu();
    void pressNext();
    void pressPrec();
};

#endif //PROJETQT_TUTO2_H
