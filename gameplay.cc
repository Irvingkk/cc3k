//
//  gameplay.cpp
//  item
//
//  Created by 姚博伦 on 2017/7/19.
//  Copyright © 2017年 姚博伦. All rights reserved.
//

#include "gameplay.h"
#include <ctype.h>
#include <sstream>
#include <iostream>
using namespace std;
Gameplay::Gameplay(): is_hostile{false}, champion{' '}, pc{nullptr}, curr{0}{
    Floor f1;
    Floor f2;
    Floor f3;
    Floor f4;
    Floor f5;
    v.push_back(f1);
    v.push_back(f2);
    v.push_back(f3);
    v.push_back(f4);
    v.push_back(f5);
    
}

//Gameplay::Gameplay(string file): is_hostile{false}, champion{' '}, curr{0}{
//    Floor f1(file,1);
//    Floor f2(file,2);
//    Floor f3(file,3);
//    Floor f4(file,4);
//    Floor f5(file,5);

//    v.push_back(f1);
//    v.push_back(f2);
//    v.push_back(f3);
//    v.push_back(f4);
//    v.push_back(f5);
//}
//



void Gameplay::setplayer(){
    switch(champion){
        case 's':{
            pc=new Shade();
            break;
        }
        case 'd':{
            pc=new Drow();
            break;
        }
        case 'v':{
            pc=new Vampire();
            break;
        }
        case 'g':{
            pc=new Goblin();
            break;
        }
        case 't':{
            pc=new Troll();
            break;
        }
        default:
            string s = "bad enter";
            throw s;
            break;
    }
    v[0].spawn_player(pc);
}

int Gameplay::create_game(){
//    vector<Floor
    cout << "choose a champion" << endl;
    while(true){
        if (cin >> champion){
            try{
                setplayer();
                v[curr].spawn_potions();
                v[curr].spawn_gold();
                v[curr].spawn_enemies();
                v[curr].DisplayMap();
            } catch(string s){
                cout << s << endl;
            }
            break;
        } else {
            cin.clear();
            cin.ignore();
        }
    }
    //displayall("");

    string s;
    string cmd;
    string mode = "normal";
    char c;
    int i = 0;
    while(true){
        string info = "";
        if(cin >> cmd){
            if(cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we" || cmd == "ne" ||
               cmd == "nw" || cmd == "se" || cmd == "sw"){
                info = v[curr].attackplayer(is_hostile);
                if(info == "player die!"){
                    displayall(info);
                    cin >> i;
                    return i;
                } else {
                    info = info + "\n" + v[curr].move_player(cmd);
                }
                if(mode == "normal"){
                    v[curr].move_enemy();
                }
                if(v[curr].move_player(cmd) == "true"){
                    if(curr == 4){
                        info = "game win!";
                        displayall(info);
                        cin >> i;
                        return i;
                    } else {
                        info += " and moves to the next floor!";
                        displayall(info);
                        ++curr;
                        pc->reset();
                        v[curr].spawn_player(pc);
                    }
                }
            } else{
                istringstream ss{cmd};
                if(!(ss >> c)){
                    cin.clear();
                    cin.ignore();
                    continue;
                };
                switch (cmd[0]) {
                    case 'u':
                        cin >> cmd;
                        info += v[curr].attackplayer(is_hostile);
                        if(info == "player die!"){
                            displayall(info);
                            cin >> i;
                            return i;
                        }
                        s = v[curr].usepotion(cmd);
                        if(s == "player die!"){
                            displayall(info);
                            cin >> i;
                            return i;
                        } else {
                            info += " and " + s;
                        }
                        if(mode == "normal"){
                            v[curr].move_enemy();
                        }
                        displayall(info);
                        break;
                    case 'a':
                        cin >> cmd;
                        info = v[curr].attackenemy(cmd,is_hostile);
                        s = v[curr].attackplayer(is_hostile);
                        if(s == "player die!"){
                            displayall(info);
                            cin >> i;
                            return i;
                        } else {
                            info += " and " + s;
                        }
                        if(mode == "normal"){
                            v[curr].move_enemy();
                        }
                        displayall(info);
                        break;
                    case 'f':
                        if(mode == "normal"){
                            mode = "static";
                            info = "change to normal mode";
                        } else {
                            mode = "normal";
                            info = "change to static mode";
                        }
                        displayall(info);
                    case 'r':
                        return 1;
                    case 'q':
                        return 2;
                    default:
                        cin.clear();
                        cin.ignore();
                }
            }
        } else{
            cin.clear();
            cin.ignore();
            continue;
        }
    }
}

void Gameplay::displayall(string info){
    v[curr].DisplayMap();
    string fullinfo;
    string pc;
    switch(champion){
        case 's':
            pc = "Shade";
        case 'd':
            pc = "Drow";
        case 'v':
            pc = "Vampire";
        case 'g':
            pc = "Goblin";
        case 't':
            pc = "Troll";
        default:
            break;
    }
    Character * player = (v[curr].getPlayer())->getCharacter();
    cout << "Race: " << pc << " Gold: " << player->getGold() << endl;
    cout << "Hp: " << player->getHp() <<endl;
    cout << "Atk: " << player->getAtk() <<endl;
    cout << "Def: " << player->getDef() <<endl;
    if(info == "player die!" || info == "game win!"){
        fullinfo = info + "1-playagain \n2-quit";
    }
    cout <<"Action: " << info<< endl;
}

Gameplay::~Gameplay(){
    //cout << "Game dtor" << endl;
    delete pc;
}
//consider player enemy movement after every round

















