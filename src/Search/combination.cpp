#include <iostream>
#include <vector>
using namespace std;

// recursion
int n, m; // n개의 원소에서 m개를 뽑는 조합 구현
int a[];
bool check[];

void dfs(int idx, int cnt)
{
  if (cnt == m)
  {
    // 실행할 함수 or 출력문
    return;
  }
  for (int i = idx; i < n; i++)
  {
    if (check[i])
      continue;
    check[i] = true;
    // (vector)v.push_back(a[i]);
    dfs(i + 1, cnt + 1);
    check[i] = false;
    // (vector)v.pop_back();
  }
}

// not recursion with do-while
bool next_permutation(vector<int> &a, int n)
{
  int i = n - 1;
  while (i > 0 && a[i - 1] >= a[i])
  {
    i -= 1;
  }
  if (i <= 0)
  {
    return false; // 마지막 순열
  }
  int j = n - 1;
  while (a[j] <= a[i - 1])
  {
    j -= 1;
  }
  swap(a[i - 1], a[j]);
  j = n - 1;
  while (i < j)
  {
    swap(a[i], a[j]);
    i += 1;
    j -= 1;
  }
  return true;
}

int main()
{
  int n, r;
  cin >> n >> r; // nCr
  vector<int> a;
  do
  {
    vector<int> ret; // 조합 결과
    for (int i = 0; i < n - r; i++)
      a.push_back(0);
    for (int i = 0; i < r; i++)
      a.push_back(1);
    for (int i = 0; i < n; i++)
    {
      if (a[i])
        ret.push_back(i + 1);
    }
    for (int i = 0; i < r; i++)
    {
      cout << ret[i] << ' ';
    }
    cout << '\n';
  } while (next_permutation(a, n));
}