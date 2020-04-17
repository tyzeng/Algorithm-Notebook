/**
 * 纯靠暴力，没有参考别人的题解。熟悉了一下结构体指针的用法。之后二刷时再参考一下别人的题解吧
 */

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* res = NULL;
        ListNode* cur;
        int c = 0; //进位
        int s = 0;

        //初始
        if(l1 != NULL) {
            s += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL) {
            s += l2->val;
            l2 = l2->next;
        }
        c = s/10;
        s = s%10;
        cur = new ListNode(s);
        res = cur;

        while(l1 != NULL || l2 != NULL )
        {

            s = c;
            if(l1 != NULL)
                s += l1->val;
            if(l2 != NULL)
                s += l2->val;

            c = s/10;
            s = s%10;

            cur->next = new ListNode(s);;
            cur = cur->next;

            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }
        if(c > 0)
            cur->next = new ListNode(c);

        return res;
    }
};
