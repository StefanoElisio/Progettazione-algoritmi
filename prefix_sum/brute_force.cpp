//
// Created by stfne on 05/03/2024.
//
#include<iostream>
#include<vector>
#include<numeric>
std::vector<int> A = {3,4,6,5,8};

int main(){
    unsigned int result = 0;

    //iteriamo 2 indici sull'array per trovare i subarray   O(n^2)
    for(unsigned int i=0; i<A.size(); i++)
        for(unsigned int j=i; j<A.size(); j++)

            //accumulate somma tutti gli elementi da i a j, e verifichiamo se è pari    O(n)
            if(std::accumulate(A.begin()+i, A.begin()+j+1, 0)%2 == 0)
                result++;

    std::cout<<result;
}
