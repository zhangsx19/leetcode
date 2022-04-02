#include <iostream>
using namespace std;
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
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur = new ListNode();
        ListNode* pre = cur;//cur会移动，所以要用预先指针pre来保存cur的头信息，pre的next才是开始
        int carry = 0;//进位
        while (l1!=nullptr||l2!=nullptr)
        {
            int l1_val = l1==nullptr?0:l1->val, l2_val = l2==nullptr?0:l2->val;//不等长的链表要补0
            int sum = l1_val + l2_val + carry;
            carry = sum / 10;
            sum %= 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
            //移动l1,l2时要注意null不能取next
            if (l1!=nullptr)
            {
                l1 = l1->next;
            }
            if (l2!=nullptr)
            {
                l2 = l2->next;
            }
        }
        if (carry == 1)//最后一位相加可能是两位数
        {
            cur->next = new ListNode(carry);
        }
        
        return pre->next;
    }
};
