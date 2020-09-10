#include <bits/stdc++.h>
using namespace std;

// 배열을 시계방향으로 90도 회전
// 반시계 방향으로 회전하는 경우는 시계방향으로 90도로 3번 회전시키는 것으로 구현 가능
vector<vector<int>> rotate_Matrix(vector<vector<int>> a)
{
  int n = a.size();                              // 행 길이 계산
  int m = a[0].size();                           // 열 길이 계산
  vector<vector<int>> result(n, vector<int>(m)); // 결과 리스트
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      result[j][n - i - 1] = a[i][j];
    }
  }
  return result;
}