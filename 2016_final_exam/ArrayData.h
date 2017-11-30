#include <iostream>
using namespace std;

template <typename T>
class ArrayData
{
protected:
    T * data;
    int capacity;
    int top;
public:
    ArrayData();
    virtual ~ArrayData() {
        delete[] this->data;
    }
    ArrayData(const int & capacity) : capacity(capacity), top(0) {
        this->data = new T[capacity];
    }
    ArrayData(const ArrayData& arr) {
        delete[] this->data;
        this->data = new T[arr.capacty];
        for (int i = 0; i < arr.capacity; ++i) {
            this->addElement(arr[i]);
        }
    }
    void addElement(const T & dat) {
        if (!full()) {
            this->data[top++] = dat;
        } else { cout << "full." << endl; }
    }
    bool full() {
        return this->top == this->capacity;
    }
    int getCapacity();
    int getUsed();
    void emptyArray();
    void showData();
    void showData() const;
    ostream & operator<<(ostream & os) {
        for (int i = 0; i < this->top; ++i) {
            os << this->data[i] << endl;
        }
        return os;
    }
    
    friend ostream& operator<<(ostream& out, ArrayData<T> & arr) {
        return arr << out;
    }
    T & operator[](int index) {
        return this->arr[index];
    }
    ArrayData<T> & operator=(ArrayData<T> a) {
        if (this->capacity != a.capacity) {
            delete[] data;
            data = new double[a.capacity];
            this->capacity = a.capacity;
        }
        this->top = a.top;
        
        for (int i = 0; i < this->top; i++)
        {
            data[i] = a.data[i];
        }
        return *this;
    }
};

template <typename T>
ArrayData<T>::ArrayData()
: capacity(5), top(0)
{
    this->data = new T[capacity];
}

