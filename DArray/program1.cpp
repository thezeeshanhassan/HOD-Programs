#include <iostream>
using namespace std;

int x = -1;

class DArray
{
private:
    int _size;
    int count;
    int *array;
    void doubleSize();

public:
    DArray();
    DArray(const DArray &);
    DArray &operator=(const DArray &) ;
    int &operator[](int) const;
    void push_back(int);
    int size() const;
};

DArray::DArray() : _size(1), count(0)
{
    array = new int[_size];
}
DArray::DArray(const DArray &obj)
{
    _size = obj._size;
    count = obj.count;
    array = new int[obj._size];
    for (int i{}; i < obj._size; i++)
    {
        array[i] = obj.array[i];
    }
}
DArray &DArray::operator=(const DArray &obj) 
{
    if (this != &obj)
    {
        _size = obj._size;
        count = obj.count;
        array = new int[obj._size];
        for (int i{}; i < obj._size; i++)
        {
            array[i] = obj.array[i];
        }
    }
    return *this;
}
int &DArray::operator[](int index) const
{
    if (index >= 0 && index < _size)
    {
        return array[index];
    }
    cout << "Index Out of Bounds" << endl;
    return x;
}

void DArray::push_back(int val)
{
    if (count >= _size)
    {
        doubleSize();
    }

    array[count] = val;
    count += 1;
}

int DArray::size() const
{
    return count;
}

ostream &operator<<(ostream &os, const DArray &arr)
{
    for (int i{}; i < arr.size(); i++)
    {
        os << arr[i] << " ";
    }
    return os;
}

DArray doSomething(DArray arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = arr[i] + 1;
    }
    return arr;
}
void DArray::doubleSize()
{
    _size *= 2;
    int *newArray = new int[_size];
    for (int i = 0; i < count; i++)
    {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}

int main()
{
    DArray arr1;
    int num;
    cin >> num;
    while (num >= 0)
    {
        arr1.push_back(num);
        cin >> num;
    }
    cout << arr1 << endl;
    DArray arr2 = arr1;
    cout << arr2 << endl;
    arr2 = doSomething(arr1);
    cout << arr2 << endl;
    return 0;
}
