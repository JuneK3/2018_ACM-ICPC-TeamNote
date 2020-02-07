// c++의 템플릿을 이용해서 stl처럼 사용할 수 있게 구현

// push_front과 push_back 멤버함수 사용시
// head와 tail 포인터의 위치가 갱신되지 않는 설계 오류 발생
// 재설계 필요

// <수정안>
// 멤버함수 : insert / erase / changeData / print(head->tail)
// 단일, 이중, 원형 링크드리스트 모두 따로 구현
// insert 함수에서 head와 tail 포인터의 위치가 갱신되도록 구현
// 참고 : https://meylady.tistory.com/5?category=784614

#include <iostream>
using namespace std;
 
template<typename T>
class ListNode{
public:
  T value;
  ListNode<T> *next;
  ListNode<T> *prev;
  // 생성자
  ListNode<T>(T value1, ListNode<T> *prev1, ListNode<T> *next1): value(value1), prev(prev1), next(next1){}
  ListNode<T>(T value2): value(value2), prev(nullptr), next(nullptr){}
};
 
template<typename T>
class LinkedList{
public:
  int size;
  ListNode<T> *head;
  ListNode<T> *tail;
 
  // 생성자
  LinkedList<T>(){
    size = 0;
    tail = head = nullptr;
  }
  LinkedList<T>(T value){
    tail = head = new ListNode<T>(value);
    size = 1;
  }

  void push_front(T val){
    ListNode<T> *newNode = new ListNode<T>(val);
    if(head == nullptr){
      tail = head;
    }else{
      newNode->next = head;
      head->prev = newNode;
    }
    head = newNode;
    size++;
  }
  
  void push_back(T val){
    ListNode<T> *newNode = new ListNode<T>(val);
    if(tail == nullptr){
      head = tail;
    }else{
      newNode->prev = tail;
      tail->next = newNode;
    }
    tail = newNode;
    size++;
  }
  
  void pop_front(){
    if(head != nullptr){
      ListNode<T> *remove = head;
      head = head->next;
      head->prev = nullptr;
      delete remove;
      size--;
    }
  }

  void pop_back(){
    if(tail != nullptr){
      ListNode<T> *remove = tail;
      tail = tail->prev;
      tail->next = nullptr;
      delete remove;
      size--;
    }
  }

  void insert(int idx, T val){
    if(idx < 0 || idx >= size){
      cout << "인덱스 범위 초과" << endl;
      return;
    }
    else if(idx == 0){
      push_front(val);
    }
    else if(idx == size-1){
      push_back(val);
    }
    else{
      ListNode<T> *newNode = new ListNode<T>(val);
      ListNode<T> *cur = head;
      int i=0;
      while(i < idx - 1){
        cur = cur->next;
        i++;
      }
      newNode->prev = cur;
      newNode->next = cur->next;
      cur->next = newNode;
      newNode->next->prev = newNode;
      //cur->prev = newNode->prev;
    }
  }
  /*
    void erase(int k){ // k번째 원소를 제거
        try{
            // 예외 처리: 잘못된 인덱스
            if(k < 0 || k >= size) throw InvalidIndexException();
 
            if(k == 0){ // head를 삭제
                ListNode<T> *temp = head->next;
                delete head;
                head = temp;
            }
            else{ // k번째 원소 삭제
                ListNode<T> *dest = head, *temp;
                for(int i=0; i<k-1; i++) dest = dest->next;
                temp = dest->next->next;
                delete dest->next;
                dest->next = temp;
            }
            size--;
        }
        catch(InvalidIndexException e){
            cerr << "잘못된 인덱스입니다." << endl;
            exit(2);
        }
    }
  */
  int search(T value){ // 값을 찾아 첫번째 인덱스 리턴, 없으면 -1 리턴
    ListNode<T> *temp = head;
    for(int i=0; i<size; i++){
      if(temp->value == value) return i;
      temp = temp->next;
    }
    return -1;
  }

  void print(){
    ListNode<T> *cur = head;
    while(cur != nullptr){
      if(cur->next == nullptr){
        cout << cur->value << '\n';
      }else{
        cout << cur->value << " ";
      }
      cur = cur->next;
    }
  }

  // 소멸자
  ~LinkedList<T>(){
    ListNode<T> *cur = head;
    while(cur != nullptr){
      pop_front();
    }
  }
};
