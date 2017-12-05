#include <vector>
#include <memory>
#include "GraphicBoard.h"
#include "Board.h"

using namespace std;



GraphicBoard::GraphicBoard(int winSize):winSize{winSize}, xw{winSize, winSize}{
    int w = winSize;
    //int h = winSize;
    int mid = winSize/2;
    int btw = 5;
    int bth = 20;
    int cw = 120;
    int ch = 110;
    int s = winSize/5;

    // background
    xw.fillRectangle(0, 0, winSize, winSize, Xwindow::Brown);
    // gameBoard
    xw.fillRectangle(15, 15, w-15*2, bth + ch*5 + 15, Xwindow::Yellow);

    xw.drawBigString(mid-95, bth + ch*2 + 20*2 + 45,"Sorcery", Xwindow::Black);
}

void drawDescription(int x, int y, Xwindow &xw, string s, int width) {
    int charWidth = 3; // a guess
    int charsPerLine = (width - x) / charWidth;
    int start = 0;
    int height = y;
    while (start < s.length()) {
        xw.drawString(x, height, s.substr(start, charsPerLine), Xwindow::Black);
        start += charsPerLine;
        height += 15;
    }
}

Xwindow::Colour col(string type) {
  if (type == "Minion") return Xwindow::Green;
  if (type == "Enchantment") return Xwindow::Cyan;
  if (type == "Spell") return Xwindow::Blue;
  if (type == "Ritual") return Xwindow::Magenta;
}


void drawCard(int x, int y, Xwindow &xw, shared_ptr<Card> c) {
    int w = 800;
    //int h = winSize;
    int mid = w/2;
    int btw = 5;
    int bth = 20;
    int cw = 120;
    int ch = 110;
    int s = w/5;
    Xwindow::Colour strCol = Xwindow::Black;
  

    xw.fillRectangle(x, y, cw, ch, col(c->getType()));
    xw.drawString(x + 5, y + 15, c->getName(), strCol);
    xw.drawString(x + 105, y + 15, to_string(c->getCost()), strCol);
    //xw.drawString(x + 5, y + 45, c->getInfo(), strCol); // minion description

  if (c->getType() == "Minion") {
    xw.drawString(x + 85, y + 30, c->getType(), strCol);
    xw.drawString(x + 5, y + 105, to_string(dynamic_pointer_cast<Minion>(c)->getAttack()), strCol);
    xw.drawString(x + 105, y + 105, to_string(dynamic_pointer_cast<Minion>(c)->getDefence()), strCol);
  }
  if (c->getType() == "Enchantment") {
    shared_ptr<Enchantment> e = dynamic_pointer_cast<Enchantment>(c);
    xw.drawString(x + 50, y + 30, c->getType(), strCol);

    if (e->getAttack() != 0 && e->getDefence() != 0) {
      if (e->getName() == "Giant Strength") {
        xw.drawString(x + 5, y + 105, "+" + to_string(e->getAttack()), strCol);
        xw.drawString(x + 105, y + 105, "+" + to_string(e->getDefence()), strCol);
      } else if (e->getName() == "Enrage") {
        xw.drawString(x + 5, y + 105, "*" + to_string(e->getAttack()), strCol);
        xw.drawString(x + 105, y + 105, "*" + to_string(e->getDefence()), strCol);
      }
    }
  }
  if (c->getType() == "Spell") {
    xw.drawString(x + 85, y + 30, c->getType(), strCol);
  }
  if (c->getType() == "Ritual") {
    shared_ptr<Ritual> r = dynamic_pointer_cast<Ritual>(c);
    xw.drawString(x + 85, y + 30, c->getType(), strCol);
    xw.drawString(x + 5, y + 45, to_string(r->getAC()), strCol);

  }

}

void GraphicBoard::notify(Player &p) {
    int w = winSize;
    //int h = winSize;
    int mid = winSize/2;
    int btw = 5;
    int bth = 20;
    int cw = 120;
    int ch = 110;
    int s = winSize/5;

    vector<shared_ptr<Card>> c = p.getHand();
    Xwindow::Colour strCol = Xwindow::Orange;

    // row 1
    for (int i = 0; i < 5; ++i) {
      xw.fillRectangle(s*i + 20, bth, cw, ch, Xwindow::Green);
    }

    // row 2
    for (int i = 0; i < 5; ++i) {
      xw.fillRectangle(s*i + 20, bth + ch + 20, cw, ch, Xwindow::Blue);
    }

    // row 3
    for (int i = 0; i < 5; ++i) {
      xw.fillRectangle(s*i + 20, bth + ch*3, cw, ch, Xwindow::Blue);
    }

    // row 4
    for (int i = 0; i < 5; ++i) {
      xw.fillRectangle(s*i + 20, bth + ch*4 + 20, cw, ch, Xwindow::Green);
    }


    // active player hand
    if (p.getActive()) {
      for (int i = 0; i < p.getHand().size(); ++i) {
        drawCard(s*i + 20, bth + ch*5 + 60, xw, c.at(i));
        //xw.fillRectangle(s*i + 20, bth + ch*5 + 60, cw, ch, col(c.at(i)->getType()));
        //xw.drawString(s*i + 25, bth + ch*5 + 75, p.getHand().at(i)->getName(), strCol);
        //xw.drawString(s*i + 125, bth + ch*5 + 75, to_string(p.getHand().at(i)->getCost()), strCol);
      }
    }
    
}

  //enum Colour {White=0, Black, Red, Green, Blue, Cyan, Yellow, Magenta, Orange, Brown}; // Available colours.
