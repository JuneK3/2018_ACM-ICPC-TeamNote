// 양방항 링크드 리스트로 구현
// c++의 템플릿을 이용해서 stl처럼 사용할 수 있게 코딩
// 멤버함수 : push_front / push_back / pop_front / pop_back /
// insert / erase...

#include <iostream>
#include <cstdlib>
using namespace std;
 
class InvalidIndexException{};
 
template<typename T>
class ListNode{
public:
  T value;
  ListNode<T> *next; // 마지막 노드면 nullptr
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
  LinkedList<T>(T value){
    tail = head = new ListNode<T>(value);
    size = 1;
  }
 
  // 소멸자
  ~LinkedList<T>(){
    ListNode<T> *t1 = head, *t2;
      while(t1 != nullptr){
        t2 = t1->next;
        delete t1;
        t1 = t2;
      }
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
  /*
  void push_back(T val){
    
  }
  */
    // 멤버 함수
    void insert(int k, T value){ // k번째 원소 앞에 새 원소 삽입
        try{
            // 예외 처리: 잘못된 인덱스
            if(k < 0 || k > size) throw InvalidIndexException();
 
            if(k == 0){ // 처음에 삽입
                head = new ListNode<T>(value, head);
            }
            else{ // k번째 원소 앞에 삽입
                ListNode<T> *dest = head;
                for(int i=0; i<k-1; i++) dest = dest->next;
                dest->next = new ListNode<T>(value, dest->next);
            }
            size++;
        }
        catch(InvalidIndexException e){
            cerr << "잘못된 인덱스입니다." << endl;
            exit(1);
        }
    }
 
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
 
    int search(T value){ // 값을 찾아 첫번째 인덱스 리턴, 없으면 -1 리턴
        ListNode<T> *temp = head;
        for(int i=0; i<size; i++){
            if(temp->value == value) return i;
            temp = temp->next;
        }
        return -1; // 못 찾음
    }
};