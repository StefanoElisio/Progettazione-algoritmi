#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
std::vector<int> A = {5,2,4,1,3,2,5};
std::vector<int> P(A.size()+1);
std::vector<int> X(A.size()+1);
int k = 9;

int binary_search(int min, int max){
    int i = min;
    while(min < max){
        int mid = (min+max)/2;
        if(P[mid]<=P[i]+k)
            min = mid+1;
        else
            max = mid;
    }
    return max-1;
}

int main(){
    std::partial_sum(A.begin(), A.end(), P.begin()+1);
    int best = 0;
    for(unsigned int i=0; i<P.size(); i++){
        int x = (P[binary_search(i, P.size())]-P[i]);
        if (x > best) best = x;
    }
    std::cout<<best;
}