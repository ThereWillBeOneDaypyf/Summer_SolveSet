#include <bits/stdc++.h>
using namespace std;
class Solution {
    map<int, int> row;
    map<int, int> col;
public:
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0;i < grid.size(); i ++)
        {
            for(int j = 0;j < grid[i].size(); j ++) 
            {
                if(grid[i][j])
                    row[i] ++, col[j] ++;
            }
        }
        for(int i = 0; i < grid.size(); i ++)
        {
            for(int j = 0;j < grid[i].size(); j ++)
            {
                if(grid[i][j])
                {
                    if(row[i] > 1 || col[j] > 1)
                        ans ++;
                }
            }
        }
        return ans;
    }
};