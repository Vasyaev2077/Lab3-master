#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int pInt[13]);

void quickSort(int i, int n);

void sort3(int mas[], int sz);

const int findNext(int *pInt, int i, int i1, const bool odd);

//Сортировка из примера
int main() {
    int mas[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int imin, imax;
    int n = sizeof(mas) / sizeof(int);
    int i;
    imin = i = 0;
    imax = i = 0;
    system("cls");
    for (i = 0; i < n; i++)
        cout << mas[i] << ' ';
    cout << endl;
    for (i = 0; i < n - 1; i++)
    {
        imin=i;
        for(int j=i+1; j<n; j++)
            if(mas[j] < mas[imin]) imin = j;
        int t=mas[i];
        mas[i]=mas[imin];
        mas[imin]=t;
    }
    for(i=0; i<n; i++)
        cout << mas[i] << ' ';
    cout << endl;
    bubbleSort(mas);   // Сортировка пузырьком
    quickSort(*mas, n);  // Быстрая сортировка
    sort3(mas, n);      // Сортировка по возрастанию четных и по убыванию нечетных значений
    return 0;
}

// Быстрая сортировка
void quickSort(int mas[], int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    int mid = mas[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(mas[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(mas[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //"Левый кусок"
        quickSort(mas, j + 1);
    }
    if (i < size) {
        //"Правый кусок"
        quickSort(&mas[i], size - i);
    }
}

// Сортировка пузырьком
void bubbleSort(int mas[13]) {
    int n = sizeof(mas) / sizeof(int);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (mas[j] > mas[j + 1]) {
                int b = mas[j]; // создали дополнительную переменную
                mas[j] = mas[j + 1]; // меняем местами
                mas[j + 1] = b; // значения элементов
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << mas[i] << ' '; // выводим элементы массива
    cout << endl;
}

// Сортировка по возрастанию четных и по убыванию нечетных значений
void sort3(int mas[], int sz)
{
    srand(123343);

    int* array = mas;

    // Сортировка пузырьком

    bool sorted = false;
    for (int k = 0; k < sz - 1 && !sorted; ++k)
    {
        sorted = true;
        for (int j = 0; j < sz - k - 1; ++j)
        {
            const bool odd = array[j] % 2;
            const int next = findNext(array, sz - k, j + 1, odd);

            if (next > 0)
            {
                if ((array[j] < array[next]) == odd)
                {
                    swap(array[j], array[next]);
                    sorted = false;
                }
            }
        }
    }

    cout << endl << "Отсортированный массив:" << endl;
    for (int i = 0; i < sz; ++i)
    {
        cout << array[i] << ' ';
    }
    delete[] array;
}

const int findNext(int * array, int sz, int startpos, const bool odd) {
    for (int i = startpos; i < sz; ++i)
    {
        if (odd == static_cast<bool>(array[i] % 2)) return i;
    }
    return -1;
}
// Заданиe 4
// N - количество элементов массива
// a,b - диапазон индексов
void partSort(int arr[], int N, int a, int b)
{
    // Переменные для хранения начала и конца диапазона индексов
    int l = min(a, b);
    int r = max(a, b);

    // Временный массив
    int temp[r - l + 1];
    int j = 0;
    for (int i = l; i <= r; i++) {
        temp[j] = arr[i];
        j++;
    }

    // Сортируем временный массив
    sort(temp, temp + r - l + 1);

    // Изменение исходного массива с помощью элементов временного массива
    j = 0;
    for (int i = l; i <= r; i++) {
        arr[i] = temp[j];
        j++;
    }

    // Выводим измененный массив
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " " ;
    }
}
// Заданиe 5
// N - количество элементов массива
// a,b - диапазон индексов
void partSort2(int arr[], int N, int a, int b)
{
    // Переменные для хранения начала и конца диапазона индексов
    int l = min(a, b);
    int r = max(a, b);

    // Временный массив
    int temp[r - l + 1];
    int j = 0;
    for (int i = r; i >= l; i++) {
        temp[j] = arr[i];
        j++;
    }

    // Сортируем временный массив
    sort(temp, temp + r - l + 1);

    // Изменение исходного массива с помощью элементов временного массива
    j = 0;
    for (int i = l; i <= r; i++) {
        arr[i] = temp[j];
        j++;
    }

    // Выводим измененный массив
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " " ;
    }
}