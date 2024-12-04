/*Exercici pràctica micro examen
1. Write a class to store an array that has the array itself, information on current size and capacity, and a constructor.
2. Create a function that inverts the order of elements in the array: the first will be the last, the last will be the first.
3. Use the function in the main loop, and print the array before and after the inversion*/

#include <iostream>
using namespace std;

class DynamicArray 
{
private:
    int* array;
    int size;
    int capacity;

    void resize(int new_capacity) 
    {
        int* new_array = new int[new_capacity];

        for (int i = 0; i < size; ++i) 
        {
            new_array[i] = array[i];
        }

        delete[] array;
        array = new_array;
        capacity = new_capacity;
    }

public:
    DynamicArray(int initial_capacity = 10) 
    {
        capacity = initial_capacity;
        size = 0;
        array = new int[capacity];
    }

    ~DynamicArray() 
    {
        delete[] array;
    }

    void append(int value) 
    {
        if (size == capacity) 
        {
            resize(capacity * 2);
        }
        array[size] = value;
        ++size;
    }

    void invert() 
    {
        int left = 0;
        int right = size - 1;
        while (left < right) 
        {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;

            ++left;
            --right;
        }
    }

    void print() const 
    {
        for (int i = 0; i < size; ++i) 
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    int getSize() const 
    {
        return size;
    }

    int getCapacity() const 
    {
        return capacity;
    }
};

int main() 
{
    DynamicArray myArray;

    myArray.append(1);
    myArray.append(2);
    myArray.append(3);
    myArray.append(4);
    myArray.append(5);

    cout << "Array before inversion: ";
    myArray.print();

    myArray.invert();
    cout << "Array after inversion: ";
    myArray.print();
}
