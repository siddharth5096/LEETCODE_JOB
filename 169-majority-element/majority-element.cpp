class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        int i, candidates = -1, votes = 0;
        for (i = 0; i < n; i++) {
        if (votes == 0) {
            candidates = arr[i];
            votes = 1;
        }
        else {
            if (arr[i] == candidates)
                votes++;
            else
                votes--;
        }
    }
    return candidates;
    }
};