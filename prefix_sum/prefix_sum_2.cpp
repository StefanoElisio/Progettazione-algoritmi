//
// Created by stfne on 05/03/2024.
//
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
std::vector<int> A = {3,4,6,5,8};

int main(){
    //creiamo il vettore delle somme parziali P    O(n)
    std::partial_sum(A.begin(), A.end(), A.begin());

    //contiamo il numero di numeri pari in P    O(n)
    int odd = count_if(A.begin(), A.end(),[](int x) {return x%2;});
    int even = A.size()+1-odd;

    //troviamo le coppie    O(1)
    std::cout<<odd*(odd-1)/2 + even*(even-1)/2;
}
