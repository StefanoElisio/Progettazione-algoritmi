#include<iostream>
#include<vector>
std::vector<int> A = {5,2,4,1,3,2,5};
int n = A.size();
int k = 9;

int main(){
    int left=0, right=-1, sum=0;
    int best_left=-1, best_right=-1, best_sum=-1;
    do
    {
        if(sum<=k && right<n-1)
            sum += A[++right];
        else
            sum -= A[left++];
        if(sum<=k && sum>best_sum)
        {
            best_sum = sum; best_left = left; best_right = right;
        }
    } while(left<n-1 || right<n-1);
    std::cout << "Cut from position " << best_left
              << " to position " << best_right << "\n";
    std::cout << "with solution " << best_sum;
}