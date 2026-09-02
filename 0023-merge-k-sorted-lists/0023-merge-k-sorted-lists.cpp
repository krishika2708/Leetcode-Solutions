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


 //BRUTE FORCE


// class Solution {
// public:

//  ListNode* convert(vector<int>array){
//      ListNode* dummynode=new  ListNode();
//       ListNode*dummypointer=dummynode;
//     for(int i=0;i<array.size();i++){
//          ListNode*newnode=new  ListNode(array[i]);
//             dummypointer->next=newnode;
//             dummypointer=newnode;
//     }
//     return dummynode->next;
//  }
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         vector<int> arr;
//         for (int i = 0; i < lists.size(); i++) {
//             ListNode* temp = lists[i];
//             while (temp != NULL) {
//                 arr.push_back(temp->val);
//                 temp = temp->next;
//             }
//         }
//         sort(arr.begin(),arr.end());
//          ListNode*head=convert(arr);
//         return head;
//     }
// };


//OPTIMAL USING PRIORITY QUEUE( min heap)
class Solution {
public:
 ListNode* mergeKLists(vector<ListNode*>& lists) {
priority_queue<pair<int,ListNode* >, vector<pair<int,ListNode* >>, greater<pair<int,ListNode* >>>pq;
for(int i=0;i<lists.size();i++){
    if(lists[i]){
        pq.push({lists[i]->val, lists[i]});

    }
}
 ListNode* dummynode=new ListNode(-1);
 ListNode* temp=dummynode;
 while(!pq.empty()){
    auto it=pq.top();
    pq.pop();
  
    if(it.second->next){
        pq.push({it.second->next->val, it.second->next});
    }
        temp->next=it.second;
        temp=temp->next;
    
    
 }
 return dummynode->next;
 }
};