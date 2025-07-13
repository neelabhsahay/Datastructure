#include<iostream>

using namespace std;


// sending as string just for simpilcity
// number will be single digit and only [ & ]
int
nestedListWeightSum(string &nestList)
{
    vector<int> values;
    int bracketCount = 0;
    int num;
    for(auto s:nestList) {
        if (isdigit(s)) {
            num = bracketCount* (s-'0');
            values.push_back(num);
        } else if (s =='[') {
            bracketCount++;
        } else if (s == ']') {
            bracketCount--;
        }
    }

    num = 0;
    for(auto v:values) {
        num += v;
    }
    return num;
}

int
main()
{
    string nestList = "[1,[4,[6]]]"; // "[[1,1],2,[1,1]]"; //"[1, [2, 2], [[3, 7], 2], 1]";
    int result = nestedListWeightSum(nestList);
    cout << "Value of \"" <<  nestList << "\" is: " << result <<"\n"; 
    return 0;
}
