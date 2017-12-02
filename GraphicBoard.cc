#include "GraphicBoard.h"

using namespace std;



GraphicBoard::GraphicBoard(int winSize):winSize{winSize}, xw{winSize, winSize}{
    xw.fillRectangle(0, 0, winSize, winSize, Xwindow::White);
}


void GraphicBoard::notify(Player &p) {
  
}

