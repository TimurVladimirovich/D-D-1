#include "Leaf.h"

// Функция рандома из списка длинной 4 и вероятность выпадения каждого элемента
char Random(vector<char> &v, int ( &a )[4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < a[i]; j++) {
            v.push_back(v[i]);
        }
    }
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist_r(0, v.size());
    int r = dist_r(rng);
    return v[r];
}


Leaf::Leaf(Chars C, const int Width, int Height, int Difficulty, float Size_coefficient, int Count_rooms,
           int Count_trails) {
    this->C = C;
    this->_width = Width;
    this->_height = Height;
    this->_difficulty = Difficulty;
    this->_size_coefficient = Size_coefficient;
    this->_count_rooms = Count_rooms;
    this->_count_trails = Count_trails;


    //Заполняем массив символами стены
    for (int i = 0; i < _height; i++) {
        for (int j = 0; j < _width; j++) {
            this->_map[i][j] = C.char_wall;
        }
    }

    //Рандомное кол-во вещей от 1 + сложность до сложности *3
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(1 + _difficulty, _difficulty * 3);
    this->_traps = dist(rng);
    this->_monsters = dist(rng);
    this->_chests = dist(rng);

    //Рандомное кол-во smth(?) от 0 до сложности/3
    uniform_int_distribution<mt19937::result_type> dist_smth(0, _difficulty / 3);
    this->_smth = dist_smth(rng);

    //Создание комнат
    for (int k = 0; k < _count_rooms; k++) {
        cout << "Creating a new room " << endl;

        // Максимальные координаты новой комнаты (левый верхний угол)
        int xmax = int((this->_width) * 0.75);
        int ymax = int((this->_height) * 0.75);

        // Рандомные координаты новой комнаты
        uniform_int_distribution<mt19937::result_type> dist_x(4, xmax);
        uniform_int_distribution<mt19937::result_type> dist_y(4, ymax);
        int x = dist_x(rng);
        int y = dist_y(rng);

        //Максимальный размер новой комнаты
        int Width_max = 2 + (this->_width - x) * _size_coefficient;
        int Hight_max = 2 + (this->_height - y) * _size_coefficient;

        // Рандомные размер новой комнаты
        uniform_int_distribution<mt19937::result_type> dist_size_x(4, Width_max + 1);
        uniform_int_distribution<mt19937::result_type> dist_size_y(4, Hight_max + 1);
        int Width_Room = dist_size_x(rng);
        int Height_Room = dist_size_y(rng);


        //Создание комнаты
        this->_Rooms.push_back(Room(C, _width, _height, x, y, Width_Room, Height_Room));

        //Изменение карты
        ChangeMap(x, y, Height_Room, Width_Room, k);

        //Вывод
        /*
        cout<<"Creating a new room "<<endl;
        cout << "xmax = " << xmax << " ymax = " << ymax << endl;
        cout << "x = " << x << " y = " << y << endl;
        cout << "Width_max = " << Width_max << " Hight_max = " << Hight_max << endl;
        cout << "Width = " << Width << " Height = " << Height << endl;
        for (int i = 0; i < _height; i++) {
            cout << "  ";
            for (int j = 0; j < _width; j++) {
                cout << _map[i][j];
            }
            cout << endl;
        }
         */
    }
}

void Leaf::ChangeMap(int x, int y, int Height, int Width, int k) {
    for (int i = y; i < y + Height; i++) {
        for (int j = x; j < x + Width; j++) {
            this->_map[i][j] = _Rooms[k].getmap(i, j);
        }
    }
}

void Leaf::ChangePoint(int x, int y, int c, int k) {
    this->_map[y][x] = c;
}


void Leaf::MakeBorder(char c) {
    for (int i = 2; i < _height - 2; i++) {
        for (int j = 2; j < _width - 2; j++) {
            if (_map[i][j] == C.char_wall) {
                if (_map[i + 1][j] == C.char_blank or _map[i - 1][j] == C.char_blank or
                    _map[i][j + 1] == C.char_blank or
                    _map[i][j - 1] == C.char_blank or _map[i + 1][j + 1] == C.char_blank or
                    _map[i - 1][j + 1] == C.char_blank or
                    _map[i + 1][j - 1] == C.char_blank or _map[i - 1][j - 1] == C.char_blank) {
                    _map[i][j] = c;
                }
            }
        }
    }
}


