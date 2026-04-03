#!/bin/bash
#!/usr/bin/env bash

# Check if an argument is provided
if [ $# -lt 1 ]; then
  echo "Usage: $0 <destination_folder>"
  exit 1
fi

destination_folder="$1"

# Define the file name
file_name="main.cpp"

get_files() {
  # Convert to UpperCamelCase by capitalizing the first letter of each word
 ls | grep .hpp | awk '{print "#include \""$0"\""}'
}

files=$(get_files)

# Create and write to the file
{
echo "/* ************************************************************************** */"
echo "/*                                                                            */"
echo "/*                                                        :::      ::::::::   */"
echo "/*   main.cpp                                       :+:      :+:    :+:   */"
echo "/*                                                    +:+ +:+         +:+     */"
echo "/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */"
echo "/*                                                +#+#+#+#+#+   +#+           */"
echo "/*   Created: 2025/09/25 12:47:51 by edugonza          #+#    #+#             */"
echo "/*   Updated: 2025/10/07 15:42:24 by edugonza         ###   ########.fr       */"
echo "/*                                                                            */"
echo "/* ************************************************************************** */"
echo ""

echo "$files"
echo "#include <sstream>"

echo "
void printSeparator(std::string title)
{
	std::cout << \"\n========================================\" << std::endl;
	std::cout << \"  \" << title << std::endl;
	std::cout << \"========================================\n\" << std::endl;
} "

for n in $(ls | grep .hpp | sed 's/.hpp/ /')
do
	echo "void basicTests$n()
{
	printSeparator(\"basicTests$n\");"
	echo "	$n x(\"John\", 150);           // Default constructor"
	echo "	$n y(x);        // Copy constructor (not assignment!)"
	echo "	$n z = x;       // Also copy constructor! (confusing syntax)"
	echo "	$n w(\"Peter\", 1);"
	echo "	w = x;             // Copy assignment operator"
	echo "}"
done

echo "
int main()
{
	printSeparator(\"CPP0X - EX0Y\");"

for n in $(ls | grep .hpp | sed 's/.hpp/ /')
do
		echo "	basicTests$n();"
done

echo "
	printSeparator(\"ALL TESTS COMPLETED!\");

	std::cout << \"To check for memory leaks, run:\" << std::endl;
	std::cout << \"  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./\"XXXXX\" << std::endl;
	std::cout << \"\nExpected result: \\\"All heap blocks were freed -- no leaks are possible\\\" \" << std::endl;
	std::cout << \"========================================\n\" << std::endl;

	return 0;
}
"

} > "$file_name"

if [ $destination_folder ]; then
  mv "$file_name" "./$destination_folder/$file_name"
fi

# Inform the user
echo "File '$file_name'"
