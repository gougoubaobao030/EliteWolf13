#ifndef CONTESTANT_H
#define CONTESTANT_H

#include <QGraphicsPixmapItem>

class Contestant : public QGraphicsPixmapItem
{
public:
    Contestant(int s);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget * widget = nullptr) override;
    int status;
};

#endif // CONTESTANT_H
