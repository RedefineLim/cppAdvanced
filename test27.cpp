#include <iostream>
#include <deque>
#include <algorithm>    //标准算法库
using namespace std;

// deque容器的排序

void printDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;
}

int main()
{
    deque<int> d;

    d.push_back(10);
    d.push_back(20);
    d.push_back(30);

    d.push_front(100);
    d.push_front(200);
    d.push_front(300);

    //排序前的打印
    printDeque(d);

    //排序
    sort(d.begin(), d.end());
    printDeque(d);

    return 0;
}