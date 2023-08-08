#include <iostream>
#include <ostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// recursive
ListNode *reverseList(ListNode *head) {
  if (!head) {
    return nullptr;
  }

  ListNode *new_head = head;
  if (head->next) {
    new_head = reverseList(head->next);
    head->next->next = head;
  }
  head->next = nullptr;

  return new_head;
}

// iterate
ListNode *reverseList(ListNode *head) {
  ListNode *prev = nullptr;
  while (head) {
    ListNode *curr = head;
    head = head->next;
    curr->next = prev;
    prev = curr;
  }
  return prev;
}

ostream &operator<<(ostream &out, ListNode *head) {
  ListNode *node = head;
  for (; node;) {
    out << node->val << " "s;
    node = node->next;
  }

  return out;
}
int main() {
  ListNode head{1};
  ListNode node_2{2};
  ListNode node_3{3};
  ListNode node_4{4};
  ListNode node_5{5};

  head.next = &node_2;
  node_2.next = &node_3;
  node_3.next = &node_4;
  node_4.next = &node_5;

  cout << reverseList(&head) << endl;
}