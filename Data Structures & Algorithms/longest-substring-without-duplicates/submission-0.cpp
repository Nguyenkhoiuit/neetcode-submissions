#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> char_set;
        int l=0;
        int res=0;
        for(int r=0;r<s.length();r++){
            while(char_set.find(s[r])!= char_set.end()){
                char_set.erase(s[l]);
                l++;
            }
            char_set.insert(s[r]);
            res=max(res,r-l+1);
        }
        return res;
    }
};
