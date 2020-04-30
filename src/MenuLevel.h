//
// Created by Théo on 19/04/2020.
//

#ifndef PROJETQT_MENULEVEL_H
#define PROJETQT_MENULEVEL_H

#include <QMainWindow>
#include <QPushButton>
#include <QDesktopWidget>
//PAGE INTERMEDAIRE POUR CHOISIR LE NIVEAU QU'ON VEUT
class MenuLevel : public QMainWindow {
    Q_OBJECT

public:
    MenuLevel(QWidget *parent = nullptr);
    QDesktopWidget dw;

public slots:
    void pressMainPage();
    void presslvl1();
    void presslvl2();
    void presslvl3();

};


#endif //PROJETQT_MENULEVEL_H
