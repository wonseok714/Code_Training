#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int used[2][1001];
vector<vector<int>> alist(1001);
int V, E, start;

void BFS(int start){
	queue<int> q;
	q.push(start);
	used[0][start] = true;
	
	while (!q.empty()){
		int now = q.front();
		q.pop();
		
		cout << now << ' '; //경로 출력
		
		for (int i =0 ; i<alist[now].size();++i){
			int next = alist[now][i];
			
			if (used[0][next]) continue;
			
			q.push(next);
			used[0][next] = true;
		}
	}
	
}

void DFS(int now){
	if (used[1][now]) return;
	used[1][now] = true;
	cout << now << ' ';
	
	for (int i = 0; i<alist[now].size();++i){
		int next = alist[now][i];
		DFS(next);
		
	}
	return;
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//freopen("input.txt","r",stdin);
	int u, v;
	cin >> V >> E >> start;
	
	for (int i = 0; i <E ; ++i){
		cin >> u >> v;
		alist[u].push_back(v);
		alist[v].push_back(u);
	}
	
	for (int i =1; i<=V; ++i){
		if (1<alist[i].size())
		sort(alist[i].begin(), alist[i].end());
	}
	
	DFS(start);
	cout << '\n';
	BFS(start);

    
    return 0;

}
