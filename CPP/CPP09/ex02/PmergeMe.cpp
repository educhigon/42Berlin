/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2026/04/03 14:58:41 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"PmergeMe.hpp"

// ##############
// CANONICAL FORM
// ##############

int count_comparisons = 0;

PmergeMe::PmergeMe(): vec(), lis(), ordered_vec(), ordered_lis()
{
	if (verbose) { std::cout << "\033[32m[PmergeMe]\033[0m Default Constructor called on " << std::endl;}
}
PmergeMe::~PmergeMe()
{
	if (verbose) { std::cout << "\033[32m[PmergeMe]\033[0m Destructor called on " << std::endl;}
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (verbose) { std::cout << "\033[32m[PmergeMe]\033[0m Copy assignment operator called" << std::endl;}
	if (this != &other)
	{
		for (size_t i = 0; i < other.vec.size(); i++)
			vec.push_back(other.vec[i]);
		for (std::list<int>::const_iterator it = other.lis.begin(); it != other.lis.end(); ++it)
			lis.push_back(*it);
		for (size_t i = 0; i < other.ordered_vec.size(); i++)
			ordered_vec.push_back(other.ordered_vec[i]);
		for (std::list<int>::const_iterator it = other.ordered_lis.begin(); it != other.ordered_lis.end(); ++it)
			ordered_lis.push_back(*it);
	}
	return (*this);
}

PmergeMe::PmergeMe(const PmergeMe &obj) : vec(obj.vec), lis(obj.lis), ordered_vec(obj.ordered_vec), ordered_lis(obj.ordered_lis)
{
	if (verbose) { std::cout << "\033[32m[PmergeMe]\033[0m Copy constructor called" << std::endl;}
}

// ################
// HELPER FUNCTIONS
// ################

int FJ_standard(int n)
{
	// C(n) = n⌈log2 n⌉ − 2^⌈log2 n⌉ + 1
	double lg = std::log(static_cast<double>(n)) / std::log(2.0); // Because log2 n = log n / log 2
	int ceil_log2 = static_cast<int>(std::floor(lg));
	if (lg > static_cast<double>(ceil_log2))
		++ceil_log2;
	// now compute n*ceil_log2 - 2^ceil_log2 + 1
	int pow2 = 1 << ceil_log2; // safe for ceil_log2 < (int)sizeof(int)*8
	return n * ceil_log2 - pow2 + 1;
}

bool compare(int a, int b)
{
	pretty_print("33", "Comparing", a, "and", b);
	count_comparisons++;
	if (a < b)
		return true;
	else
		return false;
}

int calc_jacobsthal(int n)
{
	int first = 0;
	int second = 1;

	if (n < 2)
		return n;
	else
	{
		for (int i = 0; i < n; i++)
		{
			int temp = second;
			second = 2 * first + second;
			first = temp;
		}
	}
	return second;
}

int get_jacobsthal_index(int index)
{
	int jacob = 1;
	while(index != calc_jacobsthal(jacob) && !(index < calc_jacobsthal(jacob) && index > calc_jacobsthal(jacob - 1)))
		jacob++;

	if (index - 1 == calc_jacobsthal(jacob - 1))
		return calc_jacobsthal(jacob + 1);
	else
		return (index - 1);
}

int get_number_on_index(std::vector<int>& v, int index) {
	return v[index];
}

int get_number_on_index(std::list<int>& l, int index) {
	std::list<int>::iterator it = l.begin();
	std::advance(it, index);
	return *it;
}

std::vector<int>::iterator get_iterator_on_index(std::vector<int>::iterator it, int distance) {
	return it + distance;
}

std::list<int>::iterator get_iterator_on_index(std::list<int>::iterator it, int distance) {
	std::advance(it, distance);
	return it;
}


// ################
// MEMBER FUNCTIONS
// ################

