#include "Room.h"


Room::Room(int x, int y, int Width, int Height, int R, vector<Room> _Rooms) {
    this->x1 = x;
    this->y1 = y;
    this->x2 = x1 + Width;
    this->y2 = y1 + Height;
    this->R = R;
    this->Old_Rooms = _Rooms;
    //cout << "x1 = " << x1 << " x2 = " << x2 << " y1 = " << y1 << " y2 = " << y2 << ' ' << Old_Rooms.size() << endl;

    //Закраска комнаты
    for (int i = y1; i < y2; i++) {
        for (int j = x1; j < x2; j++) {
            this->map_in_room[i][j] = char_blank;
        }
    }
}