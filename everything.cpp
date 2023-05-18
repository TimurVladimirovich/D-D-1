#include <iostream>
#include <string>
#include <random>
#include <functional>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;

const int width = 110;      //Ширина пещеры
const int height = 40;      //Высота пещеры
int difficulty = 8;         //Сложность уровня (=> насыщенность)
float size_coefficient=0.3; //Коэф Максимального размера комнаты
int count_rooms = 8;        //Количество комнат
int count_trails = 35;      //Количество троп

char char_wall = char(178); // ▓
char char_border = char(176); // ░
char char_blank = char(32); //
char char_trail = char(254); // ■
char char_traps = char(33); // !
char char_monsters = char(206); // ╬
char char_chests = char(127); //⌂
char char_smth = char(63);   //?
char char_input_1 = char(40); //
char char_input_2 = char(41); //
char char_exit_1 = char(91); //
char char_exit_2 = char(93); //


/*
    178 начальная стена
    176 граница
    32 пробел
    254 тропа
*/


struct BoundaryCoordinates{
    BoundaryCoordinates(int x,int y){
        this->x=x;
        this->y=y;
    }
    int x;
    int y;
    bool operator ==(const BoundaryCoordinates &boundary_coordinates);
};

bool BoundaryCoordinates::operator ==(const BoundaryCoordinates &boundary_coordinates) {
    if (boundary_coordinates.x == boundary_coordinates.x and boundary_coordinates.y == boundary_coordinates.y) {
        return true;
    } else {
        return false;
    }
}

char random(std::vector<char> &v, int ( &a )[4])
{
    for(int i = 0; i < 4; i++){
        //cout<<a[i]<<' ';
        for(int j = 0; j < a[i]; j++) {
            v.push_back(v[i]);
        }
    }
    //cout<<endl;
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist_r(0, v.size());
    int r = dist_r(rng);
    return v[r];
}