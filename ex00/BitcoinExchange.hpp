/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:16:36 by chajjar           #+#    #+#             */
/*   Updated: 2023/03/07 14:17:20 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <string>

// Déclare la classe BitcoinExchange
class BitcoinExchange {
public:
    // Constructeur par défaut
    BitcoinExchange();

    // Destructeur
    ~BitcoinExchange();

    // Charge les taux de change depuis un fichier
    void loadExchangeRates(const std::string &filename);

    // Évalue les valeurs à partir d'un autre fichier
    void evaluateValues(const std::string &filename);

private:
    // Un conteneur qui stocke les taux de change sous forme de clé (date) et valeur (taux)
    std::map<std::string, float> exchangeRates;
};