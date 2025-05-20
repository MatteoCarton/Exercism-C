#ifndef BEER_SONG_H
#define BEER_SONG_H

#include <stdint.h>
#include <stdio.h>

void format_verse(char *verse, int bottles);
void format_second_line(char *line, int bottles);
void recite(uint8_t start_bottles, uint8_t take_down, char **song);

#endif
