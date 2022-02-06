/*Завдання 1. Написати такі функції для роботи з динамічним масивом:
■ Функція розподілу динамічної пам’яті;
■ Функція ініціалізації динамічного масиву;
■ Функція друку динамічного масиву;
■ Функція видалення динамічного масиву;
■ Функція додавання елемента в кінець масиву;
■ Функція вставки елемента за вказаним індексом;
■ Функція видалення елемента за вказаним індексом.*/

#include <iostream>
using namespace std;

void inputArr(int*& arr, int& size) {       //Функція ініціалізації динамічного масиву;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter [" << i + 1 << "] element of massive = ";
        cin >> arr[i];
    }
}
void printArr(int *arr, int size) {        // Функція друку динамічного масиву
    for (int i = 0; i < size; i++)
    {
        cout << "Arr [" << i + 1 << "] = " << arr[i] << endl;
    }
}
void deleteArr(int*& arr, int &size)        //Функція видалення динамічного масиву;
{
    delete[] arr;
}
void plusArrinEnd(int*& arr, int& size) {       //Функція додавання елемента в кінець масиву;
    int f = 0;   //змінна для елемента який хочемо добавити у масив
    cout << "Enter new last element of massive = ";
    cin >> f;       //просимо кор ввести елемент
    int size1 = size + 1;   //збільшуємо розмір
    int* arr1 = new int[size1]; //створюємо новий масив
    for (int i = 0; i < size1; i++)
    {
        arr1[i] = arr[i];//переписуємо наш масив
        if (i == size ) {   //в кінцеь додаємо новий елемент
            arr1[i] = f;
        }
    }
    arr = arr1;
    size=size1;
}
void indexPlus(int*&arr,int&size){ //Функція вставки елемента за вказаним індексом;
    int index = 0;      //наш індекс
    int f = 0;          //змінна для елемента який хочемо добавити у масив
    cout << "Enter position = ";
    cin >> index;       //просимо кор ввести індекс
    cout << "Enter new element of massive = ";
    cin >> f;           //просимо кор ввести елемент
    int size1 = size + 1;   //збільшеємо розмір 
    int* arr1 = new int[size1];     //створюємо новий масив
    for (int i = 0; i < size1; i++) 
    {
        if(i<index-1){      //переписуємо елементи до індекса
        arr1[i] = arr[i];
        }
        if (i == index-1) {     //вписуємо наш новий елемент
            arr1[i] = f;
        }
        if (i > index -1) {     //переписуємо усі інші елементи 
            arr1[i] = arr[i-1];
        }
    }
    arr = arr1;
    size = size1;
}
void indexMinus(int*& arr, int& size) { //Функція видалення елемента за вказаним індексом;
    int index = 0;
    cout << "Enter position = ";    //Просимо кор ввести індекс елемента який видалити
    cin >> index;

    int size1 = size -1;    //зменшуємо розмір 
    int* arr1 = new int[size1]; //створюємо новий масив з новим розміром 

    for (int i = 0; i < size1; i++) //перебираємо елементи по новому розміру
    {
        if (i < index - 1) {        //Переписуємо елементи до індекса 
            arr1[i] = arr[i];
        }
        if (i >= index - 1) {       //Переписуємо елементи після індексу
            arr1[i] = arr[i + 1];
        }
    }
    arr = arr1;       
    size = size1;
}

int main()
{ 
    int size = 100;
    cout << "Enter size=";
    cin >> size;
    int* arr = new int[size];       //розподіл динамічної пам’яті;

    inputArr(arr, size);    //Викликаємо ф-цію ініціалізації динамічного масиву
    plusArrinEnd(arr, size);//Викликаємо ф-цію додавання елемента в кінець масиву;
    printArr(arr, size);    //Викликаємо ф-цію друку динамічного масиву;
    indexPlus(arr, size);   //Викликаємо ф-цію вставки елемента за вказаним індексом;
    printArr(arr, size);    //Викликаємо ф-цію друку динамічного масиву;
    indexMinus(arr, size);  //Викликаємо ф-цію видалення елемента за вказаним індексом
    printArr(arr, size);    //Викликаємо ф-цію друку динамічного масиву
    deleteArr(arr, size);   //Викликаємо ф-цію видалення динамічного масиву;
}


