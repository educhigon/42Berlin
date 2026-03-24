#!/bin/bash
#!/usr/bin/env bash

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

get_files() {
  local destination_folder="$1"
  cd "$destination_folder" || return 1
  # Convert to UpperCamelCase by capitalizing the first letter of each word
  ls | grep .cpp | sed 's/.cpp/.cpp \\/'
}

# Convert to UpperCamelCase
upper_camel_case_name=$(to_upper_camel_case "$input_name")

# Convert to all CAPS
all_caps_name=$(echo "$upper_camel_case_name" | tr '[:lower:]' '[:upper:]')

# Define the file name
file_name="Makefile"

# get CPP files in folder
files="$(get_files "$destination_folder")"
files=${files::-1}

# Create and write to the file
{

echo "NAME = $upper_camel_case_name"
echo "CXX = c++"
echo "RM = rm -f"
echo "CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -Wshadow -Wno-shadow"
echo "SRC = \\"
echo "$files"
echo 'OBJDIR := build'
echo 'OBJS := $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))'
echo 'DEPS := $(OBJS:.o=.d)'
echo ''
echo 'all:'
echo '	@echo "\033[34m \n- COMPILING -\033[0m" ; $(MAKE) --no-print-directory $(NAME)'
echo ''
echo '$(NAME): $(OBJS)'
echo '	@echo "\033[34m \n- CREATING EXECUTABLE -\033[0m"'
echo '	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)'
echo '	@echo " ----- Created executable:" $(NAME)'
echo "	@echo \"\n\n\033[32m>>>>   'Usage : run ./$upper_camel_case_name'   <<<<\n\033[0m\""
echo ''
echo '$(OBJDIR)/%.o: %.cpp'
echo '	@mkdir -p $(dir $@)'
echo '	@$(CXX) $(CXXFLAGS) -c $< -o $@'
echo '	@echo " ----- Compiling $< -> $@"'
echo ''
echo '-include $(DEPS)'
echo ''
echo 'clean:'
echo '	@echo "\033[33m \n- CLEANING .o FILES -\033[0m"'
echo '	@$(RM) $(OBJS) $(DEPS)'
echo '	@rm -rf $(OBJDIR)'
echo '	@echo " ----- Cleaned object and dependancie files"'
echo ''
echo 'fclean: clean'
echo '	@echo "\033[33m \n- CLEANING EXECUTABLE FILES -\033[0m"'
echo '	@$(RM) $(NAME)'
echo '	@echo " ----- Removed Executable"'
echo ''
echo 're:	fclean all'
echo ''
echo 'cleanly : all clean'
echo ''
echo '.PHONY: all clean fclean re'
echo ''
echo ''

} > "$file_name"

if [ $destination_folder ]; then
  mv "$file_name" "./$destination_folder/$file_name"
fi

# Inform the user
echo "File '$file_name'"
