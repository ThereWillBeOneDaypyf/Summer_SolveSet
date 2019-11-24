#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 1; i < points.size(); i ++)
        {
            int x = points[i - 1][0];
            int y = points[i - 1][1];
            int tx = points[i][0];
            int ty = points[i][1];
            int del_x = tx - x;
            int del_y = ty - y;
            del_x = abs(del_x);
            del_y = abs(del_y);
            ans += max(del_x, del_y);
        }        
        return ans;
    }
};