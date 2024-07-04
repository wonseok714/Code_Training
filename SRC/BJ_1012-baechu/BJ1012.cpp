#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<pair<int,int>> q;
int N,M,K; // 가로, 세로, 배추갯수
bool visited[51][51];
int baechu[51][51];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void clear(){
    N = 0;
    M = 0;
    K = 0;
    memset(baechu, 0, sizeof(baechu));
    memset(visited, false, sizeof(visited));
}

bool in_range(int x, int y)
{
    return (x >= 0 && x < M && y >= 0 && y < N);
}

void BFS(int x, int y){
    q.push(std::pair<int,int>(x,y));
    visited[x][y] = true;
    baechu[x][y] = 0;

    while(!q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for(int i =0; i <4; i++){
            int ax = xx + dx[i];
            int ay = yy + dy[i];
            if (in_range(ax,ay) && !visited[ax][ay] && baechu[ax][ax] != 0){

                q.push(std::pair<int,int>(ax,ay));
                visited[ax][ay] = true;
                baechu[ax][ay] = 0;

            }
            
        }
        
    }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    for (int test_case = 0; test_case<TC; ++test_case){

        clear();

        cin >> M >> N >> K;
        for (int j = 0; j<K;j++){
            int x, y;
            cin >> x >> y;
            baechu[x][y] = 1;
        }
        int num = 0;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (baechu[i][j] == 1)
                {

                    BFS(i, j);
                    num++;
   
                }
            }
        }
        cout << num << '\n';

    }
    return 0;
}
/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int map[51][51];
int dx[4] = { 1,-1,0,0};
int dy[4] = { 0,0,1,-1 };
int M, N, K; // 가로, 세로, 배추 수
int T, u, v;
int earthworm;
queue<pair<int,int>> q;

void BFS(int x, int y)
{
	map[x][y] = 0;

	q.push(pair<int, int>(x, y));

	while (!q.empty())
	{
		int now_x = q.front().first;
		int now_y = q.front().second;
		
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];
			if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M)
			{
				if (map[next_x][next_y] == 1)
				{
					map[next_x][next_y] = 0;
					q.push(pair<int, int>(next_x, next_y));
				}
			}
		}
	}
	earthworm++; 
}

int main() 
{
	ios::sync_with_stdio(0); 
	cin.tie(0); 

	cin >> T;

	while (T--)
	{
		// 맵 초기화
		for (int i = 0; i < 50; i++)
			for (int j = 0; j < 50; j++)
				map[i][j] = 0;

		earthworm = 0;

		cin >> M >> N >> K;

		for (int i = 0; i < K; i++)
		{
			cin >> u >> v;
			map[v][u] = 1;
		}

		for (int i = 0; i < 50; i++)
			for (int j = 0; j < 50; j++)
			{
				if (map[i][j] == 1) BFS(i, j);
			}

		cout << earthworm << '\n';

	}
    return 0;\\wsl.localhost\Ubuntu-24.04\home\wonseok_main\Project\Practice
}
*/