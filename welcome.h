#ifndef WELCOME_H
#define WELCOME_H

#include <QGraphicsPixmapItem>

class Welcome : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;

public:
    Welcome();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
signals:
    void shited();
};

#endif // WELCOME_H
