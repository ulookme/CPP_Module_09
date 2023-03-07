/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:16:24 by chajjar           #+#    #+#             */
/*   Updated: 2023/03/07 15:19:32 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <sstream>
#include "BitcoinExchange.hpp"

// Implémente le constructeur par défaut
BitcoinExchange::BitcoinExchange() {
}

// Implémente le destructeur
BitcoinExchange::~BitcoinExchange() {
}

// Charge les taux de change depuis un fichier
void BitcoinExchange::loadExchangeRates(const std::string &filename) {
    // Ouvre le fichier en lecture
    std::ifstream file(filename);
    std::string line;

    // Ignore la première ligne (en-tête)
    std::getline(file, line);

    // Lit chaque ligne restante dans le fichier
    while (std::getline(file, line)) {
        // Transforme la ligne en un flux de chaînes
        std::istringstream ss(line);
        std::string date;
        float rate;
        char delimiter;

        // Lit la date et le taux de change depuis la ligne
        ss >> date >> delimiter >> rate;

        // Ajoute le taux de change au conteneur exchangeRates en utilisant la date comme clé
        exchangeRates[date] = rate;
    }
}

// Évalue les valeurs à partir d'un fichier et affiche les résultats
void BitcoinExchange::evaluateValues(const std::string &filename) {
    // Ouvre le fichier en lecture
    std::ifstream file(filename);
    std::string line;

    // Ignore la première ligne (en-tête)
    std::getline(file, line);

    // Lit chaque ligne restante dans le fichier
    while (std::getline(file, line)) {
        // Transforme la ligne en un flux de chaînes
        std::istringstream ss(line);
        std::string date;
        float value;
        char delimiter;

        // Lit la date, le délimiteur et la valeur depuis la ligne
        ss >> date >> delimiter >> value;

        // Vérifie si la date est au bon format "année-mois-jour" et si le délimiteur est '|'
        if (date.size() != 10 || date[4] != '-' || date[7] != '-' || delimiter != '|') {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Recherche le taux de change associé à la date dans le conteneur exchangeRates
        std::map<std::string, float>::iterator it = exchangeRates.find(date);

        // Vérifie si la date est présente dans la base de données
        if (it == exchangeRates.end()) {
            std::cout << "Error: date not found in exchange rates database" << std::endl;
        }
        // Vérifie si la valeur est un nombre positif
        else if (value < 0) {
            std::cout << "Error: not a positive number" << std::endl;
        }
        // Vérifie si la valeur est inférieure ou égale à 1000
        else if (value > 1000) {
            std::cout << "Error: too large a number" << std::endl;
        }
        // Si toutes les vérifications sont valides, multiplie la valeur par le taux de change associé à la date et affiche le résultat
        else {
            std::cout << date << " => " << value << " = " << value * it->second << std::endl;
        }
    }
}