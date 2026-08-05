/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }
        int from_front = length - n + 1;
        temp = head;
        int ptr=1;
        if(from_front==1&&length==1){
            return nullptr;
        }
        if(from_front==1){
            return head->next;
        }
        while (temp) {
            ListNode* prev=temp;
            if(ptr==from_front-1){
               temp->next=temp->next->next;
                break;
            }
            temp=temp->next;
            ptr++;
        }
        return head;
    }
};
