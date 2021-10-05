#include<bits/stdc++.h>
using nampespace std;
int static dp[1001][1001];
int lcs(string x, string y, int n, int m){
  if(dp[n][m]!=-1)
     return dp[n][m];
  if(x[n-1]==y[m-1])
    return dp[n][m] = 1+lcs(x,y,n-1,m-1);
  else
    return dp[n][m]=max(lcs(x,y,n,m-1),lcs(x,y,n-1,m));
}
int main(){
  string x,y;
  cin>>x;
  cin>>y;
  int n=x.length();
  int m=y.length();
  memset(dp,-1,sizeof(dp));
  cout<<lcs(x,y,n,m)<<endl;
  return 0;
}
