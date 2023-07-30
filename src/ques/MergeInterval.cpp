/* This take two non-overlapping interval lists, and merge them.
 * if two interval overlap then they are merged into
 * one interval. This can be used in many questions.
 * like finding common time for setting meeting if
 * people already booked calender is given.
 *  
 * Function arguments are: list1 is two dimension with second
 *                         vector has two values, start and end.
 * example:
 *    list1 = [[9,10],[10,12],[14,16]]
 *    list2 = [[8,9], [11,13], [13,14]]
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
      void sortIntervalOnEnd(vector<vector<int>>& list1, vector<vector<int>>& list2) {
      }
   public:
       void printInterval(vector<vector<int>>& list) {
           cout <<endl;
           for( auto l: list ) {
               cout <<"[ " << l[0] << ", " << l[1] << "], ";
           }
           cout << endl;
       }
       vector<vector<int>> mergeNonOverLappingInterval(vector<vector<int>>& list1, vector<vector<int>>& list2 ) {
           vector<vector<int> > res;
           int i =0, j=0;
           while(i< list1.size() && j < list2.size()) {
               if(list1[i][1] <= list2[j][0]) {
                   res.push_back(list1[i]);
                   i++;
               } else if(list2[j][1] <= list1[i][0]){
                   res.push_back(list2[j]);
                   j++;
               } else {
                   list1[i][0] = list1[i][0] < list2[j][0] ? list1[i][0] : list2[j][0];
                   list1[i][1] = list1[i][1] > list2[j][1] ? list1[i][1] : list2[j][1];
                   j++;
               }
           }
           if( i == list1.size() ) {
               while(j < list2.size()) {
                  res.push_back(list2[j]);
                  j++;
               }
           } else {
               while(i < list1.size()) {
                  res.push_back(list1[i]);
                  i++;
               }
           }
           return res;
       }
};

int
main() {
   vector<vector<int>> list1 = {{9,10},{10,12},{14,17}};
   vector<vector<int>> list2 = {{8,9},{11,13},{13,15},{15,18},{18,20}};

   Solution s;
   s.printInterval(list1);
   s.printInterval(list2);
   vector<vector<int>> res = s.mergeNonOverLappingInterval(list1, list2);
   s.printInterval(res);
   return 0;
}
