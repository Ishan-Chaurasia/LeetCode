class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0, j=0, flips=0, k=1;
        int MaxLen = INT_MIN;
        int len=0;
        int n = nums.size();
         
        while(j<n) {
            if(nums[j] == 1) j++;
            else {
                if(flips < k) {
                    flips++;
                    j++;
                }
                else {
                    len = j-i;
                    MaxLen = max(MaxLen, len);
                    while(nums[i] == 1) i++;
                    i++;
                    j++;
                }
            }
        }
        len = j-i;
        MaxLen = max(MaxLen, len);
        return MaxLen-1;
    }
};