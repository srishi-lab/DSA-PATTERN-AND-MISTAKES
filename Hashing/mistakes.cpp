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

