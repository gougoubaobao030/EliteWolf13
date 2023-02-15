#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPolygonItem>

class Triangle : public QObject, public QGraphicsPolygonItem
{
    Q_OBJECT
private:
    bool isHover;
public:
    Triangle();
//    QRectF boundingRect() const override;
//    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget) override;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
//    void hoverEnterEvent(QGraphicsSceneHoverEvent * event) override;
//    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event) override;

    //やりたい　wheelEvent;

signals:
    void shited();
};

#endif // TRIANGLE_H
