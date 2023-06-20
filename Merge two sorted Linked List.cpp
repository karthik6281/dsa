ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* ans = NULL ;
    if(list1==NULL)return list2 ;
    if(list2==NULL)return list1 ;
    if(list1->val <= list2->val){
        ans = new ListNode(list1->val) ;
        list1 = list1->next ;
    }
    else{
        ans = new ListNode(list2->val) ;
        list2 = list2->next ;
    } 
    ListNode* temp = ans ;
    while(true){
        if(list1 == NULL && list2 == NULL)break ; 
        else if(list1 == NULL){ans->next = list2 ;break ;}
        else if(list2 == NULL){ans->next = list1 ; break ;}
        else{
            if(list1->val <= list2->val){put(list1->val,ans);list1 = list1->next ;}
            else{put(list2->val,ans);list2 = list2->next ;}
        }
    }
    return temp ;

}

// 

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1==NULL)return list2 ;
    if(list2==NULL)return list1 ;
    if(list1->val > list2->val)swap(list1,list2) ;
    ListNode* ans = list1 ;
    while(list1!=NULL && list2!=NULL){
        ListNode* temp = NULL ;
        while(list1!=NULL && list1->val<=list2->val){
            temp = list1 ;
            list1 = list1->next ;
        }
        swap(list1,list2) ;
        temp->next = list1 ;
    }
    return ans ;
}