#include <iostream>
#include <vector>
using namespace std;
int a[];

// recursion
int n, m; // n개의 원소에서 m개를 뽑는 순열 구현
int a[];
bool check[];

void dfs(int cnt)
{
  if (cnt == m)
  {
    // 실행할 함수 or 출력문
    return;
  }
  for (int i = 0; i < n; i++)
  {
    if (check[i])
      continue;
    check[i] = true;
    // (vector)v.push_back(a[i]);
    dfs(cnt + 1);
    check[i] = false;
    // (vector)v.pop_back();
  }
}

// not recursion with do-while
bool next_permutation(int *a, int n)
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

bool prev_permutation(int *a, int n)
{
  int i = n - 1;
  while (i > 0 && a[i - 1] <= a[i])
  {
    i -= 1;
  }
  if (i <= 0)
  {
    return false;
  }
  int j = n - 1;
  while (a[j] >= a[i - 1])
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

/*
 nPr은 순열배열에서 앞의 r개의 원소를 추출하여 구할수 있음
 시간복잡도는 nPn과 똑같기 때문에 개선해야 할 부분이 있음
*/

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  do
  {
    for (int i = 0; i < n; i++)
    {
      cout << a[i] << ' ';
    }
    cout << '\n';
  } while (next_permutation(a, n));
}