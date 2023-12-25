#include <iostream>
#include <string>
using namespace std;

//string容器
//string是一个类，类内部封装了char*

//string的构造函数

int main()
{
    string s1;
    const char* str = "hello world";

    string s2(str);
    cout << s2 << endl;

    string s3(s2);
    cout << s3 << endl;

    string s4(10,'a');
    cout << s4 << endl;

    return 0;
}