#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int m=nums1.size();
        int n=nums2.size();
        int total=m+n;
        int median=(total+1)/2;
        int l=0, r=m;
        while(l<=r){
            int i=(l+r)/2;
            int j=median-i;
            int a_left=(i>0) ? nums1[i-1] : INT_MIN;
            int a_right=(i<m) ? nums1[i] : INT_MAX;
            int b_left=(j>0) ? nums2[j-1] : INT_MIN;
            int b_right=(j<n) ? nums2[j] : INT_MAX;
            if(a_left<=b_right && b_left <= a_right){
                if(total % 2 != 0){
                    return max(a_left,b_left);
                }
                return (max(a_left,b_left)+min(a_right,b_right))/2.0;
            }
            else if(a_left>b_right){
                r=i-1;
            }
            else{
                l=i+1;
            }
        }
        return 0.0;
    }
};