#include "grade_school.h"

bool add_student(roster_t *roster, const char *name, uint8_t grade)
{
    int i = 0;
    while (i < roster->count)
    {
        if (strcmp(roster->students[i].name, name) == 0)
            return (false);
        i++;
    }
    roster->students->grade = grade;
    roster->students->name = name;

}

void init_roster(roster_t *roster)
{
    roster_t roster;

    roster->count = 0;

}