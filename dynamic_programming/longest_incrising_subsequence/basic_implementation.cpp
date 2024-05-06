//
// Created by stfne on 06/05/2024.
//
#include "iostream"
#include "vector"

std::vector <int> S = {4, 1, 8, 3, 4, 8, 2, 7, 5, 6, 9, 8};
std::vector <int> opt(S.size());

int main(){
    opt[0] = 0;
    opt[1] = 1;
    for(int i = 2; i<S.size(); i++){
        opt[i]=1;
        for(int j = 1; j<i; j++){
            if(S[j] < S[i]) opt[i] = std::max(opt[i],1+opt[j]);
        }
    }
    int B_size = opt[1];
    for(int i = 2; i<opt.size(); i++){
        B_size = std::max(B_size,opt[i]);
    }

    std::cout<<B_size;
}
