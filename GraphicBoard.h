#ifndef GRAPHICBOARD_H
#define GRAPHICBOARD_H
#include "window.h"
#include "Player.h"
#include "Observer.h"

class GraphicBoard: public Observer {
  const int winSize;
  //int h = winSize;
  int mid = winSize/2;
  int btw = 5;
  int bth = 20;
  int cw = 120;
  int ch = 110;
  int s = winSize/5;
  Xwindow xw;
  public:
    GraphicBoard(int winSize);
    void notify(Player &p) override;
};
#endif
