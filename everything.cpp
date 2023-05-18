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
int difficulty = 3;         //Сложность уровня (=> насыщенность)
float size_coefficient=0.3; //Коэффициент Максимального размера комнаты
int count_rooms = 8;        //Количество комнат
int count_trails = 35;      //Количество троп

char char_wall = char(178); // ▓
char char_border = char(176); // ░
char char_blank = char(32); //
char char_trail = char(254); // ■
char char_traps = char(139); // Л
char char_monsters = char(140); // М
char char_chests = char(145); // С
char char_smth = char(63);   // ?
char char_input_1 = char(40); // (
char char_input_2 = char(41); // )
char char_exit_1 = char(91); // [
char char_exit_2 = char(93); // ]



// Функция рандома из списка длинной 4 и вероятность выпадения каждого элемента
char random(std::vector<char> &v, int ( &a )[4])
{
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < a[i]; j++) {
            v.push_back(v[i]);
        }
    }
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist_r(0, v.size());
    int r = dist_r(rng);
    return v[r];
}