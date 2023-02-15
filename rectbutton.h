#ifndef RECTBUTTON_H
#define RECTBUTTON_H

#include <QGraphicsRectItem>
#include <QObject>

class RectButton :public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    RectButton();
    protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
signals:
    void shited();
};

#endif // RECTBUTTON_H
