//
// Created by stfne on 13/05/2024.
//
#include "iostream"
#include "vector"
#include "cstdint"
#include "algorithm"

std::pair<std::vector<int>,std::vector<int>> split(std::vector<int> S) {
    std::vector<int> S1;
    std::vector<int> S2;
    for(int i=0; i<S.size()/2;i++)
        S1.push_back(S[i]);
    for(int i=S.size()/2; i<S.size();i++)
        S2.push_back(S[i]);
    std::pair<std::vector<int>,std::vector<int>> S0 = {S1,S2};
    return S0;
}

std::vector<int> list(std::vector<int> S){
    uint64_t nsums = static_cast<uint64_t>(1)<<S.size(); //2^n
    std::vector<int> sums(nsums, 0);
    for(uint64_t x=0; x<nsums; x++)
        for(unsigned int i=0; i<S.size(); i++)
            sums[x] += ( (x>>i) & 1u )?S[i]:0;
    return sums;
}

bool split_and_list(std::vector<int> S, int T){
    std::pair<std::vector<int>,std::vector<int>> S0 = split(S);
    std::vector<int> S1 = S0.first;
    std::vector<int> S2 = S0.second;
    std::vector<int> T1 = list(S1);
    std::vector<int> T2 = list(S2);
    std::sort(T2.begin(),T2.end());

    //questo passaggio si potrebbe fare con la ricerca binaria per passare da
    //O(T1 * T2) a O(T1 * log(T2))
    //dato che il problema ha già complessità esponenziale questa differenza risulta trascurabile
    for (int t1:T1){
        for(int t2:T2) {
            if (T - t1 == t2)
                return true;
            if (T - t1 < t2)
                break;
        }
    }
    return false;
}

int main(){
    std::vector<int> S;
    S = {2, 5, 3, 13, 7, 8, 9, 18, 3};
    int T = 17;
    if (split_and_list(S,T))std::cout<<"true\n";
    else std::cout<<"false\n";
    return 0;
}