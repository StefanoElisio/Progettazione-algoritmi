//
// Created by stfne on 13/05/2024.
//
#include "iostream"
#include "vector"
#include "algorithm"

int edit_distance(std::string &s, std::string &t)
{
    std::vector<std::vector<int>> OPT(s.size()+1,std::vector<int>(t.size()+1));
    OPT[1][1] = 0;
    for(int i=1; i <= s.size(); i++) OPT[i][0] = i;
    for(int j=1; j <= t.size(); j++) OPT[0][j] = j;
    for(int i=1; i <= s.size(); i++)
        for (int j = 1; j <= t.size(); j++)
            OPT[i][j] = std::min({OPT[i - 1][j] + 1, OPT[i][j - 1] + 1,
                                  OPT[i - 1][j - 1] + ((s[i-1] == t[j-1]) ? 0 : 1)});
    return OPT[s.size()][t.size()];
}
int main(){
    std::string s,t;
    std::cin>>s>>t;
    std::cout<<edit_distance(s,t);
}
