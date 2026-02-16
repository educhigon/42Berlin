#!/bin/bash

# Check if an argument is provided
if [ $# -lt 1 ]; then
  echo "Usage: $0 <name_with_underscores> *<destination_folder>"
  exit 1
fi

to_lower_case() {
  local input="$1"
  # Convert to UpperCamelCase by capitalizing the first letter of each word
  echo "$input" | tr '[:upper:]' '[:lower:]'
}
# Function to convert to UpperCamelCase

to_upper_camel_case() {
  local input="$1"
  # Split by underscores and capitalize each part
  echo "$input" | awk -F'_' '{
    for(i=1;i<=NF;i++) {
      $i=toupper(substr($i,1,1)) substr($i,2)
    }
  } 1' | tr -d ' '  # Remove any space if present
}

# Get the input argument
input_name="$1"
input_name=$(to_lower_case "$input_name")

destination_folder="$2"

# Convert to UpperCamelCase
upper_camel_case_name=$(to_upper_camel_case "$input_name")

# Convert to all CAPS
all_caps_name=$(echo "$upper_camel_case_name" | tr '[:lower:]' '[:upper:]')

# Define the file name
file_name="$upper_camel_case_name.hpp"

# Create and write to the file
{

echo "/* ************************************************************************** */"
echo "/*                                                                            */"
echo "/*                                                        :::      ::::::::   */"
echo "/*   $upper_camel_case_name.hpp                                       :+:      :+:    :+:   */"
echo "/*                                                    +:+ +:+         +:+     */"
echo "/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */"
echo "/*                                                +#+#+#+#+#+   +#+           */"
echo "/*   Created: 2025/09/25 12:47:51 by edugonza          #+#    #+#             */"
echo "/*   Updated: 2025/10/07 15:42:24 by edugonza         ###   ########.fr       */"
echo "/*                                                                            */"
echo "/* ************************************************************************** */"
echo ""
echo "#ifndef $all_caps_name""_HPP"
echo "# define $all_caps_name""_HPP"
echo ""
echo "#include <iostream>"
echo "#include <string>"
echo ""
echo "class $upper_camel_case_name {"
echo ""
echo "	public:"
echo "		$upper_camel_case_name();"
echo "		virtual ~$upper_camel_case_name();"
echo "		$upper_camel_case_name& operator=(const $upper_camel_case_name& other);"
echo "		$upper_camel_case_name(const $upper_camel_case_name &obj);"
echo ""
echo "		$upper_camel_case_name(std::string name);"
echo ""
echo "	private:"
echo ""
echo "	protected:"
echo "		std::string	_name;"
echo ""
echo "};"
echo ""
echo "#endif"
} > "$file_name"

# Inform the user
echo "File '$file_name'"

if [ $destination_folder ]; then
  mv "$file_name" "./$destination_folder/$file_name"
fi

# Define the file name
file_name="$upper_camel_case_name.cpp"

# Create and write to the file
{

echo "/* ************************************************************************** */"
echo "/*                                                                            */"
echo "/*                                                        :::      ::::::::   */"
echo "/*   $upper_camel_case_name.cpp                                       :+:      :+:    :+:   */"
echo "/*                                                    +:+ +:+         +:+     */"
echo "/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */"
echo "/*                                                +#+#+#+#+#+   +#+           */"
echo "/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */"
echo "/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */"
echo "/*                                                                            */"
echo "/* ************************************************************************** */"
echo ""
echo "#include	\"$upper_camel_case_name.hpp\""
echo ""
echo "// ##############"
echo "// CANONICAL FORM"
echo "// ##############"
echo ""
echo "$upper_camel_case_name::$upper_camel_case_name() : _name(\"\")"
echo "{"
echo "	std::cout << \"\033[32m[$upper_camel_case_name]\033[0m Default Constructor called on '\" << this->_name << \"'\" << std::endl;"
echo "}"
echo "$upper_camel_case_name::~$upper_camel_case_name()"
echo "{"
echo "	std::cout << \"\033[32m[$upper_camel_case_name]\033[0m Destructor called on '\" << this->_name << \"'\" << std::endl;"
echo "}"
echo "$upper_camel_case_name& $upper_camel_case_name::operator=(const $upper_camel_case_name& other)"
echo "{"
echo "	std::cout << \"\033[32m[$upper_camel_case_name]\033[0m Copy assignment operator called\" << std::endl;"
echo "	if (this != &other)"
echo "	{"
echo "		this->_name = other._name;"
echo "	}"
echo "	return (*this);"
echo "}"
echo ""
echo "// Better construction - best practice"
echo "$upper_camel_case_name::$upper_camel_case_name(const $upper_camel_case_name &obj) : _name(obj._name)"
echo "{"
echo "	std::cout << \"\033[32m[$upper_camel_case_name]\033[0m Copy constructor called\" << std::endl;"
echo "}"
echo ""
echo "// // Not the best practice:"
echo "// $upper_camel_case_name::$upper_camel_case_name(const $upper_camel_case_name &obj)"
echo "// {"
echo "// 	std::cout << \"Copy constructor called\" << std::endl;"
echo "//	*this = obj;"
echo "// }"
echo ""
echo "$upper_camel_case_name::$upper_camel_case_name(std::string name) : _name(name)"
echo "{"
echo "	std::cout << \"\033[32m[$upper_camel_case_name]\033[0m Constructor called on '\" << this->_name << \"'\" << std::endl;"
echo "}"
echo ""
echo "// ################"
echo "// MEMBER FUNCTIONS"
echo "// ################"
echo ""

} > "$file_name"

# Inform the user
echo "File '$file_name'"

if [ $destination_folder ]; then
  mv "$file_name" "./$destination_folder/$file_name"
fi
