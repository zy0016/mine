/***************************************************************
**
** Definition of GameBoard class, Qt tutorial 14
**
****************************************************************/

#ifndef GAMEBRD_H
#define GAMEBRD_H

#include <qwidget.h>
#include <qcombobox.h>
#include <qcheckbox.h>
#include <qmessagebox.h>
#include <qlcdnumber.h>
#include <qtimer.h>
#include "mine.h"

class QPushButton;
//class LCDRange;
class QLCDNumber;
//class MineField;

class GameBoard : public QWidget
{
    Q_OBJECT
public:
    GameBoard( QWidget *parent=0, const char *name=0 );

protected slots:
  void  NewGame();
  void  Difficult();
  void  About();
  void  MiningTimer();
  void  slot_StartMine();
  void  slot_StopMine();
  void  slot_ClearMineTime();
 signals:
  void signals_setTime(int iTime);

private:
    MineField * qMineChess;
    QComboBox *QComboDifficult;
    QLCDNumber * lcdminenum;
    QLCDNumber * lcdTimer;
    QTimer * qMineTimer;
    unsigned int iTimerCount;
};
#endif // GAMEBRD_H
