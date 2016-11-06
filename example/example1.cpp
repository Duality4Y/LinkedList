#include <stdio.h>
#include <linkedlist.h>

LinkedList<int> list;

void print_list(LinkedList<int> list)
{
    printf("[");
    LinkedList<int>::node_ptr i;
    for(i = list.head; i; i = i->next)
    {
        if(i != list.tail)
            printf("%d, ", i->value);
        else
            printf("%d]\n", i->value);
    }
}

int main(void)
{
    printf("Hello World!\n");
    
    printf("list.append(0)\n");
    list.append(0);
    print_list(list);
    printf("list.prepend(1)\n");
    list.prepend(1);
    print_list(list);
    printf("list.insert(0, 42)\n");
    list.insert(0, 42);
    print_list(list);
    printf("list.insert(0, 43)\n");
    list.insert(0, 43);
    print_list(list);
    printf("list.pop()\n");
    list.pop();
    print_list(list);
    printf("list.push(80)\n");
    list.push(80);
    print_list(list);
    return 0;
}
