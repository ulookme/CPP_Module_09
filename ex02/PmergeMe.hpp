/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:50:33 by chajjar           #+#    #+#             */
/*   Updated: 2023/03/07 16:50:39 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <chrono>
#include <iostream>

class PmergeMe {
public:
  PmergeMe(const std::vector<int>& nums);
  void sortWithVector();
  void sortWithList();

private:
  std::vector<int> nums_;
  std::list<int> list_nums_;

  void mergeSort(std::vector<int>& nums, int l, int r);
  void merge(std::vector<int>& nums, int l, int m, int r);
  
  void mergeSort(std::list<int>::iterator start, std::list<int>::iterator end);
  void merge(std::list<int>::iterator start, std::list<int>::iterator mid, std::list<int>::iterator end);
};