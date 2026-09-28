#include <string>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";
        unordered_map<char,int> count_t;
        for(char c : t) count_t[c]++;
        unordered_map<char,int> window;
        int current=0, require=count_t.size();
        int min_length= INT_MAX;
        int start=-1;
        int l=0;
        for(int r=0;r<s.length();r++){
            char c=s[r];
            window[c]++;
            if(count_t.count(c) && window[c]==count_t[c]){
                current++;
            }
            while(current == require){
                if(r-l+1<min_length){
                    min_length=r-l+1;
                    start=l;
                }
                char left_char=s[l];
                window[left_char]--;
                if(count_t.count(left_char)&& window[left_char]<count_t[left_char]){
                    current--;
                }
                l++;
            }
        }
        return min_length==INT_MAX ? "" : s.substr(start,min_length);
    }
};
