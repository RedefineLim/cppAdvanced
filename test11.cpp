#include <iostream>
#include <string>
using namespace std;

//string字符存取

int main()
{
    string str = "hello";
    //1、通过[]访问单个字符
    for(int i = 0;i < str.size(); ++i)
        cout << str[i] << " " ;
    cout << endl;
    //2、通过at方式访问单个字符
    for(int i = 0;i < str.size(); ++i) 
        cout << str.at(i) << " " ;
    cout << endl;

    str[0] = 'x';
    cout << str << endl;
    str.at(0) = 'h';
    cout << str << endl;

    return 0;
}