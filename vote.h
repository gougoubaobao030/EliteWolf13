#ifndef VOTE_H
#define VOTE_H

#include <QGraphicsPixmapItem>
#include <QPainter>

class Vote : public QGraphicsPixmapItem
{
public:
    Vote(int sequence, int isAlive);
    void showVote();
    int getVoteCounter() const;
    void setVoteCounter();
    void showFinalScore(QString fs);

private:
    int voteCounter;
    QPixmap *vote;
//    QPainter * pain;
    QGraphicsTextItem * score;
};

#endif // VOTE_H
