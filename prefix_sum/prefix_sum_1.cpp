//
// Created by stfne on 05/03/2024.
//
#include<iostream>
#include<vector>
#include<numeric>
std::vector<int> A = {3,4,6,5,8};

int main(){
    std::vector<int> P(A.size()+1);

    //creiamo il vettore delle somme parziali P    O(n)
    std::partial_sum(A.begin(), A.end(), P.begin()+1);

    unsigned int result = 0;

    //iteriamo 2 indici sull'array per trovare i subarray   O(n^2)
    for(unsigned int i=1; i<=A.size(); i++)
        for(unsigned int j=i; j<=A.size(); j++)

            //verifichiamo che sia pari    O(1)
            if((P[j] - P[i-1])%2 == 0)
                result++;


    std::cout<<result;
}
