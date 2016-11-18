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

    LinkedList();
    node_ptr new_node();
    
    bool insert(int, T);
    int64_t length();
    void prepend(T);
    void append(T);
    void push(T);
    T pop();

    T& operator[] (const int index);

    node_ptr start();
    node_ptr end();
    node_ptr next(node_ptr);
    weak_node_ptr prev(node_ptr);
};

// so ugly but this way the user won't have to
// include it in thier source.
#ifndef __LINKEDLIST_TPP__
#define __LINKEDLIST_TPP__
#include <../src/linkedlist.tcc>
#endif

#endif