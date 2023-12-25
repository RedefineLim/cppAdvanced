#include <iostream>
#include <string>
using namespace std;

//string插入和删除
/*
basic_string& insert(size_type p0, const E *s);
basic_string& insert(size_type p0, const E *s, size_type n);
basic_string& insert(size_type p0,
    const basic_string& str);
basic_string& insert(size_type p0,
    const basic_string& str, size_type pos, size_type n);
basic_string& insert(size_type p0, size_type n, E c);
iterator insert(iterator it, E c);
void insert(iterator it, const_iterator first, const_iterator last);
void insert(iterator it, size_type n, E c);
*/

int main()
{
    string str = "hello";
    //插入
    str.insert(1,"111");
    cout << str << endl;
    //删除
    str.erase(1, 3);
    cout << str << endl;

    return 0;
}
//插入和删除的起始下标都是从0开始的