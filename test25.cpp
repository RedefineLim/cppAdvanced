#include <iostream>
#include <deque>
using namespace std;

// deque容器插入和删除

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
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);

    d1.push_front(100);
    d1.push_front(200);

    printDeque(d1);

    d1.pop_back();
    d1.pop_front();

    printDeque(d1);

    // insert插入
    d1.insert(d1.begin(), 1000);
    printDeque(d1);

    d1.insert(d1.begin(), 2, 10000);
    printDeque(d1);

    // 按照区间来进行插入
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d1.insert(d1.begin(), d2.begin(), d2.end());
    printDeque(d1);

    // 删除
    deque<int>::iterator it = d1.begin();
    ++it;
    d1.erase(it);
    printDeque(d1);

    // 按照区间的方式删除
    // d1.erase(d1.begin(), d1.end());
    // printDeque(d1);

    d1.clear();
    printDeque(d1);

    return 0;
}