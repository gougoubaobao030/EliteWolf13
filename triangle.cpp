#include "triangle.h"
#include <QPainter>
#include <QPolygon>


Triangle::Triangle()
{
//    setFlag(QGraphicsItem::ItemIsMovable);
    QPolygon tri;
    tri << QPoint(0, 0) << QPoint(100, 100) << QPoint(0, 200);
    setPolygon(tri);
    setBrush(QBrush(Qt::cyan));
    isHover = false;
}

//QRectF Triangle::boundingRect() const
//{
//    return QRectF(0, 0, 100, 200);
//}

//void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
////    Q_UNUSED(option); Q_UNUSED(widget);
//    painter->setBrush(Qt::cyan);

//    QPolygon triangle;
//    triangle << QPoint(0, 0) << QPoint(100, 100) << QPoint(0, 200);
//    painter->drawPolygon(triangle);
//    QGraphicsPolygonItem::paint(painter, option, widget);
//}

void Triangle::mousePressEvent(QGraphicsSceneMouseEvent *event)

{
    Q_UNUSED(event);
    emit shited();
//    QGraphicsPolygonItem::mousePressEvent(event);
}

//void Triangle::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
//{
//    isHover = true;
//}

//void Triangle::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
//{
//    isHover = false;
//}
