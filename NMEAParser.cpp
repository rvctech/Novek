#include "NMEAParser.h"
#include <iostream>
#include <sstream>

void NMEAParser::parse(const std::string& sentence) {
    if (sentence.substr(0, 6) == "$GPGGA") {
        parseGPGGA(sentence);
    } else if (sentence.substr(0, 6) == "$GPRMC") {
        parseGPRMC(sentence);
    } else if (sentence.substr(0, 6) == "$GPGLL") {
        parseGPGLL(sentence);
    }
}

void NMEAParser::parseGPGGA(const std::string& sentence) {
    std::stringstream ss(sentence);
    std::string token;
    std::vector<std::string> fields;

    while (std::getline(ss, token, ',')) {
        fields.push_back(token);
    }

    if (fields.size() >= 15) {
        std::string time = fields[1];
        std::string latitude = fields[2] + " " + fields[3];
        std::string longitude = fields[4] + " " + fields[5];
        std::string altitude = fields[9] + " " + fields[10];

        results.push_back("GPGGA - Time: " + time + ", Latitude: " + latitude + ", Longitude: " + longitude + ", Altitude: " + altitude);
    }
}

void NMEAParser::parseGPRMC(const std::string& sentence) {
    std::stringstream ss(sentence);
    std::string token;
    std::vector<std::string> fields;

    while (std::getline(ss, token, ',')) {
        fields.push_back(token);
    }

    if (fields.size() >= 12) {
        std::string time = fields[1];
        std::string latitude = fields[3] + " " + fields[4];
        std::string longitude = fields[5] + " " + fields[6];
        std::string speed = fields[7];
        std::string course = fields[8];
        std::string date = fields[9];

        results.push_back("GPRMC - Time: " + time + ", Latitude: " + latitude + ", Longitude: " + longitude + ", Speed: " + speed + " knots, Course: " + course + "°, Date: " + date);
    }
}

void NMEAParser::parseGPGLL(const std::string& sentence) {
    std::stringstream ss(sentence);
    std::string token;
    std::vector<std::string> fields;

    while (std::getline(ss, token, ',')) {
        fields.push_back(token);
    }

    if (fields.size() >= 7) {
        std::string latitude = fields[1] + " " + fields[2];
        std::string longitude = fields[3] + " " + fields[4];
        std::string time = fields[5];

        results.push_back("GPGLL - Latitude: " + latitude + ", Longitude: " + longitude + ", Time: " + time);
    }
}

void NMEAParser::printResults() const {
    for (const auto& result : results) {
        std::cout << result << std::endl;
    }
}
