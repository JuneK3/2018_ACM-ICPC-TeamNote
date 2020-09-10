// single LinkedList
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
  T data;
  Node *next;
  Node() {}
  Node(T data) : data(data)
  {
    next = nullptr;
  }
  ~Node() {}
};

template <typename T>
class LinkedList
{
public:
  Node<T> *head;
  int size;
  LinkedList()
  {
    size = 0;
    head = nullptr;
  }

  void addNode(T data)
  {
    Node<T> *newNode = new Node<T>(data);
    size++;
    if (head == nullptr)
    {
      head = newNode;
    }
    else
    {
      Node<T> *cur = head;
      while (cur)
      {
        if (cur->next == nullptr)
        {
          cur->next = newNode;
          break;
        }
        cur = cur->next;
      }
    }
  }

  void printList()
  {
    if (head == nullptr)
    {
      cout << "빈 리스트" << '\n';
      return;
    }
    Node<T> *cur = head;
    while (cur)
    {
      cout << cur->data << " ";
      cur = cur->next;
    }
    //cout << size;
    cout << '\n';
    return;
  }

  void chaneNode(int idx, T data)
  {
    if (idx < 0 || idx >= size)
    {
      cout << "잘못된 인덱스 참조" << '\n';
      return;
    }
    Node<T> *cur = head;
    for (int i = 0; i < idx; i++)
    {
      cur = cur->next;
    }
    cur->data = data;
    return;
  }

  void deleteNode(int idx)
  {
    if (idx < 0 || idx >= size)
    {
      cout << "잘못된 인덱스 참조" << '\n';
      return;
    }
    Node<T> *cur = head;
    Node<T> *pre = nullptr;
    for (int i = 0; i < idx; i++)
    {
      pre = cur;
      cur = cur->next;
    }
    size--;
    if (idx == 0)
      head = head->next;
    else
      pre->next = cur->next;

    delete cur;
    return;
  }
};

int main()
{
  LinkedList<int> List;
  List.addNode(1);
  List.addNode(3);
  List.addNode(2);
  List.addNode(4);
  List.printList();
  List.chaneNode(0, 2);
  List.printList();
  List.deleteNode(3);
  List.printList();
  //List.chaneNode(3, 4);
  List.chaneNode(2, 4);
  List.printList();
}