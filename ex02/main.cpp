/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:51:10 by chajjar           #+#    #+#             */
/*   Updated: 2023/03/07 20:32:51 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <chrono>
#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
  if (argc <= 1) {
    std::cerr << "Usage: " << argv[0] << " No arguments " << std::endl;
    return 1;
  }

  std::vector<int> nums;
  for (int i = 1; i < argc; i++) {
    int num = atoi(argv[i]);
    nums.push_back(num);
  }

  PmergeMe pmerge(nums);
  pmerge.sortWithVector();
  pmerge.sortWithList();

  return 0;
}