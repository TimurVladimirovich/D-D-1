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


#include "Leaf.h"
#include "Room.h"
#include "Chars.h"

int main() {

    //Типа ввели
    int width = 110;      //Ширина пещеры
    int height = 40;      //Высота пещеры
    int difficulty = 3;         //Сложность уровня (=> насыщенность)
    float size_coefficient=0.3; //Коэффициент Максимального размера комнаты
    int count_rooms = 5;        //Количество комнат
    int count_trails = 20;      //Количество троп


    Chars C;
    Leaf Leaf_0(C, width, height, difficulty, size_coefficient, count_rooms, count_trails);
    cout << "The dungeon has been created. " << endl;
    cout << Leaf_0.getTraps() << " Traps  " << endl << Leaf_0.getMonsters() << " Monsters  " << endl
         << Leaf_0.getChests() << " Chests  " << endl << Leaf_0.getSMTH() << " SMTH? " << endl
         << Leaf_0.getCountRooms() << " Rooms" << endl;
    Leaf_0.MakeBorder(C.char_border);                              // Делаем границу
    Leaf_0.MakeTrails();                                              // Делаем тропы
    cout<<'q';
    Leaf_0.MakeBorder(C.char_border);                              // Делаем границу
    cout<<'q';
    Leaf_0.ExpandVoids(C.char_border, C.char_blank);  // Удаляем артефакты (единичные границы)

    //Вывод без всего
    /*
    for (int i = 0; i < height; i++) {
        cout << "  ";
        for (int j = 0; j < width; j++) {
            cout << Leaf_0.getMap(i, j);
        }
        cout << endl;
    }
    cout << endl << endl << endl;
     */

    Leaf_0.SetObjects();                                            // Устанавливаем объекты
    Leaf_0.SetInputExit();                                          // Устанавливаем вход/выход


    //Вывод с границей
    for (int i = 0; i < height; i++) {
        cout << "  ";
        for (int j = 0; j < width; j++) {
            cout << Leaf_0.getMap(i, j);
        }
        cout << endl;
    }
    cout << endl << endl << endl;


    Leaf_0.ChangeChar(C.char_border, C.char_wall);      // Заменяем границу на стену
    //Leaf_0.ChangeChar(char_border, char_blank);                   // Заменяем границу на символ

    //Вывод со всем
    for (int i = 0; i < height; i++) {
        cout << "  ";
        for (int j = 0; j < width; j++) {
            cout << Leaf_0.getMap(i, j);
        }
        cout << endl;
    }



    //Запись в файл
    string name = "Leaf_difficulty(" + to_string(difficulty) + ") _rooms(" + to_string(count_rooms) + ") _trails("
                  + to_string(count_trails) + ") _sizecoef(" + to_string(size_coefficient) + ").txt";
    ofstream out;          // поток для записи
    out.open(name);      // открываем файл для записи
    if (out.is_open()) {
        for (int i = 0; i < height; i++) {
            out << "  ";
            for (int j = 0; j < width; j++) {
                out << Leaf_0.getMap(i, j);
            }
            out << endl;
        }
    }
    out.close();
    cout << "File has been written" << endl;
    return 0;
}