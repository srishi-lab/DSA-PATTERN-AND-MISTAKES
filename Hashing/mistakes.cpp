#include <iostream>
using namespace std;

int main(){
    unordered_map<int,int> mp;

    for(auto i: mp){ // here i will create acopy of every key and value pair
        // condition 
}
    for(auto &i:mp){ // take reference from map no copy creation
        // condition
    }

}
 
// #347 


// #451
// pq.top().first;    // Reading is allowed
// pq.top().first--;  // Modifying is not allowed
/*
        while(pq.top().first){
        ans+=pq.top().second;
        pq.top().first--; // wrong
        }
*/



vector<int> nums = {1, 2, 3};

next_permutation(nums.begin(), nums.end());

// nums = {1, 3, 2}if (i >= 0) {
    // Find successor and swap
}
reverse(nums.begin() + i + 1, nums.end());

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            maxi = max(maxi, sum);

            if(sum < 0) {
                sum = 0;
            }
        }

        return maxi;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            maxi = max(maxi, sum);

            if(sum < 0) {
                sum = 0;
            }
        }

        return maxi;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            maxi = max(maxi, sum);

            if(sum < 0) {
                sum = 0;
            }
        }

        return maxi;
    }
};