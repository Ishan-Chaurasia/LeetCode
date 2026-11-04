class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0;
        int mx = INT_MIN;
        for(int ele : nums) {
            if(ele > mx) mx = max(mx,ele);
        }
        for(int i=0; i<nums.size(); i++) {
           if(nums[i] < mx){
            moves += mx - nums[i];
           }
        }
        return moves;
    }
};