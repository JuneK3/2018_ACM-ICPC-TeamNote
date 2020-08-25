// #include <queue>로 사용가능
// c++의 우선순위 큐는 최대힙으로 구현되어 있음
// 최소힙으로 사용하기 위해서는 일반적으로
// priority_queue<int> q;같은 형식으로 선언해서는 안되고
// priority_queue<int, vector<int>, greater<int>> q;와 같이 선언해주어야 한다.

// 위 방법을 사용하지 못하는 경우나 잊어버린 경우
// 백준저지 [1766 문제집]문제 참고 https://www.acmicpc.net/problem/1766
// 위상정렬 + 우선순위 큐 유형의 문제
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> a[];
int ind[]; // 각 정점의 inDegree정점의 개수를 저장
int main() {
    int n,m; // 정점개수 n, 간선정보 개수 m
    scanf("%d %d",&n,&m);
    // 간선정보 입력
    for (int i=0; i<m; i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        //정점 x가 정점 y의 inDegree 정점에 해당하므로 1증가
        ind[y] += 1;
    }
    priority_queue<int> q;
    for (int i=1; i<=n; i++) {
        if (ind[i] == 0) {
            q.push(-i); // 최소힙으로 활용하기 위해서 정점번호 큐에 음수로 넣는다
        }
    }
    // BFS
    for (int k=0; k<n; k++) {
        int x = -q.top(); // BFS를 위해 정점번호를 다시 양수로 변환 
        q.pop();
        printf("%d ",x); // 방문한 정점번호를 양수형태로 출력
        for (int i=0; i<a[x].size(); i++) {
            int y = a[x][i];
            // y의 inDegree에 해당하는 정점을 방문했으므로 inDegree[y]-=1;
			//새롭게 진입차수가 0이 된 정점을 큐에 삽입
            ind[y] -= 1;
            if (ind[y] == 0) {
                q.push(-y); // 최소힙으로 활용하기 위해서 정점번호 큐에 음수로 넣는다
            }
        }
    }
    printf("\n");
    return 0;
}