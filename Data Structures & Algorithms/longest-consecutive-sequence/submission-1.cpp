#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(),nums.end());
        int longest_sequences=0;
    for(int n : num_set){
        if(num_set.find(n-1)==num_set.end()){
            int length=1;
            while(num_set.find(n+length) != num_set.end()){
                length++;
            }
            longest_sequences=max(longest_sequences,length);
        }
    }
    return longest_sequences;
    }
};
