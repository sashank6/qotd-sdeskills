class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        vector<vector<int> > result;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int target = -nums[i];
            int f=i+1;
            int r=nums.size()-1;
            while(f<r){
                int value = nums[f]+nums[r];
                if(value==target){
                    result.push_back(vector<int>{-target,nums[f],nums[r]});
                    f++;
                    while(f<r && nums[f]==nums[f-1]) f++;
                    r--;
                    while(f<r && nums[r]==nums[r+1]) r--;
                }
                else
                if(value<target){
                    f++;
                }
                else{
                    r--;
                }
            }
        }
        
      return result; 
        
    }
};
