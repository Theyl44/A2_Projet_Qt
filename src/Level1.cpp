//
// Created by Théo on 17/04/2020.
//

#include "Level1.h"
#include <QFile>
#include <QTextStream>
using namespace std;

Level1::Level1() {
    //ON INIT LE NIVEAU AVEC LES IMAGES
    this->background.load("../img/level1/FondEspace.png");
    this->setSceneRect(0, 0, background.width(), background.height());

    this->player = new Player("player", "../img/level1/player.png", 2 , background.height() -144 -23);
    this->addItem(player);//144 sur 100 player.png
    //COMME LES IMAGES SONT PREVU POUR CE NIVEAU ON PEUT SE PERMETTRE DE LES PLACER AUX COO 0,0
    Ground* floor1 = new Ground("1floor", "../img/level1/1floor.png", 0, 0);
    Ground* floor2 = new Ground("2floor", "../img/level1/2floor.png",0,0);
    Ground* moon = new Ground(  "moon", "../img/level1/moon.png",0,0);
    Wall* wall1 = new Wall("wall1", "../img/level1/wall.png",0,0);
    Ground* floor4wall = new Ground("f4w", "../img/level1/floor4wall.png",0,0);
    Wall* wall4floor = new Wall("w4f", "../img/level1/wall4floor.png",0,0);
    FinalFlag* arrive = new FinalFlag("arrive", "../img/level1/finalFlag.png",0,0);
    Flammes* flammes = new Flammes("flammes", "../img/level1/flammes.png",0,0);
    Piece* c1 = new Piece("c1", "../img/level1/Coins.png",508,998);
    Piece* c2 = new Piece("c2", "../img/level1/Coins.png",1665,763);
    Piece* c3 = new Piece("c3", "../img/level1/Coins.png",776,503);

    //ON AJOUTE LES OBJET DANS LE THIS
    this->addItem(floor1);
    this->addItem(floor2);
    this->addItem(moon);
    this->addItem(wall1);
    this->addItem(floor4wall);
    this->addItem(wall4floor);
    this->addItem(arrive);
    this->addItem(flammes);
    this->addItem(c1);
    this->addItem(c2);
    this->addItem(c3);

}
//ON VA ECRIRE LE SCORE DANS UN FICHIER PRECIS QUAND LE JOUEUR A GAGNE LE NIVEAU
void Level1::writescore(float time, int score){
    QString filePath = "../resultat/timer-score1.txt";
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;
    QString buff = file.readAll();//contenu du fichier
    QTextStream flux(&file);
    flux.setCodec("UTF-8");

    if(buff.length() > 0){
//        cout<<"le fichier n'est pas vide\n";
//        QString nombre = buff;
        QString nombre = buff.split(" sec - ")[0];
        if(nombre.toFloat() > time){
            file.resize(0);
            flux <<time<<" sec - "<<score<<" pts";
        }
    }else{
//        cout<<"le fichier est vide et j'ecris dedans \n";
        flux <<time<<" sec - "<<score<<" pts";
    }

    file.close();
}
//SURCHARGE DE LA FONTION DRAWBACKGROUND DONNEE PAR M KARINE
void Level1::drawBackground(QPainter *painter, const QRectF &rect) {
    Q_UNUSED(rect);
    painter->drawPixmap(QRectF(0,0,background.width(), background.height()), background, sceneRect());
}

void Level1::keyPressEvent(QKeyEvent* event){
    this->player->keyPressEvent(background, event);

}

