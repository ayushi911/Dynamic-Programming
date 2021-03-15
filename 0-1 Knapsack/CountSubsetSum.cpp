/*arr[] = {1,2,3,5,6,8,10} sum=10, o/p=4*/
#include<bits/stdc++.h>
using namespace std;

int countsubset(vector<int> v, int sum){
int n = v.size();
int dp[n+1][sum+1];
for(int i=0;i<n+1;++i){
    for(int j=0;j<sum+1;++j){
        if(i==0)
            dp[i][j]=0;
        if(j==0)
            dp[i][j]=1;
    }
}

for(int i=1;i<n+1;++i){
    for(int j=1;j<sum+1;++j){
        if(v[i-1]<=j)
            dp[i][j]=dp[i-1][j-v[i-1]] + dp[i-1][j];
        else
            dp[i][j]=dp[i-1][j];
    }
}

return dp[n][sum];
}

int main(){
    vector<int> v;
    int n,x,sum;
    cin>>n>>sum;
    for(int i=0;i<n;++i){
        cin>>x;
        v.push_back(x);
    }
    cout<<countsubset(v,sum)<<endl;
    return 0;
}