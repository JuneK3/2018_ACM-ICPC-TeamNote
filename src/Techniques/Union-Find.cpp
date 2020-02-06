// Disjoint-set
#include <iostream>
using namespace std;
int parent[]; // 각 정점의 부모 정점을 저장하는 배열 
// x가 어떤 집합에 포함되어 있는지 찾는 연산
int Find(int x) {
    if (x == parent[x]) {
        return x;
    } else {
        return parent[x] = Find(parent[x]);
    }
}
// x와 y가 포함되어 있는 집합을 합치는 연산
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    // x와 y가 같은 집합이 아니라면 두 집합을 합치기 위해 y의 부모를 x으로 만든다
    if (x != y) {
        parent[y] = x;
    }
}
int main()
{
    int n; // 정점의 개수
    cin >> n;
    // 처음에 각 정점의 부모를 자기 자신으로 초기화한다
    for (int i=1; i<=n; i++) {
        parent[i] = i;
    }
}