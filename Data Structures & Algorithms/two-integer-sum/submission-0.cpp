#include <vector>
#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std:unordered_map<int, int>seen;
        for(int j=0;j<nums.size();++j){
            int complement = target - nums[j];
            if(seen.find(complement)!=seen.end()){
                return {seen[complement],j};
            }
            seen[nums[j]]=j;
        }
        return {};
    }
};
