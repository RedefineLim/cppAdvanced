#include <iostream>
#include <vector>
using namespace std;

//巧用swap收缩内存空间

int main()
{
    vector<int> v;
    for (int i = 0; i < 10000; ++i)
        v.push_back(i);
    cout << v.capacity() << endl;
    cout << v.size() << endl;

    v.resize(3);    //重新指定大小
    cout << v.capacity() << endl;
    cout << v.size() << endl;

    //巧用swap收缩
    vector<int>(v).swap(v);
    //vector<int>(v) ----> 创建匿名对象     调用拷贝函数
    //vector<int>(v).swap(v) 然后进行容器交换       本质是地址交换

    cout << v.capacity() << endl;
    cout << v.size() << endl;

    return 0;
}