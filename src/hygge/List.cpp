#include <hygge/List.h>
#include <stdexcept>
#include <string>

namespace hygge {
List::List() :
    m_front(nullptr),
    m_back(nullptr),
    m_size(0)
{
}

List::~List()
{
    ListNode* curNode = m_front;
    for (size_t i = 0; i < m_size; ++i) {
        ListNode* nextNode = m_front->next;

        delete curNode;
        curNode = nextNode;
    }
}

void List::add(double value, size_t pos)
{
    if (pos > m_size || pos < 0)
        throw std::out_of_range("[List]: Invalid position. Position = {" + std::to_string(pos) + "}");

    if (m_size == 0) {
        ListNode* newNode = new ListNode(nullptr, nullptr, value);
        m_front = newNode;
        m_back = newNode;
        ++m_size;
        return;
    }

    if (pos == 0) {
        ListNode* newNode = new ListNode(m_front, nullptr, value);
        m_front = newNode;
        m_front->prev = newNode;
        ++m_size;
        return;
    }

    if (pos == m_size) {
        ListNode* newNode = new ListNode(nullptr, m_back, value);
        m_back = newNode;
        m_back->prev->next = newNode;
        ++m_size;
        return;
    }

    ListNode* curNode = m_front;
    for (size_t i = 0; i < pos; ++i) {
        curNode = curNode->next;
    }

    ListNode* newNode = new ListNode(curNode, curNode->prev, value);

    curNode->prev->next = newNode;
    curNode->prev = newNode;

    ++m_size;
}

void List::remove(size_t pos)
{
    if (pos > m_size - 1 || pos < 0)
        throw std::out_of_range("[List]: Invalid position. Position = {" + std::to_string(pos) + "}");

    if (m_size == 1) {
        delete m_back;

        m_front = nullptr;
        m_back = nullptr;

        --m_size;
        return;
    }

    if (pos == 0) {
        ListNode* nextNode = m_front->next;

        delete m_front;

        nextNode->prev = nullptr;
        m_front = nextNode;
        m_front->next = nextNode;

        --m_size;
        return;
    }

    if (pos == m_size - 1) {
        ListNode* prevNode = m_back->prev;

        delete m_back;

        prevNode->next = nullptr;
        m_back = prevNode;
        m_back->prev = prevNode;

        --m_size;
        return;
    }

    ListNode* curNode = m_front;
    for (size_t i = 0; i < pos; ++i) {
        curNode = curNode->next;
    }

    curNode->next->prev = curNode->prev;
    curNode->prev->next = curNode->next;

    delete curNode;

    --m_size;
}

ListNode* List::get(size_t pos) const
{
    if (pos > m_size - 1 || pos < 0)
        throw std::out_of_range("[List]: Invalid position. Position = {" + std::to_string(pos) + "}");

    if (pos == 0) {
        return m_front;
    }

    if (pos == m_size - 1) {
        return m_back;
    }

    ListNode* curNode = m_front;
    for (size_t i = 0; i < pos; ++i) {
        curNode = curNode->next;
    }

    return curNode;
}

size_t List::size() const
{
    return m_size;
}

ListNode* List::front() const
{
    return m_front;
}

ListNode* List::back() const
{
    return m_back;
}
}