std::vector<int> PmergeMe::sort_vector(std::vector<int> v)
{
	std::vector<int> SortedA; // winners
	std::vector<int> A; // winners
	std::vector<int> B; // losers
	std::vector<int> newB; // losers
	int NP = -1;

	if (v.size() == 1)
		return v;

	pretty_print("32", "sort_vector() called with vector of size", v.size());

	/*########################################
	##################### 1 ##################
	##########################################

	First step is to divide the numbers in pairs and compare them, saving winners in A and losers in B
	If we have an odd number of elements, we store the odd element in NP to be later added to the insertion numbers */

	divide_nums(v, A, B, NP);

	/*########################################
	##################### 2 ##################
	##########################################

	After we divide all numbers, we take the winners and call the same function recursively, to do the same process again
	We step the recursion when the vector with the numbers has 2 or less numbers.
	On the step we stop the recursion we will order the vector with up to two simple comparisons. */

	if (A.size() >= 2)
		SortedA = this->sort_vector(A);
	else
	{
		SortedA = A;
		if (!B.empty())
			SortedA.insert(SortedA.begin(), B[0]);
		if (NP != -1)
		{
			if (compare(NP, SortedA[0]))
				SortedA.insert(SortedA.begin(), NP);
			else if (compare(NP, SortedA[SortedA.size() - 1]))
				SortedA.insert(SortedA.begin() + 1, NP);
			else
				SortedA.push_back(NP);
		}
		return SortedA;
	}
	pretty_print("32", "sort_vector() back with vector of size", SortedA.size());

	/*########################################
	##################### 3 ##################
	##########################################

	Back to where we called the recursion, we have now a winner vector with sorted values: SortedA
	With this new vector we create newB, which is the former loser vector B now sorted
	respecting the original pairs (the ones that created A and B in the beginning).

	This will help us when we need to find the right numbers to be inserted.
	Additionally, if in this iteration we had a NP number, we simply add it to the end of newB (after the losers are sorted) */

	for (size_t i = 0; i < SortedA.size(); i++) {
		std::vector<int>::iterator it = std::find(A.begin(), A.end(), SortedA[i]);
		newB.push_back(* (B.begin() + std::distance(A.begin(), it)));
	}
	if (NP != -1)
		newB.push_back(NP);

	/*########################################
	##################### 4 ##################
	##########################################

	For the insertion mechanism, we first find out the next index of the number we need to insert
	based on the Jacobsthal sequence.
	The Jacobsthal calculation here not only calculates the right Jacobsthal for the last index we added to SortedA,
	but also gives back the next index we need to add: 1 -> 3 -> 2 -> 5 -> 4 -> 11 -> 10 ....
	We have a special condition for the end of the insertion, checking if the index given by the Jacobsthal goes
	out of bounds in the losers newB vector. If it does, we can skip a few numbers in Jacobsthal sequence, using the
	last item in newB as the number to be inserted and the index to be used for the next iteration. */

	int index = 1;
	SortedA.insert(SortedA.begin(), newB[index - 1]);
	while(SortedA.size() != A.size() + newB.size())
	{
		if (verbose) {
			std::cout << "\nIteration: " << (SortedA.size() - (A.size() + 1)) << std::endl;
			std::cout << "SortedA: ";
			for (size_t i = 0; i < SortedA.size(); i++)
				std::cout << SortedA[i] << " ";
			std::cout << std::endl;
			std::cout << "newB: ";
			for (size_t i = 0; i < newB.size(); i++)
				std::cout << newB[i] << " ";
			std::cout << std::endl;
		}

		pretty_print("33", "Index to Jacob", index);
		index = get_jacobsthal_index(index);
		pretty_print("33", "Index from Jacob", index);
		if (static_cast<size_t>(index) > newB.size())
			index = newB.size();
		pretty_print("33", "Index from Jacob (fixed)", index);

		size_t u_bound = index + (SortedA.size() - (A.size() + 1));
		if (u_bound > SortedA.size())
			u_bound = SortedA.size() + 1;
		insert_num(SortedA, newB[index - 1], u_bound);
	}
	if (verbose) {
		std::cout << "\nIteration: " << (SortedA.size() - (A.size() + 1)) << std::endl;
		std::cout << "SortedA: ";
		for (size_t i = 0; i < SortedA.size(); i++)
			std::cout << SortedA[i] << " ";
		std::cout << std::endl;
		std::cout << "newB: ";
		for (size_t i = 0; i < newB.size(); i++)
			std::cout << newB[i] << " ";
		std::cout << std::endl;
	}

	// Optional Check to find where the vector started to be not sorted
	// for (size_t i = 0; i < SortedA.size() -1; i++) {
	// 	if(SortedA[i] > SortedA[i + 1])	{
	// 		std::cout << "\033[31m" << "ERROR: Vector is not sorted!" << "\033[0m" << std::endl;
	// 		std::cout << "wrong in i: " << i << " with values: " << SortedA[i] << " and " << SortedA[i + 1] << std::endl;
	// 	}
	// }
	return SortedA;
}

