// MST(Minimum Spanning Tree)
// Spanning Tree : 그래프에서 일부 간선을 선택해서 만든 트리
// MST : Spanning Tree중에서 선택한 간선의 가중치의 합이 최소인 트리

// Prim
// 시간 복잡도 : O(VE), 최대 O(V^3)
// 우선순위 큐를 이용하면 최소값을 logE만에 찾을 수 있기 때문에 O(ElogE)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int>> a[]; // 간선정보(연결된 정점, 가중치) 저장
bool c[]; // 방문여부 체크
int main() {
    int n,m; // 정점개수 n, 간선정보 개수 m
    scanf("%d %d",&n,&m);
    // 간선정보 입력
    for (int i=0; i<m; i++) {
        int t1,t2,t3; // t1,t2:정점 ,t3:가중치
        scanf("%d %d %d",&t1,&t2,&t3);
        a[t1].push_back(make_pair(t2,t3));
        a[t2].push_back(make_pair(t1,t3));
    }
    c[1] = true; // 임의의 정점을 선택, 1번 정점부터 BFS
    priority_queue<pair<int,int>> q; // 우선순위 큐 활용
    for (auto &p : a[1]) {
        q.push(make_pair(-p.second,p.first)); // 최대힙을 최소힙으로 활용하기 위해서 가중치를 큐에 음수로 넣는다
    }
    int ans = 0;
    while (!q.empty()) {
        // 우선순위 큐에서 가중치가 최소인 순으로 정렬됨
        auto p = q.top(); // p.first:가중치, p.second:정점번호
        q.pop();
        if (c[p.second]) continue; // 해당정점을 이미 방문했다면 pass
        c[p.second] = true; // 처음 방문하는 정점이라면 방문체크
        ans += -p.first; // 음수로 저장한 가중치를 저장
        int x = p.second; // 현재 정점번호 저장
        // 다음정점 탐색
        for (auto &p : a[x]) {
            q.push(make_pair(-p.second,p.first));
        }
    }
    printf("%d\n",ans); // 탐색한 MST의 최소 가중치의 합 출력
    return 0;
}

// 구조체 및 생성자를 이용한 구현
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct Edge {
    int start;
    int end;
    int cost;
    // 모두 0으로 초기화하는 기본 생성자
    Edge() : start(0), end(0), cost(0) {
    }
    // 입력값을 받는 생성자
    Edge(int start, int end, int cost) : start(start), end(end), cost(cost) {
    }
    // 연산자 오버로딩
    bool operator < (const Edge &other) const {
        return cost > other.cost;
    }
};
vector<pair<int,int>> a[];
bool c[];
int main() {
    int n, m; // 정점개수 n, 간선정보 개수 m
    scanf("%d",&n);
    scanf("%d",&m);
    // 간선정보 입력
    for (int i=0; i<m; i++) {
        int start, end, cost;
        scanf("%d %d %d",&start, &end, &cost);
        a[start].push_back(make_pair(end,cost));
        a[end].push_back(make_pair(start,cost));
    }
    c[1] = true; // 1번정점부터 BFS시작
    priority_queue<Edge> q; // 우선순위 큐
    for (int i=0; i<a[1].size(); i++) {
        q.push(Edge(1, a[1][i].first, a[1][i].second));
    }
    int ans = 0;
    for (int i=0; i<n-1; i++) {
        Edge e;
        while (!q.empty()) {
            e = q.top();
            q.pop();
            if (c[e.end] == false) {
                break; // 방문하지 않은 정점 탐색
            }
        }
        c[e.end] = true; // 현재 정점 방문체크
        ans += e.cost;
        int x = e.end;
        for (int i=0; i<a[x].size(); i++) {
            q.push(Edge(x, a[x][i].first, a[x][i].second));
        }
    }
    printf("%d\n",ans);
    return 0;
}