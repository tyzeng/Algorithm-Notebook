//后面的车永远不会超过前面的车

class Solution {
    static bool comp(const pair<int,double>& a, const pair<int,double>& b)
    {
        return a.first > b.first;
    }
public:
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> val;
        for(int i = 0; i < n; i++)
        {
            double time = (target - position[i]) * 1.0 / speed[i];
            val.push_back({position[i], time});
        }
        sort(val.begin(),val.end(),comp);

        int queueNum = n;
        for(int i = 1;i < n; i++)
        {
            if(val[i].second <= val[i-1].second)
            {
                // cout<<i<<endl;
                val[i] = make_pair(val[i].first,val[i-1].second);
                queueNum--;
            }
        }
        return queueNum;      
    }
};