void Leaf::MakeTrails() {
    random_device dev;
    mt19937 rng(dev());
    for (int k = 0; k < _count_trails; k++) {
        int x = 0, y = 0;
        while (_map[y][x] != C.char_border) {
            uniform_int_distribution<mt19937::result_type> dist_x(3, _width - 3);
            uniform_int_distribution<mt19937::result_type> dist_y(3, _height - 3);
            x = dist_x(rng);
            y = dist_y(rng);
        }
        ChangePoint(x, y, C.char_trail, k);

        // Первый шаг
        int count = 0;    //Номер шага
        char forbidden_step;    //Нельзя идти в обратном направлении
        while (count != 1 and count > -30) {
            vector<char> direction = {'U', 'R', 'D', 'L'};
            int a[4] = {y, _width - x, _height - y, x};
            char move_of_direction = Random(direction, a);   //Случайное направление движения

            if (move_of_direction == 'U' and _map[y - 1][x] != C.char_blank and
                _map[y - 1][x] != C.char_border) {       //Вверх и смотрим чтобы не пошел внутрь комнаты
                y--;
                count = 2;
                forbidden_step = 'D';

            }
            if (move_of_direction == 'R' and _map[y][x + 1] != C.char_blank and
                _map[y][x + 1] != C.char_border) {       //Вправо и смотрим чтобы не пошел внутрь комнаты
                x++;
                count = 2;
                forbidden_step = 'L';
            }
            if (move_of_direction == 'D' and _map[y + 1][x] != C.char_blank and
                _map[y + 1][x] != C.char_border) {        //Вниз и смотрим чтобы не пошел внутрь комнаты
                y++;
                count = 2;
                forbidden_step = 'U';
            }
            if (move_of_direction == 'L' and _map[y][x - 1] != C.char_blank and
                _map[y][x - 1] != C.char_border) {        //Влево и смотрим чтобы не пошел внутрь комнаты
                x--;
                count = 2;
                forbidden_step = 'R';
            }
            count--;
            ChangePoint(x, y, C.char_trail, k);
        }


        //Идём до следующей комнаты
        while (_map[y][x] != C.char_border or _map[y][x] != C.char_blank) {

            //Вывод
            /*
            for (int i = 0; i < _height; i++) {
                cout << "  ";
                for (int j = 0; j < _width; j++) {
                    cout << _map[i][j];
                }
                cout << endl;
            }
            */

            vector<char> direction = {'U', 'R', 'D', 'L'};
            int a[4] = {y * _width / 100, (_width - x) * _height / 100,
                        (_height - y) * _width / 100, x * _height / 100};
            char move_of_direction = Random(direction, a);

            //Движение
            if (move_of_direction == 'U' and move_of_direction != forbidden_step and y > 3) {                //Вверх
                y--;
                forbidden_step = 'D';
            }
            if (move_of_direction == 'R' and move_of_direction != forbidden_step and _width - x > 4) {       //Вправо
                x++;
                forbidden_step = 'L';
            }
            if (move_of_direction == 'D' and move_of_direction != forbidden_step and _height - y > 3) {       //Вниз
                y++;
                forbidden_step = 'U';
            }
            if (move_of_direction == 'L' and move_of_direction != forbidden_step and x > 4) {                 //Влево
                x--;
                forbidden_step = 'R';
            }

            //Проверка на то, не дошла ли тропа до комнаты
            if (_map[y][x] == C.char_border or _map[y][x] == C.char_blank) {
                ChangePoint(x, y, C.char_trail, k);
                break;
            }
            ChangePoint(x, y, C.char_trail, k);
        }

        //Красим тропу в пробелы
        for (int i = 0; i < _height; i++) {
            for (int j = 0; j < _width; j++) {
                if (_map[i][j] == C.char_trail) { _map[i][j] = C.char_blank; }
            }
        }
    }
}

void Leaf::ChangeChar(char old_char, char new_char) {
    for (int i = 1; i < _height - 1; i++) {
        for (int j = 1; j < _width - 1; j++) {
            if (_map[i][j] == old_char) {
                _map[i][j] = new_char;
            }
        }
    }
}

