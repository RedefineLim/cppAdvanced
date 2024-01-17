#include <iostream>
#include <vector>
using namespace std;

// vector容器预留空间
// reserve(int len);

int main() 
{
    // vector<int> v;
    // int num = 0;
    // int *p = NULL;
    // for (int i = 0; i < 10000; ++i) {
    //     v.push_back(i);

    //     if(p != &v[0]) {
    //         p = &v[0];
    //         ++num;
    //     }
    // }
    // cout << num << endl;

    //利用reserve预留空间
    vector<int> v;
    v.reserve(10000);
    int num = 0;
    int *p = NULL;
    for (int i = 0; i < 10000; ++i) {
        v.push_back(i);

        if(p != &v[0]) {
            p = &v[0];
            ++num;
        }
    }
    cout << num << endl;

    return 0;
}