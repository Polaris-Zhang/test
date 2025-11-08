#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    for(int i = 0;i<n;i++){
        int x = nums[i];
        if(i > 0 && x == nums[i-1]) continue;
        if(x+nums[i+1]+nums[i+2] > 0) break;
        if(x+nums[n-1]+nums[n-2] < 0) continue;

        int y = i+1,z = n-1;
        while(y<z){
            int s = x+nums[y]+nums[z];
            if(s>0){
                z--;
            }
            else if(s<0){
                y++;
            }else{
                res.push_back({x, nums[y], nums[z]});
                for(y++; y<z && nums[y]==nums[y-1];y++) continue;
                for(z--; y<z && nums[z] == nums[z+1];z--) continue;
            }
        }

    }
    return res;
}

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    
    cout << "Three sum result:" << endl;
    for(auto& triplet : result){
        cout << "[";
        for(int i = 0; i < triplet.size(); i++){
            cout << triplet[i];
            if(i < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}