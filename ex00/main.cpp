/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:16:20 by chajjar           #+#    #+#             */
/*   Updated: 2023/03/07 14:51:55 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    // Vérifie que le nom de fichier est donné en argument
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    // Crée une instance de la classe BitcoinExchange
    BitcoinExchange exchange;

    // Charge les taux de change à partir d'un fichier
    exchange.loadExchangeRates("change.txt");

    // Évalue les valeurs à partir d'un autre fichier
    exchange.evaluateValues(argv[1]);

    return 0;
}



