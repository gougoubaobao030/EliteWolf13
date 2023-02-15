#include "phototoplayer.h"
#include <QPainter>

PhotoToPlayer::PhotoToPlayer(QString index)
{
    this->index = index;
    isChoosed = false;
//    setFlag(QGraphicsItem::ItemIsMovable);
}

QRectF PhotoToPlayer::boundingRect() const
{
    return QRectF(0, 0, 150, 200);
}

void PhotoToPlayer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);


    if(isChoosed){
//        painter->setBrush(Qt::darkGray);
        painter->fillRect(boundingRect(),Qt::gray);
    }
    else{
        painter->fillRect(boundingRect(), Qt::transparent);
    }
    QPixmap pm = QPixmap(QString(":/elite/") + index + QString(".png")).scaled(150, 200);
    painter->drawPixmap(0, 0, 150, 200, pm);
}

void PhotoToPlayer::mousePressEvent(QGraphicsSceneMouseEvent *event)

{
    Q_UNUSED(event);
    if(isChoosed) isChoosed = false;
    else isChoosed = true;

    update();
}

bool PhotoToPlayer::getIsChoosed() const
{
    return isChoosed;
}

void PhotoToPlayer::setIsChoosed(bool newIsChoosed)
{
    isChoosed = newIsChoosed;
}
