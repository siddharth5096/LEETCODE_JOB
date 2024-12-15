class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int ele = -1;

        // First pass: Find a candidate for the majority element
        for (int i = 0; i < nums.size(); i++) {
            switch (cnt) {
                case 0:
                    ele = nums[i];
                    cnt = 1;
                    break;
                default:
                    cnt += (nums[i] == ele) ? 1 : -1;
                    break;
            }
        }
        return ele;
    }
};