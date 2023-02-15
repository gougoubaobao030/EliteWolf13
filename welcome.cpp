#include "welcome.h"


Welcome::Welcome()
{
    setPixmap(QPixmap(":/elite/main.png").scaled(1300, 700));
}

void Welcome::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    emit shited();
//    QGraphicsPixmapItem::keyPressEvent(event);
}
