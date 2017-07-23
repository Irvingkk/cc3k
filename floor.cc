//
//  floor.cpp
//  cc3k
//
//  Created by j539li on 2017-07-17.
//  Copyright © 2017 j539li. All rights reserved.
//

#include "floor.h"

//vector<vector<Cell>> grid;
//vector<vector<Cell>> chamber;
//vector<cell> availableCell;

using namespace std;

Floor::Floor() {
    cout << "Default cotr" <<endl;
    ifstream map("floor.txt");
//    if (map.is_open()) {
//        cout << "file is open" << endl;
//    }
    char ch = 'a';
    //grid[width][height];
    for (int i = 0; i < height; i++) {
        vector<Cell> temp;
        for (int j = 0; j < width; j++) {
            map.read(&ch,1);
            //grid[i][j].Cell();
            //grid[i][j].setCell(i,j,ch);
            Cell a = Cell();
            a.setCell(i,j,ch);
            temp.push_back(a);
            //cout << a.display;
        }
        //cout << endl;
        grid.push_back(temp);
    }
    vector<Cell*> temp1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width;j++) {
            if (i > 2 && i < 7) {
                if (j < 29 && j > 2) {
                    Cell* a = &(grid[i][j]);
                    temp1.push_back(a);
                }
            }
        }
    }
    //cout << temp1.size() << endl;
    chamber.push_back(temp1);
    vector<Cell*> temp2;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width;j++) {
            if (i == 3 || i == 4) {
                if (j < 62 && j > 38) {
                    Cell* a = &(grid[i][j]);
                    temp2.push_back(a);
                }
            }else if (i == 5) {
                if (j < 70 && j > 38) {
                    Cell* a = &(grid[i][j]);
                    temp2.push_back(a);
                }
            }else if (i == 6) {
                if (j < 73 && j > 38) {
                    Cell* a = &(grid[i][j]);
                    temp2.push_back(a);
                }
            }else if ( i > 6 && i < 13) {
                if (j > 60 && j < 78) {
                    Cell* a = &(grid[i][j]);
                    temp2.push_back(a);
                }
            }
        }
    }
   //cout << temp2.size() << endl;
    chamber.push_back(temp2);
    vector<Cell*> temp3;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i < 13 && i > 9) {
                if (j > 37 && j < 50) {
                    Cell* a = &(grid[i][j]);
                    temp3.push_back(a);
                }
            }
        }
    }
    chamber.push_back(temp3);
    //cout << temp3.size() << endl;
    vector<Cell*> temp4;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i < 22 && i > 14) {
                if (j > 3 && j < 25) {
                    Cell* a = &(grid[i][j]);
                    temp4.push_back(a);
                }
            }
        }
    }
    chamber.push_back(temp4);
    //cout << temp4.size() << endl;
    vector<Cell*> temp5;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 16 || i == 17 || i == 18) {
                if (j > 64 && j < 76) {
                    Cell* a = &(grid[i][j]);
                    temp2.push_back(a);
                }
            }else if (i < 22 && i > 18) {
                if (j > 36 && j < 76) {
                    Cell* a = &(grid[i][j]);
                    temp5.push_back(a);
                }
            }
        }
    }
    chamber.push_back(temp5);
    //cout << temp5.size() << endl;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <  width; j++) {
            if (is_valid(i-1, j-1)) {
                grid[i][j].neighbours.push_back(&(grid[i-1][j-1]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i, j-1)) {
                grid[i][j].neighbours.push_back(&(grid[i][j-1]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i+1, j-1)) {
                grid[i][j].neighbours.push_back(&(grid[i+1][j-1]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i-1, j)) {
                grid[i][j].neighbours.push_back(&(grid[i-1][j]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i+1, j)) {
                grid[i][j].neighbours.push_back(&(grid[i+1][j]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i+1, j)) {
                grid[i][j].neighbours.push_back(&(grid[i+1][j]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i-1, j+1)) {
                grid[i][j].neighbours.push_back(&(grid[i-1][j+1]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i, j+1)) {
                grid[i][j].neighbours.push_back(&(grid[i][j+1]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i+1, j+1)) {
                grid[i][j].neighbours.push_back(&(grid[i+1][j+1]));
                grid[i][j].numberofneighbours++;
            }
        }
    }
//    Character *pc = new Vampire();
//    spawn_player(pc);
//    spawn_potions();
//    spawn_gold();
//    spawn_enemies();
//    cout << playerX << "    "  << playerY << endl;
//    //swap(&(grid[4][11]), &(grid[4][12]));
//    
//    delete pc;
}


Floor::Floor(string filename, int floorindex) {
    ifstream map("floor.txt");
    char ch = 'a';
    for (int i = 0; i < height; i++) {
        vector<Cell> temp;
        for (int j = 0; j < width; j++) {
            map.read(&ch,1);
            Cell a = Cell();
            a.setCell(i,j,ch);
            temp.push_back(a);
            //cout << a.display;
        }
        //cout << endl;
        grid.push_back(temp);
    }
}

bool Floor::is_valid(int x, int y) {
    if (x < height && x >=0 && y >= 0 && y < width) return true;
    else return false;
}

Cell* Floor::getCell(int x, int y) {
    return &(grid[x][y]);
}

Cell* Floor::getPlayer() {
    return &(grid[playerX][playerY]);
}


void Floor::spawn_player(Character* pc) {
    cout << "spawn player here" << endl;
    int x, stairX;
    unsigned int y, stairY;
    x = rand() % 5;
//    cout << chamber[0].size() << endl;
//    cout << chamber[1].size() << endl;
//    cout << chamber[2].size() << endl;
//    cout << chamber[3].size() << endl;
//    cout << chamber[4].size() << endl;
    y = rand() % chamber[x].size();
    stairX = rand() % 5;
    while (1) {
        if (stairX == x) {
            stairX = rand() % 5;
        }else {
            break;
        }
    }
    chamber[x][y]->_content = pc;
    chamber[x][y]->display = '@';
    chamber[x][y]->set_player();
    cout << x << endl;
    cout << y << endl;
    playerX = chamber[x][y]->getx();
    playerY = chamber[x][y]->gety();
    cout << playerY << endl;
    cout << playerX << endl;
    stairY = rand() % chamber[stairX].size();
    chamber[stairX][stairY]->is_occupied = true;
    chamber[stairX][stairY]->is_player = false;
    chamber[stairX][stairY]->is_item = false;
    chamber[stairX][stairY]->is_enemy = false;
    chamber[stairX][stairY]->display = '\\';
    
}


void Floor::spawn_potions() {
    vector<string> lop = {"RH", "BA", "BD", "PH", "WA", "WD" };
    for (int i = 0; i <  10; i++) {
        cout << "spawn potion here " << i << endl;
        unsigned int indexofpotion, numofchamber, indexofcellinsidechamber;
        indexofpotion = rand() % 6;
        Potion a(lop[indexofpotion],is_drow);
        listofpotion.push_back(a);
        numofchamber = rand() % 5;
        indexofcellinsidechamber = rand() % chamber[numofchamber].size();
        if (chamber[numofchamber][indexofcellinsidechamber]->display == '.') {
            chamber[numofchamber][indexofcellinsidechamber]->set_item(&a);
        }else {
            indexofcellinsidechamber = rand() % chamber[numofchamber].size();
        }
        cout << "potion address" << numofchamber  << " " << indexofcellinsidechamber << endl;
    }
}


void Floor::spawn_enemies() {
    for (int i = 0;i < 20;i++) {
        cout << "spawn enemy here" << i << endl;
        int x = rand() % 18;
        if (x >= 0 && x <= 3) {
            Character* addr = new Human();
            listofenmey.push_back(addr);
            int posx,posy;
            posx = rand() % height;
            posy = rand() % width;
            if (grid[posx][posy].display == '.') {
                grid[posx][posy].set_enemy(addr);
                grid[posx][posy].display = 'H';
            }else{
                posx = rand() % height;
                posy = rand() % width;
            }
        }else if (x == 4 || x == 5 || x == 6) {
            Character* addr = new Dwarf();
            listofenmey.push_back(addr);
            
            int posx,posy;
            posx = rand() % height;
            posy = rand() % width;
            if (grid[posx][posy].display == '.') {
                grid[posx][posy].set_enemy(addr);
                grid[posx][posy].display = 'W';
            }else{
                posx = rand() % height;
                posy = rand() % width;
            }
        }else if (x >= 7 && x <= 11) {
            Character* addr = new Halfling();
            listofenmey.push_back(addr);
            int posx,posy;
            posx = rand() % height;
            posy = rand() % width;
            if (grid[posx][posy].display == '.') {
                grid[posx][posy].set_enemy(addr);
                grid[posx][posy].display = 'L';
            }else{
                posx = rand() % height;
                posy = rand() % width;
            }
        }else if (x == 12 || x == 13) {
            Character* addr = new Elf();
            listofenmey.push_back(addr);
            int posx,posy;
            posx = rand() % height;
            posy = rand() % width;
            if (grid[posx][posy].display == '.') {
                grid[posx][posy].set_enemy(addr);
                grid[posx][posy].display = 'E';
            }else{
                posx = rand() % height;
                posy = rand() % width;
            }
        }else if (x == 14 || x == 15) {
            Character* addr = new Orcs();
            listofenmey.push_back(addr);
            int posx,posy;
            posx = rand() % height;
            posy = rand() % width;
            if (grid[posx][posy].display == '.') {
                grid[posx][posy].set_enemy(addr);
                grid[posx][posy].display = 'O';
            }else{
                posx = rand() % height;
                posy = rand() % width;
            }
        }else if (x == 16 || x == 17) {
            Character* addr = new Merchant();
            listofenmey.push_back(addr);
            int posx,posy;
            posx = rand() % height;
            posy = rand() % width;
            if (grid[posx][posy].display == '.') {
                grid[posx][posy].set_enemy(addr);
                grid[posx][posy].display = 'M';
            }else{
                posx = rand() % height;
                posy = rand() % width;
            }
        }
    }
}

void Floor::spawn_gold() {
    for (int i = 0; i < 10; i++) {
        cout << "spawn gold here" << i << endl;
        int x = rand() % 8;
        if (x >= 0 && x <= 4) {
            Treasure a("normal",nullptr);
            listoftreasure.push_back(a);
            int posx,posy;
            posx = rand() % height;
            posy = rand() % width;
            if (grid[posx][posy].display == '.') {
                grid[posx][posy].set_item(&a);
                grid[posx][posy].display = 'G';
            }
        }else if (x == 5) {
            Character* d = new Dragon();
            listofenmey.push_back(d);
            Treasure a("dragon hoard",d);
            listoftreasure.push_back(a);
            int posx,posy;
            posx = rand() % height;
            posy = rand() % width;
            while (grid[posx][posy].display != '.') {
                posx = rand() % height;
                posy = rand() % width;
            }
            grid[posx][posy].set_item(&a);
            grid[posx][posy].display = 'G';
            unsigned int dpos = rand() % grid[posx][posy].numberofneighbours;
            while (grid[posx][posy].getNeighbour(dpos)->display != '.')
            {
                dpos =rand() % grid[posx][posy].numberofneighbours;
            }
            grid[posx][posy].getNeighbour(dpos)->set_enemy(d);
            grid[posx][posy].getNeighbour(dpos)->display = 'D';
            
        }else if (x == 6 || x == 7) {
            Treasure a("small hoard",nullptr);
            listoftreasure.push_back(a);
            int posx,posy;
            posx = rand() % height;
            posy = rand() % width;
            if (grid[posx][posy].display == '.') {
                grid[posx][posy].set_item(&a);
                grid[posx][posy].display = 'G';
            }
        }
        
    }
}

void Floor::move_enemy() {
    vector<Character*> temp;
    for (int i = 0;i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j].display == 'H' || grid[i][j].display == 'W' || grid[i][j].display == 'E' ||
                grid[i][j].display == 'O' || grid[i][j].display == 'M' || grid[i][j].display == 'L') {
                bool is_moved = false;
                for (unsigned int k = 0; k < temp.size(); k++) {
                    if (grid[i][j]._content == temp[i]) {
                        is_moved = true;
                    }
                }
                if (!is_moved) {
                // swap at the bottom side
                unsigned int pos = rand() % grid[i][j].neighbours.size();
                while (grid[i][j].neighbours[pos]->display != '.') {
                    pos = rand() % grid[i][j].neighbours.size();
                }
                Character* tempenemy = grid[i][j]._content;
                temp.push_back(tempenemy);
                swap(&(grid[i][j]), grid[i][j].neighbours[pos]);
            }
            }
        }

    }
}

void Floor::swap(Cell* one, Cell* two) {
    char swapdisplay = one->display;
    bool tempocc = one->is_occupied;
    bool tempenem = one->is_enemy;
    bool tempitem = one->is_item;
    bool tempplayer = one->is_player;
    one->display = two->display;
    one->is_player = two->is_player;
    one->is_item = two->is_item;
    one->is_enemy = two->is_enemy;
    one->is_occupied = two->is_occupied;
    two->display = swapdisplay;
    two->is_occupied = tempocc;
    two->is_enemy = tempenem;
    two->is_item = tempitem;
    two->is_player = tempplayer;
}


string Floor::move_player(string dir){
    if (dir == "no") {
        if (grid[playerX-1][playerY].display == '.' ||
            grid[playerX-1][playerY].display == '#' ||
            grid[playerX-1][playerY].display == '+') {
            grid[playerX-1][playerY]._content = grid[playerX][playerY]._content;
            grid[playerX-1][playerY].set_player();
            grid[playerX][playerY].rmobject();
            playerX--;
            return "PC move north";
        }if (grid[playerX-1][playerY].display == '\\') {
            return "true";
        }
    }else if (dir == "so") {
        if (grid[playerX+1][playerY].display == '.' ||
            grid[playerX+1][playerY].display == '#' ||
            grid[playerX+1][playerY].display == '+') {
            grid[playerX+1][playerY]._content = grid[playerX][playerY]._content;
            grid[playerX+1][playerY].set_player();
            grid[playerX][playerY].rmobject();
            playerX++;
            return "PC move south";
        }if (grid[playerX+1][playerY].display == '\\'){
            return "true";
        }
    }else if (dir == "ea") {
        if (grid[playerX][playerY+1].display == '.' ||
            grid[playerX][playerY+1].display == '#' ||
            grid[playerX][playerY+1].display == '+') {
            swap(&(grid[playerX][playerY]),&(grid[playerX][playerY+1]));
            playerY++;
            return "PC move east";
        }if (grid[playerX][playerY+1].display == '\\'){
            return "true";
        }
    }else if (dir == "we") {
        if (grid[playerX][playerY-1].display == '.' ||
            grid[playerX][playerY-1].display == '#' ||
            grid[playerX][playerY-1].display == '+') {
            swap(&(grid[playerX][playerY]),&(grid[playerX][playerY-1]));
            playerY--;
            return "PC move west";
        }if (grid[playerX][playerY-1].display == '\\'){
            return "true";
        }
    }else if (dir == "ne") {
        if (grid[playerX-1][playerY+1].display == '.' ||
            grid[playerX-1][playerY+1].display == '#' ||
            grid[playerX-1][playerY+1].display == '+') {
            swap(&(grid[playerX][playerY]),&(grid[playerX-1][playerY+1]));
            playerY++;
            playerX--;
            return "PC move northeast";
        }if (grid[playerX-1][playerY+1].display == '\\'){
            return "true";
        }
    }else if (dir == "nw"){
        if (grid[playerX-1][playerY-1].display == '.' ||
            grid[playerX-1][playerY-1].display == '#' ||
            grid[playerX-1][playerY-1].display == '+') {
            swap(&(grid[playerX][playerY]),&(grid[playerX-1][playerY-1]));
            playerY--;
            playerX--;
            return "PC move northest";
        }if (grid[playerX-1][playerY-1].display == '\\'){
            return "true";
        }
    } else if (dir == "se") {
        if (grid[playerX+1][playerY+1].display == '.' ||
            grid[playerX+1][playerY+1].display == '#' ||
            grid[playerX+1][playerY+1].display == '+') {
            swap(&(grid[playerX][playerY]),&(grid[playerX+1][playerY+1]));
            playerY++;
            playerX++;
            return "PC move southeast";
        }if (grid[playerX+1][playerY+1].display == '\\'){
            return "true";
        }
        
    }else if (dir == "sw") {
        if (grid[playerX+1][playerY-1].display == '.' ||
            grid[playerX+1][playerY-1].display == '#' ||
            grid[playerX+1][playerY-1].display == '+') {
            swap(&(grid[playerX][playerY]),&(grid[playerX+1][playerY-1]));
            playerY--;
            playerX++;
            return "PC move southeast";
        }if (grid[playerX+1][playerY-1].display == '\\'){
            return "true";
        }
    }
    return "false";
}



void Floor::DisplayMap() {
    for(int i = 0; i < height; i ++) {
        for (int j = 0; j < width; j++) {
            cout << grid[i][j].display;
            //cout << "1";
        }
        //cout << endl;
    }
}

Floor::~Floor() {
    cout << "dtor" << endl;
    unsigned int x;
    x = listofenmey.size();
    for (int i = 0; i < x; i++) {
        delete listofenmey[i];
    }
}

Cell* Floor::newcord(string dir, int x, int y){
    Cell *c;
    if (dir == "no"){
        c = getCell(x - 1, y);
    } else if (dir == "so") {
        c= getCell(x + 1, y);
    } else if (dir == "ea") {
        c= getCell(x, y + 1);
    } else if (dir == "we") {
        c= getCell(x, y - 1);
    } else if (dir == "ne") {
        c= getCell(x - 1, y + 1);
    } else if (dir == "nw") {
        c= getCell(x - 1, y - 1);
    } else if(dir == "se") {
        c= getCell(x + 1, y + 1);
    } else if (dir == "sw"){
        c= getCell(x + 1, y - 1);
    }
    return c;
}

string Floor::usepotion(string dir){
    Cell *n = newcord(dir, playerX, playerY);
    Item *p;
    Character *player;
    if(n->display == 'P') {
        p = n->getItem();
        player = getPlayer()->getCharacter();
    } else {
        throw "that is not a potion";
    }
    string potion = p->effect(player);
    if(player->getHp() == 0){//player die by using poison
        return "player die!";
    }
    return "PC uses " + potion;
}

string Floor::attackenemy(string dir, bool is_hostile){
    Cell *c = newcord(dir, playerX, playerY);
    Character *nc;
    Character *player;
    string info;
    if(c->display == 'H'|| c->display =='W'|| c->display =='E' || c->display =='O'
       || c->display == 'M'|| c->display == 'D' || c->display =='L') {
        nc = c->getCharacter();
        player = getPlayer()->getCharacter();
    } else {
        return "That is not an enemy";
    }
    if(nc->getType() == "merchant"){
        is_hostile = true;
        info = player->attack(nc);
    } else {
        info = player->attack(nc);
    }
    if(nc->getHp() == 0){//enemy die;
        if(nc->getType() == "human"){
            Treasure gold{"human_normal", nullptr};
            c->rmobject();
            c->set_item(&gold);
        } else if(nc->getType() == "dragon"){
            int len = c->numberofneighbours;
            for(int i = 0; i < len; ++i){
                if(c->getNeighbour(i)->is_item){
                    Item *item = c->getNeighbour(i)->getItem();
                    if(!(item->is_Potion())){
                        item->setdragon(nullptr);
                    }
                }
            }
        } else if(nc->getType() == "merchant"){
            Treasure gold{"merchant_hoard", nullptr};
            c->rmobject();
            c->set_item(&gold);
        } else{
            player->addGold(nc->getGold());
            c->rmobject();
        }
    }
    return info;
}

string Floor::attackplayer(bool is_hostile){
    string info;
    Cell *player = getPlayer();
    Character *pc = player->getCharacter();
    int len = player->numberofneighbours;
    for (int i = 0; i < len; ++i){
        if(player->getNeighbour(i)->is_enemy){
            Character *nc = player->getNeighbour(i)->getCharacter();
            if(nc->getType() == "elf"){
                if(pc->getType() != "drow"){
                    info = nc->attack(pc);
                    info += nc->attack(pc);
                }
            } else if (nc->getType() == "merchant"){
                if(is_hostile){
                    info = nc->attack(pc);
                }
            } else{
                info = nc->attack(pc);
            }
        }else if(player->getNeighbour(i)->is_item){
            Item *item = player->getNeighbour(i)->getItem();
            if(!(item->is_Potion())){
                Character *nc = item->getdragon();
                if(nc->getType() == "dragon"){
                    info = nc->attack(pc);
                }
            }
        }
    }
    if(pc->getHp() == 0){
        return "player die!";
    } else {
        return info;
    }
}

