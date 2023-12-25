#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//vector存放内置数据类型

void my_print(int val) {
    cout << val <<' ';
}

int main()
{
    //创建了一个vector容器
    vector<int> v;
    //插入
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end();  //结束迭代器，指向容器中最后一个元素的下一个位置
    //第一种迭代方式
    while(itBegin != itEnd)
    {
        cout << *itBegin << endl;
        itBegin++;
    }
    //第二种遍历方式
    for(vector<int>::iterator it = v.begin(); it!=v.end();it++)
        cout << *it << endl;
    //第三种遍历方式
    for_each(v.begin(), v.end(), my_print);

    return 0;
}