// 인접행렬 O(V^2)
// 인접리스트 O(V+E)

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[]; // 인접리스트
bool check[];      // 방문한 정점 체크

// 인접리스트 구현
void dfs(int start)
{
    check[start] = true;
    cout << start << ' ';
    for (int i = 0; i < adj[start].size(); i++)
    {
        int next = adj[start][i];
        if (check[next])
            continue;
        dfs(next);
    }
}

int adj[][]; // 인접행렬
bool check[];

// 인접행렬 구현
void dfs(int start)
{
    check[start] = true;
    cout << start << ' ';
    for (int next = 1; next <= n; next++)
    {
        if (!check[next] && adj[start][next] == 1)
        {
            dfs(next);
        }
    }
}

// 스택을 이용한 구현 (인접리스트)
void dfs(int start)
{
    check[start] = true;
    stack<int> st;
    st.push(start);
    cout << start << ' ';
    while (!st.empty())
    {
        int cur = st.top();
        bool can_go = false;
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int next = adj[cur][i];
            if (check[next])
                continue;
            can_go = true;
            check[next] = true;
            st.push(next);
            cout << next << ' ';
            break;
        }
        if (!can_go)
        {
            st.pop();
        }
    }
}

// 스택을 이용한 구현 (인접행렬)
void dfs(int start)
{
    check[start] = true;
    stack<int> st;
    st.push(start);
    cout << start << ' ';
    while (!st.empty())
    {
        int cur = st.top();
        bool can_go = false;
        for (int next = 1; next <= n; next++)
        {
            if (!check[next] && adj[cur][next] == 1)
            {
                can_go = true;
                check[next] = true;
                st.push(next);
                cout << next << ' ';
                break;
            }
        }
        if (!can_go)
        {
            st.pop();
        }
    }
}

// 격자판 버전
int board[][];
bool check[][];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

// 격자판의 가로 세로 범위 내에 있는지 검사
bool isInRange(int y, int x)
{
    return (0 <= y && y <= n - 1) && (0 <= x && x <= m - 1);
}

void dfs(int y, int x)
{
    check[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (!isInRange(ny, nx))
            continue;
        if (!check[ny][nx] && board[ny][nx] == 1)
        {
            dfs(ny, nx);
        }
    }
}