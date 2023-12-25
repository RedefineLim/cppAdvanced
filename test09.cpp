#include <string>
#include <iostream>
using namespace std;

//字符串的查找和替换
//查找指定字符串是否存在

int main()
{
    string str1 = "abcdefghi";
    //1、查找
    // int pos = str1.find("de");  //找到返回偏移量，没找到返回 -1
    // // cout << pos << endl;
    // if(pos == -1)
    //     cout << "Not found" << endl;
    // else
    //     cout << "Found, pos = " << pos << endl;
    
    int pos = str1.rfind("de");
    cout << pos << endl;
    //rfind和find的区别：rfind是从右往左查，find是从左往右查

    //2、替换
    string str2 = "abcdefgh";
    str2.replace(1, 3, "1111");
    //从1号位置起3个字符 替换为1111
    cout << str2 << endl;

    return 0;
}