void Leaf::ExpandVoids(char old_char, char new_char) {
    for (int i = 1; i < _height - 1; i++) {
        for (int j = 1; j < _width - 1; j++) {
            if (_map[i][j] == old_char and ((_map[i + 1][j] == new_char and _map[i - 1][j] == new_char) or
                                            (_map[i][j + 1] == new_char and _map[i][j - 1] == new_char))) {
                _map[i][j] = new_char;
            }
        }
    }
}


void Leaf::SetObjects() {
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist_x(3, _width - 3);
    uniform_int_distribution<mt19937::result_type> dist_y(3, _height - 3);

    //Ловушки
    int x = 0, y = 0;
    for (int t = 0; t < _traps; t++) {
        while (_map[y][x] != C.char_blank) {
            x = dist_x(rng);
            y = dist_y(rng);
            if (_map[y][x] == C.char_blank) {
                _map[y][x] = C.char_traps;
                break;
            }
        }
    }

    //Монстры
    x = 0, y = 0;
    for (int t = 0; t < _monsters; t++) {
        x = dist_x(rng);
        y = dist_y(rng);
        while (_map[y][x] != C.char_monsters) {
            x = dist_x(rng);
            y = dist_y(rng);
            if (_map[y][x] == C.char_blank and _map[y + 1][x] == C.char_blank and _map[y - 1][x] == C.char_blank and
                _map[y][x + 1] == C.char_blank and _map[y][x - 1] == C.char_blank and
                _map[y + 1][x + 1] == C.char_blank and
                _map[y - 1][x + 1] == C.char_blank and _map[y + 1][x - 1] == C.char_blank and
                _map[y - 1][x - 1] == C.char_blank) {
                _map[y][x] = C.char_monsters;
            }
        }
    }

    //Сундуки
    x = 0, y = 0;
    for (int t = 0; t < _chests; t++) {
        while (_map[y][x] != C.char_blank) {
            x = dist_x(rng);
            y = dist_y(rng);
            if (_map[y][x] == C.char_blank) {
                _map[y][x] = C.char_chests;
                break;
            }
        }
    }

    //SMTH
    x = 0, y = 0;
    for (int t = 0; t < _smth; t++) {
        while (_map[y][x] != C.char_blank) {
            x = dist_x(rng);
            y = dist_y(rng);
            if (_map[y][x] == C.char_blank) {
                _map[y][x] = C.char_smth;
                break;
            }
        }
    }
}


void Leaf::SetInputExit() {
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist_x(3, _width - 3);
    uniform_int_distribution<mt19937::result_type> dist_y(3, _height - 3);
    int x_in = 0, y_in = 0;
    int x_ex = 0, y_ex = 0;

    //Устанавливаем вход
    while (true) {
        x_in = dist_x(rng);
        y_in = dist_y(rng);
        if (_map[y_in][x_in] == C.char_border and _map[y_in][x_in + 1] == C.char_border) {
            _map[y_in][x_in] = C.char_input_1;
            _map[y_in][x_in + 1] = C.char_input_2;
            break;
        }
        if (_map[y_in][x_in - 1] == C.char_border and _map[y_in][x_in] == C.char_border) {
            _map[y_in][x_in - 1] = C.char_input_1;
            _map[y_in][x_in] = C.char_input_2;
            break;
        }
    }

    //Устанавливаем выход
    while (true) {
        x_ex = dist_x(rng);
        y_ex = dist_y(rng);
        //Смотрим чтобы вход и выход не были слишком близко друг к другу
        while (sqrt(pow(x_in - x_ex, 2) + pow(y_in - y_ex, 2)) < sqrt(_height * _width) / 3) {
            x_ex = dist_x(rng);
            y_ex = dist_y(rng);
        }
        if (_map[y_ex][x_ex] == C.char_border and _map[y_ex][x_ex + 1] == C.char_border) {
            _map[y_ex][x_ex] = C.char_exit_1;
            _map[y_ex][x_ex + 1] = C.char_exit_2;
            break;
        }
        if (_map[y_ex][x_ex - 1] == C.char_border and _map[y_ex][x_ex] == C.char_border) {
            _map[y_ex][x_ex - 1] = C.char_exit_1;
            _map[y_ex][x_ex] = C.char_exit_2;
            break;
        }
    }
}