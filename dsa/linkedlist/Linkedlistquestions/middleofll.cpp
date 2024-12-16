int getlen(ListNode* head){
    int len= 0 ;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}
    ListNode* middleNode(ListNode* head) {
        int length = getlen(head);
        int ans = length/2 ;
        ListNode*temp = head;
        int cnt = 0;
        while(cnt<ans){
            temp= temp->next;
            cnt++;
        }
        return temp;
        
    }
    
// More optimised 
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        if(head->next->next==NULL){
            return head->next;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
        }
        return slow ;
        
    }