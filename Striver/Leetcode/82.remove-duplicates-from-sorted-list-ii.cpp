/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 */

// @lc code=start
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
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        //         if(head==NULL || head->next == NULL)
        //             return head;

        //         set<int> s;

        //         ListNode *temp = head;

        //         while(temp!=NULL && temp->next!=NULL){
        //             if(temp->val == temp->next->val){
        //                 ListNode *del = temp->next;
        //                 s.insert(del->val);
        //                 temp->next = del->next;
        //                 delete del;
        //             }
        //             else{
        //                 temp = temp->next;
        //             }
        //         }

        //         ListNode *prev = head;
        //         temp = head->next;

        //         while(temp!=NULL){
        //             if(s.find(temp->val) != s.end()){
        //                 ListNode *del = temp;
        //                 temp = temp->next;
        //                 prev->next = prev->next->next;
        //                 delete del;
        //             }
        //             else{
        //                 temp = temp->next;
        //                 prev = prev->next;
        //             }
        //         }

        //         if(s.find(head->val) != s.end())
        //             return head->next;
        //         else
        //             return head;
        //     }
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;

        while (head != NULL && head->next != NULL)
        {
            if (head->next != NULL && head->val == head->next->val)
            {
                while (head->next != NULL && head->val == head->next->val)
                    head = head->next;

                prev->next = head->next;
            }
            else
                prev = prev->next;

            head = head->next;
        }

        return dummy->next;
    }
};
// @lc code=end
