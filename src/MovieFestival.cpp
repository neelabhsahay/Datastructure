/*
 * In a movie festival n movies will be shown.
 * You know the starting and ending time of each movie.
 * What is the maximum number of movies you can watch entirely?
 *
 * Input:
 * The first input line has an integer n: the number of movies.
 *
 * After this, there are n lines that describe the movies.
 * Each line has two integers a and b: the starting and ending times of a movie.
 *
 * Output:
 *
 * Print one integer: the maximum number of movies.
 *
 * g++ -shared -o libMovieFestival.so MovieFestival.cpp
 */

#include<cstdint>
#include<iostream>
#include<vector>

typedef struct Movie {
    uint32_t str;
    uint32_t end;
} Movie;

std::ostream& operator<<(std::ostream& os, const Movie& mov) {
    return os << "(" << mov.str << ", " << mov.end <<")";
}

template <typename S>
std::ostream& operator<<(std::ostream& os,
                    const std::vector<S>& vector)
{
    // Printing all the elements
    // using <<
    for (auto element : vector) {
        os << element << " ";
    }
    return os;
}

bool sortByEnd (Movie i,Movie j) { return (i.end<j.end); }
bool sortByInterval(Movie i,Movie j) { return ((i.end-i.str)<( j.end-j.str)); }
void
MaxMoviesWatch(uint32_t* str, uint32_t* end, uint32_t numP) {
    std::vector<Movie> mov;
    
    for( int i =0; i < numP; i++ ) {
        Movie m;
        m.str = str[i];
        m.end = end[i];
        mov.push_back(m);
    }
    std::sort(mov.begin(), mov.end(), sortByEnd);
    std::cout << mov << std::endl;
    
    uint32_t no = 0;
    uint32_t last_end = 0;
    for(auto r : mov) {
        if( r.str >= last_end ) {
            no++;
            last_end = r.end;
        }
    }
    std::cout << "Max movies that can be watched: " << no << std::endl;
    return;
}

 // C-linkage is required as this function we will call from python.
extern "C"  //Tells the compile to use C-linkage for the next scope.
{
    void testCode(uint32_t* str, uint32_t* end, uint32_t numP) {
        MaxMoviesWatch(str, end, numP);
        return;
    }
}