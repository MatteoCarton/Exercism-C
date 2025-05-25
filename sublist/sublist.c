#include "sublist.h"

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count)
{
    if (list_to_compare == base_list)
        return (EQUAL);
    if (list_to_compare == NULL && base_list != NULL)
        return (SUBLIST);
    if (list_to_compare != NULL && base_list == NULL)
        return (SUPERLIST);

    size_t i = 0;
    if (list_to_compare_element_count == base_list_element_count)
    {
        for (i = 0; i < list_to_compare_element_count; i++)
        {
            if (list_to_compare[i] != base_list[i])
                break;
        }
        if (i == list_to_compare_element_count)
            return EQUAL;
    }

    for (size_t i = 0; i < base_list_element_count; i++)
    {
        if (base_list[i] == list_to_compare[0])
        {
            size_t j = 0;
            while (j < list_to_compare_element_count && 
                i + j < base_list_element_count)
            {
                if (base_list[i + j] != list_to_compare[j])
                    break;
                j++;
            }
            if (j == list_to_compare_element_count)
                return (SUBLIST);
        }
    }

    for (size_t i = 0; i < list_to_compare_element_count; i++)
    {
        if (list_to_compare[i] == base_list[0])
        {
            size_t j = 0;
            while (j < base_list_element_count && 
                i + j < list_to_compare_element_count)
            {
                if (list_to_compare[i + j] != base_list[j])
                    break;
                j++;
            }
            if (j == base_list_element_count)
                return (SUPERLIST);
        }
    }

    return (UNEQUAL);
}
