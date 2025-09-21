#include<iostream>

using namespace std;


// sending as string just for simpilcity
// number will be single digit and only [ & ]
int
nestedListWeightSum(string &nestList)
{
    int bracketCount = 0;
    int num;
    int sum =0;
    for(auto s:nestList) {
        if (isdigit(s)) {
            num = bracketCount* (s-'0');// cal culate the value inside a bracket
            sum += num; // add the value to sum.
        } else if (s =='[') {
            bracketCount++;
        } else if (s == ']') {
            bracketCount--;
        }
    }

    return sum;
}

int
main()
{
    //string nestList = "[1,[4,[6]]]"; // "[[1,1],2,[1,1]]"; //"[1, [2, 2], [[3, 7], 2], 1]";
    string nestList = "[[1,1],2,[1,1]]"; //"[1,[4,[6]]]"; // "[[1,1],2,[1,1]]"; //"[1, [2, 2], [[3, 7], 2], 1]";
    int result = nestedListWeightSum(nestList);
    cout << "Value of \"" <<  nestList << "\" is: " << result <<"\n"; 
    return 0;
}
