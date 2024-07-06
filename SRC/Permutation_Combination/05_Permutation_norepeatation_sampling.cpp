/*
https://www.acmicpc.net/problem/15654

중복을 허락하지 않는 순열조합(임의의 데이터 M개 선택)
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. N개의 자연수는 모두 다른 수이다.

N개의 자연수 중에서 M개를 고른 수열

*/

#include <iostream>

using namespace std;

const int MAX_N = 8 + 2;

int N, M;
int ans[MAX_N] = {0,}, arr[MAX_N] = {0,}, trr[MAX_N] = {0,};
bool visited[MAX_N] = {false,};

void mergeSort(int start, int end){
    // 0. base condition
    if(start >= end) return;
    // 1. devided
    int mid = (start + end) / 2;

    // 2. conquer
    mergeSort(start, mid);
    mergeSort(mid+1, end);

    // 3. Merge
    int i = start, j = mid + 1, k = start;
    while( i <= mid && j <= end){
        if(arr[i] < arr[j])
            trr[k++] = arr[i++];
        else 
            trr[k++] = arr[j++];
    }
    while (i <= mid) trr[k++] = arr[i++];
    while (j <= end) trr[k++] = arr[j++];

    // 4. Copy
    for(i = start; i <=end; i++)
        arr[i] = trr[i];

}

void DFS(int depth){
    if(depth == M){
        for(int i = 0 ; i < M; i++)
            printf("%d ", ans[i]);
        printf("\n");
        return;
    }

    for(int i = 0 ; i < N; i++){
        if(visited[i]) continue;
        visited[i] = true;
        ans[depth] = arr[i];
        DFS(depth + 1);
        visited[i] = false;
    }
}


int main(){

    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N; i++)
        scanf("%d", &arr[i]);
    mergeSort(0,N - 1);
    DFS(0);

    return 0;
}

