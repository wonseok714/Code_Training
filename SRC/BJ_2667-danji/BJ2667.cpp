#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[26][26];
int house[26][26];
queue<pair<int,int>> q;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int N;
int total; // 총 단지의 수
int num; // 단지 내 집 수
vector<int> danji; // 단지의 벡터 어레이

bool in_range(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}

void BFS(int x, int y){
    
    q.push(std::pair<int,int>(x,y));
    visited[x][y] = true;
    num = 1;


    while(!q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for (int i = 0; i<4; ++i){
            int ax = xx+ dx[i];
            int ay = yy + dy[i];
            if (in_range(ax,ay) && !visited[ax][ay] && house[ax][ay] == '1'){
                visited[ax][ay] = true;
                num++;
                q.push(make_pair(ax,ay));

            }
        }

    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;

    cin >>N;
    total = 0;
    for (int i =0;i<N;++i) {
        cin >> s;
        for (int j = 0;j<N;++j){
            house[i][j] = s[j];
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (house[i][j] == '1' && !visited[i][j])
            {
 
                BFS(i, j);
                danji.push_back(num);
 
            }
        }
    }

    cout << danji.size() << '\n';
    sort(danji.begin(),danji.end());
    for (int i=0;i<danji.size();++i) cout << danji[i] <<'\n';

    return 0;
}