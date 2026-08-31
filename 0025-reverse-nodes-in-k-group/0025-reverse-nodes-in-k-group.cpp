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
ListNode* reverselinkedlist(ListNode*temp){
    ListNode* tem=temp;
    ListNode* prev=NULL;
    while(tem!=NULL){
        ListNode* front=tem->next;
        tem->next=prev;
        prev=tem;
        tem=front;
    }
    return prev;
}
ListNode* findkthnode(ListNode* temp, int k){
    k--;
    while(temp!=NULL && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevlast=NULL;
        while(temp!=NULL){
        ListNode* kthnode=findkthnode(temp, k);
        if(kthnode==NULL) 
        {
            if(prevlast) prevlast->next=temp;
            break;
        }
        ListNode* nextnode=kthnode->next;
        kthnode->next=NULL;
        reverselinkedlist(temp);
        if(temp==head) head=kthnode;
        else{
                prevlast->next=kthnode;
        }
        prevlast=temp;
        temp=nextnode;
        }
        return head;
    }
};