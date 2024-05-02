//
// Created by stfne on 29/04/2024.
//

#include<iostream>
#include<vector>
#include<algorithm>

struct job {int id; int time; int deadline;};
std::vector<job> jobs;
//lettura lavori

std::vector<job> schedul;
int t;

int main(){
    std::sort(jobs.begin(), jobs.end(), [](const job &j1, const job &j2){ return j1.deadline < j2.deadline; });
    for(int j = 0; j < jobs.size(); j++){
        t = 0;
        for(int i = 0; i < j; i++){
            t += jobs[i].time;
        }
        for(int i = 0; i < t; i++){
            schedul.insert(schedul.begin()+t+i,jobs[j]);
        }
    }

    for(int j = 0; j < schedul.size(); j++){
        std::cout<<j<<": "<<schedul[j].id;
    }
    return 0;
}