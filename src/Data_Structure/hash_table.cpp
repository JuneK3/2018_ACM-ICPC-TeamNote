#include <cstring>
#include <iostream>
#include <list>
using namespace std;

#define HTSIZE 137  // prime number

struct Node {
  Node(char* n, float v) : val(v) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
  }
  char* name;
  float val;
};

list<Node> HT[HTSIZE];  // Hash Table;

int hashfcn(char* name) { return name[0] * name[strlen(name) - 1] % HTSIZE; }

bool GetFromHT(char* name, float& val) {
  int hashVal = hashfcn(name);
  list<Node>::iterator iter;
  for (iter = HT[hashVal].begin(); iter != HT[hashVal].end(); iter++) {
    if (!strcmp(iter->name, name)) {  // Found the Value
      val = iter->val;
      return true;
    }
  }
  return false;
}

void StoreIntoHT(char* name, float val) {
  int hashVal = hashfcn(name);
  list<Node>::iterator iter;
  for (iter = HT[hashVal].begin(); iter != HT[hashVal].end(); iter++) {
    if (!strcmp(iter->name, name)) {  // Found the Value
      val = iter->val;                // Value updated
      return;
    }
  }
  HT[hashVal].push_front(Node(name, val));
}

void PrintValue(char* name) {
  float val;
  if (!GetFromHT(name, val)) {
    cout << name << "does not exist.\n";
  } else {
    cout << name << ": " << val << '\n';
  }
}

int main() {
  StoreIntoHT((char*)"abro", 23);
  StoreIntoHT((char*)"bb", 34.5);
  StoreIntoHT((char*)"haha", 99);
  StoreIntoHT((char*)"bb", 1234.5);
  PrintValue((char*)"abro");
  PrintValue((char*)"bb");
  PrintValue((char*)"haha");
  PrintValue((char*)"hoho");
  return 0;
}