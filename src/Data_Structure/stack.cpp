#include <iostream>
using namespace std;

template <typename T>
class Stack {
public:
	struct Node {
		T val;
		Node *next;
		Node() : next(nullptr){}
		Node(T val) : val(val), next(nullptr){}
	};
    
	Node *head;
	int _size;
	Stack() : _size(0), head(nullptr){}
    
	void push(T val) {
		Node *temp = new Node(val);
		if (head == nullptr)
			head = temp;
		else {
			temp->next = head;
			head = temp;
		}
		_size++;
	}
    
	void pop() {
		Node *temp = head;
		head = head->next;
		delete temp;
		_size--;
	}
    
	bool empty() const{
		return _size == 0;
	}
    
	T top() const{
		return head->val;
	}
    
	int size() const{
		return _size;
	}
    
};

int main(){
  Stack<int> st;
  st.push(1);
  st.push(3);
  st.push(2);
  st.push(5);
  int len = st.size();
  for(int i=0; i<len; i++){
    int temp = st.top();
    st.pop();
    cout << temp << '\n';
  }
  cout << st.empty() << '\n';
  return 0;
}