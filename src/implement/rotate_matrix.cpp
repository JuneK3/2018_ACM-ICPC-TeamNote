#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateMatrixBy90Degree(vector<vector<int>> a)
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