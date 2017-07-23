//
//  treasure.cpp
//  item
//
//  Created by 姚博伦 on 2017/7/17.
//  Copyright © 2017年 姚博伦. All rights reserved.
//

#include <iostream>
#include "treasure.h"

Treasure::Treasure(string type, Character *dragon): Item{type}, dragon{dragon}{}

string Treasure::effect(Character *c) {
    int Gold = c->getGold();
    string g;
    if(type == "small"){
        c->addGold(Gold + 1);
        g = "small";
    } else if(type == "normal") {
        c->addGold(Gold + 2);
        g = "normal";
    } else if(type == "merchant_hoard") {
        c->addGold(Gold + 4);
        g = "merchant_hoard";
    } else if(type == "dragon_hoard") {
        c->addGold(Gold + 6);
        g = "dragon_hoard";
    } else if(type == "human_normal"){
        c->addGold(Gold + 4);
    } else {
        cout << "Gold type doesn't exist" << endl;
    }
    return g;
}
bool Treasure::is_Potion() {
    return false;
}

Character *Treasure::getdragon(){
    return dragon;
}

void Treasure::setdragon(Character *d){
    dragon = d;
}
