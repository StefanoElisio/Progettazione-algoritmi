//
// Created by stfne on 08/05/2024.
//
#include "iostream"
#include "vector"

std::vector <int> S = {4, 1, 8, 3, 4, 8, 2, 7, 5, 6, 9, 8};
std::vector <int> opt(S.size());

int main(){
    opt[0]=0;
    opt[1]=S[0];
    for (int i = 2; i<=S.size(); i++){
        opt[i]= std::max(S[i-1]+opt[i-2],opt[i-1]);
    }

    std::cout<<opt[S.size()];
}