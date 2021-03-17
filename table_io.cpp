#include "table_io.h"

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>

namespace {
void printTable(std::ostream& os, const uint8_t* table, bool prettyPrint) {
  char buffer[13];
  buffer[prettyPrint ? 11 : 9] = '\n';
  buffer[prettyPrint ? 12 : 10] = '\0';
  if (prettyPrint) {
    buffer[3] = buffer[7] = ' ';
  }
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      buffer[prettyPrint ? j + j / 3 : j] = (table[i * 9 + j] == 0) ? ' ' : static_cast<char>(table[i * 9 + j] + '0');
    }
    os << buffer;
    if (prettyPrint && i % 3 == 2) {
      os << "\n";
    }
  }
}
}

void readTable(int argc, char** argv, uint8_t* table) {
  std::string inputPath;
  if (argc < 2) {
    std::cout << "Provide an input file: ";
    std::getline(std::cin, inputPath);
  } else {
    inputPath = argv[1];
  }
  std::ifstream input(inputPath);
  if (!input) {
    std::cout << "Error reading file.\n";
    std::exit(0);
  }
  char buffer[10];
  for (int i = 0; i < 9; ++i) {
    input.getline(buffer, 10);
    int j = 0;
    while (buffer[j] != '\0') {
      table[i * 9 + j] = std::isdigit(buffer[j]) ? buffer[j] - '0' : 0;
      ++j;
    }
    while (j < 9) {
      table[i * 9 + j++] = 0;
    }
  }
}

void printTable(int argc, char** argv, const uint8_t* table) {
  if (argc >= 3) {
    std::ofstream output(argv[2]);
    printTable(output, table, false);
  }
  printTable(std::cout, table, true);
}
