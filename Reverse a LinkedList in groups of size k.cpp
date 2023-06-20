ListNode* reverse(ListNode* node , int k , ListNode* bef){
    ListNode* temp = node ;
    ListNode* cur = bef ;
    ListNode* prev = NULL ;
    ListNode* next = node ;
    int count = 0 ;
    while(count < k){
        cur = next ;
        next = next->next ;
        cur->next = prev ;
        prev = cur ;
        count++ ;
    }
    temp->next = next ;
    if(bef!=NULL)bef->next = cur ;
    return temp ;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    int count = 0 ;
    ListNode* ans = head ;
    ListNode* temp = head ;
    while(temp!=NULL){
        if(count==k-1)ans= temp ;
        temp = temp->next ;count++ ;
    }
    ListNode* prev = NULL ;
    ListNode* node = head ;
    while(count-k >= 0){
        prev = reverse(node,k,prev) ;
        count -= k ;
        node = prev->next ;
    }
    return ans ;
}