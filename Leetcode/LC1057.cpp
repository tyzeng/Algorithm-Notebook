//校园自行车分配

class Solution {
public:
static bool comp(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b)
{
    if(a.first != b.first)
        return a.first < b.first;
    else
    {
        if(a.second.first != b.second.first)
            return a.second.first < b.second.first;
        else
            return a.second.second <= b.second.second;
    }
}

vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
     vector< pair<int, pair<int, int>> > dist;
    int n_workers = workers.size();
    int n_bikes = bikes.size();
    vector<bool> vis_w(n_workers, false); //初始化全为false
    vector<bool> vis_b(n_bikes, false);
    vector<int> res(n_workers);

    for(int i = 0; i < n_workers; i++)
        for(int j = 0; j < n_bikes; j++)
        {
            int d = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
            dist.push_back({d,{i,j}});
        }
    sort(dist.begin(), dist.end(), comp);
    int ans = 0;
    for(auto it = dist.begin(); it != dist.end(); it++)
    {
        int w = it->second.first;
        int b = it->second.second;
        if(vis_w[w] || vis_b[b]) //已经匹配过了
            continue;
        res[w] = b;
        vis_b[b] = true;
        vis_w[w] = true;
        ans ++;
        if(ans == n_workers)
            break;
    }
    return res;
}

};
