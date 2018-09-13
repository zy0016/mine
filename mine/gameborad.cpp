/***************************************************************
**
** Implementation of GameBoard class, Qt tutorial 14
**
****************************************************************/

#include "gameborad.h"
#include <qfont.h>
#include <qapplication.h>
#include <qlabel.h>
#include <qaccel.h>
#include <qpushbutton.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qvbox.h>
#include <qcombobox.h>
#include <qtextcodec.h>

GameBoard::GameBoard( QWidget *parent, const char *name )
        : QWidget( parent, name )
{
    iTimerCount = 0;
    //new game
    QPushButton *QBNewGame = new QPushButton( tr("&New Game"), this, "NewGame" );
    QBNewGame->setFont( QFont( "Times", 18, QFont::Bold ) );
    connect( QBNewGame, SIGNAL(clicked()), this, SLOT(NewGame()) );
    
    //exit
    QPushButton *QBQuit = new QPushButton( "&Quit", this, "Quit" );
    QBQuit->setFont( QFont( "Times", 18, QFont::Bold ) );
    connect( QBQuit, SIGNAL(clicked()), qApp, SLOT(quit()) );
    //difficult
    QComboDifficult = new QComboBox(this,"Difficult");
    QComboDifficult->setFont( QFont( "Times", 18, QFont::Bold ) );
    QComboDifficult->insertItem("Easy");
    QComboDifficult->insertItem("Middle");
    QComboDifficult->insertItem("Hard");
    connect(QComboDifficult,SIGNAL(activated(int)),this,SLOT(Difficult()));

    //about
    QPushButton *QBAbout = new QPushButton( "&About", this, "About" );
    QBAbout->setFont( QFont( "Times", 18, QFont::Bold ) );
    connect( QBAbout, SIGNAL(clicked()), this, SLOT(About()) );

    //MineChess
    QGridLayout *grid = new QGridLayout( this, 2, 2, 10 );
    qMineChess = new MineField( this, "Minechess" );

    //lcdnumber
    lcdminenum = new QLCDNumber(2,this,"lcd");
    lcdminenum->setFont(QFont("Times",9,QFont::Bold));
    //lcdminenum->display(10);
    connect(qMineChess,SIGNAL(MineNumberValueChange(int)),lcdminenum,SLOT(display(int)));

    //QVBoxLayout *leftBox = new QVBoxLayout;
    //grid->addLayout( leftBox, 1, 0 );

    //lcd for display timer
    lcdTimer = new QLCDNumber(2,this,"lcdTimer");
    lcdTimer->setFont(QFont("Times",9,QFont::Bold));
    lcdTimer->display(0);
    connect(this,SIGNAL(signals_setTime(int)),lcdTimer,SLOT(display(int)));

    //timer
    qMineTimer = new QTimer(this,"Mine handler");
    connect(qMineTimer,SIGNAL(timeout()),this,SLOT(MiningTimer()));
    //////////////////////////////////////////////////////////////
    connect(qMineChess,SIGNAL(StartMineTimer()),this,SLOT(slot_StartMine()));
    connect(qMineChess,SIGNAL(StopMineTimer()),this,SLOT(slot_StopMine()));
    connect(qMineChess,SIGNAL(ClearMineTime()),this,SLOT(slot_ClearMineTime()));
#if 0
    //This code is ok,too.
    QHBoxLayout *topBox = new QHBoxLayout;
    grid->addLayout( topBox, 0, 0 );
    topBox->addWidget( QBNewGame );
    topBox->addWidget( QBContrition );
    topBox->addWidget( QBPrompt );
    topBox->addWidget( QBQuit );
#else
    grid->addWidget( QBNewGame, 0, 0 );
    grid->addWidget( QBQuit, 0, 3 );
    grid->addWidget( QComboDifficult,0,1);
    grid->addWidget( QBAbout,0,2);
    grid->addWidget( lcdminenum,0,4);
    grid->addWidget( lcdTimer,0,5);
    grid->addMultiCellWidget(qMineChess,1,1,0,5);
#endif
    //topBox->addWidget( shotsLeftL );
    //topBox->addStretch( 1 );
    //topBox->addWidget( NewGame );

    //angle->setFocus();

    setMinimumSize(700,700);
    setMaximumSize(700,700);
    NewGame();
}

void GameBoard::slot_StartMine()
{
  qWarning("slot_StartMine");
  if (qMineTimer->isActive())
    return;
  iTimerCount = 0;
  qMineTimer->start(1000);
}
void GameBoard::slot_StopMine()
{
  qWarning("slot_StopMine");
  iTimerCount = 0;
  qMineTimer->stop();
}
void GameBoard::slot_ClearMineTime()
{
  qWarning("slot_ClearMineTime");
  iTimerCount = 0;
  signals_setTime(iTimerCount);
}

void GameBoard::MiningTimer()
{
  //if (qMineTimer->isActive())
  //  return;
  //lcdTimer->display(++iTimerCount);
  iTimerCount++;
  signals_setTime(iTimerCount);
  qWarning("Timer begin:%d",iTimerCount);
}
void GameBoard::Difficult()
{
}

void GameBoard::NewGame()
{
  qMineChess->NewGame();
}

void GameBoard::About()
{
    QMessageBox::about(this,"About Mine","Mine1.0 \n\n Copyright 21-12-2006 by Zhao Yong\n\n");
}
