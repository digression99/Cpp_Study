// 20171108
// operator overloading
//
//

#include <iostream>
using namespace std;

class Time {
private:
    int hr;
    int min;
public:
    Time(int h = 0, int m = 0) : hr(h), min(m) {}
    void addMin(int m) {
        this->min += m;
        this->hr += this->min / 60;
        this->min %= 60;
    }
    void addHr(int h) {
        this->hr += h;
    }
    void reset(int h, int m) {
        this->hr = h;
        this->min = m;
    }
    Time sum(const Time & t) const {
        // const function : can call only other const functions.
        
        return Time();
    }
    void show() const {
    }
    //Time
    operator int() {
        return this->hr * 60 + this->min;
    }
    friend Time operator*(double mul, Time & t) {
        int totalMin = t.hr * mul * 60 + t.min * mul;
        return Time(totalMin / 60, totalMin % 60);
    }
    
    Time operator*(double mul) const {
        long totalMin = this->hr * mul * 60 + this->min * mul;
        return Time(int(totalMin) / 60, totalMin % 60);
    }
    Time operator+(const Time & t) {
        //this->add
        this->addHr(t.hr);
        this->addMin(t.min);
        return *this;
    }
    Time operator+(int m) {
        this->addMin(m);
        return *this;
    }
    Time operator+(double time) {
        this->addHr(int(time));
        int min = (time - int(time)) * 10 * 6;
        this->addMin(min);
        return *this;
    }
    ostream & operator<<(ostream & os) {
        return os << "hr : " << this->hr << ", min : " << this->min << endl;
    }
    friend ostream & operator<<(ostream & os, Time & t) {
        return t << os;
    }
//    friend Time operator Time()(int t) {
//    }
//    friend operator int()(int n) {
//    }
};

class Test {
private:
    friend ostream & operator<<(ostream & os, Test & t) {
        return t << os;
    }
    
public:
    int num;
    string str;
    Test(int n = 1, string s = "123") : num(n), str(s) {
        cout << "constructor" << endl;
    }
    Test(const Test & t) : num(t.num), str(t.str) {
        cout << "copy constructor" << endl;
    }
    Test operator+(Test & t) {
        return Test(this->num + t.num, this->str + t.str);
    }
    Test & operator=(Test & t) {
        cout << "operator equal" << endl;
        this->num = t.num;
        this->str = t.str;
        return *this;
    }
    int test() {
        return 10;
    }

    ostream & operator<<(ostream & os) {
        return os << this->num << " " << this->str << endl;
    }
};

class LinkedList {
private:
    
    class Node {
    public:
        Node * next;
        int data;
        Node(int d = 0) : data(d) {}
    };
    
    friend class Node;
    Node * head;
    Node * tail;
public:
    LinkedList() {
        this->head = new Node(0);
        this->tail = new Node(0);
        this->head->next = this->tail;
        this->tail->next = this->tail;
    }
    
    void push_front(int dat) {
        Node * temp = new Node(dat);
        temp->next = this->head->next;
        this->head->next = temp;
    }
    
    bool deleteNode(Node * n) {
        Node * cur = this->head;
        
        while (cur != this->tail && cur->next != n) {
            cur = cur->next;
        }
        if (cur == tail) return false;
        
        cur->next = n->next;
        delete n;
        
        return true;
    }
    
    int pop_front() {
        if (this->head->next != this->tail) {
            int ret = this->head->next->data;
            if (this->deleteNode(this->head->next)) return ret;
            else return -1;
        } else {
            return -1;
        }
    }
    ostream & operator<<(ostream & os) {
        Node * cur = this->head->next;
        
        while (cur != this->tail) {
            os << cur->data << endl;
            cur = cur->next;
        }
        return os;
    }
    friend ostream & operator<<(ostream & os, LinkedList & list) {
        return list << os;
    }
    
    LinkedList & operator+=(LinkedList & list) {
        Node * cur = list.head;
        
        while (cur != list.tail) {
            this->push_front(cur->data);
            cur = cur->next;
        }
        return *this;
    }
    bool clear() {
        if (this->head->next == this->tail) return false;
        
        Node * cur = this->head->next;
        Node * next = cur->next;
        while (cur != this->tail) {
            this->deleteNode(cur);
            cur = next;
            next = cur->next;
        }
        return true;
    }
    
    LinkedList & operator=(LinkedList & list) {
        this->clear();
        
        Node * cur = list.head->next;
        while (cur != list.tail) {
            this->push_front(cur->data);
            cur = cur->next;
        }
        return *this;
    }
    
    LinkedList operator+(LinkedList & list) {
        LinkedList ret;
        Node * cur = this->head->next;
        
        while (cur != this->tail) {
            ret.push_front(cur->data);
            cur = cur->next;
        }
        
        cur = list.head->next;
        
        while (cur != list.tail) {
            this->push_front(cur->data);
            cur = cur->next;
        }
        
        return ret;
    }
    
};

int main() {
    LinkedList list1;
    
    list1.push_front(10);
    list1.push_front(20);
    list1.push_front(30);
    cout << "list 1 " << endl << list1;
    
    LinkedList list2 = list1;
    list2.push_front(40);
    
    cout << "list 2" << endl << list2;
    
    LinkedList list3 = list1 + list2;
    
    cout << "list3 " << endl << list3;
    
//    int dat = list1.pop_front();
//
//    cout << dat << endl;
//    int dat2 = list1.pop_front();
//    cout << dat2 << endl;
//    int dat3 = list1.pop_front();
//    cout << dat3 << endl;
    

    
    
//    Test test1(10, "hi"), test2(30, "1235");
//    cout << "test1, test 2 constructed. " << endl;
//
//    Test test3 = Test(10, "12345");
//
//    //test1 = test2;
//
//    cout << test3 << endl;
//
//    Test t1(10, "hi"), t2(20, "yellow");
//
//    cout << t1 << t2 << endl;
//
//    Test t3 = t1 + t2, t4(40, "blabla");
//    cout << t3 << endl;
//
//    t4 = t3;
//    cout << t4 << endl;
    
    //cout <<  << endl;
    
    // Time class use
//    Time t1, t2;
//    t1.addMin(70);
//    t1.addHr(3);
//
//    cout << t1 << endl;
//
//    t2.addMin(165);
//
//    Time t3 = t1 + t2;
//
//    cout << t3 << endl;
//    Time t4 = t3 + 10;
//    cout << t4 << endl;
//
//    int c = static_cast<int>(t4);
//    cout << c << endl;
    
//    Time t2(3, 50);
//    Time t3 = t1 + t2;
//    cout << t1 << endl;
    
    return 0;
}
