// 시간복잡도 O(VE)
// E<V^2이므로 최대 O(V^3)
// 시작점 1개
// 가중치가 음수인 경우에도 가용할 수 있다

// 음수사이클 검사기능
// 최단경로는 항상 최대 N-1(정점개수 N)개로 구성되어 있기 때문에
// N번째 단계에서 최단경로가 갱신되면, 음수로된 사이클이 존재하게 된다
#include <iostream>
#include <vector>
using namespace std;
// 간선 구조체
struct Edge {
    int from;
    int to;
    int cost;
};
int dist[]; // dist[i]:시작점에서 i로 가는 최단거리
int inf = 100000000;
int main() {
    int n,m; // 정점개수 n, 간선정보 개수 m
    scanf("%d %d",&n,&m);
    vector<Edge> a(m);
    // 간선정보 입력
    for (int i=0; i<m; i++) {
        scanf("%d %d %d",&a[i].from, &a[i].to, &a[i].cost);
    }
    // 처음에 모두 무한대로 초기화
    for (int i=1; i<=n; i++) {
        dist[i] = inf;
    }
    dist[1] = 0; // 정점1을 시작점으로 설정
    bool negative_cycle = false; // 음수 사이클 검사기능
    for (int i=1; i<=n; i++) {
        for (int j=0; j<m; j++) {
            int x = a[j].from;
            int y = a[j].to;
            int z = a[j].cost;
            // 최단경로 갱신
            if (dist[x] != inf && dist[y] > dist[x]+z) {
                dist[y] = dist[x]+z;
                // N번째 단계에서 최단경로가 갱신되면 음수사이클 존재
                if (i == n) {
                    negative_cycle = true;
                }
            }
        }
    }
    // 음수사이클이 존재하면 -1출력
    if (negative_cycle) {
        printf("-1\n");
    } else {
        // 시작점에서 각 정점으로의 최단거리 출력
        for (int i=2; i<=n; i++) {
            if (dist[i] == inf) dist[i] = -1;
            printf("%d\n",dist[i]);
        }
    }
    return 0;
}
