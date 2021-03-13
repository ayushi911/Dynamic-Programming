#include<bits/stdc++.h>
//#include<cstring>
using namespace std;

int t[100][100];

int knapsack(int val[], int wt[], int W, int n){
    if(W==0 || n==0)
        return 0;
    if(t[n][W]!=-1)
        return t[n][W];
    if(wt[n-1]<=W)
        return t[n][W] = max(val[n-1]+knapsack(val,wt,W-wt[n-1],n-1), knapsack(val,wt,W,n-1));
    else if (wt[n-1]> W)
        return t[n][W] = knapsack(val,wt,W,n-1);
}

int main(){
    memset(t,-1 , sizeof(t));
    int val[]={1,2,5,7,100};
    int wt[]={3,4,8,9,10};
    int W=10, n=5;
    int j= knapsack(val,wt,W,n);
    // for(int i=0;i<n+2;++i){
    //     for(int j=0;j<W+2;++j){
    //         cout<<t[i][j]<<" ";

    //     }
    //     cout<<endl;
    // }
    cout<<j;
    return 0;
} 
