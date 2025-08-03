#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Cashier {
    private:
       int cusNo;
       int cusR;
       
       int dis;
       map<int, int> prodPrice;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        cusNo = n;
        dis = discount;
        cusR = 0;
        for(int i = 0; i < products.size();i++) {
            prodPrice.insert(pair<int,int>(products[i], prices[i]));
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        cusR++;
        double bill = 0;
        map<int,int>::iterator it;
        int fac = 100;
        if( (cusR % cusNo) == 0 ) {
            fac = fac - dis;
        }
        for(int i = 0; i < product.size();i++) {
            it = prodPrice.find(product[i]);
            if( it != prodPrice.end()) {
                bill += ((amount[i] * it->second ) * fac * 0.01);
            }
        }
        return bill;
    }
};

int main() {
   int n = 3;
   int discount = 50;
   vector<int> products{1,2,3,4,5,6,7};
   vector<int> prices{100,200,300,400,300,200,100};
   vector<int> pd1{1,2};
   vector<int> amount1{1,2};   
   vector<int> pd2{3,7};
   vector<int> amount2{10,10};   
   vector<int> pd3{1,2,3,4,5,6,7};
   vector<int> amount3{1,1,1,1,1,1,1};   
   vector<int> pd4{4,};
   vector<int> amount4{10,};
   vector<int> pd5{7,3};
   vector<int> amount5{10,10};
   vector<int> pd6{7,5,3,1,6,4,2};
   vector<int> amount6{10,10,10,9,9,9,7};

   Cashier c = Cashier(n, discount, products, prices);

   cout << "Bill: " << c.getBill(pd1, amount1) << endl;   
   cout << "Bill: " << c.getBill(pd2, amount2) << endl;   
   cout << "Bill: " << c.getBill(pd3, amount3) << endl;   
   cout << "Bill: " << c.getBill(pd4, amount4) << endl;
   cout << "Bill: " << c.getBill(pd5, amount5) << endl;
   cout << "Bill: " << c.getBill(pd6, amount6) << endl;

   return 0;
} 
