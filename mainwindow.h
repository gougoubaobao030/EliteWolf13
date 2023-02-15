#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QStringList>
#include <triangle.h>
#include "sceneofvote.h"
#include "commondata.h"
#include "playbutton.h"
#include <QTimer>
#include <QShortcut>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //discuss scene
    MainWindow(QWidget *parent = nullptr);
    void welcome();
    void notationForPlayer();
    void write();
    void read();

    //show text and character
    void iniDayN();
    void takeSpeech();

    QGraphicsScene * scene;
    QGraphicsView * view;
    CommonData * cd;
private:
    //tracking photo of elites
    QList<QGraphicsItem*> contestantsList;

    //store contestants's phrase and number from file
    int sequenceCounter; //count line, size
    QList<int> sequenceOfNumber;
    QStringList sequenceOfReason;

    int speechCounter;
    QGraphicsTextItem * speech;
    QGraphicsPixmapItem * character;
    Triangle * triangle;

    //-------------------------------------------------
    //vote scene
    SceneOfVote * sceneOfVote;

    //-------------------------------------------------
    //AutoPlay
    PlayButton * pb;
    QTimer * timer;
    //-------------------------------------------------
    //shortcut
    QShortcut * arrow;

    //-------------------------------------------------
    //tool function
    void giveCharacterName(QStringList & rawData);
    bool gameOver();

public slots:
    //start game and do all thing
    void mainScene();
    void voteScene();
    void sceneSwitch();

    //AutoPlay
    void beginAutoPlay();

    //-------------------------------------------------
    //how about that day alive one dead one

};
#endif // MAINWINDOW_H
