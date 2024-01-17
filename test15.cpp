#include <iostream>
#include <vector>
using namespace std;

//vector容器的赋值

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
    //1、等号赋值
    vector<int> v2 = v1;
    print_vector(v2);

    //2、assign赋值
    vector<int> v3;
    v3.assign(v2.begin(), v2.end());
    print_vector(v3);

    //3、n个elem方式
    vector<int> v4;
    v4.assign(10, 100);
    print_vector(v4);

    return 0;
}