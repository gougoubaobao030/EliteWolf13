#ifndef SCENEOFVOTE_H
#define SCENEOFVOTE_H

#include <QGraphicsScene>
#include "vote.h"
#include "triangle.h"
#include "phototoplayer.h"
#include <QGraphicsView>
#include "commondata.h"
#include <QVector>
#include <playbutton.h>
#include <QTimer>
#include <QShortcut>

class SceneOfVote : public QGraphicsScene
{
public:
    SceneOfVote(QGraphicsView * view, QGraphicsScene * scene, CommonData * rcd, QObject *parent = nullptr);

    QGraphicsScene * mMainScene;
    QGraphicsView * mView;
    CommonData * cd;

    void iniVote();

    void showVoteList();
    void read(QString fileName);
    void showReason();

    //final
    void finalRead();
    void showFinalReason();
    void showFinalVote();
    void showyuigon();

    //playerTime
    void playChoice();

private:
    QList<bool> answerOfWolf;
    //tracking 13 photoes.
    QString fileNameOfCSV;
    QList<Vote*> trackingVote;

    //read data manage
    int countLine;
    QList<int> voteIndex;
    QList<int> votedIndex;
    QStringList voteReason;
    QVector<int> statisticVote;

    //show reason manage
    int countReason;
    QGraphicsPixmapItem * character;
    QGraphicsTextItem * reason;

    //button
    Triangle * triangle;

    //final
    bool needFinal;

    int countFinalReason;
    QList<int> fSpeechNumber;
    QStringList fSpeechReason;
    QStringList finalVote;

    //yuigonn
    QList<int> killedNumber;
    QStringList finalReason;
    int j; //謎のj

    //playerTime
    Triangle * playTri;
    QList<PhotoToPlayer*> playerChooseList;

    //AutoPlay
    PlayButton * pb;
    QTimer * timer;

    //-----------------------------------------------------
    QShortcut * arrow;

    //tool function
    void giveCharacterName(QStringList & rawData);

public slots:
    //player Time
    void checkPlayersChoose();
    void switchScene();
    void beginAutoPLay();
    void beginAutoFinal();
    void beginAutoFinalVote();
    void beginAutoYuigon();

};

#endif // SCENEOFVOTE_H
