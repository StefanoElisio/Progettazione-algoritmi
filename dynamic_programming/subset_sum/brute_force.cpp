//
// Created by stfne on 13/05/2024.
//
#include "iostream"
#include "vector"

bool brute_force(std::vector<int> S, int T){
    std::vector<std::vector<int>> OPT(S.size()+1,std::vector<int>(T));
    OPT[0][0] = true;
    for(int i=1; i<=T; i++) OPT[0][i] = false;
    for(int i=1; i<=S.size(); i++){
        for(int t=1; t<=T; t++){
            if (t < S[i-1]) OPT[i][t] = OPT[i-1][t];
            else{
                OPT[i][t] = OPT[i-1][t-S[i-1]]? OPT[i-1][t-S[i-1]]:OPT[i-1][t];
            }
        }
    }
    for(int i=0; i<=S.size(); i++)
        if (OPT[i][T]==true) return true;
    return false;
}

int main(){
    std::vector<int> S = {2, 5, 3, 13, 7, 8, 9, 18, 3};
    int T = 37;
    if (brute_force(S,T))std::cout<<"true\n";
    else std::cout<<"false\n";
    return 0;
}
