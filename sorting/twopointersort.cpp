#include<iostream>
using namespace std;



// TWO SUM II (#167)

vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        // using two pointer approach 
        int i=0; 
        int j=numbers.size()-1;

        while( i<j){
            int sum = numbers[i]+numbers[j];
            if(sum== target){
                ans.push_back(i+1);// ques says 1 based indexing
                ans.push_back(j+1);
                break;
            }
            else if(numbers[i]+numbers[j] < target){
                i++;
            }

            else {
                j--;
            }
        }
        return ans;
    }

int main(){

}