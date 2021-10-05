//https://www.youtube.com/watch?v=I-l6PBeERuc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=17
#include<bits/stdc++.h>
using namespace std;

int coinchange1(vector<int> denom,int s,int n){
  //int n=denom.size();
  int dp[n+1][s+1];
  for(int i=0;i<n+1;++i){
    for(int j=0;j<s+1;++j){
      if(j==0) dp[i][j]=0;
      if(i==0) dp[i][j]=INT_MAX-1;
    }
  }
  for(int j=1;j<s+1;++j){
    if(j%denom[0]==0)
      dp[1][j]=j/denom[0];
    else
      dp[1][j]=INT_MAX-1;
  }
  for(int i=2;i<n+1;++i){
    for(int j=1;j<s+1;++j){
      if(denom[i-1]<=j)
        dp[i][j]=min(dp[i-1][j],1+dp[i][j-denom[i-1]]);
      else
        dp[i][j]=dp[i-1][j];
    }
  }
  return dp[n][s];
}

int main(){
  int s,n,x;
  cin>>s>>n;
  //s = sum and n = size of the array
  //denom = denomination array here in below example it is {1,2,3}
  vector<int>denom;
  for(int i=0;i<n;++i){
    cin>>x;
    denom.push_back(x);
  }
  cout<<coinchange1(denom,s,n)<<endl;
  return 0;
}
