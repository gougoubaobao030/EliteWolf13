#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H

#include <QGraphicsPolygonItem>
#include <QObject>
#include <QPolygon>

class PlayButton :public QObject, public QGraphicsPolygonItem
{
    Q_OBJECT
public:
    bool isAuto;
    PlayButton();
    void changePolygon();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
private:
//    QPolygon tri;
//    QPolygon oct;
signals:
    void shit();

};

#endif // PLAYBUTTON_H
