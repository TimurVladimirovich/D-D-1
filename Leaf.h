#ifndef HEADER_LEAF_H
#define HEADER_LEAF_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <array>
using namespace std;

#include "Room.h"
#include "Chars.h"


class Leaf {
protected:
    Chars C;
    int _width, _height;
    int _difficulty;
    float _size_coefficient;
    int _traps, _monsters, _chests, _smth, _count_rooms, _count_trails;
    array<array<char, 200>, 600> _map;
    vector<Room> _Rooms;
    int person_coord_x;
    int person_coord_y;
    int Move_or_not_to_move = -1;

public:
    Leaf(Chars C, int Width, int Height, int Difficulty, float Size_coefficient, int Count_rooms,
         int Count_trails);

    void MakeTrails();
    void MakeBorder(char c);
    void ChangeMap(int x, int y, int Height, int Width, int k);   //Добавляет к карте комнату k
    void ChangePoint(int x, int y, int c);      //Изменяет выбранную точку k-ой комнаты на символ c
    void ChangeChar(char old_char, char new_char);      //Заменяет один символ на другой
    void ExpandVoids(char old_char, char new_char);     //Удаляет единичные границы
    void SetObjects();      //Ставит ловушки, монстров, сундуки, smth
    void SetInputExit();    //Ставит вход и выход из подземелья
    void Move(char user_movement);//Движение

    void getMap();
    int getTraps(){ return _traps;}
    int getMonsters(){ return _monsters;}
    int getChests(){ return _chests;}
    int getSMTH(){return _smth;}
    int getCountRooms(){ return _count_rooms;}
    char getPoint(int i,int j){ return _map[i][j];}
    int getTrueOrFalse(){return Move_or_not_to_move;}
};

#endif //HEADER_LEAF_H