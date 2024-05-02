//
// Created by stfne on 19/04/2024.
//

#include<iostream>
#include<vector>
#include<algorithm>

struct job {int id; int start; int end;};
std::vector<job> jobs;
//lettura lavori

std::vector<job> jobs_todo;
int f = 0;

int main(){
    std::sort(jobs.begin(), jobs.end(), [](const job &j1, const job &j2){ return j1.end < j2.end; });
    for(int j = 0; j < jobs.size(); j++){
        if(jobs[j].start >= f){
            jobs_todo.push_back(jobs[j]);
            f = jobs[j].end;
        }
    }
    for (int j = 0; j < jobs_todo.size(); j++){
        std::cout<<jobs_todo[j].id<<", ";
    }
    return 0;
}
