//
// Created by stfne on 06/05/2024.
//
#include "iostream"
#include "vector"

std::vector <int> S = {4, 1, 8, 3, 4, 8, 2, 7, 5, 6, 9, 8};
std::vector <int> opt(S.size());

int binary_search(int start,int end){
    int l = 0;
    int i = end+1;
    while (start <= end){
        int mid = (start+end)/2;
        if (opt[mid] == -1 or S[opt[mid]] >= S[i])
            end = mid - 1;
        else {
            l = mid;
            start = mid + 1;
        }
    }
    return l;
}

int main(){
    opt[1] = S[0] <= S[1]? 0:1;
    for (int l = 2; l<S.size(); l++) opt[l] = -1;
    for (int i = 2; i<S.size(); i++){
        int l = binary_search(1,i-1);
        int best_l = l + 1;
        opt[best_l] = i;
        std::cout<<"opt["<<i<<","<<best_l<<"]\n";
    }
    int B_size = 1;
    for(int i = 2; i<opt.size(); i++){
        if(opt[i] != -1) B_size++;
        else break;
    }
    std::cout<<B_size<<"\n";
}
