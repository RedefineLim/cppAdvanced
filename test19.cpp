#include <iostream>
#include <vector>
using namespace std;

//vector容器互换

void printVector(vector<int>& v)
{
    for (auto it = v.begin(); it != v.end() ; ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

int main()
{
    vector<int> v1;
    for (int i = 0; i < 10; ++i)
        v1.push_back(i);
    printVector(v1);

    vector<int> v2;
    for (int i = 10; i > 0; --i)
        v2.push_back(i);
    printVector(v2);

    //交换后
    v1.swap(v2);
    printVector(v1);
    printVector(v2);

    return 0;
}