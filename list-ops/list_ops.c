#include "list_ops.h"

list_t *new_list(size_t length, list_element_t elements[])
{
    list_t *list = malloc(sizeof(list_t) + sizeof(list_element_t) * length);
    if (!list)
        return NULL;

    list->length = length;
    for (size_t i = 0; i < length; i++)
        list->elements[i] = elements[i];

    return (list);
}

list_t *append_list(list_t *list1, list_t *list2)
{
    if (list1 == NULL || list2 == NULL)
        return (NULL);

    size_t new_length = list1->length + list2->length;
    list_t *list = malloc(sizeof(list_t) + sizeof(list_element_t) * new_length);
    if (!list)
        return NULL;

    list->length = new_length;
    for (size_t i = 0; i < list1->length; i++)
        list->elements[i] = list1->elements[i];

    size_t j = 0;
    for (size_t i = list1->length; i < new_length; i++)
        list->elements[i] = list2->elements[j++];
    
    return (list);
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t))
{
    if (list == NULL)
        return (NULL);
    
    size_t new_length = 0;
    for (size_t i = 0; i < list->length; i++)
    {
        if (filter(list->elements[i]) == true)
            new_length++;
    }
    list_t *new_list = malloc(sizeof(list_t) + sizeof(list_element_t) * new_length);
    if (!new_list)
        return (NULL);
    
    new_list->length = new_length;

    size_t j = 0;
    for (size_t i = 0; i < list->length; i++)
    {
        if (filter(list->elements[i]) == true)
            new_list->elements[j++] = list->elements[i];
    }

    return (new_list);
}

size_t length_list(list_t *list)
{
    if (list == NULL)
        return 0;
    return (list->length);
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t))
{
    if (list == NULL)
        return (NULL);

    list_t *new_list = malloc(sizeof(list_t) + sizeof(list_element_t) * list->length);
    if (!new_list)
        return (NULL);
    
    new_list->length = list->length;

    for (size_t i = 0; i < list->length; i++)
        new_list->elements[i] = map(list->elements[i]); 

    return (new_list);
}

list_element_t foldl_list(list_t *list, list_element_t initial, list_element_t (*foldl)(list_element_t, list_element_t))
{
    if (list == NULL)
        return (0);

    list_element_t current = initial;

    for (size_t i = 0; i < list->length; i++)
        current = foldl(current, list->elements[i]);

    return (current);
}

list_element_t foldr_list(list_t *list, list_element_t initial, list_element_t (*foldr)(list_element_t, list_element_t))
{
    if (list == NULL || list->length == 0)
        return (initial);

    list_element_t current = initial;

    for (size_t i = list->length; i > 0; i--)
        current = foldr(list->elements[i-1], current);
    
    return (current);
}

list_t *reverse_list(list_t *list)
{
    if (list == NULL)
        return (NULL);
    
    list_t *new_list = malloc(sizeof(list_t) + sizeof(list_element_t) * list->length);
    if (!new_list)
        return NULL;

    new_list->length = list->length;

    int j = 0;
    for (int i = list->length - 1; i >= 0; i--)
        new_list->elements[j++] = list->elements[i];

    return (new_list);
}

void delete_list(list_t *list)
{
    if (list == NULL)
        return ;
    free(list);
}
