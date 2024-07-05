
/*
https://www.acmicpc.net/problem/15649
중복을 허용하지 않는 순열의 기본 형태, 
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

*/

#include <iostream>

using namespace std;

const int MAX_N = 8+2;
int N, M, ans[MAX_N];
bool visited[MAX_N];

void DFS(int depth){
    if(depth == M){
        for (int i = 0; i < M; i++)
            printf("%d ", ans[i]);
        printf("\n");
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if(visited[i]) continue;
        visited[i] = true;
        ans[depth] = i + 1;
        DFS(depth + 1);
        visited[i] = false;
    }
}

int main(){
    scanf("%d %d", &N, &M);
    DFS(0);
    return 0;
}