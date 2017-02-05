//#include <ctype.h>
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <Windows.h>

template <class T, size_t Size>
class Bufer
{
    T values [Size];
    size_t head;
    size_t tail;
    size_t realSize;

    public:
    Bufer ();

    void put (T value);
    T get ();

    void dump ();
};

template <class T, size_t Size>
Bufer <T, Size> :: Bufer ():
    values {},
    head (0),
    tail (0),
    realSize (0)
{}

template <class T, size_t Size>
void Bufer <T, Size> :: put (T value)
{
    assert (realSize < Size);
    values [tail] = value;
    tail++;
    tail = tail % Size;

    realSize++;
}

template <class T, size_t Size>
T Bufer <T, Size> :: get ()
{
    assert (realSize != 0);

    T value = values [head];
    head++;
    head = head % Size;
    realSize --;
}

template <class T, size_t Size>
void Bufer <T, Size> :: dump ()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (size_t i = 0; i < Size; i++)
    {
        SetConsoleTextAttribute(hConsole, 7);

        if (i == head) SetConsoleTextAttribute(hConsole, 1);
        if (i == tail) SetConsoleTextAttribute(hConsole, 4);
        if (i == tail && i == head) SetConsoleTextAttribute(hConsole, 2);
        std :: cout << values [i] << ' ';
    }
    SetConsoleTextAttribute(hConsole, 7);

    std :: cout << "\n" << "head = " << head << "\n" << "tail = " << tail << "\n" << "rSize = " << realSize << "\n" ;
}


