#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

// c++에서 우선순위큐 stl인 priority_queue는 최대힙으로 구현되어있음
// 최소힙으로 적용하기 위해서는 별도의 과정이 더 필요함

// greater<pii>와 같음
struct cmp
{
  bool operator()(pii a, pii b)
  {
    return a > b; // less<pii>는 return a < b;
  }
};

// 첫번째 인자는 저장할 원소의 자료형을 나타내고
// 두번째 인자는 원소를 저장할 컨테이너를 나타낸다
// 두번째 인자는 vector, deque등을 주로 사용한다
priority_queue<pii, vector<pii>> pq; // 최대힙

// 두경우 모두 최소힙으로 동작한다
priority_queue<pii, vector<pii>, cmp> pq;          //최소힙
priority_queue<pii, vector<pii>, greater<pii>> pq; //최소힙

// 정렬함수(sort)에서의 비교함수는 greater일때 내림차순,
// less일때 오름차순으로 작동한다
// 즉 비교함수가 false를 반환할때 원소를 swap하는 형식으로 동작한다

// 우선순위 큐에서는 반대로 작동한다
// greater일때 최소힙(오름차순), less일때 최대힙(내림차순)이 되고
// 비교함수가 true를 반환할때 원소를 swap하는 형식으로 동작한다