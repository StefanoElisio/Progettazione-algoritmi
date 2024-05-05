//
// Created by stfne on 05/05/2024.
//
#include "iostream"

int n;

int fiboncacci(int n){
    if (n <= 1) return n;
    return fiboncacci(n-1) + fiboncacci(n-2);
}

int main(){
    std::cin>>n;
    std::cout<<fiboncacci(n);
}
