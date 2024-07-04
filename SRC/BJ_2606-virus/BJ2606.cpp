#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visited[101];
vector<int> cpt[101];
queue<int> q;

void BFS(int start)
{
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < cpt[cur].size(); ++i)
        {
            if (visited[cpt[cur][i]])
                continue;
            q.push(cpt[cur][i]);
            visited[cpt[cur][i]] = true;
        }
    }
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i  = 0; i<m;++i){
        int a, b;
        cin >> a>> b;
        cpt[a].push_back(b);
        cpt[b].push_back(a);
    }
    BFS(1);
    int total =0;
    for (int j = 1;j<=n;++j)
        if (visited[j+1]) total++;
    cout << total << '\n';

    return 0;
}