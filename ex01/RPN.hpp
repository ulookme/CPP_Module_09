/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:47:15 by chajjar           #+#    #+#             */
/*   Updated: 2023/03/07 16:08:46 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>  
#include <string>  
#include <iostream>  
#include <cctype> 

class RPN {
public:
    // Constructeur qui prend en argument une expression en notation polonaise inverse.
    RPN(const std::string &expression) : m_expression(expression) {}

    // Méthode pour calculer le résultat de l'expression.
    int calculate() {
        // Initialisation d'une pile pour stocker les nombres.
        std::stack<int> stk;

        // Boucle pour parcourir les caractères de l'expression.
        for (std::string::const_iterator it = m_expression.begin(); it != m_expression.end(); ++it) {
            char c = *it;
            // Si le caractère est un chiffre, il est converti en entier et empilé sur la pile.
            if (std::isdigit(c)) {
                stk.push(c - '0');
            } else if (!std::isspace(c))  {
                if (stk.size() < 2) {
                    std::cerr << "Error" << std::endl;
                    return 0;
                }
                // Sinon, il s'agit d'un opérateur.
                // Les deux derniers nombres sur la pile sont dépilés.
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();

                // L'opération est effectuée sur les deux nombres et le résultat est empilé sur la pile.
                switch (c) {
                case '+':
                    stk.push(a + b);
                    break;
                case '-':
                    stk.push(a - b);
                    break;
                case '*':
                    stk.push(a * b);
                    break;
                case '/':
                    stk.push(a / b);
                    break;
                default:
                    // Si le caractère n'est ni un chiffre ni un opérateur valide, un message d'erreur est affiché.
                    std::cerr << "Error: Invalid operator '" << c << "'" << std::endl;
                    return 0;
                }
            }
        }

        // Si la pile ne contient pas exactement un nombre, cela signifie que l'expression est invalide.
        if (stk.size() != 1) {
            std::cerr << "Error: Invalid expression" << std::endl;
            return 0;
        }

        // Le résultat final est le nombre sur le dessus de la pile.
        return stk.top();
    }
private:
    // Membre de classe pour stocker l'expression en notation polonaise inverse.
    std::string m_expression;
};

