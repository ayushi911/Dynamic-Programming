#include<bits/stdc++.h>
//#include<cstring>
using namespace std;

int knapsack(int val[], int wt[], int W, int n){
    int t[n+1][W+1];
     for(int i=0;i<n+1;++i){
        for(int j=0 ; j<W+1 ; ++j){
            if(i==0 || j==0)
                t[i][j]=0;
        }     
    }
    
     for(int i=1;i<n+1;++i){
        for(int j=1 ; j<W+1 ; ++j){
            if(wt[i-1]<=j)
                t[i][j] = max(val[i-1]+knapsack(val,wt,W-wt[i-1],n-1), knapsack(val,wt,W,n-1));
            else if (wt[n-1]> W)
                t[i][j] = knapsack(val,wt,W,n-1);
        }     
    }
return t[n][W];
}

int main(){
    //memset(t,-1 , sizeof(t));
    int val[]={27,10,20,41};
    int wt[]={9,10,2,1};
    int W=10, n=4;
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