#include "vote.h"

Vote::Vote(int sequence, int isAlive)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    voteCounter = 0;
//    QPixmap *p = new QPixmap(QString(":/elite/") + QString::number(sequence) +
//                             QString("n.png"));
//    *p = p->scaled(100,100);
//    QPainter *pain = new QPainter(p);
//    pain->drawRect(10,10,50,50);
//    pain->drawRoundedRect(10,10,80, 80,20,20);

//    pain->setFont(QFont("ubuntu",50));
//    pain->drawText(0,75, QString::number(voteCounter));

//    QGraphicsPixmapItem::setPixmap(*p);

    vote = new QPixmap(QString(":/elite/") + QString::number(sequence) +
                   QString("n.png"));
    *vote = vote->scaled(100, 100);
    score = new QGraphicsTextItem(QString("0"), this);
    score->setPos(0,5);
    score->setFont(QFont("ubuntu", 50));
//    pain = new QPainter(vote);
//    pain->setFont(QFont("ubuntu", 50));
//    pain->drawText(0, 75, QString::number(voteCounter));
    setPixmap(*vote);
    if(isAlive != 1){

        setVisible(false);
    }


}

void Vote::showVote()
{
//    pain->drawText(0, 75, QString::number(voteCounter));
//    setPixmap(*vote);
    score->setPlainText(QString::number(voteCounter));
}

int Vote::getVoteCounter() const
{
    return voteCounter;
}

void Vote::setVoteCounter()
{
    voteCounter++;
    showVote();
}

void Vote::showFinalScore(QString fs)
{
//    QGraphicsTextItem * finalScore = new QGraphicsTextItem(this);
//    finalScore->setPlainText(fs);
//    finalScore->setPos(0, -this->boundingRect().height());
//    finalScore->setFont(QFont("ubuntu", 60));

    QGraphicsPixmapItem * killMan = new QGraphicsPixmapItem(this);
    killMan->setPixmap(QPixmap(QString(":/elite/") + fs +
                       QString("n.png")).scaled(100, 100));
    killMan->setPos(0, -this->boundingRect().height() - 10);
}
