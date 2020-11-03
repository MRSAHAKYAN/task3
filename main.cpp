#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void countingSort(int *array, int size);
void print(int *array, int size);

int main(int argc, char *argv[])
{
    int size = 0;
    cin >> size;
    if (size > 100000 || size < 1)
    {
        cout << "FAIL";
        return 0;
    }
     int *array = new int[size];


    for (int i = 0; i < size; i++)
    {
        cin >> array[i];

        if (array[i] > 30 || array[i] < -30)
        {
            delete[] array;
            cout << "FAIL";
            return 0;
        }
    }

    countingSort(array, size);
    print(array, size);


    delete[] array;
    return 0;
}


void countingSort(int *array, int size)
{
    int max = array[0];
    int min = array[0];
    for (int i = 0; i < size; ++i)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    int *sortArray = new int[(max - min) + 1];

    for (int i = 0; i < (max - min) + 1; ++i)
    {
        sortArray[i] = 0;
    }

    for (int i = 0; i < size; ++i)
    {
        sortArray[array[i] - min] = sortArray[array[i] - min] + 1;
    }

    int i = 0;

    for (int j = min; j < max + 1; j++)
    {
        while (sortArray[j - min] != 0)
        {
            array[i] = j;
            sortArray[j - min]--;
            i++;
        }
    }
    delete[] sortArray;
}

void print(int *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << array[i];
        if (i != (size - 1))
        {
            cout << endl;
        }
    }
}