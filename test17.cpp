#include <iostream>
#include <vector>
using namespace std;

// vector容器的插入和删除

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;
}

int main()
{
    vector<int> v1;
    // 尾插法
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    // 遍历
    printVector(v1);

    // 尾删
    v1.pop_back();
    printVector(v1);

    // 插入
    v1.insert(v1.begin(), 100);
    printVector(v1);

    v1.insert(v1.begin(), 2, 1000);
    printVector(v1);

    // 删除：参数也是迭代器
    v1.erase(v1.begin());
    printVector(v1);

    // v1.erase(v1.begin(), v1.end());
    // printVector(v1);

    v1.clear();
    printVector(v1);

    return 0;
}