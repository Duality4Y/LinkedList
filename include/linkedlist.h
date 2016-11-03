#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdint.h>
#include <stdio.h>
#include <memory>

template <class T>
class LinkedList
{
public:
    struct node_t;
    typedef std::shared_ptr<node_t> node_ptr;
    typedef LinkedList<T>::node_t node;

    node_ptr head;
    node_ptr tail;

    LinkedList();
    bool insert(int, T);
    node_ptr new_node();
    int64_t length();
    void prepend(T);
    void append(T);
    void push(T);
    T pop();
};

// so ugly but this way the user won't have to
// include it in thier source.
#ifndef __LINKEDLIST_TPP__
#define __LINKEDLIST_TPP__
#include <../src/linkedlist.tcc>
#endif

#endif