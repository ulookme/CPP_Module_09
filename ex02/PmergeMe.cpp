/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:51:02 by chajjar           #+#    #+#             */
/*   Updated: 2023/03/15 08:29:27 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::vector<int>& nums) : nums_(nums), list_nums_(nums.begin(), nums.end()) {
  // Vérifier si tous les entiers dans la séquence sont positifs
  for (int i = 0; i < nums_.size(); i++) {
    if (nums_[i] <= 0) {
      // Afficher un message d'erreur sur la sortie d'erreur standard si un entier négatif est trouvé
      std::cerr << "Erreur" << std::endl;
      // Terminer le programme immédiatement
      exit(1);
    }
  }
}

void PmergeMe::sortWithVector() {
  // Afficher la séquence avant le tri
  std::cout << "Before : ";
  for (int i = 0; i < nums_.size(); i++) {
    std::cout << nums_[i] << " ";
  }
  std::cout << std::endl;

  // Obtenir le temps actuel avant le tri
  std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
  // Effectuer le tri de la séquence en utilisant nums_ comme conteneur
  mergeSort(nums_, 0, nums_.size() - 1);
  // Obtenir le temps actuel après le tri
  std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

  // Afficher la séquence après le tri
  std::cout << "After : ";
  for (int i = 0; i < nums_.size(); i++) {
    std::cout << nums_[i] << " ";
  }
  std::cout << std::endl;

  // Calculer la durée du tri
  long long duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
  // Afficher la durée du tri
  std::cout << "Time to process a range of " << nums_.size() << " elements with std::vector : " << duration << " us" << std::endl;
}

void PmergeMe::sortWithList() {
  // Afficher la séquence avant le tri
  //std::cout << "Before : ";
  std::list<int>::iterator it;
  for (it = list_nums_.begin(); it != list_nums_.end(); it++) {
   // std::cout << *it << " ";
  }
  //std::cout << std::endl;

  // Obtenir le temps actuel avant le tri
  std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
  // Effectuer le tri de la séquence en utilisant list_nums_ comme conteneur
  mergeSort(list_nums_.begin(), list_nums_.end());
  // Obtenir le temps actuel après le tri
  std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

  // Afficher la séquence après le tri
  //std::cout << "After : ";
  for (it = list_nums_.begin(); it != list_nums_.end(); it++) {
   // std::cout << *it << " ";
  }
  //std::cout << std::endl;

  // Calculer la durée du tri
  long long duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
  // Afficher la durée du tri
  std::cout << "Time to process a range of " << list_nums_.size() << " elements with std::list : " << duration << " us" << std::endl;
}


void PmergeMe::mergeSort(std::vector<int>& nums, int l, int r) {
  // Si la longueur de la plage de tri est inférieure ou égale à 1, retourner
  if (l >= r) return;

  // Déterminer le milieu de la plage de tri
  int m = l + (r - l) / 2;

  // Trier les deux moitiés de la plage de tri
  mergeSort(nums, l, m);
  mergeSort(nums, m + 1, r);

  // Initialiser un tableau temporaire pour stocker les éléments triés
  std::vector<int> temp;

  // Initialiser les indices pour parcourir les deux moitiés triées
  int i = l, j = m + 1;

  // Fusionner les deux moitiés triées en utilisant un tableau temporaire
  while (i <= m && j <= r) {
    if (nums[i] <= nums[j]) {
      temp.push_back(nums[i]);
      i++;
    } else {
      temp.push_back(nums[j]);
      j++;
    }
  }

  // Ajouter les éléments restants de la première moitié triée au tableau temporaire
  while (i <= m) {
    temp.push_back(nums[i]);
    i++;
  }

  // Ajouter les éléments restants de la seconde moitié triée au tableau temporaire
  while (j <= r) {
    temp.push_back(nums[j]);
    j++;
  }

  // Copier les éléments du tableau temporaire dans le tableau original
  for (i = l, j = 0; i <= r; i++, j++) {
    nums[i] = temp[j];
  }
}

void PmergeMe::mergeSort(std::list<int>::iterator start, std::list<int>::iterator end) {
  // On sort la liste seulement si elle contient plus d'un élément.
  if (start == end || std::next(start) == end) return;

  // On détermine le milieu de la liste.
  std::list<int>::iterator mid = start;
  std::advance(mid, std::distance(start, end) / 2);

  // On trie les deux moitiés de la liste.
  mergeSort(start, mid);
  mergeSort(mid, end);

  // On crée un tampon pour stocker les éléments triés.
  std::list<int> temp;

  // On initialise les itérateurs pour parcourir les deux moitiés de la liste.
  std::list<int>::iterator left = start, right = mid;

  // On compare les éléments des deux moitiés de la liste et on ajoute le plus petit des deux à `temp`.
  while (left != mid && right != end) {
    if (*left <= *right) {
      temp.push_back(*left);
      left++;
    } else {
      temp.push_back(*right);
      right++;
    }
  }

  // On ajoute le reste des éléments de la première moitié à `temp`.
  while (left != mid) {
    temp.push_back(*left);
    left++;
  }

  // On ajoute le reste des éléments de la seconde moitié à `temp`.
  while (right != end) {
    temp.push_back(*right);
    right++;
  }

  // On écrase les éléments de la liste originale avec les éléments triés de `temp`.
  left = start, right = temp.begin();
  while (right != temp.end()) {
    *left = *right;
    left++;
    right++;
  }
}