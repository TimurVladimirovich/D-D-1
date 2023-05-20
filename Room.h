#ifndef HEADER_ROOM_H
#define HEADER_ROOM_H

#include "Chars.h"
#include <array>


class Room {
protected:
    int x1, y1, x2, y2;
    array<array<char, 200>, 600> map_in_room;
public:
    Room(Chars C, int x, int y, int Width, int Height);

    char getpoint(int i, int j) { return map_in_room[i][j]; }
    int getx1() { return x1; }
    int getx2() { return x2; }
    int gety1() { return y1; }
    int gety2() { return y2; }
};

#endif //HEADER_ROOM_H