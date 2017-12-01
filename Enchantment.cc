#include <string>
#include "Enchantment.h"

using namespace std;

Enchantment::Enchantment(string name, int cost, string info):
    Card{name, cost, info, "Enchantment"} {};

card_template_t Enchantment::display() {
  //if (attack_defence_enchantment) {
    //return display_enchantment_attack_defence(std::string name,int cost,std::string desc, std::string attack,std::string defence);
  //} else {
    return display_enchantment(name, cost, info);
  //}
}
void Enchantment::notify(Board &b, Player &p, int target) {
}
