#include<iostream>
#include<algorithm>
#include<vector>
std::vector<int> arrival_times = {2,5,9,16,22};
int T = 28;
int n = arrival_times.size();

int main(){
    std::sort(arrival_times.begin(), arrival_times.end());
    int L;
    for(L=2; L<=1+T/n; L++){
        int time = 1; //Next available time
        for(const int t : arrival_times)
            time = std::max(time, t) + L;
        if(time > T)
            break;
    }
    std::cout << L-1 << "\n";
}
