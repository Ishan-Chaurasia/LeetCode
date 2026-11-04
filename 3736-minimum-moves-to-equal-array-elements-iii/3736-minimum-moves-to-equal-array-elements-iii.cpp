class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0;
        int mx = INT_MIN;
        int sum = 0;
        for(int ele : nums) {
            if(ele > mx) {
                mx = max(mx,ele);
            }
            sum += ele;
        }
        mx = mx*nums.size();
        return mx-sum;
    }
};