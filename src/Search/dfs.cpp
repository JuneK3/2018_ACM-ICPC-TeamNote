// 인접행렬 O(V^2)
// 인접리스트 O(V+E)

// 인접리스트를 이용한 구현
// 재귀를 이용한 구현
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<int> a[]; // 정점간 간선 저장
bool check[]; // 방문한 정점 체크

void dfs(int node) {
    check[node] = true;
    // printf("%d ",node);
    for (int i=0; i<a[node].size(); i++) {
        int next = a[node][i];
        if (check[next] == false) {
            dfs(next);
        }
    }
}
// 스택을 이용한 비재귀 구현
void dfs(int node) {
    stack<pair<int,int>> s;
    s.push(make_pair(node,0));
    check[node] = true;
    printf("%d ",node); // 방문정점 출력
    while (!s.empty()) {
        int node = s.top().first;
        int start = s.top().second;
        s.pop();
        for (int i=start; i<a[node].size(); i++) {
            int next = a[node][i];
            if (check[next] == false) {
                printf("%d ",next);
                check[next] = true;
                s.push(make_pair(node,i+1));
                s.push(make_pair(next,0));
                break;
            }
        }
    }
}