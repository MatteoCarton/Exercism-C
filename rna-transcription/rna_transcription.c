#include "rna_transcription.h"

char *to_rna(const char *dna)
{
    char *rna = NULL;

    size_t i = 0;
    size_t length = strlen(dna);

    rna = malloc (sizeof(char) * (length + 1));
    if (!rna)
        return (NULL);

    while (i < length)
    {
        if (dna[i] == 'G')
            rna[i] = 'C';
        else if (dna[i] == 'C')
            rna[i] = 'G';
        else if (dna[i] == 'T')
            rna[i] = 'A';
        else if (dna[i] == 'A')
            rna[i] = 'U';
        i++;
    }

    rna[i] = '\0';

    return (rna);
}
