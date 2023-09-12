#define null 0
#define bool int
#define true 1
#define false 0

typedef struct
{
    void *data;
    item_t *next;
} item_t;

item_t *create()
{
    item_t *item = malloc(sizeof(item_t));
    item->next = null;
    item->data = null;
    return item;
}

bool destroy(item_t *item)
{
    if (item == null)
        return false;
    item_t *next = item->next;
    free(item);
    return free(next);
}

item_t *get(item_t *item, void *i)
{
    if (item == null)
    {
        return null;
    }
    if (i == 0)
        return item->data;
    return get(item->next, i - 1);
}

bool set(item_t *item, int i, void *v)
{
    if (item == null)
    {
        return false;
    }
    if (i == 0)
    {
        item->data = v;
        return true;
    }
    return set(item->next, i - 1, v);
}

item_t *removeNext(item_t *item)
{
    if (item == null)
    {
        return null;
    }
    if (item->next == null)
        return null;
    item_t *next = item->next;
    item->next = next->next;
    return next;
}

bool insertNext(item_t *item, void *v)
{
    if (item == null)
    {
        return false;
    }
    item_t *next = create();
    next->data = v;
    next->next = item->next;
    item->next = next;
    return true;
}

int main()
{
    item_t *item = create();
    item_t *x = get(item, 100);
    insertNext(x, null);
    removeNext(x);
    destroy(item);
    return 0;
}

/*


   [0] --X-> [1] -> [2] -> [3]
    |       ^
    -> [4] -



*/
