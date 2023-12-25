#include <iostream>
#include <string>
using namespace std;

//string字符串比较
//按照ASCII码值逐个去比

int main()
{
    string str1 = "xello";
    string str2 = "hello";

    if(str1.compare(str2) == 0)
        cout << "==" << endl;
    else if(str1.compare(str2) > 0)
        cout << ">" << endl;
    else 
        cout << "<" << endl;

    return 0;
}