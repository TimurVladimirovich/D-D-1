#ifndef HEADER_ROOM_H
#define HEADER_ROOM_H

#include "everything.cpp"


class Room {
protected:
    int x1,y1,x2,y2;
    int R;
    char map_in_room[height][width];
    vector<BoundaryCoordinates> boundary_coordinates;
    vector<Room> Old_Rooms;
public:
    Room(int x, int y,int Width, int Height,int R,vector<Room> _Rooms);

    void FindBorderCoordinates();

    char getmap(int i, int j){ return map_in_room[i][j];}
    BoundaryCoordinates getboundary_coordinates(int i){return boundary_coordinates[i];}
    vector<Room>getRooms(){return Old_Rooms;}
    int getx1(){return x1;}
    int getx2(){return x2;}
    int gety1(){return y1;}
    int gety2(){return y2;}

};

#endif //HEADER_ROOM_H