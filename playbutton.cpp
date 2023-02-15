#include "playbutton.h"
#include <QBrush>

PlayButton::PlayButton()
{
    isAuto = false;
    QPolygon tri;
    tri << QPoint(0, 0) << QPoint(50, 50) << QPoint(0, 100);
    setPolygon(tri);
    setBrush(QBrush(Qt::gray));
}

void PlayButton::changePolygon()
{
    if(isAuto){
        setBrush(QBrush(Qt::cyan));
    }
    else{
        setBrush(QBrush(Qt::gray));
    }
}

void PlayButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);

    if(isAuto){
        isAuto = false;
    }
    else{
        isAuto = true;
    }
    changePolygon();
    emit shit();
}
