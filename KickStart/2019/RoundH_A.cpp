/**
计算H
一开始用multiset排序做
仔细分析了一下没那么复杂,用一个最大堆维护前H个最大值就行了(因为每次状态转移最多+1)
纪念一下kickstart第一个完全通过的题。。
感谢leetcode ！
**/

#include<iostream>
#include<vector>
#include <queue>

using namespace std;

int main()
{
    int T, n, h, t;
    cin >> T;
    t = 1;
    while(t <= T)
    {
        cout << "Case #" << t << ":";
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> pq;

        cin >> h;
        int curH = 1;
        pq.push(h);
        cout << " 1";

        for(int i = 1; i < n; i++)
        {
            cin >> h;
            if(h > curH && pq.top() > curH)
            {
                curH++;
                pq.push(h);
            }
            else
            {
                pq.push(h);
                pq.pop();
            }
            cout << " " << curH;
        }
        cout << endl;
        t++;
    }
}
