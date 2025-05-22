#include "yacht.h"

static int one_number(dice_t dice, int number)
{
    int score = 0;

    for (int i = 0; i < 5; i++)
    {
        if (dice.faces[i] == number)
            score++;
    }
    return(score * number);
}

static int sum_total(dice_t dice)
{
    int score = 0;
    for (int i = 0; i < 5; i++)
        score += dice.faces[i];
    return (score);
}

int score(dice_t dice, category_t category)
{
    for (int i = 0; i < 5; i++)
    {
        if (dice.faces[i] <= 0 || dice.faces[i] > 6)
            return (0);
    }

    // CASES FOR ONES TO SIXES
    switch (category)
    {
    case ONES:
        return(one_number(dice, 1));
        break;
    case TWOS:
        return(one_number(dice, 2));
        break;
    case THREES:
        return(one_number(dice, 3));
        break;
    case FOURS:
        return(one_number(dice, 4));
        break;
    case FIVES:
        return(one_number(dice, 5));
        break;
    case SIXES:
        return(one_number(dice, 6));
        break;
    default:
        break;
    }

    // CASE FULL
    if (category == FULL_HOUSE)
    {
        int number1 = 1;
        bool same_numbers[5] = {true, false, false, false, false};
        for (int i = 1; i < 5; i++)
        {
            if (dice.faces[i] == dice.faces[0])
            {
                number1++;
                same_numbers[i] = true;
            }
        }
        if (number1 != 2 && number1 != 3)
            return (0);

        int number2 = 1;
        int j;
        for (j = 0; j < 5; j++)
        {
            if (same_numbers[j] == false)
                break;
        }
        for (int i = 0; i < 5; i++)
        {
            if (dice.faces[i] == dice.faces[j] && i != j && same_numbers[i] == false)
                number2++;
        }
        if ((number1 == 2 && number2 == 3) || (number1 == 3 && number2 == 2))
                return (sum_total(dice));
        else
            return (0);
    }

    // CASE FOUR_OF_A_KIND
    if (category == FOUR_OF_A_KIND)
    {
        int count[7] = {0};

        for (int i = 0; i < 5; i++)
            count[dice.faces[i]]++;

        for (int i = 1; i <= 6; i++)
        {
            if (count[i] >= 4)
                return (i * 4);
        }
        return (0);
    }

    // CASE LITTLE_STRAIGHT
    if (category == LITTLE_STRAIGHT)
    {
        int count[7] = {0};

        for (int i = 0; i < 5; i++)
            count[dice.faces[i]]++;
        if (count[1] == 1 && count[2] == 1 && count[3] == 1 && count[4] == 1 && count[5] == 1)
            return (30);
        else
            return (0);
    }
    // CASE BIG_STRAIGHT
    if (category == BIG_STRAIGHT)
    {
        int count[7] = {0};

        for (int i = 0; i < 5; i++)
            count[dice.faces[i]]++;
        if (count[2] == 1 && count[3] == 1 && count[4] == 1 && count[5] == 1 && count[6] == 1)
            return (30);
        else
            return (0);
    }

    //CASE CHOICE
    if (category == CHOICE)
        return (sum_total(dice));

    if (category == YACHT)
    {
        for (int i = 1; i < 5; i++)
        {
            if (dice.faces[i] != dice.faces[0])
                return (0);
        }
        return (50);
    }

    return (0);
}
