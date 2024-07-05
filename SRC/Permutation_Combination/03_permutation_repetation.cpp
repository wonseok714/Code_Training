/*
https://www.acmicpc.net/problem/15651
중복을 허용하는 순열조합

자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.

*/

#include <iostream>

using namespace std;
const int MAX_N = 8 + 2;
int N, M, ans[MAX_N] = {0,};
//bool visited[MAX_N] = {false,};

void DFS(int depth){
    if(depth == M){
        for(int i = 0 ; i < M; i++)
            printf("%d ", ans[i]);
        printf("\n");
        return;
    }
    for(int i = 0 ; i < N; i++){
        //visited[i] = true;
        ans[depth] = i + 1;
        DFS(depth+1);
        //visited[i] = false;
        //ans[depth] = 0;
    }
}
int main(){
    scanf("%d %d", &N, &M);
    DFS(0);
    return 0;
}