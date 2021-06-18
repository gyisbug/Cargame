/*-------NOM:GAO YAN-------*/
#ifndef GUITIME_H
#define GUITIME_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>
#include  <tgmath.h>

//Dessinez et gérez l'affichage du temps dans le jeu
class UI : public QGraphicsView
{
public:
    UI(QWidget *parent = 0);
    ~UI();

    void resettime(){time_->setText("00:00");}//reset
    void increasetime();//Croissance du temps

private:
    QFont * f;
    QGraphicsScene* Scene_;
    QGraphicsSimpleTextItem* time_;
    int record;
};

#endif // GUITIME_H
