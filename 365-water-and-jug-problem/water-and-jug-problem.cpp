class Solution {
public:
    bool canMeasureWater(int x, int y, int t) {
        if(x>y)return canMeasureWater(y,x,t);
        queue<int> q;
        set<int> vis;
        q.push(y);vis.insert(y);
        while(!q.empty()) {
            int to = q.front();
            q.pop();
            if(to+x == t)return true;
            if(to == t)return true;
            if(to + x < y && vis.count(to + x)==0) {
                q.push(to+x);
                vis.insert(to+x);
            }
            if(to + x > y && vis.count(x + to - y)==0) {
                q.push(x + to - y);
                vis.insert(to+x-y);
            }
            if(to - x > 0 && vis.count(to - x)==0) {
                q.push(to-x);
                vis.insert(to-x);
            }
            if(to < x && vis.count(y + to - x)==0) {
                q.push(y + to - x);
                vis.insert(y + to - x);
            }
        }
        return false;
    }
};