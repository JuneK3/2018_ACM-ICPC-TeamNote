// 최대힙을 배열로 구현
#include <bits/stdc++.h>
using namespace std;

int heap[]; // index:1부터 원소를 저장하는 최대힙
int top;    // heap의 top원소를 가리키는 index

int pop()
{
  int ret = heap[1];
  heap[1] = heap[top];
  heap[top--] = 0;
  for (int i = 1; i * 2 <= top;)
  {
    if (heap[i] > heap[i * 2] && heap[i] > heap[i * 2 + 1])
    {
      break;
    }
    else if (heap[i * 2] > heap[i * 2 + 1])
    {
      swap(heap[i], heap[i * 2]);
      i = i * 2;
    }
    else
    {
      swap(heap[i], heap[i * 2 + 1]);
      i = i * 2 + 1;
    }
  }
  return ret;
}

void push(int x)
{
  heap[++top] = x;
  for (int i = top; i > 1; i /= 2)
  {
    if (heap[i / 2] < heap[i])
    {
      swap(heap[i / 2], heap[i]);
    }
    else
    {
      break;
    }
  }
}