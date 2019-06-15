#pragma once

namespace hygge {
class ListNode
{
public:
    ListNode();

    ListNode(ListNode* next, ListNode* prev, double value);

    ~ListNode() = default;

    ListNode* next;
    
    ListNode* prev;
    
    double value;
};
}