#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n; // 정점개수 n
int inDegree[]; // 각 정점의 inDegree정점의 개수를 저장
int result[]; // 정점 저장 
vector<int> a[]; // 인접리스트를 활용한 BFS를 이용

void topologySort(){
	queue<int> q;
	//진입 차수가 0인 노드를 큐에 삽입
	for(int i=1; i<=n; i++){
		if(inDegree[i]==0){
			q.push(i);
		}
	} 
	//정렬이 완전히 수행되기 위해서는 정확히 n개의 노드를 방문해야 함
    //인접리스트를 활용한 BFS
	for(int i=1; i<=n; i++){
		int x = q.front();
		q.pop();
		result[i]=x; // 방문한 순서대로 현재정점 저장
		for(int j=0; j<a[x].size(); j++){
			int y = a[x][j];
            // y의 inDegree에 해당하는 정점을 방문했으므로 inDegree[y]-=1;
			//새롭게 진입차수가 0이 된 정점을 큐에 삽입 
			if(--inDegree[y]==0)
				q.push(y);
		}
	}
    // 방문한 순서대로 저장한 정점 출력
	for(int i=1; i<=n; i++){
		printf("%d ", result[i]);
	}
}

int main(){
	int m; // 정점간의 간선정보 m개
	scanf("%d %d", &n, &m);
    // 정점간의 간선입력
	for(int i=0; i<m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		inDegree[y]++; //정점 x가 정점 y의 inDegree 정점에 해당하므로 1증가
	}
	topologySort(); // 위상정렬 실행
}