#include <iostream>
#include <string>
using namespace std;

//string 求子串

int main()
{
    string str = "abcdef";
    string sub = str.substr(1,3);
    cout << "str:  " << str << endl; 
    cout << "sub:  " << sub << endl; 

    //实用操作
    string email = "hello@sina.com";
    //从中获得用户名的信息
    int offs = email.rfind('@');
    string userName = email.substr(0, offs);
    cout << userName << endl;

    return 0;
}