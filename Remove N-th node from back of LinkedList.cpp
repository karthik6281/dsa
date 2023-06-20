ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len = 0 ; 
    ListNode* temp = head ;
    while(temp!=NULL){len++ ;temp=temp->next ;} ;
    int req = len-n ;
    if(req == 0){
        if(len==1)return NULL ;
        return head->next ;
    }
    int count = 0 ;
    ListNode* check = head ;
    while(true){
        if(count == req-1){
            if(check->next==NULL)check->next = NULL ;
            else check->next = check->next->next ;
            break ;
        }
        count++ ; 
        check = check->next ;
    }
    return head ;
}

// 

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* temp = head ;
    ListNode* dummy = new ListNode(101) ;
    dummy->next = head ;
    ListNode* slow = dummy ;
    ListNode* fast = dummy ;
    int count = 0 ;
    while(count <= n-1){fast = fast->next ;count++ ;}
    while(fast->next!=NULL){fast=fast->next ; slow=slow->next ;}
    slow->next = slow->next->next ;
    return dummy->next ;
}
