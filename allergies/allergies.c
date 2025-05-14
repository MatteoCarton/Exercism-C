#include "allergies.h"

bool is_allergic_to(allergen_t allergen, unsigned int score)
{
    if ((score & (1 << allergen)) != 0)
        return (true);
    return (false);
}

allergen_list_t get_allergens(unsigned int score)
{
    allergen_list_t list_allergens = { 
    .count = 0,
    .allergens = { false }
    };

    if (is_allergic_to(ALLERGEN_EGGS, score))
    {
        list_allergens.count++;
        list_allergens.allergens[ALLERGEN_EGGS] = true;
    }
    if (is_allergic_to(ALLERGEN_PEANUTS, score))
    {
        list_allergens.count++;
        list_allergens.allergens[ALLERGEN_PEANUTS] = true;
    }
    if (is_allergic_to(ALLERGEN_SHELLFISH, score))
    {
        list_allergens.count++;
        list_allergens.allergens[ALLERGEN_SHELLFISH] = true;
    }
    if (is_allergic_to(ALLERGEN_STRAWBERRIES, score))
    {
        list_allergens.count++;
        list_allergens.allergens[ALLERGEN_STRAWBERRIES] = true;
    }
    if (is_allergic_to(ALLERGEN_TOMATOES, score))
    {
        list_allergens.count++;
        list_allergens.allergens[ALLERGEN_TOMATOES] = true;
    }
    if (is_allergic_to(ALLERGEN_CHOCOLATE, score))
    {
        list_allergens.count++;
        list_allergens.allergens[ALLERGEN_CHOCOLATE] = true;
    }
    if (is_allergic_to(ALLERGEN_POLLEN, score))
    {
        list_allergens.count++;
        list_allergens.allergens[ALLERGEN_POLLEN] = true;
    }
    if (is_allergic_to(ALLERGEN_CATS, score))
    {
        list_allergens.count++;
        list_allergens.allergens[ALLERGEN_CATS] = true;
    }
    return (list_allergens);
}
