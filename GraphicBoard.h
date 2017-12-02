#ifndef GRAPHICBOARD_H
#define GRAPHICBOARD_H
#include "window.h"
#include "Player.h"
#include "Observer.h"

class GraphicBoard: public Observer {
  const int winSize;
  Xwindow xw;
  public:
    GraphicBoard(int winSize);
    void notify(Player &p) override;
};
#endif
