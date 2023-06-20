ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL ;
    ListNode* cur = NULL ;
    ListNode* next = head ;
    while(next!= NULL){
        cur = next ;
        next = cur->next ;
        cur->next = prev ;
        prev = cur ;
    }
    return cur ;
}

// 

ListNode* reverseList(ListNode* head) {
    ListNode* newHead = NULL ;
    while(head!= NULL){
        ListNode* temp = head->next ;
        head->next = newHead;
        newHead = head ;
        head = temp ;
    }
    return newHead ;
}

// 

ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next == NULL)return head ;
    ListNode* temp = reverseList(head->next) ;
    head->next->next = head ;
    head->next = NULL;
    return temp ;
}