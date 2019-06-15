#pragma once

#include <hygge/ListNode.h>

namespace hygge {
class List
{
public:
    List();

    ~List();

    void add(double value, size_t pos);

    void remove(size_t pos);

    ListNode* get(size_t pos) const;

    size_t size() const;

    ListNode* front() const;

    ListNode* back() const;

private:
    ListNode* m_front;

    ListNode* m_back;

    size_t m_size;
};
}