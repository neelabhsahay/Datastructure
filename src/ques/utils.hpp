// header file for utility function for priniting
// vectors, 
#ifndef __UTILS_HPP__
#define __UTILS_HPP__

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& data) {
    if(data.size() == 0) {
        os << "[]";
        return os;
    }
    os << "[";
    for(int i =0; i<data.size()-1; i++) {
        os << data[i] <<",";
    }
    if(data.size()-1 >=0) {
        os << data[data.size()-1] << "] ";
    } else {
        os << "] ";
    }
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>>& matrix) {
    os << "[";
    for(auto row:matrix) {
        os <<"[";
        for(auto e:row) {
            os << e <<" ";
        }
        os << "]";
    }
    os << "] ";
    return os;
}

// Binary search to find the last occurrence if larger = TRUE
// Binary search to find the first occurrence if larger = FALSE
template <typename T>
static inline int binarySearchPos(std::vector<T> &nums, int l, int r, T val, bool larger)
{
    int at = -1;
    int m;
    while(l<=r) {
        m = (r+l)/2;
        if(nums[m] == val) {
            // found one occurance now try to find
            // next item in direction as the varable larger
            at = m;
            if(larger) {
                l = m+1;
            } else {
                r = m-1;
            }
        } else if(val >nums[m]) {
            l = m+1;
        } else {
            r = m-1;
        }
    }
    return at;
}
#endif  //  __UTILS_HPP__
