// 출처: 종만북 20장 접미사 배열
#include <bits/stdc++.h>
using namespace std;

// 접미사 배열을 정렬하는 과정에서 접미사간의 문자열 비교가 이루어 지므로
// 시간복잡도는 O(n^2lg(n))가 된다
struct SuffixComparator
{
  const string &s;
  SuffixComparator(const string &s) : s(s) {}
  // c_str()로 string을 char* 형으로 변환시켜
  // strcmp로 두 문자열을 비교 사전순으로 오름차순이 되면 음수 변환
  bool operator()(int i, int j)
  {
    return strcmp(s.c_str() + i, s.c_str() + j) < 0;
  }
};

vector<int> getSuffixArrayNavie(const string &s)
{
  //접미사의 시작위치를 담는 배열을 만든다
  vector<int> perm;
  for (int i = 0; i < s.size(); i++)
    perm.push_back(i);
  sort(perm.begin(), perm.end(), SuffixComparator(s));
  return perm;
}

// 접미사 배열을 여러번 정렬하는데 매번 그 기준을 바꾼다
// 접미사의 첫 t글자를 기준으로 비교하여 정렬한다
// 문자열의 길이내에 한해서 t를 2배씩 증가시키면서 lg(n)번 정렬이 이루어진다
// 따라서 시간복잡도는 O(nlg^2(n))
struct Comparator
{
  const vector<int> &group;
  int t;
  Comparator(const vector<int> &_group, int _t) : group(_group), t(_t) {}
  bool operator()(int a, int b)
  {
    if (group[a] != group[b])
      return group[a] < group[b];
    return group[a + t] < group[b + t];
  }
};

vector<int> getSuffixArray(const string &s)
{
  int n = s.size();
  int t = 1;
  // group[i] = 접미사들을 첫 t글자를 기준으로 정렬했을때, s[i..]가 들어가게 될 그룹번호
  // t=1일때는 정렬할것 없이 s[i..]의 첫글자로 그룹번호를 정해준다
  vector<int> group(n + 1);
  group[n] = -1; // 범위 밖의 배열을 참조해서 생기는 오류를 방지
  for (int i = 0; i < n; i++)
    group[i] = s[i];
  // 결과적으로 접미사 배열이 될 반환 값. 이 배열을 log(n)번 정렬
  vector<int> perm(n);
  for (int i = 0; i < n; i++)
    perm[i] = i;

  while (t < n)
  {
    // group[]은 첫t글자를 기준으로 계산해 뒀다
    // 첫 2t글자를 기준으로 perm을 다시 정렬한다
    Comparator compareUsing2T(group, t);
    sort(perm.begin(), perm.end(), compareUsing2T);
    // 2t글자가 n을 넘는다면 접미사 배열이 완성된다
    t *= 2;
    if (t >= n)
      break;
    // 2t글자를 기준으로 하는 그룹정보를 만든다
    vector<int> newGroup(n + 1);
    newGroup[n] = -1;
    newGroup[perm[0]] = 0;
    for (int i = 1; i < n; i++)
    {
      if (compareUsing2T(perm[i - 1], perm[i]))
        newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
      else
        newGroup[perm[i]] = newGroup[perm[i - 1]];
    }
    group = newGroup;
  }
  return perm;
}