// 출처: 종만북 20장 문자열
#include <bits/stdc++.h>
using namespace std;

// N에서 자기 자신을 찾으면서 나타나는 부분일치를 이용해
// pi[]를 계산한다
// pi[i] = N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
vector<int> getPartialMatch(const string &N)
{
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, match = 0;
    while (begin + match < m)
    {
        if (N[begin + match] == N[match])
        {
            ++match;
            pi[begin + match - 1] = match;
        }
        else
        {
            if (match == 0)
                ++begin;
            else
            {
                begin += match - pi[match - 1];
                match = pi[match - 1];
            }
        }
    }
    return pi;
}

// 짚더미 H의 부분 문자열로 바늘 N이 출현하는 시작 위치들을 모두 반환한다
vector<int> kmpSearch(const string &H, const string &N)
{
    int n = H.size(), m = N.size();
    vector<int> result;
    vector<int> pi = getPartialMatch(N);
    int begin = 0, match = 0;
    while (begin <= n - m)
    {
        if (match < m && H[begin + match] == N[match])
        {
            ++match;
            if (match == m)
                result.push_back(begin);
        }
        else
        {
            if (match == 0)
                ++begin;
            else
            {
                begin += match - pi[match - 1];
                match = pi[match - 1];
            }
        }
    }
    return result;
}