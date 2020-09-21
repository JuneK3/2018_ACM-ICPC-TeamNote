#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &A)
{
  for (int i = 0; i < A.size(); i++)
  {
    int min_index = i; // 가장 작은 원소의 인덱스
    for (int j = i + 1; j < A.size(); j++)
    {
      if (A[min_index] > A[j])
      {
        min_index = j;
      }
    }
    swap(A[i], A[min_index]);
  }
}