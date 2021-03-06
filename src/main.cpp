
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <assert.h>
#include <linkedlist.h>

void test_append()
{
    LinkedList<int> alist;
    alist.append(42);
    assert(alist.start()->value == 42);
    assert(alist.end()->value == 42);

    LinkedList<int> blist;
    for(int i = 0; i < 100; i++)
    {
        blist.append(i);
    }
    assert(blist.start()->value == 0);
    assert(blist.end()->value == 99);
    LinkedList<int>::node_ptr node = blist.start();
    for(int i = 0; i < 100; i++)
    {
        assert(node->value == i);
        node = node->next;
    }
}

void test_prepend()
{
    LinkedList<int> alist;
    
    alist.prepend(42);
    assert(alist.start()->value == 42);
    assert(alist.end()->value == 42);

    LinkedList<int> blist;
    for(int i = 0; i < 100; i++)
    {
        blist.prepend(i);
    }
    assert(blist.end()->value == 0);
    assert(blist.start()->value == 99);
    LinkedList<int>::node_ptr node = blist.start();
    for(int i = 0; i < 100; i++)
    {
        // test for the reversed of the list.
        // since prepending caused this to happen.
        assert(node->value == (99 - i));
        node = node->next;
    }
}

void test_length()
{
    LinkedList<int> alist;
    assert(alist.length() == 0);
    
    alist.append(42);
    assert(alist.length() == 1);
    assert(alist.end()->value == 42);
    assert(alist.start()->value == 42);
    
    alist.prepend(43);
    assert(alist.length() == 2);
    assert(alist.end()->value == 42);
    assert(alist.start()->value == 43);

    for(int i = 0; i < 10000; i++)
    {
        alist.append(i);
    }
    assert(alist.length() == 10002);
    assert(alist.end()->value == 9999);
    assert(alist.start()->value == 43);

    for(int i = 0; i < 10000; i++)
    {
        alist.prepend(i);
    }
    assert(alist.length() == 20002);
    assert(alist.end()->value == 9999);
    assert(alist.start()->value == 9999);
}

void test_insert()
{
    LinkedList<int> alist;
    alist.append(1);
    alist.prepend(0);
    assert(alist.length() == 2);

    assert(alist.insert(1, 2) == true);
    assert(alist.length() == 3);
    assert(alist.start()->value == 0);
    assert(alist.end()->value == 2);

    LinkedList<int>::node_ptr anode = alist.start();
    for(int i = 0; i < 3; i++)
    {
        assert(anode->value == i);
        anode = anode->next;
    }

    LinkedList<int> blist;
    assert(blist.insert(0, 42) == true);
    assert(blist.length() == 1);
    assert(blist.start()->value == 42);
    assert(blist.end()->value == 42);

    assert(blist.insert(1, 43) == true);
    assert(blist.length() == 2);
    
    assert(blist.insert(2, 44) == true);
    assert(blist.length() == 3);
    
    assert(blist.insert(3, 45) == true);
    assert(blist.length() == 4);
    assert(blist.start()->value == 42);
    assert(blist.end()->value == 45);

    assert(blist.insert(0, 2) == true);
    assert(blist.length() == 5);
    assert(blist.start()->value == 42);
    assert(blist.end()->value == 45);
    
    assert(blist.insert(10, 46) == false);
    assert(blist.length() == 5);
    assert(blist.start()->value == 42);
    assert(blist.end()->value == 45);

    assert(blist.insert(-10, 47) == false);
    assert(blist.length() == 5);
    assert(blist.start()->value == 42);
    assert(blist.end()->value == 45);
}

void test_push()
{
    LinkedList<int> alist;
    assert(alist.length() == 0);
    alist.push(42);
    assert(alist.length() == 1);
    assert(alist.start()->value == 42);
    assert(alist.end()->value == 42);

    for(int i = 0; i < 100; i++)
    {
        alist.push(48);
    }
    assert(alist.length() == 101);
    assert(alist.start()->value == 42);
    assert(alist.end()->value == 48);


}

void test_pop()
{
    LinkedList<int> alist;
    for(int i = 0; i < 100; i++)
    {
        alist.push(i);
    }

    for(int i = 99; i >= 0; i--)
    {
        assert(alist.pop() == i);
    }
    assert(alist.length() == 0);
    assert(alist.start() == NULL);
    assert(alist.end() == NULL);

    // raises an exception. or atleast should
    bool isThrown = false;
    try
    {
        alist.pop();
    }
    catch (std::runtime_error e)
    {
        isThrown = true;
    }
    assert(isThrown == true);
}

void test_new_node()
{
    LinkedList<int> alist;
    LinkedList<int>::node_ptr node = alist.new_node();
    assert(node->next == NULL);
    assert(node->value == 0);
    node->value = 0;
    LinkedList<int>::node_ptr anode = alist.new_node();
    node->next = anode;
    anode->value = 1;

    for(int i = 0; i < 2; i++)
    {
        assert(node->value == i);
        node = node->next;
    }
}

void test_forward_loop()
{
    // generate a list to test against.
    // and also put the ints in the LinkedList.
    LinkedList<int> alist;
    std::vector<int> ints;
    std::vector<int> result;
    for(int i = 0; i < 100; i++)
    {
        ints.push_back(i);
        alist.append(i);
    }

    LinkedList<int>::node_ptr i;
    for(i = alist.start(); i; i = alist.next(i))
    {
        result.push_back(i->value);
    }

    assert(ints == result);
}

void test_indexing()
{
    // reading from index
    LinkedList<int> alist;
    for(int i = 0; i < 3; i++)
    {
        alist.append(i);
    }

    assert(alist[0] == 0);
    assert(alist[1] == 1);
    assert(alist[2] == 2);

    bool isThrown = false;
    try
    {
        alist[-1];
    }
    catch (std::runtime_error e)
    {
        isThrown = true;
    }
    assert(isThrown == true);

    isThrown = false;
    try
    {
        alist[3];
    }
    catch (std::runtime_error e)
    {
        isThrown = true;
    }
    assert(isThrown == true);

    // writing to index
    LinkedList<int> blist;

    for(int i = 0; i < 3; i++)
    {
        blist.append(32);
    }

    blist[0] = 0;
    blist[1] = 1;
    blist[2] = 2;

    for(int i = 0; i < 3; i++)
    {
        assert(blist[i] == i);
    }

    for(unsigned int i = 0; i < 3; i++)
    {
        assert(blist[i] == (int)i);
    }

}

int main(void)
{
    std::cout << "Running Tests!" << std::endl;
    test_new_node();
    test_prepend();
    test_append();
    test_length();
    test_insert();
    test_push();
    test_pop();
    test_indexing();

    test_forward_loop();
    // test_reverse_loop();
    std::cout << "All Tests Passed!" << std::endl;

    return 0;
}