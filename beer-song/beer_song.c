#include "beer_song.h"

void format_verse(char *verse, int bottles)
{
    if (bottles == 0)
        snprintf(verse, 100, "No more bottles of beer on the wall, no more bottles of beer.");
    else if (bottles == 1)
        snprintf(verse, 100, "1 bottle of beer on the wall, 1 bottle of beer.");
    else
        snprintf(verse, 100, "%d bottles of beer on the wall, %d bottles of beer.", bottles, bottles);
}

void format_second_line(char *line, int bottles)
{
    if (bottles == 0)
        snprintf(line, 100, "Go to the store and buy some more, 99 bottles of beer on the wall.");
    else if (bottles == 1)
        snprintf(line, 100, "Take one down and pass it around, 1 bottle of beer on the wall.");
    else
        snprintf(line, 100, "Take one down and pass it around, %d bottles of beer on the wall.", bottles);
}

void recite(uint8_t start_bottles, uint8_t take_down, char **song)
{
    if (start_bottles > 99)
        return;

    if (take_down == 0)
        return;

    int i = 0;
    int actual_bottle = start_bottles;
    while (i < take_down)
    {
        format_verse(song[i*3], actual_bottle);
        if (actual_bottle == 1)
            snprintf(song[i*3+1], 100, "Take it down and pass it around, no more bottles of beer on the wall.");
        else if (actual_bottle == 0)
            snprintf(song[i*3+1], 100, "Go to the store and buy some more, 99 bottles of beer on the wall.");
        else
            format_second_line(song[i*3+1], actual_bottle - 1);
        if (i < take_down - 1)
            snprintf(song[i*3+2], 100, "%s", "");
        actual_bottle--;
        i++;
    }
}
