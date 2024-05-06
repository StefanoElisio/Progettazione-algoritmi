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
    for (int i = 2; i<S.size(); i++) opt[i] = -1;
    for (int i = 2; i<S.size(); i++){
        int best_l = 1;
        for (int l = 1; l < i; l++){
            if (opt[l] != -1 and S[opt[l]] < S[i])
                best_l = l + 1;
        }
        opt[best_l] = i;
    }
    int B_size = 1;
    for(int i = 2; i<opt.size(); i++){
        if(opt[i] != -1) B_size++;
        else break;
    }
    std::cout<<B_size<<"\n";
}
