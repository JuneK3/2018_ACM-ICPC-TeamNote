#include <bits/stdc++.h>
using namespace std;

// 피벗을 첫번쨰 원소로 지정하는 퀵소트
// 평균 시간복잡도는 O(NlogN)이지만
// 이미 정렬되어 있는 경우에는 O(N^2)으로 동작한다
// 초깃값: start=0, end=arr.size()-1
void quickSort(vector<int> &arr, int start, int end)
{
  if (start >= end)
    return;          // 원소가 1개인 경우 종료
  int pivot = start; // 피벗은 첫 번째 원소
  int left = start + 1;
  int right = end;
  while (left <= right)
  {
    // 피벗보다 큰 데이터를 찾을 때까지 반복
    while (left <= end && arr[left] <= arr[pivot])
      left++;
    // 피벗보다 작은 데이터를 찾을 때까지 반복
    while (right > start && arr[right] >= arr[pivot])
      right--;
    // 엇갈렸다면 작은 데이터와 피벗을 교체
    if (left > right)
      swap(arr[pivot], arr[right]);
    // 엇갈리지 않았다면 작은 데이터와 큰 데이터를 교체
    else
      swap(arr[left], arr[right]);
  }
  // 분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 정렬 수행
  quickSort(arr, start, right - 1);
  quickSort(arr, right + 1, end);
}