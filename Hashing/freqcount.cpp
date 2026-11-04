#include <iostream>
using namespace std;

// FREQUENCY COUNTING
// Look for phrases such as:
// - Count occurrences.
// - Find the most frequent element.
// - Find the element appearing only once.
// - Check whether two strings have the same character frequencies.
// - Find duplicates.
   
// - Count occurrences using unordered_map or frequency array.
// - Recognition: count, duplicates, most frequent, unique elements.
// - Average time: \(O(n)\), space: \(O(k)\). k is no of distinct elements



// VALID ANAGRAM
bool isAnagram(string s, string t){
     if(s.length() != t.length()){
        return false;
    }
    // basically we have to check for every letter must be present equal no
    unordered_map<char,int> mp1;
     unordered_map<char,int> mp2;
    for(int i=0;i<s.length();i++){
        mp1[s[i]]++;   
    }

    for(int i=0;i<t.length();i++){
        mp2[t[i]]++;
    }

    for(auto i:mp1){
        if(mp1[i.first]!= mp2[i.first]){
            return false;
        }
    }
    return true;
}

// TAKING ONE UNORDERED MAP
bool isAnagram(string s, string t){
     if(s.length() != t.length()){
        return false;
    }
    unordered_map<char,pair<int,int>> mp;

    // first store frequency of each letter from one of the string
    for(int i=0;i<s.length();i++){
            mp[s[i]].first++;
    }

    // now take another string and check freq of each letter
    for(int i=0;i<t.length();i++){
        mp[t[i]].second++;
    }

    for(auto i: mp){
        if(i.second.first != i.second.second){
            return false;
        }
    }
    return true;
} // this is good but not so much effective

// optimised code with using one map
bool isAnagram(string s, string t){
    if(s.length() != t.length()){
        return false;
    }
    unordered_map<char,int> mp;

    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
    }
    for(int i=0;i<t.length();i++){
        mp[t[i]]--;
    }

    for(auto i: mp){ 
        if(i.second !=0){
            return false;
        }
    }
    return true;
}

// TOP K FREQUENT WORDS (#692)
vector<string> topKFrequent(vector<string>& words, int k){
    unordered_map<string,int> mp;
    for(int i=0;i<words.size();i++){
        mp[words[i]]++;
    }
    priority_queue<pair<int,string>> pq;
    for(auto i:mp){
        // if same frequency then opposite lexicography
        
    }

}~


int main(){

}