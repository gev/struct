#define null 0
#define bool int
#define true 1
#define false 0

typedef struct
{
    int size;
    void **data;
} list_t;

list_t *create(int size)
{
    list_t *list = malloc(sizeof(list_t));
    list->size = size;
    list->data = alloc(size * sizeof(void *), null);
    return list;
}

void destroy(list_t *list)
{
    free(list->data);
    free(list);
}

void *get(list_t *list, int i)
{
    if (i >= list->size)
        return null;
    return list->data[i];
}

bool set(list_t *list, int i, char v)
{
    if (i >= list->size)
        return false;
    list->data[i] = v;
    return true;
}

bool remove(list_t *list, int i)
{
    if (i >= list->size)
        return false;

    char *data = malloc((list->size - 1) * sizeof(char));

    for (int j = 0; j < i; j++)
    {
        data[j] = list->data[j];
    }

    for (int j = i + 1; j < list->size; j++)
    {
        data[j] = list->data[j - 1];
    }

    free(list->data);
    list->data = data;
    list->size--;

    return true;
}

bool insert(list_t *list, int i, void *v)
{
    if (i >= list->size)
        return false;

    char *data = malloc((list->size + 1) * sizeof(char));

    for (int j = 0; j < i; j++)
    {
        data[j] = list->data[j];
    }

    data[i] = v;

    for (int j = i + 1; j < list->size + 1; j++)
    {
        data[j] = list->data[j - 1];
    }

    free(list->data);
    list->data = data;
    list->size++;

    return true;
}

list_t *concat(list_t *a, list_t *b)
{
    list_t *list = create(a->size + b->size);
    for (int i = 0; i < a->size; i++)
    {
        set(list, i, get(a, i));
    }
    for (int i = 0; i < b->size; i++)
    {
        set(list, a->size + i, get(b, i));
    }
    return list;
}

int a = 1;
int b = 2;

int main()
{
    int *c = malloc(sizeof(int));
    *c = 3;
    list_t *list = create(10);
    set(list, 0, &a);
    set(list, 1, &b);
    set(list, 3, c);
    destroy(list);
    free(c);
    return 0;
}
