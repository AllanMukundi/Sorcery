#include <string>
#include <iostream>
#include "Minion.h"
#include "Player.h"

using namespace std;

Minion::Minion(string name, int cost, string info, int attack, int defence, int abilityCost):
    Card{name, cost, info, "Minion"}, attack{attack}, defence{defence}, abilityCost(abilityCost)  {} 

void Minion::changeAttack(int amount) { attack += amount; }
void Minion::changeDefence(int amount) { defence += amount; }

int Minion::getAttack() const { return attack;}
int Minion::getDefence() const { return defence;}

card_template_t Minion::display() {
    //if (triggered_ability) {
      //return display_minion_triggered_ability(std::string name,int cost,int attack,int defence, std::string trigger_desc);
    //} else if(activated_ability) {
      //return display_minion_activated_ability(std::string name,int cost,int attack,int defence, int ability_cost, std::string ability_desc);
    //} else {
      return display_minion_no_ability(name, cost, attack, defence);
    //}
}

void Minion::attackMinion(Minion &m) {
  defence -= m.attack;
  m.defence -= m.attack;
}

void Minion::attackPlayer(Player &p) {
  p.changeHealth( -1 * attack);
}

void Minion::notify(Board &b, Player &p, int target) {
}

