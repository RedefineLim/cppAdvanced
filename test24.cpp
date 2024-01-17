#include <iostream>
#include <deque>
using namespace std;

//deque容器大小操作

void printDeque(const deque<int>& d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

int main() 
{
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }
    printDeque(d1);
    if(d1.empty())
        cout << "empty" << endl;
    else
        cout << "not empty" << endl;

    cout << "d1的大小: " << d1.size() << " ." << endl;

    //deque容器没有容量的概念

    // d1.resize(15);
    // printDeque(d1);

    d1.resize(15,1);
    printDeque(d1);

    return 0;
}