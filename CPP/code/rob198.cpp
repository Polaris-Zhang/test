#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int rob(vector<int> &nums){
    int n = nums.size();
    if(n==0) return 0;
    vector<int> dp(n+1,0);
    dp[1] = nums[0];
    for(int k = 2;k<=n;k++){
        dp[k] = max(dp[k-1],dp[k-2]+nums[k-1]);
    }
    return dp[n];

}

int main(){
    vector<int> nums = {2,7,9,3,1};
    cout<<rob(nums)<<endl;
    return 0;
}