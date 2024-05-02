#include<iostream>
#include<algorithm>
#include<vector>
std::vector<int> arrival_times = {2,5,9,16,22};
int T = 29;

bool feasible(int L){
    int time=1;
    for(const int t : arrival_times)
        time = std::max(time, t) + L;
    return time<=T;
}

template<typename T> T binary_search(T min, T max, bool (*p)(T) ){
    while(min < max){
        if(T mid = (min+max)/2; p(mid))
            min = mid+1;
        else
            max = mid;
    }
    return max;
}

template<typename T> T exponential_search(T min, T max, bool (*p)(T) ){
    if(!p(min))
        return min;
    for(T i=1; min+i<max; i*=2)
        if(!p(min+i))
            return min+i;
    return max;
}

int main(){
    std::sort(arrival_times.begin(), arrival_times.end());
    int U = exponential_search(2, T, feasible);
    std::cout << binary_search(U/2, U, feasible) - 1;
}
