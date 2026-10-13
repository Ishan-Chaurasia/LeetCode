class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int MaxLen = INT_MIN;
        int len = 0;
        int flips = 0, i = 0, j = 0;
        while(j < n) {
            if(nums[j] == 1) j++;
            else{
                if(flips < k) {
                    flips++;
                    j++;
                }
                else{
                    len = j - i;
                    MaxLen = max(MaxLen, len);
                    while(nums[i]==1) i++; // after this nums[i] = 0 always
                    i++;
                    j++;
                }
            }
        }
        len = j - i;
        MaxLen = max(MaxLen, len);
        return MaxLen;
    }
};