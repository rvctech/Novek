#include <iostream>
#include <fstream>
#include <string>
#include "NMEAParser.h"

void processFile(const std::string& filename, NMEAParser& parser) {
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        parser.parse(line);
    }
}

int main() {
    std::string filename = "jogging_path.txt";
    NMEAParser parser;

    processFile(filename, parser);
    parser.printResults();

    return 0;
}
