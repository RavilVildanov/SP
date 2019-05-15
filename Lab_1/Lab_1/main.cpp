//
//  main.cpp
//  Lab_1
//
//  Created by Равиль Вильданов on 12/05/2019.
//  Copyright © 2019 Vildanov. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

// MARK: - Class Definition

class Apartment {
    
private:
    
    string addres;
    int level;
    int countOfRooms;
    float square;
    
public:
    
    Apartment() {
        cout << "Адрес: "; cin >> addres;
        cout << "Этаж: ";  cin >> level;
        cout << "Кол-во комнат: "; cin >> countOfRooms;
        cout << "Площадь: "; cin >> square;
    }
    
    Apartment(string _addres, int _level, int _countOfRooms, float _square) {
        addres = _addres;
        level = _level;
        countOfRooms = _countOfRooms;
        square = _square;
    }
    
    void show() {
        cout << "=========================================" << endl;
        cout << "Адрес: " << addres << endl;
        cout << "Этаж: " << level << endl;
        cout << "Кол-во комнат: " << countOfRooms << endl;
        cout << "Площадь: " << square << endl;
        cout << "=========================================" << endl << endl;
    }
    
    int getCountOfRooms() {
        return countOfRooms;
    }
    
    int getLevel() {
        return level;
    }
    
    bool isSquareGreaterThan(float s) {
        return square > s;
    }
};

// MARK: -

int main(int argc, const char * argv[]) {
    
    Apartment apartments [5] = {
        Apartment("Московская 6",   7,  3, 72),
        Apartment("Кировская 10",   3,  1, 41),
        Apartment("Толстого 15",    1,  2, 56),
        Apartment("Ленина 12",      6,  3, 100),
        Apartment("Кремлевская 32", 15, 4, 150)
    };
    
    float s = 0;
    int n = 0; int min = 0; int max = 0;
    
    
    cout << "----------------------------------------------------------" << endl;
    cout << "Задание 1: Вывести список квартир с заданым кол-вом комнат" << endl << endl;
    
    cout << "Введите кол-во комнат: "; cin >> n;
    
    cout << "Список квартик с кол-вом комнат равным " << n << endl;
    for (int i = 0; i < 5; i++)
        if (apartments[i].getCountOfRooms() == n)
            apartments[i].show();
    
    
    cout << "\n\n\n----------------------------------------------------------" << endl;
    cout << "Задание 2: Вывести список квартир,имеющих заданное число комнат и расположен- ных на этаже, который находится в определенном промежутке" << endl << endl;
    
    cout << "Введите кол-во комнат: "; cin >> n;
    cout << "Введите мин  этаж: "; cin >> min;
    cout << "Введите макс этаж: "; cin >> max;
    
    cout << endl << "Список: " << endl;
    
    for (int i = 0; i < 5; i++)
        if (apartments[i].getCountOfRooms() == n && apartments[i].getLevel() >= min && apartments[i].getLevel() <= max)
            apartments[i].show();
    
    
    cout << "\n\n\n----------------------------------------------------------" << endl;
    cout << "Задание 3: Вывести список квартир,имеющих площадь, превосходящую заданную" << endl << endl;
    
    cout << "Введите площадь: "; cin >> s;
    
    for (int i = 0; i < 5; i++)
        if (apartments[i].isSquareGreaterThan(s))
            apartments[i].show();
    
    return 0;
}
