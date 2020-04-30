//
// Created by Théo on 17/04/2020.
//

#ifndef PROJETQT_FLAMMES_H
#define PROJETQT_FLAMMES_H

//objet qui va etre le danger de certain niveau car quand il rentre en contact avec le joueur il va fermer la fenetre et afficher la fenetre de gameover
#include <QtWidgets/QGraphicsItem>

class Flammes  : public QObject , public QGraphicsPixmapItem {
Q_OBJECT
private:
    QString description;
public:
    Flammes(QString description, QString imageFileName, int x, int y) : QGraphicsPixmapItem(QPixmap(imageFileName)),description(description)
    {
        this->setPos(x, y);
    }
};

#endif //PROJETQT_FLAMMES_H
