#include <bits/stdc++.h>
using namespace std;

// 모든 원소의 값이 0보다 크거나 같다고 가정
// 모든 범위를 포함하는 배열 선언(모든 값은 0으로 초기화)
int cnt[MAX + 1];

// 데이터의 개수 N, 데이터중 최댓값의 크기 K
// 시간복잡도: O(N+K)
void countingSort(vector<int> &arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cnt[arr[i]] += 1; // 각 데이터에 해당하는 인덱스의 값 증가
  }
  for (int i = 0; i <= MAX; i++)
  { // 배열에 기록된 정렬 정보 확인
    for (int j = 0; j < cnt[i]; j++)
    {
      cout << i << ' '; // 띄어쓰기를 기준으로 등장한 횟수만큼 인덱스 출력
    }
  }
}