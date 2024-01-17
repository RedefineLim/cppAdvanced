#include <iostream>
#include <vector>
using namespace std;

//vector容量和大小

void print_vector(vector<int>& v)
{
    //也可以使用auto
    for(vector<int>::iterator it = v.begin(); it!= v.end(); ++it) {
        cout << *it << ' ' ;
    }
    cout << endl;
}

int main()
{
    vector<int> v1;
    for(int i = 0; i<10 ; ++i)
        v1.push_back(i);
    print_vector(v1);
    if(v1.empty())
        cout << "empty" << endl;
    else 
    {
        cout << "not empty" << endl;
        //capacity代表容量
        cout << "capacity is " << v1.capacity() << endl;
        //size代表大小
        cout << "size is " << v1.size() << endl;
    }
    v1.resize(15);
    print_vector(v1);
    //默认填充值为0
    v1.resize(20, 100);
    print_vector(v1);
    //利用重载版本，可以指定填充值

    return 0;
}