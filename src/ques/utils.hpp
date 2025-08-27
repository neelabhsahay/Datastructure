// header file for utility function for priniting
// vectors, 
#ifndef __UTILS_HPP__
#define __UTILS_HPP__

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& data) {
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

#endif  //  __UTILS_HPP__
