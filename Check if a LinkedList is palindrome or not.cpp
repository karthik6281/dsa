class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head ;
        ListNode* fast = head ;
        while(fast->next!= NULL && fast->next->next != NULL){
            slow = slow->next ; fast = fast->next->next ;
        }
        ListNode* prev = NULL ;
        ListNode* cur = NULL ;
        ListNode* next = slow->next ;
        while(next!= NULL){
            cur = next ;
            next = next->next ;
            cur->next = prev ;
            prev =cur ;
        }
        slow->next = cur ;
        slow = slow->next ;
        ListNode* temp = head ;
        while(slow!=NULL){
            if(slow->val!=temp->val)return false ;
            slow = slow->next ;
            temp = temp->next ;
        }
        return true ;
    }
};