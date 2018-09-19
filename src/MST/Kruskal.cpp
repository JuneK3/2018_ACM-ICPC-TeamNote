// 유니온 파인드를 이용한 구현
// 간선의 가중치를 작은순으로 정렬하고 가중치가 작은 간선부터 MST를 만든다
// 간선의 시작정점과 도착정점이 이미 같은 집합에 있다면 그 간선은 선택하지 않는다
// 간선의 시작정점과 도착정점이 다른 집합에 있으면 두 집합을 합친다
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 간선 구조체
struct Edge {
    int start, end, cost;
    bool operator < (const Edge &other) const {
        return cost < other.cost;
    }
};
int p[]; // 각 정점의 부모를 저장하는 배열
// 유니온 파인드
int Find(int x) {
    if (x == p[x]) {
        return x;
    } else {
        return p[x] = Find(p[x]);
    }
}
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    p[x]=y;
}
int main() {
    int n,m; // 정점개수 n, 간선정보의 개수 m
    scanf("%d %d",&n,&m);
    // 처음에 각 정점의 부모를 자기 자신으로 초기화한다
    for (int i=1; i<=n; i++) {
        p[i] = i;
    }
    // 간선정보 입력
    vector<Edge> a(m);
    for (int i=0; i<m; i++) {
        scanf("%d %d %d",&a[i].start, &a[i].end, &a[i].cost);
    }
    // 연산자 오버로딩에 의해서 cost가 작은순으로 정렬
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i=0; i<m; i++) {
        Edge e = a[i];
        // Find연산으로 간선의 시작정점과 도착정점의 부모를 찾는다
        int x = Find(e.start);
        int y = Find(e.end);
        // 시작정점과 도착정점이 같은 집합이 아니라면 두 집합을 합친다
        if (x != y) {
            Union(e.start, e.end);
            ans += e.cost;
        }
    }
    printf("%d\n",ans);
    return 0;
}