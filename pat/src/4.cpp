#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int maxn, mind = 0x3f3f3f3f;
int n;

void dfs(priority_queue<int> qmax, priority_queue<int, vector<int>, greater<int>> qmin)
{
    int t = qmax.top();
    qmax.pop();
    for (int i = t / 3; (i << 1) <= t; i++)
    {
        int j = t - i;

        if ((i << 1) <= j || qmax.size() && (i << 1) <= qmax.top())
            continue;

        auto qmax1 = qmax;
        auto qmin1 = qmin;
        qmax1.push(i), qmax1.push(j);
        qmin1.push(i);
        dfs(qmax1, qmin1);
    }

    if(maxn < qmax.size() + 1)
        maxn = qmax.size() + 1, mind = t - qmin.top();
    else if( maxn == qmax.size() + 1)
        if(t - qmin.top() < mind)
            mind = t - qmin.top();
}

int main()
{
    cin >> n;
    priority_queue<int> qmax;
    priority_queue<int, vector<int>, greater<int>> qmin;
    qmax.push(n), qmin.push(n);
    dfs(qmax, qmin);

    cout << maxn << ' ' << mind;

    return 0;
}