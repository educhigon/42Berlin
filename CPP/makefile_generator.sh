#!/bin/bash

# Check if an argument is provided
if [ $# -lt 1 ]; then
  echo "Usage: $0 <name>"
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
  # Convert to UpperCamelCase by capitalizing the first letter of each word
  echo "$input" | awk '{for(i=1;i<=NF;i++) { $i=toupper(substr($i,1,1)) substr($i,2) }}1'
}

get_files() {
  # Convert to UpperCamelCase by capitalizing the first letter of each word
 ls | grep .cpp | sed 's/.cpp/.cpp \\/'
}

# Get the input argument
input_name="$1"
input_name=$(to_lower_case "$input_name")

# Convert to UpperCamelCase
upper_camel_case_name=$(to_upper_camel_case "$input_name")

# Convert to all CAPS
all_caps_name=$(echo "$upper_camel_case_name" | tr '[:lower:]' '[:upper:]')

# Define the file name
file_name="Makefile"

# get CPP files in folder
files=$(get_files)
files=${files::-1}

# Create and write to the file
{

echo "NAME = $upper_camel_case_name"
echo "CXX = c++"
echo "CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -Wshadow -Wno-shadow"
echo "SRC = \\"
echo "$files"
echo ""
echo 'OBJ = $(SRC:.cpp=.o)'
echo ""
echo 'all: $(NAME)'
echo ''
echo '$(NAME): $(OBJ)'
echo '	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)'
echo ''
echo '%.o: %.cpp'
echo '	$(CXX) $(CXXFLAGS) -c $< -o $@'
echo ''
echo 'clean:'
echo '	rm -f $(OBJ)'
echo ''
echo 'fclean: clean'
echo '	rm -f $(NAME)'
echo ''
echo 're: fclean all'
echo ''
echo '.PHONY: clean fclean re all'
echo ''

} > "$file_name"


# Inform the user
echo "File '$file_name'"
