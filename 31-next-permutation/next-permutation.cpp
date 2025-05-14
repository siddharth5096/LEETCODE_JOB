class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakPoint = -1;

        // Step 1: Find the first index from the end where nums[i - 1] < nums[i]
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                breakPoint = i - 1;
                break;
            }
        }

        // Step 2: If no such index exists, reverse the whole array
        if (breakPoint == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the smallest number > nums[breakPoint] to the right
        for (int i = n - 1; i > breakPoint; i--) {
            if (nums[i] > nums[breakPoint]) {
                swap(nums[i], nums[breakPoint]);
                break;
            }
        }

        // Step 4: Reverse the suffix after breakPoint
        reverse(nums.begin() + breakPoint + 1, nums.end());
    }
};
