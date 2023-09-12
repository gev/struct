#define null 0
#define bool int
#define true 1
#define false 0

typedef struct
{
    item_t *head;
    item_t *tail;
} list_t;

typedef struct
{
    void *data;
    item_t *next;
    item_t *prev;
} item_t;

item_t *createItem()
{
    item_t *item = malloc(sizeof(item_t));
    item->next = null;
    item->prev = null;
    item->data = null;
    return item;
}

void destroyItem(item_t *item)
{
    if (item == null)
        return;
    free(item);
}

list_t *createList()
{
    list_t *list = malloc(sizeof(list_t));
    list->head = null;
    list->tail = null;
    return list;
}

void destroyList(list_t *list)
{
    if (list == null)
        return;
    item_t *item = list->head;
    while (item != null)
    {
        item_t *next = item->next;
        destroyItem(item);
        item = next;
    }
    free(list);
}

item_t *get(list_t *list, int i)
{
    if (list == null)
        return null;
    item_t *item = list->head;
    while (item != null && i > 0)
    {
        item = item->next;
        i--;
    }
    return item;
}

item_t *set(list_t *list, int i, void *v)
{
    if (list == null)
        return null;
    item_t *item = get(list, i);
    if (item == null)
        return null;
    item->data = v;
    return item;
}

item_t *remove(list_t *list, int i)
{
    if (list == null)
        return null;
    item_t *item = get(list, i);
    if (item == null)
        return null;
    if (item->prev == null)
        list->head = item->next;
    else
        item->prev->next = item->next;
    if (item->next == null)
        list->tail = item->prev;
    else
        item->next->prev = item->prev;
    destroyItem(item);
    return item;
}

bool insert(list_t *list, int i, void *v)
{
    if (list == null)
        return false;
    item_t *item = createItem();
    item->data = v;
    if (i == 0)
    {
        item->next = list->head;
        if (list->head != null)
            list->head->prev = item;
        list->head = item;
    }
    else
    {
        item->prev = get(list, i - 1);
        item->next = get(list, i);
        if (item->prev != null)
            item->prev->next = item;
        if (item->next != null)
            item->next->prev = item;
    }
    return true;
}

bool appendLast(list_t *list, void *v)
{
    if (list == null)
        return false;
    item_t *item = createItem();
    item->data = v;
    if (list->tail != null)
        list->tail->next = item;
    list->tail = item;
    if (list->head == null)
        list->head = item;
    return true;
}

bool appendFirst(list_t *list, void *v)
{
    if (list == null)
        return false;
    item_t *item = createItem();
    item->data = v;
    if (list->head != null)
        item->next = list->head;
    list->head = item;
    if (list->tail == null)
        list->tail = item;
    return true;
}

bool removeFirst(list_t *list)
{
    if (list == null)
        return false;
    item_t *item = list->head;
    if (item == null)
        return false;
    if (item->next == null)
        list->tail = null;
    else
        item->next->prev = null;
    list->head = item->next;
    destroyItem(item);
    return true;
}

item_t *removeLast(list_t *list)
{
    if (list == null)
        return null;
    item_t *item = list->tail;
    if (item == null)
        return null;
    if (item->prev == null)
        list->head = null;
    else
        item->prev->next = null;
    list->tail = item->prev;
    destroyItem(item);
    return item;
}

bool push(list_t *list, void *v)
{
    return appendLast(list, v);
}

item_t *pop(list_t *list)
{
    return removeLast(list);
}

bool unshift(list_t *list, void *v)
{
    return appendFirst(list, v);
}

item_t *shift(list_t *list)
{
    return removeFirst(list);
}
