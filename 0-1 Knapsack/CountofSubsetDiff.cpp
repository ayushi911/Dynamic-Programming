/* arr[] = {1,1,2,3} diff=1 so o/p=3 as the pairs of subset will be [({1,3},{1,2}), ({1,3},{1,2}), ({1,1,2},{3})]*/

#include<bits/stdc++.h>
using namespace std;

int countSubstDiff(vector<int> v, int diff){
    int n = v.size();
    int range=0;
    for(int i=0;i<n;++i)
        range+=v[i];
    int sub = (diff + range)/2;
    int dp[n+1][sub+1];
    for(int i=0;i<n+1;++i){
        for(int j=0;j<sub+1;++j){
            if(i==0)
                dp[i][j]=0;
            if(j==0)
                dp[i][j]=1;
        }
    }
    for(int i=1;i< n+1;++i){
        for(int j=1;j<sub+1;++j){
            if(v[i-1]<=j)
                dp[i][j]= dp[i-1][j-v[i-1]] + dp[i-1][j];
            else    
                dp[i][j]= dp[i-1][j];
        }
    }

    return dp[n][sub];
}

int main(){
    int n,x,diff;
    vector<int> v;
    cin>>n>>diff;
    for(int i=0;i<n;++i){
        cin>>x;
        v.push_back(x);
    }
    int res = countSubstDiff(v,diff);
    cout<<res<<endl;
    return 0;
}