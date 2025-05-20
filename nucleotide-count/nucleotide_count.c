#include "nucleotide_count.h"

char *count(const char *dna_strand)
{
    if (!dna_strand)
        return NULL;

    int i = 0;
    int A = 0;
    int C = 0;
    int G = 0;
    int T = 0;

    while (dna_strand[i])
    {
        if (dna_strand[i] == 'A')
            A++;
        else if (dna_strand[i] == 'C')
            C++;
        else if (dna_strand[i] == 'G')
            G++;
        else if (dna_strand[i] == 'T')
            T++;
        else
        {
            char *result = malloc(sizeof(char));
            if (!result)
                return NULL;
            result[0] = '\0';
            return (result);
        }
        i++;
    }
    char *result = malloc(sizeof(char) * 100);
    if (!result)
        return (NULL);
    sprintf(result, "A:%d C:%d G:%d T:%d", A, C, G, T);

    return (result);
}
