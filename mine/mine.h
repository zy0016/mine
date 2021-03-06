/****************************************************************
**
** Definition of NimField class, Qt tutorial 14
**
****************************************************************/

#ifndef _MINE_H_
#define _MINE_H_

class QTimer;

#include <qwidget.h>

typedef struct tagPOINT
{
    long x;
    long y;
}POINT;

#define DIFF_PRIMARY
//#define DIFF_MIDDLE
//#define DIFF_ADVANCED

#ifdef DIFF_PRIMARY
#define CHESSNUM 8
#define MINESNUM 10
#define MULTIPLIER 100000
#define HX1                    180                                    //????????
#define HY1                    3                                    //????????
#define BH                    40                                    //???
#define BW                    BH                                    //???
#elif defined DIFF_MIDDLE
#define CHESSNUM 16
#define MINESNUM 40
#define MULTIPLIER 100000
#define HX1                    90                                    //????????
#define HY1                    3                                    //????????
#define BH                    30                                    //???
#define BW                    BH                                    //???
#else
#define CHESSNUM 40
#define MINESNUM 100
#define MULTIPLIER 100000
#define HX1                    11                                    //????????
#define HY1                    3                                    //????????
#define BH                    20                                    //???
#define BW                    BH                                    //???
#endif

typedef enum
  {
    GRID_NORMAL,
    GRID_FLAG,
    GRID_INTERROGATION,
    GRID_CLICKOPEN,
    GRID_DEFEAT
  }GRIDTYPE;
typedef struct
{
  bool bMineType;//true:the grid has a mine,false:the grid hasn't a mine
  int iMineNum;//if the grid hasn't a mine,recore the number that around grid has mine.
  QPoint qPChessman;//the grid coordinate
  //bool bBroken;//true:the grid has been clicked by mouse left button,false:the grid hasn't been click by mouse left button
  GRIDTYPE eGridType;//when people click the grid by mouse right button,record the grid type.
  bool bCheck;//true:Be checked by recursion,false :don't check by recursion
}CHESSMANTYPE;

typedef enum
{
    Difficult_Easy,
    Difficult_Middle,
    Difficult_Hard
}CHESS_DIFFICULTY;

class MineField : public QWidget
{
    Q_OBJECT
public:
    MineField( QWidget *parent=0, const char *name=0 );

public slots:
    void NewGame();
    void Difficult(int iDifficult);

private slots:
  // void TimerMoveChessman();
signals:
 void MineNumberValueChange(int iValue);
 void StartMineTimer();
 void StopMineTimer();
 void ClearMineTime();
protected:
     void  paintEvent( QPaintEvent * );
     void  mousePressEvent( QMouseEvent * );
     //void  mouseMoveEvent( QMouseEvent * );
     //void  mouseReleaseEvent( QMouseEvent * );

private:
     void InitChessman();
     bool IfGameOver();
     bool IfExistMineInCurrentCol(int icol);
     bool GetChessNumber(int & iRow,int & iCol,const QPoint &point);
     void SetMines(int iRow,int iCol);
     void DrawMineNumber(QPainter & pTxt,int i,int j);
     void SetMineNumber(int iValue);
     void BeginMine();
     void MineOver();
     void ClearTime();
     //////
     int iFindMineNumber;//Find the mine number
     bool bMineDefeat;//true:mine defeat,display game over,false:game doesn't over,
     bool bStartMine;//true:begin mine,false:don't begin mine
     QString qClew;
     CHESSMANTYPE sChessmine[CHESSNUM][CHESSNUM];
};

#endif // _NIM_H_
