#ifndef HEADER_CHARS_H
#define HEADER_CHARS_H

#include <iostream>
#include <vector>
using namespace std;


class Chars {
public:
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
    char char_person = char(1);  // ☺
    Chars(){};

};
#endif //HEADER_CHARS_H
