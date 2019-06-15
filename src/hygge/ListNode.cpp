#include <hygge/ListNode.h>

namespace hygge {
ListNode::ListNode() :
    next(nullptr),
    prev(nullptr)
{
}

ListNode::ListNode(ListNode* next, ListNode* prev, double value) :
    next(next),
    prev(prev),
    value(value)
{
}
}
