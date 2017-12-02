#include "GraphicBoard.h"

using namespace std;



GraphicBoard::GraphicBoard(int winSize):winSize{winSize}, xw{winSize, winSize}{
    xw.fillRectangle(0, 0, winSize, winSize, Xwindow::White);
    // for now just figure out which pixels will go where,
    // what width and height etc.
    // Define constants and use functions for "card" and "player"
}


void GraphicBoard::notify(Player &p) {
  // later on, when observer patter done, we will have display items on notify
  // i.e move everything from constructor to here
}

