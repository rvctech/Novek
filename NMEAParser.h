#ifndef NMEAPARSER_H
#define NMEAPARSER_H

#include <string>
#include <vector>

class NMEAParser {
public:
    void parse(const std::string& sentence);
    void printResults() const;

private:
    void parseGPGGA(const std::string& sentence);
    void parseGPRMC(const std::string& sentence);
    void parseGPGLL(const std::string& sentence);

    std::vector<std::string> results;
};

#endif
