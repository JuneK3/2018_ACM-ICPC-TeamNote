// 시간복잡도 인접행렬, 인접리스트 모두 O(V^2)
// 힙을 이용하여 최소값을 찾는다면 O(ElogE)

/*
// 인접 행렬
#include <iostream>
using namespace std;
int a[][];
int dist[];
bool check[];
int inf = 1000000000;
int main() {
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            a[i][j] = inf;
        }
    }
    int m;
    scanf("%d",&m);
    for (int i=0; i<m; i++) {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        if (a[x][y] > z) {
            a[x][y] = z;
        }
    }
    int start, end;
    scanf("%d %d",&start,&end);
    for (int i=1; i<=n; i++) {
        dist[i] = inf;
    }
    dist[start] = 0;
    for (int k=0; k<n-1; k++) {
        int m = inf+1;
        int x = -1;
        for (int i=1; i<=n; i++) {
            if (check[i] == false && m > dist[i]) {
                m = dist[i];
                x = i;
            }
        }
        check[x] = true;
        for (int i=1; i<=n; i++) {
            if (dist[i] > dist[x] + a[x][i]) {
                dist[i] = dist[x] + a[x][i];
            }
        }
    }
    printf("%d\n",dist[end]);
    return 0;
}
*/

// 인접 리스트
#include <iostream>
#include <vector>
using namespace std;
struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {
    }
};
vector<Edge> a[];
int dist[]; // 시작점에서 i까지의 최단경로 저장
bool check[]; // 방문여부 체크
int inf = 1000000000;
int main() {
    int n; // 정점개수
    scanf("%d",&n);
    int m; // 간선 정보 개수
    scanf("%d",&m);
    // 시작정점, 도착정점, 가중치 입력
    for (int i=0; i<m; i++) {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        a[x].push_back(Edge(y,z));
    }
    // 시작점, 도착점 입력
    int start, end;
    scanf("%d %d",&start,&end);
    // 벨만포드와 마찬가지로 처음에는 모두 무한대로 저장
    for (int i=1; i<=n; i++) {
        dist[i] = inf;
    }
    dist[start] = 0; // 시작점 최단경로 0으로 설정
    // 이 부분 암기필요
    for (int k=0; k<n-1; k++) {
        int m = inf+1;
        int x = -1;
        // 최단경로가 최소인 정점부터 다시 시작
        for (int i=1; i<=n; i++) {
            if (check[i] == false && m > dist[i]) {
                m = dist[i];
                x = i; // 최단경로가 최소인 정점번호 저장
            }
        }
        check[x] = true; // 방문 체크
        for (int i=0; i<a[x].size(); i++) {
            int y = a[x][i].to;
            // 최단경로 갱신
            if (dist[y] > dist[x] + a[x][i].cost) {
                dist[y] = dist[x] + a[x][i].cost;
            }
        }
    }
    // 도착점까지의 최단경로 출력
    printf("%d\n",dist[end]);
    return 0;
}
// 힙을 활용한 구현 O(ElogE)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {
    }
};
vector<Edge> a[];
int dist[];
bool check[];
int inf = 1000000000;
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int start;
    scanf("%d",&start);
    for (int i=0; i<m; i++) {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        a[x].push_back(Edge(y,z));
    }
    for (int i=1; i<=n; i++) {
        dist[i] = inf;
    }
    dist[start] = 0;
    // 이 부분부터 보면
    // 체크되어 있지 않은 정점중에서 최단거리의 값이 가장 작은 정점을 선택하는 과정을
    // 우선순위 큐를 이용하여 구현
    priority_queue<pair<int,int>> q;
    q.push(make_pair(0, start)); // 시작점을 큐에 push
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        int x = p.second; // 정점번호 저장
        // 이미 방문한 정점이면 pass
        if (check[x]) {
            continue;
        }
        check[x] = true; // 방문하지 않은 정점이면 방문 체크
        for (int i=0; i<a[x].size(); i++) {
            int y = a[x][i].to; // 다음 정점번호 저장
            // 최단경로 갱신
            if (dist[y] > dist[x] + a[x][i].cost) {
                dist[y] = dist[x] + a[x][i].cost;
                q.push(make_pair(-dist[y], y)); // 최소힙으로 활용하기 위해서 가중치에 음부호를 붙여서 큐에 push
            }
        }
    }
    // 출력 조건에 맞춰서 출력
    // case by case
    /*
    for (int i=1; i<=n; i++) {
        if (dist[i] >= inf) {
            printf("INF\n");
        } else {
            printf("%d\n",dist[i]);
        }
    }
    */
    return 0;
}

// DFS를 장착한 다익스트라 알고리즘 구현
// 추후 추가
