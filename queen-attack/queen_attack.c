#include "queen_attack.h"

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
    // Check that queens are on the board (uint8_t is unsigned so don't need to check negative number)
    if (queen_1.row > 7 || queen_1.column > 7 ||
        queen_2.row > 7 || queen_2.column > 7)
        return (INVALID_POSITION);
    
    // Check that queens are not on the same position
    if (queen_1.row == queen_2.row && queen_1.column == queen_2.column)
        return (INVALID_POSITION);
    
    // if same column and row -> can attack
    if (queen_1.row == queen_2.row ||
        queen_1.column == queen_2.column)
        return (CAN_ATTACK);

    // if same diagonal -> can attack
    if (abs(queen_1.row - queen_2.row) == abs(queen_1.column - queen_2.column))
        return (CAN_ATTACK);

    // else -> can not attack
    return (CAN_NOT_ATTACK);
}
