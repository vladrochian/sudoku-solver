#include "solver.h"

#include <cstring>

namespace {
void markRow(const std::uint8_t* table, int cell, bool* used) {
  int rowStart = cell / 9 * 9;
  for (int i = rowStart; i < rowStart + 9; ++i) {
    used[table[i]] = true;
  }
}

void markColumn(const std::uint8_t* table, int cell, bool* used) {
  for (int i = cell % 9; i < 81; i += 9) {
    used[table[i]] = true;
  }
}

void markSquare(const std::uint8_t* table, int cell, bool* used) {
  int squareRowStart = cell / 27 * 27;
  int squareStart = squareRowStart + cell % 9 / 3 * 3;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      used[table[squareStart + i * 9 + j]] = true;
    }
  }
}
}

bool solve(std::uint8_t* table, int startAt) {
  int cell = startAt;
  while (cell < 81 && table[cell] > 0) {
    ++cell;
  }
  if (cell == 81) {
    return true;
  }
  bool used[10];
  std::memset(used, 0, sizeof used);
  markRow(table, cell, used);
  markColumn(table, cell, used);
  markSquare(table, cell, used);
  for (int i = 1; i < 10; ++i) {
    if (!used[i]) {
      table[cell] = i;
      if (solve(table, cell + 1)) {
        return true;
      }
      table[cell] = 0;
    }
  }
  return false;
}
