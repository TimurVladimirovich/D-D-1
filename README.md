# Dungeon Generator for D&D (C++)

Не очень сложный код, который генерирует случайную карту с ловушками Л, монстрами М, сундуками С, чем-то предельно невразумительным и таниснтвенным (?), входом () и выходом [] из подземелья.
В файле everything.cpp можно редактировать размер карты (width и height), сложность уровня (difficulty), которая влияет на количество предметов, коэффициент максимального размера одной комнаты (size_coefficient), количество комнат (count_rooms) и количество троп (count_trails). Комбинируя эти параметры можно получить самые разные результаты. Пример:

difficulty = 4, size_coefficient = 0.1, count_rooms = 15, count_trails = 30
![4 0 1 15 30](https://github.com/Klapeyrof/D-D/assets/113589355/edfc2eab-ced8-451e-9b15-f71d8512b540)

difficulty = 4, size_coefficient = 0.6, count_rooms = 5, count_trails = 10
![4 0 6 5 10](https://github.com/Klapeyrof/D-D/assets/113589355/076269b3-c5d5-44c0-b557-c38482dd2183)
