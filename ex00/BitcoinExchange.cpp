/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:16:24 by chajjar           #+#    #+#             */
/*   Updated: 2023/03/15 10:06:50 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <regex>

//using namespace std;
// Implémente le constructeur par défaut
BitcoinExchange::BitcoinExchange() {
}

// Implémente le destructeur
BitcoinExchange::~BitcoinExchange() {
}

void BitcoinExchange::loadExchangeRates(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cout << "Error: could not open exchange rates file." << std::endl;
        return;
    }
    std::cout << "Exchange rates file opened successfully." << std::endl;

    std::string line, date_str, rate_str;
    float rate;
    char separator = detectSeparator(file);
    if (separator == ',') {
        while (getline(file, line)) {
            std::stringstream ss(line);
            getline(ss, date_str, ',');
            getline(ss, rate_str);
            rate = atof(rate_str.c_str());
            exchangeRates[date_str] = rate;
        }
    } else if (separator == '|') {
        while (getline(file, line)) {
            std::stringstream ss(line);
            getline(ss, date_str, '|');
            getline(ss, rate_str);
            rate = atof(rate_str.c_str());
            exchangeRates[date_str] = rate;
        }
    } else if (separator == ';') {
        while (getline(file, line)) {
            std::stringstream ss(line);
            getline(ss, date_str, ';');
            getline(ss, rate_str);
            rate = atof(rate_str.c_str());
            exchangeRates[date_str] = rate;
        }
    } else {
        std::cout << "Error: unsupported separator character." << std::endl;
    }
}

char BitcoinExchange::detectSeparator(std::ifstream &file) {
    char separator = '\0';
    std::string line;
    if (getline(file, line)) {
        if (line.find(',') != std::string::npos) {
            separator = ',';
        } else if (line.find('|') != std::string::npos) {
            separator = '|';
        } else if (line.find(';') != std::string::npos) {
            separator = ';';
        }
    }
    file.seekg(0, file.beg);
    return separator;
}

/**void BitcoinExchange::loadExchangeRates(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cout << "Error: could not open exchange rates file." << std::endl;
        return;
    }
    std::cout << "Exchange rates file opened successfully." << std::endl;
    
    std::string line, date_str, rate_str;
    float rate;
    while (getline(file, line)) {
        std::stringstream ss(line);
        getline(ss, date_str, ',');
        getline(ss, rate_str);
        rate = atof(rate_str.c_str());
        //if (rate <= 0) {
       //     std::cout << "Error: invalid exchange rate (" << rate << ") on line: " << line << std::endl;
       //     continue;
       // }
        exchangeRates[date_str] = rate;
    }
    
    //std::map<std::string, float>::iterator it;
    //for (it = exchangeRates.begin(); it != exchangeRates.end(); it++) {
    //    std::cout << it->first << " => " << it->second << std::endl;
   // }
}*/


void BitcoinExchange::evaluateValues(const std::string &filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    getline(inputFile, line); // skip header line

    std::regex dateRegex("^\\d{4}-\\d{2}-\\d{2}$");
    while (getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string date;
        float value;
        char separator;
        if (!(iss >> date >> separator >> value)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!regex_match(date, dateRegex)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number" << std::endl;
            continue;
        }
        if (value  < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }

        std::map<std::string, float>::iterator it = exchangeRates.lower_bound(date);
        if (it == exchangeRates.end()) {
            std::cout << "Error: date " << date << " is after the latest date in the exchange rates file." << std::endl;
            continue;
        } else if (it == exchangeRates.begin() && date < it->first) {
            std::cout << "Error: date " << date << " is prior to the earliest date in the exchange rates file." << std::endl;
            continue;
        } else if (date < it->first) {
            --it;
        }

        float exchangeRate = it->second;
        std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;
    }
}