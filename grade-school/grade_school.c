#include "grade_school.h"

static int compare(const void *a, const void *b)
{
    const student_t *student_a = (const student_t *)a;
    const student_t *student_b = (const student_t *)b;

    if (student_a->grade != student_b->grade)
        return (student_a->grade - student_b->grade);

    return (strcmp(student_a->name, student_b->name));
}

bool add_student(roster_t *roster, const char *name, uint8_t grade)
{
    size_t i = 0;
    while (i < roster->count)
    {
        if (strcmp(roster->students[i].name, name) == 0)
            return (false);
        i++;
    }
    roster->students[roster->count].grade = grade;
    strncpy(roster->students[roster->count].name, name, MAX_NAME_LENGTH - 1);
    roster->students[roster->count].name[MAX_NAME_LENGTH - 1] = '\0';
    roster->count++;

    // Sort after adding a new student
    qsort(roster->students, roster->count, sizeof(student_t), compare);

    return (true);
}

void init_roster(roster_t *roster)
{
    roster->count = 0;
}


roster_t get_grade(const roster_t *roster, uint8_t desired_grade)
{
    roster_t list;
    list.count = 0;

    for (size_t i = 0; i < roster->count; i++)
    {
        if (roster->students[i].grade == desired_grade)
        {
            list.students[list.count].grade = desired_grade;
            strncpy(list.students[list.count].name, roster->students[i].name, MAX_NAME_LENGTH - 1);
            list.students[list.count].name[MAX_NAME_LENGTH - 1] = '\0';
            list.count++;
        }
    }

    // Sort the list by name only
    qsort(list.students, list.count, sizeof(student_t), compare);

    return (list);
}
