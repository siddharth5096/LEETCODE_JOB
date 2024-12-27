class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int nthSuperUglyNumber(int n, vector<int>& p) {
        long long t[n+1];
        int m = p.size();
        long long _nxt[m];
        int ind[m];
        for(int i=0;i<m;i++)
        {
            _nxt[i] = p[i];
            ind[i] = 0;
        }
        t[0] = 1;
        long long nxt = 1;
        for(int i=1;i<n;i++)
        {
            nxt = INT_MAX;
            for(int j=0;j<m;j++)
                nxt = min(nxt, _nxt[j]);
            t[i] = nxt;
            for(int j=0;j<m;j++)
            {
                if(nxt == _nxt[j])
                {
                    ind[j]++;
                    _nxt[j] = t[ind[j]] * p[j];
                }
            }
        }
        return nxt;
    }
};