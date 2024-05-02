//
// Created by stfne on 29/04/2024.
//

#include<iostream>
#include<vector>
#include<algorithm>

struct job {int id; int start; int end;};
std::vector<job> jobs;
//lettura lavori

std::vector<std::tuple<int, bool, int>> events;
int d=0,k=0;

int main(){
    for(const job &j : jobs){
        //Use second entry for tie breaking (false<true)
        events.push_back( std::make_tuple(j.start, true, j.id) );
        events.push_back( std::make_tuple(j.end, false, j.id) );
    }
    std::sort(events.begin(), events.end());

    for(const auto &event : events){
        if(std::get<1>(event))d++;
        else d--;
        if (d>k) k = d;
    }
}
