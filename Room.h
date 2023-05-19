#ifndef HEADER_ROOM_H
#define HEADER_ROOM_H

#include "Chars.h"


class Room {
protected:
    int x1, y1, x2, y2;
    char map_in_room[40][110];
    vector<Room> Old_Rooms;
public:
    Room(Chars C, int Width_Leaf, int Height_Leaf, int x, int y, int Width, int Height, vector<Room> _Rooms);

    char getmap(int i, int j) { return map_in_room[i][j]; }
    vector<Room> getRooms() { return Old_Rooms; }
    int getx1() { return x1; }
    int getx2() { return x2; }
    int gety1() { return y1; }
    int gety2() { return y2; }
};

#endif //HEADER_ROOM_H