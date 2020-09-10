#include <bits/stdc++.h>
using namespace std;

// lower_bound:
//탐색할 임의의 배열에서 기준값보다 크거나 같은 수가 처음 나타나는 인덱스를 리턴

// upper_bound:
// 탐색할 임의의 배열에서 기준값보다 큰수가 처음으로 나타나는 인덱스를 리턴

vector<int> arr; // 탐색할 배열
int lower_bound(int num)
{
  int l = 0, r = arr.size();
  while (l < r)
  {
    int mid = (l + r) / 2;
    if (arr[mid] < num)
    {
      l = mid + 1;
    }
    else
    {
      r = mid;
    }
  }
  return r;
}

int upper_bound(int num)
{
  int l = 0, r = arr.size();
  while (l < r)
  {
    int mid = (l + r) / 2;
    if (arr[mid] <= num)
    {
      l = mid + 1;
    }
    else
    {
      r = mid;
    }
  }
  return r;
}