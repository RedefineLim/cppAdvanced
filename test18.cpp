#include <iostream>
#include <vector>
using namespace std;

//vector容器中数据存取操作
//接口

int main()
{
    vector<int> v1;
    for (int i = 0; i < 10; ++i)
        v1.push_back(i);
    for (int i = 0; i < v1.size(); ++i)
        cout << v1[i] << ' ';
    cout << endl;

    //at 访问
    for (int i = 0; i < v1.size(); ++i)
        cout << v1.at(i) << ' ';
    cout << endl;

    //获取第一个元素
    cout << v1.front() << endl;

    //获取最后一个元素
    cout << v1.back() << endl;

    return 0;
}