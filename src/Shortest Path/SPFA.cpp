// 벨만포드의 성능을 향상시킨 알고리즘
// 최악의 경우는 벨만포드의 시간복잡도와 같지만 평균적으로는 O(E)이다
// 벨만포드의 아이디어와 같은 아이디어이다

// 벨만포드는 모든 간선에 대해서 업데이트를 진행하고
// SPFA는 바뀐 정점(큐를 이용해 관리)과 연결된 간선에 대해서만 업데이트를 진행한다
// 따라서 인접리스트의 구현이 필요하다
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// 간선 구조체
struct Edge {
    int to, cost;
    Edge(int to, int cost) : to(to), cost(cost) {
    }
};
vector<Edge> a[];
const int inf = 1000000000;
int d[]; // 시작점에서부터의 최단거리 저장
bool c[]; // 해당정점이 큐에 들어있으면 true, 아니면 false
int cnt[]; // 벨만포드 코드의 음수사이클 검사기능을 위해 해당정점에서의 최단거리 갱신 횟수를 저장
int main() {
    int n, m; // 정점개수 n, 간선정보 개수 m
    scanf("%d %d",&n,&m);
    // 간선정보 입력
    for (int i=0; i<m; i++) {
        int from, to, cost;
        scanf("%d %d %d",&from, &to, &cost);
        a[from].push_back(Edge(to,cost));
    }
    // 벨만포드와 마찬가지로 처음에는 모두 무한대로 초기화
    for (int i=1; i<=n; i++) {
        d[i] = inf;
    }
    d[1] = 0; // 시작점에의 최단거리를 0으로 저장
    queue<int> q;
    q.push(1); // 시작점을 큐에 push
    c[1] = true; // 시작점이 큐에 들어있으므로 true
    while (!q.empty()) {
        int from = q.front();
        c[from] = false; // 큐에서 pop하므로 false
        q.pop();
        for (Edge &e : a[from]) {
            int to = e.to; // 다음정점 저장
            int cost = e.cost; // 가중치 저장
            // 최단거리 갱신
            if (d[to] > d[from] + cost) {
                d[to] = d[from] + cost;
                // 다음정점이 큐에 들어있지 않다면
                if (c[to] == false) {
                    q.push(to);
                    c[to] = true;
                    cnt[to] += 1; // 갱신횟수 저장
                    // 갱신횟수가 정점개수 n이상이면 음수사이클 존재
                    if (cnt[to] >= n) {
                        printf("-1\n");
                        return 0;
                    }
                }
            }
        }
    }
    for (int i=2; i<=n; i++) {
        if (d[i] == inf) {
            printf("-1\n");
        } else {
            printf("%d\n",d[i]);
        }
    }
    return 0;
}
