#include<iostream>
using namespace std;

   ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
    ListNode* prev = NULL;
    ListNode* curr = head;
    while(head!=NULL){
    head = curr->next;
    curr->next = prev;
    prev = curr;
    curr = head;
    }
    return prev;
    }
    // recursive solution 
void solve(ListNode* &head,ListNode* curr, ListNode* prev){
        if(curr==NULL){
          head = prev;
          return ;
        }
        Node * forward = curr->next;
        solve(head,forward,curr);
        curr->next = prev;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        solve(head,curr,prev);
        return head; 
    }
    // one more way of doing it recursively 
       // it will return head of reverse linked list
    ListNode* reverseList(ListNode* head) {
      if(head==NULL || head->next == NULL){
        return head;
      }
      // chotahead is the head of remaining linked list other than 1st one 
      ListNode* chotahead = reverseList(head->next);
      // linkage of linked list 
      head->next->next = head;
      head->next = NULL;
      return chotahead;
    }


int main(){
    // iteratively
    // TC = O(n);
    // SC = O(1);
    // recursively
    // SC = O(n);

    return 0;
}