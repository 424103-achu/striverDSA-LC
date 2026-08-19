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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
        if(temp->next==nullptr){
            return head;
        }
        while(temp->next!=nullptr){
            ListNode* newNode=new ListNode();
            int a=temp->val;
            int b=temp->next->val;
            while(b!=0){
                int tempp=b;
                b=a%b;
                a=tempp;
            }
            newNode->val=a;
            newNode->next=temp->next;
            temp->next=newNode;
            temp=newNode->next;
        }        
        return head;
    }
};