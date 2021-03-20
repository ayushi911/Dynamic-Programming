#include<bits/stdc++.h>
using namespace std;

int unbounded(vector<int> v, vector<int> val, int s){
    int n=v.size();
    int dp[n+1][s+1];
    for(int i=0;i<n+1;++i){
        for(int j=0;j<s+1;++j){
            if(i==0)
                dp[i][j]=0;
            if(j==0)
                dp[i][j]=0;
        }
    }
    for(int i=1;i<n+1;++i){
        for(int j=1;j<s+1;++j){
            if(v[i-1]<=j)
                dp[i][j]=max(val[i-1]+dp[i][j-v[i-1]], dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][s];
}

int main(){
    int n,x,s;
    cin>>n>>s;
    vector<int> v, val;
    for(int i=0;i<n;++i){
        cin>>x;
        v.push_back(x);
    }
     for(int i=0;i<n;++i){
        cin>>x;
        val.push_back(x);
    }
    //int val[]={27,10,20,41};
    //int v[]={9,10,2,1};
    //int s=10, n=4;
    cout<<unbounded(v,val,s)<<endl;
    return 0;
}

//input
/*
4 10
9 10 2 1
27 10 20 41

O/P= 410(that is "1" is taken 10 times to fill the knapsack)
*/
