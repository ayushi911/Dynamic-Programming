#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[], int wt[], int W, int n){
    if(W==0 || n==0)
        return 0;

    if(wt[n-1]<=W)
        return max(val[n-1]+knapsack(val,wt,W-wt[n-1],n-1), knapsack(val,wt,W,n-1));
    else if (wt[n-1]> W)
        return knapsack(val,wt,W,n-1);
}

int main(){
    int val[]={1,2,5,7,100};
    int wt[]={3,4,8,9,10};
    int W=10, n=5;
    int j= knapsack(val,wt,W,n);
    cout<<j;
    return 0;
} 
