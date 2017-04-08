#include <iostream>
using namespace std;

class SortedDynamicArray {
public:
    int * arr;
    int size;
    int top;
    SortedDynamicArray();
    int binarySearch(int l, int r, int tgt);
    bool deleteData(int tgt);
    int insertData(int dat);
    void print();
};

SortedDynamicArray::SortedDynamicArray() : size(4), top(4)
{
    this->arr = new int[4];
    for (int i = 0; i < 4; ++i)
    {
        this->arr[i] = i * 2;
    }
}

int SortedDynamicArray::binarySearch(int l, int r, int tgt)
{
    // 있으면 있는 위치를 리턴하고, 없으면 들어가야 할 자리를 리턴한다.
    if (l >= r)
    {
        return this->arr[l] > tgt ? l - 1 : l;
    }
    
    int m = (l + r) / 2;
    if (this->arr[m] == tgt)
        return m;
    else if (this->arr[m] > tgt)
        return binarySearch(l, m - 1, tgt);
    else
        return binarySearch(m + 1, r, tgt);
}

bool SortedDynamicArray::deleteData(int tgt)
{
    int pos = this->binarySearch(0, this->top - 1, tgt);
    if (this->arr[pos] == tgt)
    {
        for (int i = pos; i < this->top - 1; ++i)
            this->arr[i] = this->arr[i + 1];
        this->arr[--this->top] = 0;
        return true;
    }
    return false;
}

int SortedDynamicArray::insertData(int dat)
{
    if (this->top >= this->size)
    { // 자리가 없다면 자리를 만든다.
        int * newarr =  new int[this->size * 2];
        for (int i = 0; i < this->size; ++i)
            newarr[i] = this->arr[i];
        delete[] this->arr;
        this->arr = newarr;
        this->size *= 2;
    }
    int pos = this->binarySearch(0, this->top - 1, dat); // 중복된 데이터도 가능.
    for (int i = ++this->top - 1; i > pos + 1; --i)
    {
        this->arr[i] = this->arr[i - 1];
    }
    return this->arr[pos + 1] = dat;
}

void SortedDynamicArray::print()
{
    for (int i = 0; i < this->top; ++i)
        cout << this->arr[i] << endl;
}

int main()
{
    SortedDynamicArray sda;
    
    sda.insertData(5);
    sda.deleteData(4);
    sda.insertData(-1);
    sda.insertData(100);
    sda.deleteData(-1);
    sda.deleteData(100);
    sda.insertData(7);
    sda.print();
    
    return 0;
}
