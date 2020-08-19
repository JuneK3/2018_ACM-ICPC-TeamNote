// 인접행렬 O(V^2)
// 인접리스트 O(V+E)

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[]; // 인접리스트
int check[];       // 정점 방문 여부 체크

// 인럽리스트 구현
void bfs(int start)
{
    check[start] = 1;
    queue<int> q;
    q.push(start);
    cout << start << ' ';
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int next = adj[cur][i];
            if (check[next])
                continue;
            check[next] = 1;
            q.push(next);
            cout << next << ' ';
        }
    }
}

int adj[][]; // 인접행렬
int check[];

// 인접 행렬 구현
void bfs(int start)
{
    check[start] = 1;
    queue<int> q;
    q.push(start);
    cout << start << ' ';
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int next = 1; next <= n; next++)
        {
            if (!check[next] && adj[cur][next] == 1)
            {
                check[next] = 1;
                q.push(next);
                cout << next << ' ';
            }
        }
    }
}

// 격자판 버전
int board[][]; // 격자판 값 저장
int check[][]; // 방문여부 체크

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

// 격자판의 가로 세로 범위를 초과하는지 검사
bool isinRange(int y, int x)
{
    return (0 <= y && y <= n - 1) && (0 <= x && x <= m - 1);
}

// 격자판의 값이 1인 칸을 탐색
void bfs(int y, int x)
{
    check[y][x] = true;
    queue<pair<int, int>> q;
    q.push({y, x});
    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = curY + dy[i];
            int nx = curX + dx[i];
            if (!isInRange(ny, nx))
                continue;
            if (!check[ny][nx] && board[ny][nx] == 1)
            {
                check[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }
}
