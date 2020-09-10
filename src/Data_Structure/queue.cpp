// 배열로 구현했을 때가 더 빠름
// todo: queue랑 stack 배열로도 구현해보기
#include <iostream>
using namespace std;

template <typename T>
class Queue
{
public:
  struct Node
  {
    T val;
    Node *next;
    Node() : next(nullptr) {}
    Node(T val) : val(val), next(nullptr) {}
  };

  Node *Front;
  Node *Rear;
  int _size;
  Queue() : _size(0), Front(nullptr), Rear(nullptr) {}

  void push(T val)
  {
    Node *newNode = new Node(val);
    _size++;

    if (Front == nullptr)
    {
      Front = Rear = newNode;
    }
    else
    {
      Rear->next = newNode;
      Rear = newNode;
    }
  }

  void pop()
  {
    //if(_size == 0) return;
    _size--;
    Node *temp = Front;
    Front = temp->next;
    delete temp;
  }

  bool empty()
  {
    return _size == 0;
  }

  T front()
  {
    return Front->val;
  }

  int size()
  {
    return _size;
  }
};

int main()
{
  Queue<int> q;
  q.push(1);
  q.push(3);
  q.push(5);
  int len = q.size();
  for (int i = 0; i < len; i++)
  {
    cout << q.front() << '\n';
    q.pop();
  }
  cout << q.empty() << '\n';
  return 0;
}