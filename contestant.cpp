#include "contestant.h"
#include <QPainter>

Contestant::Contestant(int s)
{
//    setFlag(QGraphicsItem::ItemIsMovable);
    status = s;
    // 0 is killed by man
    // 2 is killed by wolf
}

void Contestant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rectf = boundingRect();
    QRect rect = rectf.toRect();
    switch (status) {
    case 0:
    {
        painter->drawPixmap(rect, QPixmap(":/elite/grey.png"));
        break;
    }
    case 1:
    {
        break;
    }
    case 2:
        painter->drawPixmap(rect, QPixmap(":/elite/magenta.png"));
        break;
    }
    QGraphicsPixmapItem::paint(painter, option, widget);
}
