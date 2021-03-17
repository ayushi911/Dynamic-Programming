class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int range=0;
        for(int i=0;i<n;++i)
            range+=nums[i];
        int sub = (S+range)/2;
        if(range<S)
            return 0;
        if(range==S)
            if(find(nums.begin(),nums.end(),0)==nums.end())
                return 1;
            else{
                int cz=0;
                for(int i=0;i<n;++i){
                    if(nums[i]==0)
                        cz++;
                }
                return pow(2,cz);
            }
        int dp[n+1][sub+1];
        for(int i=0;i<n+1;++i){
            for(int j=0;j<sub+1;++j){
                if(i==0)
                    dp[i][j]=0;
                if(j==0)
                    dp[i][j]=1;
            }
        }
        for(int i=1;i<n+1;++i){
            for(int j=1;j<sub+1;++j){
                if(nums[i-1]<=j)
                    dp[i][j]= dp[i-1][j] + dp[i-1][j-nums[i-1]];
                else
                    dp[i][j]= dp[i-1][j];
            }
        }
        return dp[n][sub];
    }
};
