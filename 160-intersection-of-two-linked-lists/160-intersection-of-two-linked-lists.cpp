/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = 0, b = 0;
        ListNode* l1 = headA, *l2 = headB;
        
        while(l1)
        {
            a++;
            l1 = l1 ->next;
        }        
        while(l2)
        {
            b++;
            l2 = l2 ->next;
        }
        while(a-b>0)
        {
            headA = headA->next;
            a--;
        }        
        while(b-a>0)
        {
            headB = headB->next;
            b--;
        }
        while(headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        
    return headA;
    }
};