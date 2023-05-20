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

bool isNumeric(std::string const &str)
{
    return !str.empty() && str.find_first_not_of("0123456789.") == std::string::npos;
}

int main() {

    //Считывание данных из файла
    string String;
    int width ;             //Ширина пещеры
    int height;             //Высота пещеры
    int difficulty;         //Сложность уровня (=> насыщенность)
    float size_coefficient; //Коэффициент Максимального размера комнаты
    int count_rooms;        //Количество комнат
    int count_trails;       //Количество троп

    ifstream ReadOn;
    ReadOn.open("C://Users//boldi//Documents//D-D//D-D_parametrs.txt");

    //Поиск width
    ReadOn >> String;
    while (isNumeric(String) == 0){
        ReadOn.clear();
        ReadOn >> String;
    }
    width = stoi(String);
    ReadOn.clear();
    cout << "width = " << width << endl;

    //Поиск height
    ReadOn >> String;
    while (isNumeric(String) == 0){
        ReadOn.clear();
        ReadOn >> String;
    }
    height = stoi(String);
    ReadOn.clear();
    cout << "height = " << height << endl;

    //Поиск difficulty
    ReadOn >> String;
    while (isNumeric(String) == 0){
        ReadOn.clear();
        ReadOn >> String;
    }
    difficulty = stoi(String);
    ReadOn.clear();
    cout << "difficulty = " << difficulty << endl;

    //Поиск size_coefficient
    ReadOn >> String;
    while (isNumeric(String) == 0){
        ReadOn.clear();
        ReadOn >> String;
    }
    size_coefficient = stof(String);
    ReadOn.clear();
    cout << "size_coefficient = " << size_coefficient << endl;

    //Поиск count_rooms
    ReadOn >> String;
    while (isNumeric(String) == 0){
        //cout << String <<' ';
        ReadOn.clear();
        ReadOn >> String;
    }
    count_rooms = stoi(String);
    ReadOn.clear();
    cout << "count_rooms = " << count_rooms << endl;

    //Поиск count_trails
    ReadOn >> String;
    while (isNumeric(String) == 0){
        ReadOn.clear();
        ReadOn >> String;
    }
    count_trails = stoi(String);
    ReadOn.clear();
    cout << "count_trails = " << count_trails << endl;



    //Создание Листа,
    Chars C;
    Leaf Leaf_0(C, width, height, difficulty, size_coefficient, count_rooms, count_trails);
    cout << endl<< "The dungeon has been created. " << endl;
    cout << Leaf_0.getTraps() << " Traps  " << endl << Leaf_0.getMonsters() << " Monsters  " << endl
         << Leaf_0.getChests() << " Chests  " << endl << Leaf_0.getSMTH() << " SMTH? " << endl
         << Leaf_0.getCountRooms() << " Rooms" << endl;
    Leaf_0.MakeBorder(C.char_border);                              // Делаем границу
    Leaf_0.MakeTrails();                                              // Делаем тропы
    Leaf_0.MakeBorder(C.char_border);                              // Делаем границу
    Leaf_0.ExpandVoids(C.char_border, C.char_blank);  // Удаляем артефакты (единичные границы)



    Leaf_0.SetObjects();                                            // Устанавливаем объекты
    Leaf_0.SetInputExit();                                          // Устанавливаем вход/выход

    //Вывод с границей
    Leaf_0.getMap();


    Leaf_0.ChangeChar(C.char_border, C.char_wall);      // Заменяем границу на стену
    //Leaf_0.ChangeChar(char_border, char_blank);                   // Заменяем границу на символ


    //Конечный вывод
    Leaf_0.getMap();


    //Запись в файл
    string name = "Leaf_difficulty(" + to_string(difficulty) + ") _rooms(" + to_string(count_rooms) + ") _trails("
                  + to_string(count_trails) + ") _sizecoef(" + to_string(size_coefficient) + ").txt";
    ofstream out;          // поток для записи
    out.open(name);      // открываем файл для записи
    if (out.is_open()) {
        for (int i = 0; i < height; i++) {
            out << "  ";
            for (int j = 0; j < width; j++) {
                out << Leaf_0.getPoint(i, j);
            }
            out << endl;
        }
    }
    out.close();
    cout << "File has been written" << endl;


    //Движение
    char Мovement;
    cout <<endl<<endl<<"Now enter the direction please: "<<endl<<endl;
    while (true){
        cin>>Мovement;
        Leaf_0.Move(Мovement);
        //Проверка на движение
        if(Leaf_0.getTrueOrFalse() == 1) {
            Leaf_0.getMap();
        }

    }

    return 0;
}