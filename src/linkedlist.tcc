
template <class T>
struct LinkedList<T>::node_t
{
    T value;
    node_ptr next;
    weak_node_ptr prev;
};

template <class T>
typename LinkedList<T>::node_ptr LinkedList<T>::new_node()
{
    node_ptr node(new LinkedList<T>::node());
    return node;
}

/* insert a new node after index.*/
template <class T>
bool LinkedList<T>::insert(int index, T value)
{
    /* if there is no list or inserting at the end
       then a node can simply be appended.
    */
    if(!this->length() || index == this->length())
    {
        this->append(value);
        return true;
    }

    if(index >= 0 && index < this->length())
    {
        node_ptr node = this->new_node();
        node->value = value;

        node_ptr next;
        weak_node_ptr prev;
        node_ptr current = this->list_head;

        /* Iterate over to the right place to insert. */
        int i;
        for(i = 0; i < index; i++)
            current = current->next;


        next = current->next;
        prev = current->prev;
        /* 
            no next node means inserting a new tail.
            else insert a node between two nodes.
        */
        if(!next)
        {
            node->prev = list_tail;
            list_tail->next = node;
            list_tail = node;
        }
        else
        {

            current->next = node;
            node->prev = current;

            node->next = next;
            next->prev = node;
        }
        this->list_length += 1;
        return true;
    }
    return false;
}

/* return the number of items in the list. */
template <class T>
int64_t LinkedList<T>::length()
{
    // if(!list_head and !list_tail)
    //     return 0;
    // if(list_head == list_tail)
    //     return 1;

    // // iterate over the list and return the count of items on it.
    // int64_t count = 0;
    // for(node_ptr i = list_head; i; i = i->next)
    //     count++;
    // return count;
    return this->list_length;
}

/* prepend a node at the front of the list */
template <class T>
void LinkedList<T>::prepend(T value)
{
    /*
      incase of an empty list there is a new node created and the head and tail
      are both set to be pointing to it.
    */
    if(!list_head && !list_tail)
    {
        node_ptr node = this->new_node();
        node->value = value;

        this->list_tail = node;
        this->list_head = node;

        node->next = NULL;
        node->prev = node->next;
    }
    else
    {
        /* otherwise just prepend to the head. and set the new node to be the head. */
        node_ptr node = this->new_node();
        node->value = value;

        node->next = this->list_head;
        this->list_head->prev = node;

        this->list_head = node;
    }

    this->list_length += 1;
}

/* append a new node to the end of the list.*/
template <class T>
void LinkedList<T>::append(T value)
{
    /* if the list is empty insert a new node and set both head and tail to it.*/
    if(!list_head && !list_tail)
    {
        node_ptr node = this->new_node();
        node->value = value;

        this->list_tail = node;
        this->list_head = node;

        node->next = NULL;
        node->prev = node->next;
    }
    else
    {
        /* else a new node is appended and the tail is set to the new node.*/
        node_ptr node = this->new_node();
        node->value = value;

        node->prev = this->list_tail;
        this->list_tail->next = node;

        this->list_tail = this->list_tail->next;
    }

    this->list_length += 1;
}

/* pushes a node onto the end of the list. */
template <class T>
void LinkedList<T>::push(T value)
{
    this->append(value);
}

/* pops a node off of the end of the list. */
template <class T>
T LinkedList<T>::pop()
{
    /* erroring if list is empty */
    if(this->length() == 0)
    {
        /* obviously erroring here but how to convey that? */
        throw std::runtime_error("Error: Popping off of end of list.\n");
        return 0;
    }

    node_ptr node = this->new_node();

    /* if there is one node then simply return that. */
    if(this->length() == 1)
    {
        node->value = this->list_head->value;
        T value = T(node->value);
        this->list_head = NULL;
        this->list_tail = NULL;

        this->list_length -= 1;

        return value;
    }
    else
    {
        /* 
            else find the second last one. make it the tail.
            and cut the connection to the last one. and return it.
        */
        node_ptr current;
        for(current = this->list_head; current->next->next; current = current->next);
        
        T value = T(current->next->value);
        this->list_tail = current;
        current->next = NULL;

        this->list_length -= 1;

        return value;
    }
}

template <class T>
typename LinkedList<T>::node_ptr LinkedList<T>::head()
{
    return this->list_head;
}

template <class T>
typename LinkedList<T>::node_ptr LinkedList<T>::tail()
{
    return this->list_tail;
}

template <class T>
typename LinkedList<T>::Iterator begin()
{
    return LinkedList<T>::Iterator(this->head);
}

template <class T>
typename LinkedList<T>::Iterator end()
{
    return LinkedList<T>::Iterator(this->tail);
}

template <class T>
typename LinkedList<T>::Iterator rbegin()
{
    return LinkedList<T>::Iterator(this->tail);
}

template <class T>
typename LinkedList<T>::Iterator rend()
{
    return LinkedList<T>::Iterator(this->head);
}
