/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:47:15 by chajjar           #+#    #+#             */
/*   Updated: 2023/03/15 10:47:03 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>  
#include <string>  
#include <iostream>  
#include <cctype> 

#include <stack>  
#include <string>  
#include <iostream>  
#include <cctype> 

class RPN {
public:
    // Constructeur qui prend en argument une expression en notation polonaise inverse.
    RPN(const std::string &expression) : m_expression(expression) {}

    // Méthode pour calculer le résultat de l'expression.
    int calculate();

private:
    // Membre de classe pour stocker l'expression en notation polonaise inverse.
    std::string m_expression;
};
