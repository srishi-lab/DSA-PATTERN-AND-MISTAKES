#include<iostream>
using namespace std;

// POW(X,N) (#50)
// double myPow(double x, int n) {

// }

// normal 
// double mypow(double x,int n){
//     // base case
//     if(n==0){
//         return 1;
//     }
//     if(n>0){
//         return x*mypow(x,n-1);
//     }
//     else{
//         return 1/(x*mypow(x,abs(n)-1));
//     }
// } // approach is good but tc is too high means recursive calls are to high

// /// binary exponentitation approach
// int mypow(int x,int n){
//     // base case
//     if(n==1){
//         return x;
//     }

//     if(n%2==0){
//         //even
//         return mypow(x,n/2)*mypow(x,n/2);
//     }
//     else{
//         //odd
//         return x*mypow(x,n/2)*mypow(x,n/2);
//     }
// }


// class Solution {
// public:
//     double myPow(double x, int n) {
//         // base case
//         if(n==1){
//             return x;
//         }

//         if(n>0){
//             if(n%2==0){
//                 // even
//                 return myPow(x,n/2)*myPow(x,n/2);
//             }
//             else{
//                 return x*myPow(x,n/2)*myPow(x,n/2);
//             }
//         }
//         else{
//             if(n%2==0){
//                 // even
//                 return 1/(myPow(x,abs(n)/2)*myPow(x,abs(n)/2));
//             }
//             else{
//                 return 1/(x*myPow(x,abs(n)/2)*myPow(x,abs(n)/2));
//             }

//         }
        
//     }
// };

// // UPDATED VERSION 
//  long double myPow1(long double x, long long n) {
//         // base case
//         if(n==0){
//             return 1.0L;
//         }
//         if(n==1){
//             return x;
//         }

//       long double half =myPow1(x,n/2);

//             if(n%2==0){
//                    return half*half;
//             }
//                 return half*half*x;
//             }


//         double myPow(double x, int n){
//             long long N= n; 
// // long long used here coz if n is -ve then its +ve will go beyong int bits so ll will use here
//             long double X= x;
//             if(N<0){
//                 X= 1.0L/X;
//                 N=-N;
//             }
//             return static_cast<double> (myPow1(X,N));
//         } 
    
        
string ksymbol(string ans,int n){
            // base case
            if(n==0){
                string s1= "01";
                return s1;
            }
            if(n==1){
                string s2= "10";
                return s2;
            }

            return ans+ ksymbol(ans,n-1);
        }


// kth symbol in grammar
string kgramm(string a,int n){
    // base case
    if(n==1){
        return a;
    }
    int i=0; 
    int n1= a.length();
    string nextstr ="";
    while(n1--){
        if(a[i]=='0'){
            nextstr+="01";
        }
        else{
            nextstr+="10";
        }
        i++;
    }
    return kgramm(nextstr,n-1);
    }


int kthGrammar(int n, int k){
    string ans= kgramm("0",n);
    return ans[k-1]-'0';

}

class Solution {
    private: 
    string kgramm(string a, int n){
        // base case
        if(n==1){
            return a;
        }
        int i=0;
        int n1= a.length();
        string newstr ="";
        while( n1--){
            if(a[i]=='0'){
                newstr+="01";
            }
            else{
                newstr+="10";
            }
            i++;
        }
        return kgramm(newstr,n-1);
    }
public:
    int kthGrammar(int n, int k) {
        string ans= kgramm("0",n);
        return ans[k-1]-'0';
        
    }
};


class Solution {
private:
    int solve(int n, int k) {

        // Base case
        if(n == 1) {
            return 0;
        }

    // Calculate midpoint
        int mid = 1<<(n-2);

        // First half
        if(k <= mid) {
            return solve(n-1, k);
        }

        // Second half
        else {
            // Complete this line
            k=k-mid;
            return 1- solve(n-1,k);
        }
    }

public:
    int kthGrammar(int n, int k) {
        return solve(n, k);
    }
};


// 1432 easy count step in making number to zero
class Solution {
     int countstep(int count,int num){
        // base case
        if(num==0){
            return count;
        }

        if(num %2==0){
            num = num/2;
            return countstep(count+1,num);
        }
        else{
            num =num-1;
            return countstep(count+1,num);
        }
     }
public:
    int numberOfSteps(int num) {
        int ans = countstep(0,num);
        return ans;

        
    }
};

// optimised version clean code 
class Solution {
     int countstep(int num){
        // base case
        if(num==0){
            return 0;
        }

        if(num %2==0){
          
            return 1+ countstep(num/2);
        }
        else{
            
            return 1+ countstep(num-1);
        }
     }
public:
    int numberOfSteps(int num) {
       return countstep(num);

        
    }
};
 
int main(){
    // cout<<mypow(2.00000,10);
    // cout<<mypow(2,10);
    cout<<ksymbol(" ",2);


}