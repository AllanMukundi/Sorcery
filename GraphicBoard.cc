#include "GraphicBoard.h"
#include "Board.h"

using namespace std;



GraphicBoard::GraphicBoard(int winSize):winSize{winSize}, xw{winSize, winSize}{
    int w = winSize;
    //int h = winSize;
    int mid = winSize/2;
    int btw = 5;
    int bth = 20;
    int cw = 100;
    int ch = 100;
    int s = winSize/5;
    //enum {White=0, Black, Red, Green, Blue, Cyan, Yellow, Magenta, Orange, Brown}; // Available colours.
    xw.fillRectangle(0, 0, winSize, winSize, Xwindow::Brown);
    xw.fillRectangle(15, 15, w-15*2, bth + ch*5 + 15, Xwindow::Yellow);

    for (int i = 0; i < 5; ++i) {
      xw.fillRectangle(s*i + 20, bth, cw, ch, Xwindow::Green);
    }
    for (int i = 0; i < 5; ++i) {
      xw.fillRectangle(s*i + 20, bth + ch + 20, cw, ch, Xwindow::Blue);
    }

    xw.drawBigString(mid-80, bth + ch*2 + 20*2 + 35,"Sorcery", Xwindow::Black);

    for (int i = 0; i < 5; ++i) {
      xw.fillRectangle(s*i + 20, bth + ch*3, cw, ch, Xwindow::Blue);
    }

    for (int i = 0; i < 5; ++i) {
      xw.fillRectangle(s*i + 20, bth + ch*4 + 20, cw, ch, Xwindow::Green);
    }

    for (int i = 0; i < 5; ++i) {
      xw.fillRectangle(s*i + 20, bth + ch*5 + 60, cw, ch, Xwindow::Blue);
    }
    // for now just figure out which pixels will go where,
    // what width and height etc.
    // Define constants and use functions for "card" and "player"
}


void GraphicBoard::notify(Player &p) {
  // later on, when observer patter done, we will have display items on notify
  // i.e move everything from constructor to here
}

