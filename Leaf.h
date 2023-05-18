#ifndef HEADER_LEAF_H
#define HEADER_LEAF_H

#include "Room.h"



using namespace std;



class Leaf {
protected:
    int _width, _height;
    int _difficulty;
    char _map[height][width];
    int _traps, _monsters, _chests, _smth, _count_rooms, _count_trails;
    vector<Room> _Rooms;
public:
    //Leaf(int Width, int Height, int difficulty, char ( &a )[height][width]);
    Leaf(int Width, int Height, int Difficulty);

    void MakeTrails();
    void MakeBorder(char c);
    void ChangeMap(int x, int y, int Height, int Width, int k);   //Добавляет к карте комнату k
    void ChangePoint(int x, int y, int c, int k);      //Изменяет выбранную точку k-ой комнаты на символ c
    void ChangeChar(char old_char, char new_char);      //Заменяет один символ на другой
    void ExpandVoids(char old_char, char new_char);     //Удаляет единичные границы
    void SetObjects();      //Ставит ловушки, монстров, сундуки, smth
    void SetInputExit();    //Ставит вход и выход из подземелья

    int getTraps(){ return _traps;}
    int getMonsters(){ return _monsters;}
    int getChests(){ return _chests;}
    int getCountRooms(){ return _count_rooms;}
    char getMap(int i,int j){ return _map[i][j];}
};


#endif //HEADER_LEAF_H
