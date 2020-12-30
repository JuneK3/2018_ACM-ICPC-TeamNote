#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;

void eratosthenes(int n)
{
  vector<bool> isPrime(n + 1, true);
  int sqrtn = int(sqrt(n));
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= sqrtn; i++)
  {
    if (isPrime[i])
      for (int j = i * i; j <= n; j += i)
      {
        isPrime[j] = false;
      }
  }
}