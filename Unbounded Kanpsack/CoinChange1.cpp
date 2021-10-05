#include<bits/stdc++.h>
using namespace std;

int coinchange1(vector<int> denom,int s,int n){
  //int n=denom.size();
  int dp[n+1][s+1];
  for(int i=0;i<n+1;++i){
    for(int j=0;j<s+1;++j){
      if(i==0) dp[i][j]=0;
      if(j==0) dp[i][j]=1;
    }
  }
  for(int i=1;i<n+1;++i){
    for(int j=1;j<s+1;++j){
      if(denom[i-1]<=j)
        dp[i][j]=dp[i-1][j]+dp[i][j-denom[i-1]];
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
//i/p
// 5 3
// 1 2 3

//o/p = 5
