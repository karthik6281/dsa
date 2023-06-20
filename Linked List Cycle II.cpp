class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head ;
        ListNode* fast = head ;
        ListNode* temp = head ;
        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next ;
            fast = fast->next->next ;
            if(slow==fast){
                while(true){
                    if(temp==slow)return slow ;
                    slow=slow->next ;temp = temp->next ; 
                }
            }
        }
        return NULL ;
    }
};