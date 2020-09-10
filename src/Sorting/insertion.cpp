#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &A)
{
  for (int i = 0; i < A.size(); ++i)
  {
    // A[0..i-1] 에 A[i] 를 끼워넣는다
    int j = i;
    while (j > 0 && A[j - 1] > A[j])
    {
      swap(A[j - 1], A[j]);
      --j;
    }
  }
}