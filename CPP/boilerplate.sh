
# Check if an argument is provided
if [ $# -lt 2 ]; then
  echo "Usage: $0 <name_with_underscores> <destination_folder>"
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

# DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
DIR="$(cd "$(dirname "$0")" && pwd)"

"$DIR/class_generator.sh" "$input_name" "$destination_folder"
"$DIR/main_generator.sh" "$destination_folder"
"$DIR/makefile_generator.sh" "$input_name" "$destination_folder"
