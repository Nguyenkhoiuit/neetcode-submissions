#include <iostream>
#include <vector>
#include <unordered_set>
class Solution {
private:

public:
    bool hasDuplicate(std::vector<int>& nums){
        std::unordered_set<int> seen;
        for (int x : nums){
            if(seen.find(x) != seen.end()){
                return true;
            }
            seen.insert(x);
        }
        return false;
    }
};