
template <class T>
struct LinkedList<T>::node_t
{
    T value;
    node_ptr next;
    node_ptr prev;
};

template <class T>
LinkedList<T>::LinkedList()
{
    this->head = NULL;
    this->tail = NULL;
}

template <class T>
typename LinkedList<T>::node_ptr LinkedList<T>::new_node()
{
    node_ptr node(new LinkedList<T>::node());
    return node;
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
        node->value = this->head->value;
        this->head = NULL;
        this->tail = NULL;
        return node->value;
    }
    else
    {
        /* 
            else find the second last one. make it the tail.
            and cut the connection to the last one. and return it.
        */
        node_ptr current;
        for(current = this->head; current->next->next; current = current->next);
        
        node->value = current->next->value;
        this->tail = current;
        // TODO keep track of nodes that are removed so that they can be freed.
        current->next = NULL;
        
        return node->value;
    }
}

/* insert a new node after index.*/
template <class T>
bool LinkedList<T>::insert(int index, T value)
{
    return false;
}

/* prepend a node at the front of the list */
template <class T>
void LinkedList<T>::prepend(T value)
{
    /*
      incase of an empty list there is a new node created and the head and tail
      are both set to be pointing to it.
    */
    if(!head && !tail)
    {
        node_ptr node = this->new_node();
        node->value = value;

        this->tail = node;
        this->head = node;

        node->next = NULL;
        node->prev = NULL;
    }
    else
    {
        /* otherwise just prepend to the head. and set the new node to be the head. */
        node_ptr node = this->new_node();
        node->value = value;

        node->next = this->head;
        this->head->prev = node;

        this->head = node;
    }
}

/* append a new node to the end of the list.*/
template <class T>
void LinkedList<T>::append(T value)
{
    /* if the list is empty insert a new node and set both head and tail to it.*/
    if(!head && !tail)
    {
        node_ptr node = this->new_node();
        node->value = value;

        this->tail = node;
        this->head = node;

        node->next = NULL;
        node->prev = NULL;
    }
    else
    {
        /* else a new node is appended and the tail is set to the new node.*/
        node_ptr node = this->new_node();
        node->value = value;

        node->prev = this->tail;
        this->tail->next = node;

        this->tail = this->tail->next;
    }
}

/* return the number of items in the list. */
template <class T>
int64_t LinkedList<T>::length()
{
    if(!head and !tail)
        return 0;
    if(head == tail)
        return 1;

    // iterate over the list and return the count of items on it.
    int64_t count = 0;
    for(node_ptr i = head; i; i = i->next)
        count++;
    return count;
}