#include "kindergarten_garden.h"

static int get_student_index(const char *student)
{
    if (strcmp(student, "Alice") == 0)
        return 0;
    else if (strcmp(student, "Bob") == 0)
        return 1;
    else if (strcmp(student, "Charlie") == 0)
        return 2;
    else if (strcmp(student, "David") == 0)
        return 3;
    else if (strcmp(student, "Eve") == 0)
        return 4;
    else if (strcmp(student, "Fred") == 0)
        return 5;
    else if (strcmp(student, "Ginny") == 0)
        return 6;
    else if (strcmp(student, "Harriet") == 0)
        return 7;
    else if (strcmp(student, "Ileana") == 0)
        return 8;
    else if (strcmp(student, "Joseph") == 0)
        return 9;
    else if (strcmp(student, "Kincaid") == 0)
        return 10;
    else if (strcmp(student, "Larry") == 0)
        return 11;
    else
        return (-1);
}

static plant_t get_plant_type(char letter)
{
    switch (letter)
    {
    case 'C':
        return (CLOVER);
    case 'G':
        return (GRASS);
    case 'R':
        return (RADISHES);
    case 'V':
        return (VIOLETS);
    default:
        break;
    }
    return (CLOVER);
}

plants_t plants(const char *diagram, const char *student)
{
    plants_t result;

    int student_index = get_student_index(student);
    int start_pos = student_index * 2;

    result.plants[0] = get_plant_type(diagram[start_pos]);
    result.plants[1] = get_plant_type(diagram[start_pos + 1]);

    const char *second_line = strchr(diagram, '\n') + 1;

    result.plants[2] = get_plant_type(second_line[start_pos]);
    result.plants[3] = get_plant_type(second_line[start_pos + 1]);

    return (result);
}
