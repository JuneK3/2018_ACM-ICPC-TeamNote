// 출처: 종만북 24장 펜윅트리
// 구간합을 펜윅 트리 구현: https://www.acmicpc.net/blog/view/21
#include <bits/stdc++.h>
using namespace std;

// tree[i] = 오른쪽 끝위치가 A[i]인 구간의 합
// i를 이진수로 나타냈을때 마지막 1비트가 나타내는 값을 L[i]라고 하면 ex)1, 2, 4..
// tree[i]에는 A[i]부터 앞으로 L[i]개의 합이 저장되어 있다
struct FenwickTree
{
  vector<int> tree;
  FenwickTree(int n) : tree(n + 1) {}
  // A[0..pos]의 부분합을 구한다
  int sum(int pos)
  {
    // 인덱스가 1부터 시작한다고 생각
    pos++;
    int result = 0;
    while (pos > 0)
    {
      result += tree[pos];
      // 다음 구간을 찾기 위해 최종 1비트를 지운다
      pos &= (pos - 1);
    }
    return result;
  }
  // 어떤수를 변경한 경우, 그 수를 담당하고 있는 구간을 모두 업데이트 해주어야 한다
  // A[pos]에 val을 더한다
  void update(int pos, int val)
  {
    pos++;
    while (pos < tree.size())
    {
      tree[pos] += val;
      // 마지막의 1비트를 추출하여 더하면 해당 위치를 포함하는 구간들을 모두 만날수 있다
      pos += (pos & -pos);
    }
  }
};

// 펜윅트리는 구간트리처럼 모든 구간에 대해 답을 계산하지 않기 때문에
// O(n)에 초기화하기가 불가능하다
// 따라서 구간트리의 갱신연산처럼 각 위치릐 값을 변경하는 연산을 통해 내용을 채워넣어야 한다

// ex)
// for (int i = 0; i < n; i++)
// {
//   int val;
//   cin >> val;
//   update(i, val)
// }