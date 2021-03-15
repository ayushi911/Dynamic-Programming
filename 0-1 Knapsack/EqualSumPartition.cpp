//arr[]={1,3,5,7,8} given array
// s=11 to find if a subset exits that has the same sum as the given value
/*to return the subset {3,8} as the sum is 11*/

#include<bits/stdc++.h>
using namespace std;

bool subsetsum(vector <int> v, int s){
    int n = v.size();
    bool dp[n+1][s+1];
    for(int i=0;i<n+1;++i){
        for(int j=0 ; j<s+1 ; ++j){
            if(i==0)
                dp[i][j]=false;
            if(j==0)
                dp[i][j]=true;
        }     
    }
    for(int i=1;i<n+1;++i){
        for(int j=1 ; j<s+1 ; ++j){
            if(v[i-1]<=j)
                dp[i][j]=dp[i-1][j-v[i-1]] || dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }     
    }

    // for(int i=0;i<n+1;++i){
    //     for(int j=0 ; j<s+1 ; ++j){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;     
    // }
    return dp[n][s];

}

int main(){
    vector<int> v;
    int n,x;
    int sum=0;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x;
         v.push_back(x);
         sum+=x;
    }
    if(sum%2!=0)
        cout<<"Equal Sum partition does not exist!!\n";
    else{
        if(subsetsum(v,sum/2)==1)
            cout<<"Equal sum partition subset exists!\n";
        else
            cout<<"Equal Sum partition does not exist!!\n";
    }
    return 0;
}