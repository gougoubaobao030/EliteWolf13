#include "notation.h"
#include <QPainter>

Notation::Notation(int mark)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFont(QFont("ubuntu", 16));
    setZValue(1);
    setOpacity(0.8);

    //povit is 50
    switch (mark) {
    case 10: {
        setPlainText(QString("自称预言师"));
        setDefaultTextColor(Qt::red);
        setPos(0,40);
        break;
    }
    case 11:{
        setPlainText(QString("村民"));
        setDefaultTextColor(Qt::red);
        setPos(130 -8,40);

        break;
    }
    case 12:{
        setPlainText(QString("人狼"));
        setDefaultTextColor(Qt::red);
        setPos(195 -8,40);

        break;
    }
    case 20: {
        setPlainText(QString("自称预言师"));
        setDefaultTextColor(Qt::blue);
        setPos(0,80);

        break;
    }
    case 21:{
        setPlainText(QString("村民"));
        setDefaultTextColor(Qt::blue);
        setPos(130 -8,80);

        break;
    }
    case 22:{
        setPlainText(QString("人狼"));
        setDefaultTextColor(Qt::blue);
        setPos(195 -8,80);

        break;
    }
    case 30: {
        setPlainText(QString("自称灵能师"));
        setDefaultTextColor(Qt::darkYellow);
        setPos(0,120);

        break;
    }
    case 31:{
        setPlainText(QString("村民"));
        setDefaultTextColor(Qt::darkYellow);
        setPos(130 -8,120);

        break;
    }
    case 32:{
        setPlainText(QString("人狼"));
        setDefaultTextColor(Qt::darkYellow);
        setPos(195 -8,120);

        break;
    }
    case 40: {
        setPlainText(QString("自称灵能师"));
        setDefaultTextColor(Qt::green);
        setPos(195 + 65 -8,120);

        break;
    }
    case 41:{
        setPlainText(QString("村民"));
        setDefaultTextColor(Qt::green);
        setPos(130 + 195 + 65 -8,120);

        break;
    }
    case 42:{
        setPlainText(QString("人狼"));
        setDefaultTextColor(Qt::green);
        setPos(195 + 195 + 65 -8,120);

        break;
    }
    case 50:{
        setPlainText(QString("预言师"));
        setDefaultTextColor(Qt::darkCyan);

        break;
    }
    case 51:{
        setPlainText(QString("灵能师"));
        setDefaultTextColor(Qt::darkCyan);
        setPos(80, 0);
        break;
    }
    case 52:{
        setPlainText(QString("村民"));
        setDefaultTextColor(Qt::darkCyan);
        setPos(160, 0);
        break;
    }
    case 53:{
        setPlainText(QString("人狼"));
        setDefaultTextColor(Qt::darkCyan);
        setPos(220, 0);
        break;
    }
    case 54:{
        setPlainText(QString("狂人"));
        setDefaultTextColor(Qt::darkCyan);
        setPos(280, 0);
        break;
    }
    case 55:{
        setPlainText(QString("骑士"));
        setDefaultTextColor(Qt::darkCyan);
        setPos(340, 0);
        break;
    }
    case 60: {
        setPlainText(QString("自称预言师"));
        setDefaultTextColor(Qt::darkMagenta);
        setPos(195 + 65 -8,40);
        break;
    }
    case 61:{
        setPlainText(QString("村民"));
        setDefaultTextColor(Qt::darkMagenta);
        setPos(130 + 195 + 65 -8,40);

        break;
    }
    case 62:{
        setPlainText(QString("人狼"));
        setDefaultTextColor(Qt::darkMagenta);
        setPos(195 + 195 + 65 -8,40);

        break;
    }
    case 70: {
        setPlainText(QString("自称灵能师"));
        setDefaultTextColor(Qt::darkGreen);
        setPos(195 + 65 -8,80);

        break;
    }
    case 71:{
        setPlainText(QString("村民"));
        setDefaultTextColor(Qt::darkGreen);
        setPos(130 + 195 + 65 -8,80);

        break;
    }
    case 72:{
        setPlainText(QString("人狼"));
        setDefaultTextColor(Qt::darkGreen);
        setPos(195 + 195 + 65 -8,80);

        break;
    }
    }
}

void Notation::paint(QPainter *pain, const QStyleOptionGraphicsItem *o, QWidget *widget)
{
//    pain->fillRect(boundingRect(), Qt::white);
    pain->setBrush(Qt::white);
    pain->drawRoundedRect(boundingRect(),15, 15);
//    pain->setOpacity(0.6);
    QGraphicsTextItem::paint(pain, o, widget);
}
