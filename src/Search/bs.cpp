#include <bits/stdc++.h>
using namespace std;

vector<int> arr; // 탐색할 배열

// 반복문으로 구현
int binarySearch(vector<int> &arr, int target, int start, int end)
{
  while (start <= end)
  {
    int mid = (start + end) / 2;
    // 찾은 경우 중간점 인덱스 반환
    if (arr[mid] == target)
      return mid;
    // 중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
    else if (arr[mid] > target)
      end = mid - 1;
    // 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
    else
      start = mid + 1;
  }
  return -1;
}

// 재귀함수로도 구현 가능
int binarySearch(vector<int> &arr, int target, int start, int end)
{
  if (start > end)
    return -1;
  int mid = (start + end) / 2;
  // 찾은 경우 중간점 인덱스 반환
  if (arr[mid] == target)
    return mid;
  // 중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
  else if (arr[mid] > target)
    return binarySearch(arr, target, start, mid - 1);
  // 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
  else
    return binarySearch(arr, target, mid + 1, end);
}

// lower_bound:
//탐색할 임의의 배열에서 기준값보다 크거나 같은 수가 처음 나타나는 인덱스를 리턴

// upper_bound:
// 탐색할 임의의 배열에서 기준값보다 큰수가 처음으로 나타나는 인덱스를 리턴

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