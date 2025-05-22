#include "scrabble_score.h"

unsigned int score(const char *word)
{
    int letter_values[26] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8,  // A-J
    5, 1, 3, 1, 1, 3, 10, 1, 1, 1, // K-T
    1, 4, 4, 8, 4, 10              // U-Z
    };

    unsigned int score = 0;

    for (int i = 0; word[i]; i++) {
        int index = toupper(word[i]) - 'A';
        score += letter_values[index];
    }
    return (score);
}
