#include "variable_length_quantity.h"

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
{
   int position = 0;

   for (int i = 0; i < integers_len; i++)
   {
      if (integers[i] >= 0 && integers[i] <= 127)
      {
         output[position] = integers[i];
         position++;
      }
      else
      {
         
      }
   }

   return (position);
}

// int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output)
// {
   // write to `output`, return final output's length
   // return -1 if error
   // `output` buffer should be enough to hold the full result
// }

#include <stdio.h>
int main(void)
{
    // Test avec des petits nombres
    uint32_t nombres[] = {0, 64, 127};
    uint8_t resultat[100];
    int taille = encode(nombres, 3, resultat);

    // Afficher le résultat
    printf("Taille du résultat : %d\n", taille);
    for (int i = 0; i < taille; i++) {
        printf("Octet %d : %d (0x%02x)\n", i, resultat[i], resultat[i]);
    }

    return 0;
}
