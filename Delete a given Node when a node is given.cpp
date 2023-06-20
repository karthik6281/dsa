void deleteNode(ListNode* node) {
        *node = *node->next ;
    }

// 

void deleteNode(ListNode* node) {
        node->val = node->next->val ;
        node->next = node->next->next ;
    }