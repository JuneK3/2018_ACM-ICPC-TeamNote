// 인접행렬 O(V^2)
// 인접리스트 O(V+E)

// 인접리스트를 이용한 구현
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> a[]; // 정점간 간선 저장
bool check[]; // 방문한 정점 체크

void bfs(int start) {
    queue<int> q;
    check[start] = true;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        printf("%d ",node); // 방문정점 출력
        for (int i=0; i<a[node].size(); i++) {
            int next = a[node][i];
            if (check[next] == false) {
                check[next] = true;
                q.push(next);
            }
        }
    }
}