std::list<int> PmergeMe::sort_list(std::list<int> l)
{
	std::list<int> SortedA; // winners
	std::list<int> A; // winners
	std::list<int> B; // losers
	std::list<int> newB; // losers
	int NP = -1;

	if (l.size() == 1)
		return l;
	pretty_print("32", "sort_vector() called with vector of size", l.size());

	divide_nums(l, A, B, NP);

	if (A.size() >= 2)
		SortedA = this->sort_list(A);
	else
	{
		SortedA = A;
		if (!B.empty())
			SortedA.insert(SortedA.begin(), B.front());
		if (NP != -1)
		{
			std::list<int>::iterator it = SortedA.begin();
			if (compare(NP, SortedA.front()))
				SortedA.insert(it, NP);
			else if (compare(NP, SortedA.back()))
				SortedA.insert(++it, NP);
			else
				SortedA.push_back(NP);
		}
		return SortedA;
	}
	pretty_print("32", "sort_vector() back with vector of size", SortedA.size());

	for (std::list<int>::iterator it = SortedA.begin(); it != SortedA.end(); it++) {
		std::list<int>::iterator itA = std::find(A.begin(), A.end(), *it);
		std::list<int>::iterator itB = B.begin();
		std::advance(itB, std::distance(A.begin(), itA));
		newB.push_back(*itB);
	}
	if (NP != -1)
		newB.push_back(NP);

	int index = 1;
	SortedA.insert(SortedA.begin(), newB.front());
	while(SortedA.size() != A.size() + newB.size())
	{
		index = get_jacobsthal_index(index);
		if (static_cast<size_t>(index) > newB.size())
			index = newB.size();
		size_t u_bound = index + (SortedA.size() - (A.size() + 1));
		if (u_bound > SortedA.size())
			u_bound = SortedA.size() + 1;
		insert_num(SortedA, get_number_on_index(newB, index - 1), u_bound);
	}

	// Optional Check to find where the list started to be not sorted
	// for (std::list<int>::iterator it = SortedA.begin(); it != SortedA.end(); it++) {
	// 	std::list<int>::iterator copy_it = it;
	// 	if(*it > *(++copy_it) && copy_it != SortedA.end()){
	// 		std::cout << "\033[31m" << "ERROR: List is not sorted!" << "\033[0m" << std::endl;
	// 		std::cout << "wrong with values: " << *(it) << " and " << *(copy_it) << std::endl;
	// 	}
	// }
	return SortedA;
}

