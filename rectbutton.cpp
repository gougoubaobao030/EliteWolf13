#include "rectbutton.h"

RectButton::RectButton()
{

}

void RectButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    emit shited();
}
