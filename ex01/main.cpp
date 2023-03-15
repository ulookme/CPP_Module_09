/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:50:38 by chajjar           #+#    #+#             */
/*   Updated: 2023/03/15 10:56:04 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << "Arguments expression" << std::endl;
        return 1;
    }
    RPN rpn(argv[1]);
    int result = rpn.calculate();
    if (result != 0) {
        std::cout << result << std::endl;
    }
    return 0;
}