void PmergeMe::order_numbers()
{
	clock_t time1, time2;
	size_t num_display = 10;

	// ########################################
	// ################ BEFORE ################
	// ########################################
	std::cout << "Before: ";
	for (size_t i = 0; i < this->vec.size(); i++) {
		if (i < num_display)
			std::cout << this->vec[i] << " ";
		else {
			std::cout << "[.+" << this->vec.size() - num_display << ".]";
			break;
		}
	}
	std::cout << std::endl;

	// ########################################
	// ################ VECTOR ################
	// ########################################
	time1 = clock();
	this->ordered_vec = this->sort_vector(this->vec);
	time2 = clock();
	double difference_vec = (time2 - time1) * 1000000.0 / CLOCKS_PER_SEC;
	int count_comparisons_vec = count_comparisons;
	count_comparisons = 0;

	std::cout << "After Vec: ";
	for (size_t i = 0; i < this->ordered_vec.size(); i++) {
		if (i < num_display)
			std::cout << this->ordered_vec[i] << " ";
		else {
			std::cout << "[.+" << this->ordered_vec.size() - num_display << ".]";
			break;
		}
	}
	for (size_t i = 0; i < this->ordered_vec.size() -1; i++) {
		if(ordered_vec[i] > ordered_vec[i + 1]) {
			std::cout << "\033[31m" << "Error: Vector is not sorted!" << "\033[0m" << std::endl;
			std::cout << "wrong in i: " << i << " with values: " << ordered_vec[i] << " and " << ordered_vec[i + 1] << std::endl;
			throw std::runtime_error("Vector is not sorted");
			return;
		}
	}
	std::cout << std::endl;

	// ########################################
	// ################# LIST #################
	// ########################################
	time1 = clock();
	this->ordered_lis = this->sort_list(this->lis);
	time2 = clock();
	double difference_lis = (time2 - time1) * 1000000.0 / CLOCKS_PER_SEC;
	int count_comparisons_lis = count_comparisons;
	count_comparisons = 0;

	std::cout << "After Lis: ";
	for (std::list<int>::iterator it = this->ordered_lis.begin(); it != this->ordered_lis.end(); it++) {
		if (std::distance(this->ordered_lis.begin(),it) < static_cast<long int>(num_display))
			std::cout << *it << " ";
		else
		{
			std::cout << "[.+" << this->ordered_lis.size() - num_display << ".]";
			break;
		}
	}
	std::cout << std::endl;

	for (std::list<int>::iterator it = this->ordered_lis.begin(); it != this->ordered_lis.end(); it++) {
		std::list<int>::iterator copy_it = it;
		if(*it > *(++copy_it) && copy_it != this->ordered_lis.end()){
			std::cout << "\033[31m" << "Error: List is not sorted!" << "\033[0m" << std::endl;
			std::cout << "wrong with values: " << *(it) << " and " << *(copy_it) << std::endl;
			throw std::runtime_error("List is not sorted");
			return;
		}
	}

	// ########################################
	// ########### COMPARISON CHECK ###########
	// ########################################
	if (count_comparisons_vec <= FJ_standard(this->number_of_elements()) && count_comparisons_lis <= FJ_standard(this->number_of_elements()))
	{
		std::cout << "Comparisons made on Vec: \033[32m" << count_comparisons_vec << "\033[0m vs FJ standard: \033[32m" << FJ_standard(this->number_of_elements()) << "\033[0m" << std::endl;
		std::cout << "Comparisons made on Lis: \033[32m" << count_comparisons_lis << "\033[0m vs FJ standard: \033[32m" << FJ_standard(this->number_of_elements()) << "\033[0m" << std::endl;
		std::cout << "\033[32mSuccess: Number of comparisons <= Ford-Johnson standard!\033[0m" << std::endl;
	}
	else
	{
		std::cerr << "\033[31mError: Number of comparisons > Ford-Johnson standard!\033[0m" << std::endl;
		std::cout << "Comparisons made on Vec: \033[31m" << count_comparisons_vec << "\033[0m vs FJ standard: \033[31m" << FJ_standard(this->number_of_elements()) << "\033[0m" << std::endl;
		std::cout << "Comparisons made on Lis: \033[31m" << count_comparisons_lis << "\033[0m vs FJ standard: \033[31m" << FJ_standard(this->number_of_elements()) << "\033[0m" << std::endl;
		throw std::runtime_error("Number of comparisons exceeds Ford-Johnson standard");
	}

	// ########################################
	// ############## TIME CHECK ##############
	// ########################################
	std::cout << std::endl;
	std::cout << "Time to process a range of " << this->vec.size() << " elements with std::vector: " << difference_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << this->lis.size() << " elements with std::list: " << difference_lis << " us" << std::endl;
}

void PmergeMe::check_save_input(std::string input)
{
	std::vector<std::string> out;
	std::size_t start = 0;
	count_comparisons = 0;

	while (true) {
		std::size_t pos = input.find(' ', start);
		if (pos == std::string::npos) {
			out.push_back(input.substr(start));
			break;
		}
		out.push_back(input.substr(start, pos - start));
		start = pos + 1;
	}

	for (size_t i = 0; i < out.size(); i++)
	{
		for (size_t j = 0; j < out[i].size(); j++)
		{
			if (std::isdigit(out[i][j]))
				continue;
			else
				throw std::runtime_error("Invalid character in input");
		}
		std::istringstream iss(out[i]);
		int value;
		if (!(iss >> value)) throw std::invalid_argument("stoi_ss: invalid");
		// ensure no trailing non-whitespace
		char c;
		if (iss >> c) throw std::invalid_argument("stoi_ss: trailing characters");
		vec.push_back(value);
		lis.push_back(value);
	}
}
