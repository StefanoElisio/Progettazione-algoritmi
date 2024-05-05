//
// Created by stfne on 05/05/2024.
//
#include "iostream"
#include "vector"

int n;
std::vector<int> f = {0,1};

int main(){
    std::cin>>n;
    for (int i = 2; i <= n; i++){
        f[i%2] = f[(i-1)%2] + f[(i-2)%2];
    }
    std::cout<<f[n%2];
}
