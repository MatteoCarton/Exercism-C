#include "protein_translation.h"

protein_t protein(const char *const rna)
{
    protein_t protein;
    protein.valid = true;
    protein.count = 0;

    if (!rna)
        return (protein);

    int i = 0;
    while (rna[i] && rna[i+1] && rna[i+2])
    {
        if ((rna[i] == 'U' && rna[i+1] == 'A' && (rna[i+2] == 'A' || rna[i+2] == 'G')) || 
            (rna[i] == 'U' && rna[i+1] == 'G' && rna[i+2] == 'A'))
        {
            return (protein);
        }
        if (rna[i] == 'A' && rna[i+1] == 'U' && rna[i+2] == 'G')
        {
            protein.valid = true;
            protein.count++;
            protein.amino_acids[protein.count - 1] = Methionine;
            i += 3;
        }
        else if (rna[i] == 'U' && rna[i+1] == 'U' && (rna[i+2] == 'U' || rna[i+2] == 'C'))
        {
            protein.valid = true;
            protein.count++;
            protein.amino_acids[protein.count - 1] = Phenylalanine;
            i += 3;
        }
        else if (rna[i] == 'U' && rna[i+1] == 'U' && (rna[i+2] == 'A' || rna[i+2] == 'G'))
        {
            protein.valid = true;
            protein.count++;
            protein.amino_acids[protein.count - 1] = Leucine;
            i += 3;
        }
        else if (rna[i] == 'U' && rna[i+1] == 'C' && (rna[i+2] == 'U' || rna[i+2] == 'C' || rna[i+2] == 'A' || rna[i+2] == 'G'))
        {
            protein.valid = true;
            protein.count++;
            protein.amino_acids[protein.count - 1] = Serine;
            i += 3;
        }
        else if (rna[i] == 'U' && rna[i+1] == 'A' && (rna[i+2] == 'U' || rna[i+2] == 'C'))
        {
            protein.valid = true;
            protein.count++;
            protein.amino_acids[protein.count - 1] = Tyrosine;
            i += 3;
        }
        else if (rna[i] == 'U' && rna[i+1] == 'G' && (rna[i+2] == 'U' || rna[i+2] == 'C'))
        {
            protein.valid = true;
            protein.count++;
            protein.amino_acids[protein.count - 1] = Cysteine;
            i += 3;
        }
        else if (rna[i] == 'U' && rna[i+1] == 'G' && rna[i+2] == 'G')
        {
            protein.valid = true;
            protein.count++;
            protein.amino_acids[protein.count - 1] = Tryptophan;
            i += 3;
        }
        else {
            protein.valid = false;
            return (protein);
        }
    }

    int length = 0;
    while (rna[length])
        length ++;
    if (length % 3 != 0)
    {
        protein.valid = false;
        return (protein);
    }
    
    return (protein);
}
