#include<iostream>

using namespace std;

void
print(vector<int> &vec)
{
    cout << "[";
    for(auto v:vec) {
        cout << v <<", ";
    }
    cout << "]\n";
}

int 
main()
{
    vector<int> test1 = {1,2,3,4,5,6,7};
    vector<int> in;
    for(auto t:test1) {
        in.push_back(t);
        print(in);
    }
    reverse(in.begin(), in.end());
    print(in);
    return 0;
}
