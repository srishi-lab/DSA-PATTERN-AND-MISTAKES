#include <iostream>
#include<string>
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
// vector<string> topKFrequent(vector<string>& words, int k){
//     unordered_map<string,int> mp;
//     for(int i=0;i<words.size();i++){
//         mp[words[i]]++;
//     }
//     priority_queue<pair<int,string>> pq;
//     for(auto i:mp){
//         // if same frequency then opposite lexicography
        
//     }

// }

//  TOP K FREQUENT WORDS (#692) **
// this is a comparator 
struct compare{
    bool operator() (pair<int, string> a,pair<int ,string> b){
        // return true means first one has lower priority

        if(a.first == b.first){
            // return wanted condition true
            if(a.second >b.second){
                return true; 
            }
            else{
                return false;
            }

        }
        else{
            if(a.first> b.first){
                return false;
            }
            else{
                return true;
            }
        }
    }
};

vector<string> topKFrequent(vector<string>& words, int k){
    // priority_queue<Type, Container, Comparator> pq;
    priority_queue<pair<int,string>,vector<pair<int,string>>,compare>pq;
    // pair<int,string> - operation on which element
    // vector<pair<int,string>> - where internally stored element
    // compare - which operation used for it 

    // reference 
    // priority_queue<int> pq ;
    // it is similar to  - priority_queue<int, vector<int> , less int> pq;
    // where , type is int , container is vector <int> , comparator is less int 
    // comaprator less 
// struct compare{
//     bool operator()(int a,int b){
//         if( a<b){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// };


// 

    unordered_map<string,int> mp;
    vector<string> ans;

    for(int i=0;i<words.size();i++){
        mp[words[i]]++;
    }
    
    for(auto i:mp){
        pair<int,string> a= {i.second,i.first};
        pq.push(a);
        // don't need to do compare operator manually queue does it automatically

    }

    while(k--){
        ans.push_back(pq.top().second); // stored in pair form pair<int string> we need only string in ans
        pq.pop();
    }
    return ans;

}

// time complexity and space 
/*
for frequency counting n
for building heap through insertion  m*log m
extracting k element k*logm
 (n+ mlog m + klog m)
for extra space m
*/

// SORT CHARACTER BY FREQUENCY (#451)
string frequencySort(string s) {

    unordered_map<char,int> mp;
    string ans="";

    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
    }

    priority_queue <pair<int,char>>pq;
    for(auto i:mp){
        pq.push({i.second,i.first});
    }
   
    while(pq.size()){
        int k= pq.top().first;

        while(k--){
            ans+=pq.top().second;
        }
        pq.pop();
    }
    return ans;
}

// tc and sc 
/* m: distinct char

frequecy count - n
heap insertion - m*logm
ans extracting - m.logm
building ans - n
tc = o(n+mlogm)

space -o(m+n) for string ans
*/

// GROUP ANAGRAMS (#49) 

bool compare(string a,string b){
    return a<b;
}

// 
bool isanagram (string s1, string s2){
    if(s1.length() != s2.length()){
        return false;
    }

    unordered_map<char,int> mp;
    for(int i=0;i< s1.length();i++){
        mp[s1[i]]++;
    }
    for(int i=0;i<s2.length();i++){
        mp[s2[i]]--;
    }

    for(auto i:mp){
        if(i.second != 0){
            return false;
        }
    }
    return true;
}

// wrong approach

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    vector<string> ans1;
    // first we should sort strs so that all anagram will looks similar and easy to collect

    // take one string and compare it from other who will same put it in ans
    sort(strs.begin(),strs.end());

    // use two words anagram technique here
    for(int i=0;i<strs.size();i++){
        string s1= strs[i];
        for(int j=i+1;j<strs.size();j++){
            string s2= strs[j];
            ans1.push_back(s2);
            if(s1.length()!= s2.length()){
                break;
            }
            else{
                if(isanagram(s1,s2)){
                    ans1.push_back(s2);
                }
                
            }
        }
        ans.push_back(ans1);
    }
    return ans;
}

// GROUP ANAGRAM (#49)
 vector<vector<string>> groupAnagrams(vector<string>& strs){
    vector<vector<string>> ans;

    // for escaping repeating elements checking 
    unordered_map<string,int> mp1;

    for(int i=0;i<strs.size();i++){
        string s1= strs[i];
        if(mp1[s1]==0){
            vector<string> ans1;
            ans1.push_back(s1);
            mp1[s1]++;
            for(int j=i+1;j<strs.size();j++){
                string s2= strs[j];
                if(isanagram(s1,s2)){
                    ans1.push_back(s2);
                    mp1[s2]++;
                }
            }
            
            ans.push_back(ans1);
        }
        
    }
    return ans;

 }

 // optimised approach 
 vector<vector<string>> groupAnagrams(vector<string>& strs){
    vector<vector<string>> ans;
    unordered_map<string,vector<string>> mp;

    for(int i=0;i<strs.size();i++){
        string key = strs[i];
        sort(key.begin(),key.end());
        mp[key].push_back(strs[i]);
    }

    for(auto i:mp){
        ans.push_back(i.second);
    }

    return ans;
 }

 // first uinque character in strign (#387)
 int firstUniqChar(string s) {
        // unordered_map<pair<char,int>,int> mp;
        // for(int i=0;i<s.length();i++){
        //     mp.first[s[i]]++;
        //     mp.first.second.push(i);
        // }
        unordered_map<char,pair<int,int>>mp1;
        // char, pair(index,freq)
        for(int i=0;i<s.length();i++){
            mp1[s[i]].first= i;
            mp1[s[i]].second++;
        }

        // for(auto i:mp){
        //     if(i.second ==0){
        //         return i.first.second;
        //     }
        // }
        for(auto i:mp1){
            if(i.second.second ==0){
                return i.second.first;
            }
        }

    return -1;
        
    }

    //
    //4SUM II (#454)

    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

    unordered_map<int,int> mp;
    int ans=0;
    
    for(int i:nums1){
        for(int j:nums2){
            mp[i+j]++;
        }
    }

    for(int i:nums3){
        for(int j:nums4){
            int complement = -(i+j);
            auto it = mp.find(complement);
            if(it != mp.end()){
                ans+=it->second;
            }
            }
        }
    
    return ans;
        
    }



int main(){
    
}