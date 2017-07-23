//
//  main.cpp
//  cc3k
//
//  Created by j539li on 2017-07-18.
//  Copyright © 2017 j539li. All rights reserved.
//

#include <iostream>
#include "gameplay.h"

int main(int argc, const char * argv[]) {
    while(true){
        Gameplay game;
        int i = game.create_game();
        if(i == 1){
            continue;
        } else if(i == 2){
            return 0;
        }
    }
}
