#include "high_scores.h"

/// Return the latest score.
int32_t latest(const int32_t *scores, size_t scores_len)
{
    if (scores_len <= 0)
        return (0);
    return (scores[scores_len - 1]);
}

/// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len)
{
    if (scores_len <= 0)
        return (0);
    int32_t i = 0;
    int32_t max = scores[0];
    while (i < (int32_t)scores_len)
    {
        if (scores[i] > max)
            max = scores[i];
        i++;
    }
    return (max);
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output)
{
    if (scores_len <= 0)
        return (0);

    int32_t i;
    int32_t j = 0;
    int32_t tmp_scores[scores_len];

    for (i = 0; i < (int32_t)scores_len; i++)
        tmp_scores[i] = scores[i];

    i = 0;
    while (i < (int32_t)scores_len - 1)
    {
        j = 0;
        while (j < (int32_t)scores_len - i - 1)
        {
            if (tmp_scores[j] < tmp_scores[j + 1])
            {
                int32_t tmp = tmp_scores[j];
                tmp_scores[j] = tmp_scores[j + 1];
                tmp_scores[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }

    i = 0;
    size_t scores_output;
    switch (scores_len)
    {
    case 2:
        scores_output = 2;
        for (i = 0; i < 2; i++)
            output[i] = tmp_scores[i];
        break;
    case 1:
        scores_output = 1;
            output[i] = tmp_scores[0];
        break;
    
    default:
        scores_output = 3;
        for (i = 0; i < 3; i++)
            output[i] = tmp_scores[i];
        break;
    }
    return (scores_output);
}
