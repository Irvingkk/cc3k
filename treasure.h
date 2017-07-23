//
//  treasure.h
//  item
//
//  Created by 姚博伦 on 2017/7/17.
//  Copyright © 2017年 姚博伦. All rights reserved.
//

#ifndef treasure_h
#define treasure_h

#include <iostream>
#include <string>
#include "item.h"

class Character;
class Treasure: public Item{
    Character *dragon;
public:
    Character *getdragon();
    void setdragon(Character *);
    bool is_Potion();
    Treasure(string type, Character *dragon);
    string effect(Character *c);
    ~Treasure(){}
};





#endif /* treasure_h */
