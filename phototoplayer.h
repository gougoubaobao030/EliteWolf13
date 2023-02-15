#ifndef PHOTOTOPLAYER_H
#define PHOTOTOPLAYER_H

#include <QGraphicsItem>

class PhotoToPlayer : public QGraphicsItem
{
public:

    PhotoToPlayer(QString index);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget) override;
    bool getIsChoosed() const;
    void setIsChoosed(bool newIsChoosed);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
private:
    bool isChoosed;
    QString index;
};

#endif // PHOTOTOPLAYER_H
