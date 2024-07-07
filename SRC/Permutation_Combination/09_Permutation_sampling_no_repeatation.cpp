/*
https://www.acmicpc.net/problem/15663
샘플의 중복이 있는데 중복을 허용하지 않는 경우

N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

N개의 자연수 중에서 M개를 고른 수열
*/


#include <iostream>
using namespace std;

const int MAX_N = 8+2;
int N, M, ans[MAX_N], trr[MAX_N], arr[MAX_N];
bool visited[MAX_N];

void mergeSort(int start, int end){
    // 0. base condition
    if(start >= end) return;
    
    // 1. Divided
    int mid = (start + end) / 2;
    
    //2. Conquer
    mergeSort(start, mid);
    mergeSort(mid + 1, end);

    // 3. merge
    int i = start, j = mid +1, k = start;
    while( i <= start && j <= end){
        if(arr[i] < arr[j])
            trr[k++] = arr[i++];
        else
            trr[k++] = arr[j++];
    }
    while(i <= mid) trr[k++] = arr[i++];
    while(j <= end) trr[k++] = arr[j++];
    
    // 4. Copy
    for(int i = start; i <= end; i++)
        arr[i] = trr[i];
}

void DFS(int depth){
    if(depth == M){
        for(int i = 0 ; i < M; i++){
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;
    }
    // check previous selcted number
    int prev = -1;
    for(int i = 0; i < N; i++){
        if(visited[i]) continue;
        if(prev == arr[i]) continue;
        
        visited[i] = true;
        prev = ans[depth] = arr[i];
        DFS(depth + 1);
        visited[i] = false;        
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    mergeSort(0, N-1);
    DFS(0);
    return 0;
}