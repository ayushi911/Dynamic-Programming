#include<bits/stdc++.h>
using nampespace std;
int lcs(string x, string y, int n, int m){
  if(n==0 || m==0)
  return 0;
  if(x[n-1]==y[m-1])
    return 1+lcs(x,y,n-1,m-1);
  else
    return max(lcs(x,y,n,m-1),lcs(x,y,n-1,m));
}
int main(){
  string x,y;
  cin>>x;
  cin>>y;
  int n=x.length();
  int m=y.length();
  cout<<lcs(x,y,n,m)<<endl;
  return 0;
}
