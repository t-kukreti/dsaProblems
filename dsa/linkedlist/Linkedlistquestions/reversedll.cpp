// HOMEWORK -> reverse a doubly linked list 
Node* reverseDLL(Node * head)
{
   Node* temp = head;
   Node* curr = head;
   Node* pre = NULL;
   while(temp != NULL){
       temp = curr->next;
       curr->next = pre;
       curr->prev = temp;
       pre = curr;
       curr = temp;
   }
   return pre;
}