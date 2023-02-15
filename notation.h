#ifndef NOTATION_H
#define NOTATION_H

#include <QGraphicsTextItem>

class Notation : public QGraphicsTextItem
{
public:
    Notation(int mark);
    void paint(QPainter *pain, const QStyleOptionGraphicsItem * o, QWidget * widget) override;
};

#endif // NOTATION_H
