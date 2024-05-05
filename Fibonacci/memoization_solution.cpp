//
// Created by stfne on 05/05/2024.
//
#include "iostream"
#include "vector"

int n;
std::vector<int> memo;

int fibonacci(int n){
    if(n<=1) return n;
    if(memo[n]) return memo[n];
    memo[n] = fibonacci(n-1) + fibonacci(n-2);
    return memo[n];
}

int main(){
    std::cin>>n;
    std::cout<<fibonacci(n);
}
