#include<iostream>
#include<vector>
using namespace std; // 引入命名空间，简化代码

struct ListNode{
    ListNode *next;
    int val;
    ListNode(int t):val(t),next(nullptr){}
};

// 反转链表函数
ListNode* reverse(ListNode* head){
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while(cur){
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next; 
    }
    return pre;
}

// 将vector转换为链表
ListNode* vectorToList(const vector<int>& nums) {
    if (nums.empty()) return nullptr; // 空vector返回空链表
    
    ListNode* head = new ListNode(nums[0]); // 头节点
    ListNode* cur = head;
    
    // 依次创建后续节点
    for (size_t i = 1; i < nums.size(); ++i) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    return head;
}

// 打印链表
void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur) {
        cout << cur->val;
        if (cur->next) cout << " -> "; // 最后一个节点后不打印箭头
        cur = cur->next;
    }
    cout << endl;
}

// 释放链表内存（避免内存泄漏）
void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){
    vector<int> nums = {1,2,3,4};
    
    // 转换为链表
    ListNode* head = vectorToList(nums);
    cout << "原链表: ";
    printList(head);
    
    // 反转链表
    ListNode* reversedHead = reverse(head);
    cout << "反转后: ";
    printList(reversedHead);
    
    // 释放内存
    freeList(reversedHead);
    return 0;
}