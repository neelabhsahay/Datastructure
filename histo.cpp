#include<iostream>

#include<stack>
#include<vector>


int getMaxArea( std::vector<int> A ) {
  std::stack<int> stk;
  int max_area = 0;
  int num = A.size();

  int tp = 0;
  int idx=0;

  int area_with_top;
  while( idx < num ) {
    if( stk.empty() ||
        A[stk.top()] <= A[idx ] ) {
      stk.push(idx++);
      std::cout << " Push index " << idx - 1 << std::endl; 
    } else {
      tp = stk.top();
      stk.pop();
      area_with_top = A[tp] * (stk.empty() ? idx :
                               idx - stk.top() - 1);
      std::cout << "First TP " << tp << " idx " << idx  << " area " << area_with_top<< std::endl;
      if (max_area < area_with_top)
        max_area = area_with_top;
    }
  }

  // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    while (stk.empty() == false)
    {
        tp = stk.top();
        stk.pop();
        std::cout << " TP " << tp << " idx " << idx << std::endl;
        area_with_top = A[tp] * (stk.empty() ? idx :
                                idx - stk.top() - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
}

int
main() {
  std::vector<int> A = { 6, 2, 5, 4, 5, 1, 6};
  int maxArea = getMaxArea(A);

  std::cout << " The Max area of Histogram " << maxArea << std::endl;
  return 0;
}
