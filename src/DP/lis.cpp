#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int N;
int arr[];
int cache[];
pair<int, int> answer[]; // idx, arr[]
stack<int> s;

// O(nlogn)
int LIS()
{
  int idx = 0;
  cache[idx] = arr[0];
  answer[0] = make_pair(0, arr[0]);
  for (int i = 1; i < N; i++)
  {
    if (cache[idx] < arr[i])
    {
      cache[++idx] = arr[i];
      answer[i] = make_pair(idx, arr[i]);
    }
    else
    {
      int idx2 = lower_bound(cache, cache + idx, arr[i]) - cache;
      cache[idx2] = arr[i];
      answer[i] = make_pair(idx2, arr[i]);
    }
  }
  return idx + 1;
}

int main(void)
{
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> arr[i];
  int result = LIS();
  cout << result << "\n";
  int num = result - 1;
  for (int i = N - 1; i >= 0; i--)
  {
    if (answer[i].first == num)
    {
      s.push(answer[i].second);
      num--;
    }
  }
  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
  return 0;
}