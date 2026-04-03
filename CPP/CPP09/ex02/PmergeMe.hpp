/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:47:51 by edugonza          #+#    #+#             */
/*   Updated: 2026/04/03 15:08:52 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <algorithm>
#include <cmath>

extern bool verbose;

class PmergeMe {

	private:

	protected:
		std::vector<int>	vec;
		std::list<int>	lis;
		std::vector<int>	ordered_vec;
		std::list<int>	ordered_lis;

	public:
		PmergeMe();
		virtual ~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other);
		PmergeMe(const PmergeMe &obj);

		void check_save_input(std::string input);
		void order_numbers();

		std::vector<int> sort_vector(std::vector<int> v);
		std::list<int> sort_list(std::list<int> l);
		int number_of_elements() const { return vec.size(); }
};

// HELPER FUNCTIONS
int FJ_standard(int n);
bool compare(int a, int b);
int calc_jacobsthal(int n);
int get_jacobsthal_index(int index);
int get_number_on_index(std::vector<int>& v, int index);
int get_number_on_index(std::list<int>& l, int index);
std::vector<int>::iterator get_iterator_on_index(std::vector<int>::iterator it, int distance);
std::list<int>::iterator get_iterator_on_index(std::list<int>::iterator it, int distance);


template <typename T>
void pretty_print(std::string color, std::string name, T data, std::string name1 = "", T data1 = 0, std::string name2 = "", T data2 = 0, std::string name3 = "", T data3 = 0)
{
	if (verbose) {
		std::cout << "\033[" << color << "m[PmergeMe]\033[0m ";
		std::cout << name << ": " << data;
		if (!name1.empty())
			std::cout << " // " << name1 << ": " << data1;
		if (!name2.empty())
			std::cout << " // " << name2 << ": " << data2;
		if (!name3.empty())
			std::cout << " // " << name3 << ": " << data3;
		std::cout << std::endl;
	}
}

template <typename T>
void divide_nums(T& original, T& A, T& B, int& NP)
{
	if (original.size() % 2)	{
		NP = get_number_on_index(original, original.size() - 1);
		original.pop_back();
	}
	for (size_t i = 0; i < original.size(); i = i + 2) {
		if (compare(get_number_on_index(original,i), get_number_on_index(original,i+1))) {
			A.push_back(get_number_on_index(original,i+1));
			B.push_back(get_number_on_index(original,i));
		} else {
			A.push_back(get_number_on_index(original,i));
			B.push_back(get_number_on_index(original,i+1));
		}
	}
}

template <typename T>
void insert_num(T& container, int num, int u_bound)
{
	int l_bound = 0;
	int mid;
	int mid_num;

	pretty_print("33", "num", num);
	while(l_bound <= u_bound)
	{
		mid = std::floor((l_bound + u_bound) / 2);
		mid_num = get_number_on_index(container, mid);

		pretty_print("35", "[1] container.size()", static_cast<int>(container.size()), "L_bound", l_bound, "U_bound", u_bound, "mid", mid);
		if (mid == u_bound && mid == l_bound)
		{
			pretty_print("35", "[2] container.size()", static_cast<int>(container.size()), "L_bound", l_bound, "U_bound", u_bound, "mid", mid);
			if (u_bound != static_cast<int>(container.size()) && compare(mid_num, num))
				mid++;
			pretty_print("35", "[3] container.size()", static_cast<int>(container.size()), "L_bound", l_bound, "U_bound", u_bound, "mid", mid);
			container.insert(get_iterator_on_index(container.begin(), mid), num);
			return;
		}
		if (compare(mid_num, num))
			l_bound = mid + 1;
		else
			u_bound = mid - 1;
	}
	pretty_print("35", "[4] container.size()", static_cast<int>(container.size()), "L_bound", l_bound, "U_bound", u_bound, "mid", mid);
	container.insert(get_iterator_on_index(container.begin(), mid), num);
	return;
}

#endif
