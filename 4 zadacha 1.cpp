﻿#include <iostream>  
#include <cstring> 
#include <string> 
#include <fstream>  
#include <stdlib.h> 
class Address {

private:
    std::string city;
    std::string street;
    int nomberHome = 0;
    int nomberFlat = 0;
    std::string Fulladres;
public:
    // Конструктор 
    Address(std::string ci, std::string str, int nomHo, int nomFl)
    {
        city = ci;
        street = str;
        nomberHome = nomHo;
        nomberFlat = nomFl;
    }
    //Создание строки адреса для вывода 
    std::string createFullAdr()
    {
        Fulladres = city + "," + street + "," + std::to_string(nomberHome) + "," + std::to_string(nomberFlat);
        //std::cout << Fulladres; 
        return Fulladres;
    }
    //Функция создания текстового динамического массива 
    std::string* createArrAdr(const int size)
    {
        std::string* ArrAdr = new std::string[size]{};

        return ArrAdr;
    }
    //Функция удаления динамического массива 
    void deleteArrAdr(std::string* ArrAdr, const int size)
    {
        delete[] ArrAdr;
    }
    // Функция записи массива в файл 
    void printArrOut(std::string* arrayForOut, const int size)
    {
        std::ofstream Out("out.txt");

        if (Out.is_open())
        {
            std::cout << "Файл out.txt успешно открыт." << std::endl;
        }
        else
        {
            std::cout << "Ошибка открытия файла" << std::endl;

        }

        Out << "Всего адресов: " << size << std::endl << std::endl;

        Out << "Адреса:" << std::endl;

        for (int i = size - 1; i >= 0; i--)
        {
            Out << arrayForOut[i] << std::endl;
        }
        Out.close();
    };

};
int main()
{

    setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    std::string ci = {};
    std::string str = {};
    int nomHo = 0;
    int nomFl = 0;
    int size = 0;
    Address adress(ci, str, nomHo, nomFl);
    // Проверяем файл на открытие 
    std::ifstream in("in.txt");
    if (!in)
    {
        std::cout << "Файл не открылся" << std::endl;
    }
    else
    {
        std::cout << "Файл открыт" << std::endl;
    }
    in >> size; // Считали количество адресов 

    // Cоздаем динамический массив для объектов класса Adress 

    std::string* arrayForOut = adress.createArrAdr(size);

    for (int i = 0; i < size; i++) //Считываем адрес 
    {
        in >> ci >> str >> nomHo >> nomFl;
        // std::cout << ci << str << nomHo << nomFl << std::endl; 
        Address adress(ci, str, nomHo, nomFl);
        arrayForOut[i] = adress.createFullAdr();


    };
    in.close();

    adress.printArrOut(arrayForOut, size);
    adress.deleteArrAdr(arrayForOut, size);

}