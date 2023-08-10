#ifndef LINKEDLISTCPP2_LINKEDLIST_HPP
#define LINKEDLISTCPP2_LINKEDLIST_HPP

#include <iostream>

template<class T>
class Node {
public:
    T _value;
    Node<T> *_next;  // 指向下一个节点的指针
    Node<T> *_pre;   // 指向前一个节点的指针

    explicit Node(T value);

    Node();
};

// 默认构造函数的实现
template<class T>
Node<T>::Node() {
    _next = nullptr;
    _pre = nullptr;
}

// 带参数的构造函数的实现
template<class T>
Node<T>::Node(T value):_value(value), _next(nullptr), _pre(nullptr) {}

template<class T>
class LinkedList {
private:
    Node<T> *_head;  // 头节点指针
public:
    LinkedList();  // 构造函数

    ~LinkedList();  // 析构函数

    void print() const;  // 打印链表内容

    [[nodiscard]] bool empty() const;  // 检查链表是否为空

    void push_back(T value);  // 在链表尾部添加元素

    void push_front(T value);  // 在链表头部添加元素

    void pop_front();  // 删除链表头部元素

    void pop_back();  // 删除链表尾部元素

    [[nodiscard]] int size() const;  // 获取链表元素数量

    void insert(int position, T value);  // 在指定位置插入元素

    void remove(int position);  // 删除指定位置的元素

    Node<T>* find(T value) const;  // 在链表中查找值为 value 的节点
};

// 在链表中查找值为 value 的节点
template<class T>
Node<T> *LinkedList<T>::find(T value) const {
    Node<T>* cur = _head->_next;
    while(cur != _head){
        if(cur->_value == value){
            return cur;
        }
        cur = cur->_next;
    }
    return nullptr;
}

// 删除指定位置的元素
template<class T>
void LinkedList<T>::remove(int position) {
    if (position < 0 || position >= size()) {
        std::cout << "无效的删除位置！" << std::endl;
        return;
    } else {
        int count = 0;
        Node<T>* cur = _head->_next;
        while(count < position){
            cur = cur->_next;
            count++;
        }
        cur->_pre->_next = cur->_next;
        cur->_next->_pre = cur->_pre;
        delete(cur);
    }
}

// 在指定位置插入元素
template<class T>
void LinkedList<T>::insert(int position, T value) {
    if (position < 0 || position > size()) {
        std::cout << "无效的插入位置！" << std::endl;
        return;
    } else {
        int count = 0;
        Node<T> *cur = _head->_next;
        while (count < position) {
            cur = cur->_next;
            count++;
        }
        // 在 cur 前插入新节点
        auto *newNode = new Node<T>(value);
        newNode->_pre = cur->_pre;
        newNode->_next = cur;
        cur->_pre->_next = newNode;
        cur->_pre = newNode;
    }
}

// 获取链表元素数量
template<class T>
int LinkedList<T>::size() const {
    int count = 0;
    Node<T> *cur = _head->_next;
    while (cur != _head) {
        count++;
        cur = cur->_next;
    }
    return count;
}

// 删除链表尾部元素
template<class T>
void LinkedList<T>::pop_back() {
    if (empty()) {
        std::cout << "链表为空，无法执行尾部删除操作！" << std::endl;
        return;
    } else {
        // 尾节点
        Node<T> *back = _head->_pre;
        if (back->_pre == _head) {
            delete back;
            _head->_next = _head;
            _head->_pre = _head;
        } else {
            back->_pre->_next = _head;
            _head->_pre = back->_pre;
            delete (back);
            back = nullptr;
        }
    }
}

// 删除链表头部元素
template<class T>
void LinkedList<T>::pop_front() {
    if (empty()) {
        std::cout << "链表为空，无法执行头部删除操作！" << std::endl;
        return;
    } else {
        Node<T> *first = _head->_next;
        _head->_next = first->_next;
        first->_next->_pre = _head;
        delete (first);
    }
}

// 在链表头部添加元素
template<class T>
void LinkedList<T>::push_front(T value) {
    auto *newNode = new Node<T>(value);
    newNode->_pre = _head;
    newNode->_next = _head->_next;
    _head->_next = newNode;
    _head->_next->_pre = newNode;
}

// 在链表尾部添加元素
template<class T>
void LinkedList<T>::push_back(T value) {
    auto *newNode = new Node<T>(value);
    newNode->_next = _head;
    newNode->_pre = _head->_pre;
    _head->_pre->_next = newNode;
    _head->_pre = newNode;
}

// 检查链表是否为空
template<class T>
bool LinkedList<T>::empty() const {
    return (_head->_next == _head);
}

// 打印链表内容
template<class T>
void LinkedList<T>::print() const {
    if (empty()) {
        std::cout << "链表为空！" << std::endl;
    }
    Node<T> *cur = _head->_next;
    while (cur != _head) {
        std::cout << cur->_value << " ";
        cur = cur->_next;
    }
    std::cout << std::endl;
}

// 构造函数的实现
template<class T>
LinkedList<T>::LinkedList() {
    _head = new Node<T>();
    _head->_next = _head;
    _head->_pre = _head;
}

// 析构函数的实现
template<class T>
LinkedList<T>::~LinkedList() {
    Node<T> *cur = _head->_next;
    while (cur != _head) {
        Node<T> *next = cur->_next;
        delete (cur);
        cur = next;
    }
    delete (_head);
    _head = nullptr;
}

#endif //LINKEDLISTCPP2_LINKEDLIST_HPP
