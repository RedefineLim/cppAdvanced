#include <iostream>
#include <string>
using namespace std;

//string赋值操作

int main()
{
    // string str1;
    // str1 = "Hello world";
    // cout << str1 << endl;

    string str2;
    str2.assign("Hello world");
    cout << str2 << endl;

    string str3;
    str3.assign("hello world",5);
    cout << str3 << endl;

    string str4;
    str4.assign(10,'w');
    cout << str4 << endl;

    return 0;
}