// TA.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Node.h"
#include "onesidedList.h"



int main()
{
    
    onesidedList<int> list;

    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);

    for (int i = 0; i < list.Size; i++)
    {
        std::cout << list.getByIndex(i) << " ";
    }
    printf("\n");

    list.push_front(1);
    list.push_back(9);

    for (int i = 0; i < list.Size; i++)
    {
        std::cout << list.getByIndex(i) << " ";
    }
    printf("\n");

    list.insert(5, 4);

    for (int i = 0; i < list.Size; i++)
    {
        std::cout << list.getByIndex(i) << " ";
    }
    printf("\n");

    list.pop_back();
    list.pop_front();
    list.removeAt(3);

    for (int i = 0; i < list.Size; i++)
    {
        std::cout << list.getByIndex(i) << " ";
    }
    printf("\n");
}
