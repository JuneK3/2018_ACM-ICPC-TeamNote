// Merge Sort 구현
#include <bits/stdc++.h>
using namespace std;

// 길이가 n인 벡터 a를 정렬할때 sort(a, 0, n-1)을 호출
void merge(vector<int> &a, int start, int end)
{
  vector<int> tmp(end - start + 1);
  int mid = (start + end) / 2;
  int i = start;
  int j = mid + 1;
  int k = 0;
  while (i <= mid && j <= end)
  {
    if (a[i] <= a[j])
    {
      tmp[k++] = a[i++];
    }
    else
    {
      tmp[k++] = a[j++];
    }
  }
  while (i <= mid)
  {
    tmp[k++] = a[i++];
  }
  while (j <= end)
  {
    tmp[k++] = a[j++];
  }
  for (int i = 0; i < tmp.size(); i++)
  {
    a[start + i] = tmp[i];
  }
}

void sort(vector<int> &a, int start, int end)
{
  if (start == end)
    return;
  int mid = (start + end) / 2;
  sort(a, start, mid);
  sort(a, mid + 1, end);
  merge(a, start, end);
}