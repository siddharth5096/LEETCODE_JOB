class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> lis(n, 1), parent(n, -1);

        int lisLen = 1, lisEnd = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (groups[i] != groups[j] && words[i].size() == words[j].size() && hammingDistance(words[i], words[j]) == 1 && lis[i] + 1 > lis[j])
                    {
                    lis[j] = lis[i] + 1;
                    parent[j] = i;
                    if (lis[j] > lisLen) {
                        lisLen = lis[j];
                        lisEnd = j;
                    }
                }
            }
        }

        // reconstruct subsequence
        vector<string> ans;
        for (int cur = lisEnd; cur != -1; cur = parent[cur])
        ans.push_back(words[cur]);
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int hammingDistance(const string &a, const string &b) 
    {
        int hd = 0;
        for (int i = 0, n = a.size(); i < n; i++)
        {
            if (a[i] != b[i])
            {
                hd++;
            }
        }
        return hd;
    }
};