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
//    for (int i = 0; i < height; i++) {
//        for (int j = 0; j < width; j++) {
//            if (grid[i][j].display == '.') {
//                Cell* a = &(grid[i][j]);
//                availableCell.push_back(a);
//            }
//        }
//    }
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
   // cout << temp2.size() << endl;
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
   // cout << temp3.size() << endl;
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
   // cout << temp4.size() << endl;
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
    spawn_player("Vampire");
    spawn_potions();
    spawn_gold();
    //spawn_enemies();
    

//    for (int i = 0; i < width; i++) {
//        for (int j = 0; j <  height; j++) {
//            if (i == 0) {
//                if (j == 0) {
//                    grid[i][j].addNeighbour(&(grid[i+1][j+1]));
//                    grid[i][j].addNeighbour(&(grid[i+1][j]));
//                    grid[i][j].addNeighbour(&(grid[i][j+1]));
//                }else if(j == 24) {
//                    grid[i][j].addNeighbour(&(grid[i+1][j]));
//                    grid[i][j].addNeighbour(&(grid[i+1][j-1]));
//                    grid[i][j].addNeighbour(&(grid[i][j-1]));
//                }else{
//                    grid[i][j].addNeighbour(&(grid[i][j-1]));
//                    grid[i][j].addNeighbour(&(grid[i+1][j-1]));
//                    grid[i][j].addNeighbour(&(grid[i+1][j]));
//                    grid[i][j].addNeighbour(&(grid[i][j+1]));
//                    grid[i][j].addNeighbour(&(grid[i+1][j+1]));
//                }
//            }else if (i == 79) {
//                if (j == 0) {
//                    grid[i][j].addNeighbour(&(grid[i-1][j]));
//                    grid[i][j].addNeighbour(&(grid[i-1][j+1]));
//                    grid[i][j].addNeighbour(&(grid[i][j+1]));
//                }else if(j == 24) {
//                    grid[i][j].addNeighbour(&(grid[i-1][j]));
//                    grid[i][j].addNeighbour(&(grid[i-1][j-1]));
//                    grid[i][j].addNeighbour(&(grid[i][j-1]));
//                }else{
//                    grid[i][j].addNeighbour(&(grid[i][j-1]));
//                    grid[i][j].addNeighbour(&(grid[i-1][j-1]));
//                    grid[i][j].addNeighbour(&(grid[i-1][j]));
//                    grid[i][j].addNeighbour(&(grid[i][j+1]));
//                    grid[i][j].addNeighbour(&(grid[i-1][j+1]));
//                }
//            }else{
//                grid[i][j].addNeighbour(&(grid[i-1][j-1]));
//                grid[i][j].addNeighbour(&(grid[i][j-1]));
//                grid[i][j].addNeighbour(&(grid[i+1][j-1]));
//                grid[i][j].addNeighbour(&(grid[i][j-1]));
//                grid[i][j].addNeighbour(&(grid[i][j+1]));
//                grid[i][j].addNeighbour(&(grid[i-1][j+1]));
//                grid[i][j].addNeighbour(&(grid[i][j+1]));
//                grid[i][j].addNeighbour(&(grid[i+1][j+1]));
//            }
//        }
//    }
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


Cell* Floor::getCell(int x, int y) {
    return &(grid[x][y]);
}

Cell* Floor::getPlayer() {
    return &(grid[playerX][playerY]);
}


void Floor::spawn_player(Character* pc) {
    int x, stairX;
    unsigned int y, stairY;
    x = rand() % 5;
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
    playerX = chamber[x][y]->getx();
    playerY = chamber[x][y]->gety();
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
    }
}

//
//void Floor::spawn_enemies() {
//    for (int i = 0;i < 20;i++) {
//        int x = rand() % 18;
//        if (x >= 0 && x <= 3) {
//            Human a=Human();
//            listofenmey.push_back(a);
//            Character* addr = &a;
//            int posx,posy;
//            posx = rand() % height;
//            posy = rand() % width;
//            if (grid[posx][posy].display == '.') {
//                grid[posx][posy].set_enemy(addr);
//                grid[posx][posy].display = 'H';
//            }else{
//                posx = rand() % height;
//                posy = rand() % width;
//            }
//        }
//    }
//}
//        }else if (x == 4 || x == 5 || x == 6) {
//            Dwarf a;
//            listofenmey.push_back(a);
//            Character* addr = &a;
//            int posx,posy;
//            posx = rand() % height;
//            posy = rand() % width;
//            if (grid[posx][posy].display == '.') {
//                grid[posx][posy].set_enemy(addr);
//                grid[posx][posy].display = 'W';
//            }else{
//                posx = rand() % height;
//                posy = rand() % width;
//            }
//        }else if (x >= 7 && x <= 11) {
//            Halfling a;
//            listofenmey.push_back(a);
//            Character* addr = &a;
//            int posx,posy;
//            posx = rand() % height;
//            posy = rand() % width;
//            if (grid[posx][posy].display == '.') {
//                grid[posx][posy].set_enemy(addr);
//                grid[posx][posy].display = 'L';
//            }else{
//                posx = rand() % height;
//                posy = rand() % width;
//            }
//        }else if (x == 12 || x == 13) {
//            Elf a;
//            listofenmey.push_back(a);
//            Character* addr = &a;
//            int posx,posy;
//            posx = rand() % height;
//            posy = rand() % width;
//            if (grid[posx][posy].display == '.') {
//                grid[posx][posy].set_enemy(addr);
//                grid[posx][posy].display = 'E';
//            }else{
//                posx = rand() % height;
//                posy = rand() % width;
//            }
//        }else if (x == 14 || x == 15) {
//            Orcs a;
//            listofenmey.push_back(a);
//            Character* addr = &a;
//            int posx,posy;
//            posx = rand() % height;
//            posy = rand() % width;
//            if (grid[posx][posy].display == '.') {
//                grid[posx][posy].set_enemy(addr);
//                grid[posx][posy].display = 'O';
//            }else{
//                posx = rand() % height;
//                posy = rand() % width;
//            }
//        }else if (x == 16 || x == 17) {
//            Merchant a;
//            listofenmey.push_back(a);
//            Character* addr = &a;
//            int posx,posy;
//            posx = rand() % height;
//            posy = rand() % width;
//            if (grid[posx][posy].display == '.') {
//                grid[posx][posy].set_enemy(addr);
//                grid[posx][posy].display = 'M';
//            }else{
//                posx = rand() % height;
//                posy = rand() % width;
//            }
//        }
//    }
//}

void Floor::spawn_gold() {
    for (int i = 0; i < 10; i++) {
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
            Dragon d;
            Treasure a("dragon hoard",&d);
            listoftreasure.push_back(a);
            int posx,posy;
            posx = rand() % height;
            posy = rand() % width;
            if (grid[posx][posy].display == '.') {
                grid[posx][posy].set_item(&a);
                grid[posx][posy].display = 'G';
            }
//            int dpos = rand() % grid[posx][posy].numberofneighbours;
//            while (1) {
//                if (grid[posx][posy].getNeighbour(dpos)->display == '.') {
//                    grid[posx][posy].getNeighbour(dpos)->set_enemy(&d);
//                    grid[posx][posy].getNeighbour(dpos)->display = 'D';
//                }else{
//                    dpos =rand() % grid[posx][posy].numberofneighbours;
//                }
//            }
            
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
    
}


void Floor::move_player(string dir){
    if (dir == "no") {
        if (grid[playerX][playerY].display == '.' ||
            grid[playerX][playerY].display == '#' ||
            grid[playerX][playerY].display == '+') {
            playerx
        }
    }

    
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

