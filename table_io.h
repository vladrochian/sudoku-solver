#ifndef SUDOKU_SOLVER_TABLE_IO_H
#define SUDOKU_SOLVER_TABLE_IO_H

#include <cstdint>

void readTable(int argc, char** argv, uint8_t* table);
void printTable(int argc, char** argv, const uint8_t* table);

#endif //SUDOKU_SOLVER_TABLE_IO_H
