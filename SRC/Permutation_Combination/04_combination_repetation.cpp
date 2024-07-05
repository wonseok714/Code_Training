/*
https://www.acmicpc.net/problem/15652
중복을 허용하는 조합문제
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
고른 수열은 비내림차순이어야 한다.
길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.

*/

#include <iostream>
using namespace std;
const int MAX_N = 8 + 2;
int N, M, ans[MAX_N];

void DFS(int idx, int depth){
    if( depth == M){
        for(int i = 0 ; i < M; i++)
            printf("%d ", ans[i]);
        printf("\n");
        return;
    }
    for(int i = idx; i < N; i++){
        //visited[i] = true;
        ans[depth] = i + 1;
        DFS(i, depth + 1);
        //ans[depth ] = 0;
        //visited[i] = false;
        ans[depth] = 0;
        
    }
}

int main(){
    scanf("%d %d", &N, &M);
    DFS(0,0);
    return 0;
}