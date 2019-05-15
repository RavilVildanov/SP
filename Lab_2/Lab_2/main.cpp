//
//  main.cpp
//  Lab_2
//
//  Created by Равиль Вильданов on 13/05/2019.
//  Copyright © 2019 Vildanov. All rights reserved.
//

#include <iostream>

using namespace std;

class Fraction {

    int chis;
    int znam;
    
public:
    
    Fraction() { chis = 0; znam = 0; }
    Fraction(int c, int z) { chis = c; znam = z; }
    Fraction(const Fraction &ob);  // конструктор копии
    void Enter();
    void Show ();
    Fraction operator = (Fraction);
    Fraction operator + (Fraction);
    Fraction operator - (Fraction);
    Fraction operator * (Fraction);
    Fraction operator / (Fraction);
    bool operator != (Fraction);
    bool operator > (Fraction);
    bool operator < (Fraction);
    bool operator == (Fraction);
    int NOD (Fraction);   // наибольший общий делитель
    int NOD_int(int, int); // НОД для использования в других функциях
    int NOK_int(int, int); // НОК для функций
    int NOK (Fraction); // наименьшие общие кратное
    friend std::istream& operator >> (std::istream&, Fraction);
    friend std::ostream& operator << (std::ostream&, Fraction);
};

std::istream& operator >>(std::istream& infile, Fraction f2)
{
    infile >> f2.chis >> f2.znam;
    return infile;
    
}

std::ostream& operator << (std::ostream& onfile, Fraction f2)
{
    onfile << f2.chis << "/" << f2.znam << std::endl;
    return onfile;
}

bool Fraction::operator !=(Fraction f2) // перегрузка не равно
{
    int z = NOK_int(this->znam, f2.znam); // находим НОК
    this->chis = this->chis * ( z / this->znam); // приводим числитель
    f2.chis = f2.chis * ( z / f2.znam);  // приводим знаменатель
    if(this->chis != f2.chis) // если знаменатели не равны
        return 1;
    else
        return 0;
    
}

bool Fraction::operator == (Fraction f2)
{
    if(this->znam == f2.znam && this->chis == f2.chis) // если знаменатели и числители равны, то и дроби равны
        return 1;
    else
    {
        int z = NOK_int(this->znam, f2.znam); //находим НОК
        this->chis = this->chis * ( z / this->znam);
        f2.chis = f2.chis * ( z / f2.znam);
        if(this->chis == f2.chis) // если числители равны
            return 1;
        else
            return 0;
    }
    
    return 0;
}

bool Fraction::operator<(Fraction f2)
{
    
    if(this->znam != f2.znam && this->chis != f2.chis) // если разные знаменатели и числители
    {
        int z = NOK_int(this->znam, f2.znam); // НОК
        this->chis = this->chis * ( z / this->znam); // приводим к общему знаменателю
        f2.chis = f2.chis * ( z / f2.znam);
        if(this->chis < f2.chis)
            return 1;
        else
            return 0;
    }
    
    if(this->znam == f2.znam) // если у дробей одинаковые знаменатели
    {
        if(this->chis < f2.chis)
            return 1;
        else
            return 0;
    }
    if (this->chis == f2.chis) // если одинаковые числители
    {
        if(this->znam < f2.znam)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

bool Fraction::operator>(Fraction f2)
{
    
    if(this->znam != f2.znam && this->chis != f2.chis)
    {
        int z = NOK_int(this->znam, f2.znam);
        this->chis = this->chis * ( z / this->znam);
        f2.znam = f2.znam * ( z / f2.znam);
        if(this->chis > f2.chis)
            return 1;
        else
            return 0;
    }
    
    if(this->znam == f2.znam)
    {
        if(this->chis > f2.chis)
            return 1;
        else
            return 0;
    }
    if (this->chis == f2.chis)
    {
        if(this->znam < f2.znam)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}


Fraction Fraction ::operator*(Fraction f2) // умножение числитель на числитель, знаменатель
{                                          // на знаменатель
    this->chis = this->chis * f2.chis;
    this->znam = this->znam * f2.znam;
    return *this;
    
}

Fraction Fraction ::operator / (Fraction f2) // деление
{
    this->chis = this->chis * f2.znam; // числитель первой на знаменатель второй
    this->znam = this->znam * f2.chis; // знаменатель первой на числитель второй
    return *this;
}

Fraction Fraction::operator+(Fraction f2)
{
    int z = NOK_int(this->znam, f2.znam); // НОК
    this->chis = this->chis*(z / this->znam);
    f2.chis = f2.chis * ( z / f2.znam);
    this->chis = this->chis + f2.chis;
    this->znam = z;
    return *this;
}

Fraction Fraction::operator - (Fraction f2)
{
    int z = NOK_int(this->znam, f2.znam);
    this->chis = this->chis*(z / this->znam);
    f2.chis = f2.chis * ( z / f2.znam);
    this->chis = this->chis - f2.chis;
    this->znam = z;
    return *this;
}

Fraction Fraction:: operator = (Fraction f2)
{
    this->chis = f2.chis;
    this->znam = f2.znam;
    return *this;
}

int Fraction:: NOD_int(int x, int y) // хороший алгоритм по нахождению НОД
{
    while(x && y)
        if(x >= y)
            x %= y;
        else
            y %= x;
    return x | y;
}

int Fraction:: NOD (Fraction f2)
{
    while(this->znam && f2.znam)
        if( this->znam >= f2.znam)
            this->znam %= f2.znam;
        else
            f2.znam %= this->znam;
    return this->znam | f2.znam;
}

int Fraction::NOK(Fraction f2)
{
    return this->znam / NOD_int(this->znam, f2.znam)*f2.znam;
    
}

int Fraction::NOK_int(int x, int y)
{
    return x / NOD_int(x, y)*y;
}

Fraction::Fraction(const Fraction &ob) // конструктор копии
{
    this->chis = ob.chis;
    this->znam = ob.znam;
}

void Fraction::Enter() // ввод данных
{
    std::cout << "Введите числитель дроби " << std::endl;
    std::cin >> chis;
    std::cout << "Введите знаменатель " << std::endl;
    std::cin >> znam;
}

void Fraction::Show() // вывод
{
    std::cout << chis <<  "/" << znam << " ";
}

void change(Fraction *array, int count) {
    for (int i = 0; i < count; i++)
        if (i % 2 == 0 && i < count + 1)
            array[i] = array[i] + array[i+1];
}

int main(int argc, const char * argv[]) {
    
    Fraction fractions [4] = {Fraction(1,3), Fraction(1,3), Fraction(1,5), Fraction(2,5)};
    
    change(fractions, 4);
    
    for (int i = 0; i < 4; i++)
        fractions[i].Show();
    
    return 0;
}
