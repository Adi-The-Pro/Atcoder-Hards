#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 998244353
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
//-------------------------------------------------------------------------//
int n{},k{}; 
string s{}; 
vector<vector<int>> dp;
int addChar(int mask, char a){
    int temp = mask;
    temp = temp<<1;
    if(a=='A') temp=temp+1;
    return temp;
}
bool isPalindrome(int mask){
    vector<int> v;
    for(int i{}; i<k; i++){
        if((mask&(1<<i))) v.push_back(1);
        else v.push_back(0);
    }
    int i{},j{k-1};
    while(i<=j){
        if(v[i]!=v[j]) return false;
        i++; j--;
    }
    return true;
}
int removeAndAdd(int mask, char a){
    int temp = mask;
    if((temp&(1<<k-1))) temp=temp^(1<<k-1);
    return addChar(temp,a);
}
int f(int ind, int mask){
    if(ind>=n){
        if(isPalindrome(mask)) return 0;
        else return 1;
    }
    int ans{};
    if(dp[ind][mask]!=-1) return dp[ind][mask];
    if(ind<k){
        if(s[ind]=='?'){
            ans = (ans + f(ind+1,addChar(mask,'A')))%MOD;
            ans = (ans + f(ind+1,addChar(mask,'B')))%MOD;
        }
        else{
            ans = f(ind+1,addChar(mask,s[ind]))%MOD;
        }
    }
    else{
        if(isPalindrome(mask)) return 0;
        
        if(s[ind]=='?'){
            ans = (ans + f(ind+1,removeAndAdd(mask,'A')))%MOD;
            ans = (ans + f(ind+1,removeAndAdd(mask,'B')))%MOD;
        }
        else{
            ans = f(ind+1,removeAndAdd(mask,s[ind]))%MOD;
        }
    }
    return dp[ind][mask] = ans;
}
void tarankaaa(){
    cin>>n>>k;
    cin>>s;
    dp.resize(n+1,vector<int>(1027,-1));
    int ans = f(0,0);
    cout<<ans<<endl;
}
//--------------------------------------------------------------------------//
int32_t main(){
#ifndef ONLINE_JUDGE
freopen("Error.txt", "w", stderr);
#endif    
#ifndef ONLINE_JUDGE
//for getting input from input.txt
freopen("input1.txt", "r", stdin);
//for writing output to output.txt
freopen("output.txt", "w", stdout);
#endif
    
    fastio();
    int t{1};
    while(t--){
        tarankaaa();
    }
}

