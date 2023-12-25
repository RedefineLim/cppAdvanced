#include <iostream>
#include <string>
using namespace std;

//string字符串拼接

int main()
{
    //字符串拼接
    string str1 = "我";
    str1 += "游戏";
    cout << str1 << endl;

    string str3 = "I ";
    str3.append("love ");
    cout << str3 << endl;

    return 0;
}
//字符串拼接重载版本很多，只需要先记住重要的几个