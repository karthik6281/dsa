ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_map<ListNode*, int> m ;
    while(headA!=NULL){m[headA]++; headA=headA->next;}
    while(headB!=NULL){
        if(m[headB]!=0){
            return headB ;
        }
        headB=headB->next;
    }
    return NULL ;
}

// 

class Solution {
public:
    ListNode* func(ListNode *a, ListNode *b,int diff){
        while(diff--)a=a->next ;
        while(true){
            if(a==NULL)break ;
            else if (a==b)return a ;
            a=a->next ; b=b->next ;
        }
        return NULL ;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA ;
        ListNode* temp2 = headB ;
        int count1= 0 ; int count2=0 ;
        while(temp1!=NULL){count1++;temp1=temp1->next;}
        while(temp2!=NULL){count2++;temp2=temp2->next;}
        int diff = abs(count1-count2) ;
        if(count2>count1)return func(headB , headA,diff) ;
        return func(headA,headB,diff) ;
    }
};

// 

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* temp1 = headA ;
    ListNode* temp2 = headB ;
    while(temp1!=temp2){
        temp1 = temp1==NULL? headB : temp1->next ;
        temp2 = temp2==NULL? headA : temp2->next ;
    }
    return temp1 ;
}