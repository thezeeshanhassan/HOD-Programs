// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class DArray
{
private:
    int _size;
    int count;
    int *array = new int[_size];

public:
    DArray() : _size(1), count(0) {}
        
    DArray(const DArray &obj) {
        _size = obj._size;
        count = obj.count;
        // array = obj.array;
        for(int i{}; i < obj._size; i += 1) {
            array[i] = obj.array[i];
        }
    }
    void push_back(int val)
    {
        if (count >= _size)
        {
            cout<<"Size Full"<<endl;
            doubleSize();
        }

        array[count] = val;
        count += 1;
    }

    int size()
    {
        return count + 1;
    }
    void print(){
        for(int i{}; i < _size; i += 1) {
            cout<<array[i] << " ";
        }
        cout<<endl;
    }
    void doubleSize()
    {
        int *newArray = new int[_size];
        for(int i{}; i < size(); i += 1) {
            newArray[i] = array[i];
        }
        newArray = array;
        _size *= 2;
        array = new int[_size];
        
        for(int i{}; i < size(); i += 1) {
            array[i] = newArray[i];
        }
        
    
        delete[] newArray;
        
    }
    
    
    
};

int main() {
    // Write C++ code here
    DArray arr1{};
    int num{};
    cout << "Enter a Number ";
    cin >> num;
    while (num >= 0)
    {
        arr1.push_back(num);
        cout<<"Enter a Number ";
        cin >> num;
    }
    
    arr1.print();
    DArray arr2{arr1};
    arr2.print();
    // cout<<arr1<<endl;
    

    return 0;
}