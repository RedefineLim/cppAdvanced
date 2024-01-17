#include <iostream>
#include <deque>
using namespace std;

//deque容器数据存取操作

int main()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(40);

    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    d.push_front(400);

    //通过[]方式访问元素
    for (int i = 0; i < d.size(); ++i)
        cout << d[i] << ' ';
    cout << endl;

    //通过at方式访问元素
    for (int i = 0; i < d.size(); ++i)
        cout << d.at(i) << ' ';
    cout << endl;

    cout << "first element: " << d.front() << endl;
    cout << "last element: " << d.back() << endl;

    return 0;
}