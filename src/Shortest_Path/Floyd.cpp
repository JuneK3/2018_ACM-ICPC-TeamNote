// 모든 쌍의 최단경로를 구하는 알고리즘
#include <iostream>
#include <algorithm>
using namespace std;
int d[][]; // d[i][j]: i에서 j로 가는 최단거리 저장
int main() {
    int n; // 정점 개수
    cin >> n;
    int m; // 간선정보 개수
    cin >> m;
    // 간선정보 입력
    while (m--) {
        int x,y,z;
        cin >> x >> y >> z;
        if (d[x][y] == 0) {
            d[x][y] = z;
        } else {
            d[x][y] = min(d[x][y], z);
        }
    }
    // Floyd-Warshall
    // 암기 필요
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i == j) continue;
                if (d[i][k] != 0 && d[k][j] != 0) {
                    if (d[i][j] == 0) {
                        d[i][j] = d[i][k]+d[k][j];
                    } else {
                        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
                    }
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << d[i][j] <<  ' ';
        }
        cout << '\n';
    }
    return 0;
}