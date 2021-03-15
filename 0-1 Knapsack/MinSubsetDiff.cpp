/*arr[]={1,2,7} so two subsets {1,2} and {7} diff->7-3=4*/

#include<bits/stdc++.h>
using namespace std;

vector<int> minSubsetDiff(vector<int> v){
    int n =v.size();
    int range=0;
    for(int i=0; i< n;++i)
        range+=v[i];
    bool dp[n+1][range +1];
    for(int i=0; i<n+1;++i){
for(int j=0;j<range+1;++j){
    if(i==0)
        dp[i][j]=false;
    if(j==0)
        dp[i][j]=true;
}
}
for(int i=1;i<n+1;++i){
    for(int j=0;j<range+1;++j){
        if(v[i-1]<=j)
            dp[i][j]=dp[i-1][j-v[i-1]] || dp[i-1][j];
        else    
            dp[i][j]=dp[i-1][j];
    }
}
vector<int> res;
for(int i=0;i<int(range/2)+1;++i){
    if(dp[n][i]==true)
        res.push_back(i);
}
return res;
}

int main(){
    int n,x,range;
    range=0;
    cin>>n;
    vector<int> v,f;
    for(int i=0;i<n;++i){
        cin>>x;
        v.push_back(x);
        range+=x;
    }
    int mn=INT_MAX;
    f=minSubsetDiff(v);
    for(int i=0;i<f.size();++i){
        mn= min(mn, range - 2*f[i]);
    }
    cout<<mn<<endl;
    return 0;
}