class Solution {
public:
    int minOperations(vector<int>& nums) {
        int fl = 0, cnt = 0, n = nums.size(), curr = 0; 
        vector<int> pre(n, 0);

        int size = 3; // can be variable

        for (int i = 0; i < n; i++) {
            if ((curr + nums[i] + pre[i]) % 2 == 0) {
                if (i >= n - (size - 1)) return -1;
                cnt++;
                pre[i]++;
                if (i + size < n) pre[i + size]--;
            }
            curr += pre[i];
        }
        return cnt;
    }
};