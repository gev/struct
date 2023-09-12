
#define null 0

char a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

char *get(char *a, int size, int i)
{
    if (i >= size)
        return null;
    return &a[i];
}

void set(char *a, int i, char v)
{
    a[i] = v;
}

int main()
{
    char *a5 = get(a, 10, 5);
    if (a5 != null)
    {
        printf("%c\n", *a5);
    }
    return 0;
}
