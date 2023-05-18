//#include "everything.cpp"

#include "Leaf.h"
#include "Leaf.cpp"
#include "Room.h"
#include "Room.cpp"


int main() {

    Leaf Leaf_0(width, height, difficulty);

    cout << Leaf_0.getTraps() << ' ' << Leaf_0.getMonsters() << ' ' << Leaf_0.getCountRooms() << endl;
    Leaf_0.MakeBorder(char_border);
    cout << "Maked Border " << endl << endl;
    Leaf_0.MakeTrails();
    Leaf_0.MakeBorder(char_border);
    cout << "setting traps";

    //Вывод
    for (int i = 0; i < height; i++) {
        cout << "  ";
        for (int j = 0; j < width; j++) {
            cout << Leaf_0.getMap(i, j);
        }
        cout << endl;
    }
    cout << endl << endl << endl;


    Leaf_0.ExpandVoids(char_border, char_blank);

    //Вывод
    for (int i = 0; i < height; i++) {
        cout << "  ";
        for (int j = 0; j < width; j++) {
            cout << Leaf_0.getMap(i, j);
        }
        cout << endl;
    }
    cout << endl << endl << endl;

    Leaf_0.SetObjects();
    Leaf_0.SetInputExit();



    //Вывод с границей
    for (int i = 0; i < height; i++) {
        cout << "  ";
        for (int j = 0; j < width; j++) {
            cout << Leaf_0.getMap(i, j);
        }
        cout << endl;
    }
    cout << endl << endl << endl;


    Leaf_0.ChangeChar(char_border, char_wall);

    //Вывод
    for (int i = 0; i < height; i++) {
        cout << "  ";
        for (int j = 0; j < width; j++) {
            cout << Leaf_0.getMap(i, j);
        }
        cout << endl;
    }


    string name = "Leaf_difficulty(" + to_string(difficulty) + ") _rooms(" + to_string(count_rooms) + ") _trails("
                  + to_string(count_trails) + ") _sizecoef(" + to_string(size_coefficient)+").txt";

    //Запись в файл
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


    //Игра с символами
    /*
    out.open("Chars.txt");      // открываем файл для записи
    if (out.is_open())
    {
        for(int i=0;i<255;i++){
            out<<i<<' '<< char(i)<<endl;
        }
    }
    out.close();


    //3 ♥
    //40 41 ()
    //33 !
    //79 O
    //91 92 []
    //206 ╬
    //127 ⌂

    for(int i=0;i<255;i++){
        cout<<i<<' '<< char(i)<<endl;
    }
    */
    return 0;
}
