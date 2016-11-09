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
    typedef std::weak_ptr<node_t> weak_node_ptr;
    typedef LinkedList<T>::node_t node;

    node_ptr list_head;
    node_ptr list_tail;
    int64_t list_length;

    LinkedList();
    node_ptr new_node();
    
    bool insert(int, T);
    int64_t length();
    void prepend(T);
    void append(T);
    void push(T);
    T pop();

    node_ptr head();
    node_ptr tail();
};

// so ugly but this way the user won't have to
// include it in thier source.
#ifndef __LINKEDLIST_TPP__
#define __LINKEDLIST_TPP__
#include <../src/linkedlist.tcc>
#endif

#endif