#include <cstdint>
#include <iostream>

#include "solver.h"
#include "table_io.h"

int main(int argc, char** argv) {
  std::uint8_t table[81];
  readTable(argc, argv, table);
  if (solve(table, 0)) {
    printTable(argc, argv, table);
  } else {
    std::cout << "Unsolvable!\n";
  }
  return 0;
}
