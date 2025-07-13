#include<iostream>

using namespace std;

class MovingAverage {
     vector<int> stream_;
     int pos_;
     int size_;
     int sum;
public:
     MovingAverage(int size) {
          stream_ = vector<int>(size,0);
          pos_ = 0;
          size_ = size;
          sum = 0;
     };

     double next(int n)
     {
         double avg =0;
         if(pos_ >= size_) {
             sum -= stream_[pos_%size_];
             sum += n;
             stream_[pos_%size_] = n;
             pos_++;
             avg = (double)sum/size_;
         } else {
             sum +=n;
             stream_[pos_%size_] = n;
             pos_++;
             avg = (double)sum/pos_;
         }
          
         for(int i =0;i<size_;i++) {
             cout << stream_[i] << " ";
         }
         cout << " : " << avg << "\n";
         return avg;
     };
};


int main()
{
    MovingAverage *movingAverage = new MovingAverage(3);

    movingAverage->next(1); // return 1.0 = 1 / 1
    movingAverage->next(10); // return 5.5 = (1 + 10) / 2
    movingAverage->next(3); // return 4.66667 = (1 + 10 + 3) / 3
    movingAverage->next(5); // return 6.0 = (10 + 3 + 5) / 3
    movingAverage->next(4); // return 4.0 = (4 + 3 + 5) / 3
    movingAverage->next(15); // return 8.0 = (15 + 4 + 5) / 3
    movingAverage->next(8); // return 9.0 = (15 + 4 + 8) / 3
    movingAverage->next(5); // return 9.33333 = (15 + 8 + 5) / 3

    return 0;
}


