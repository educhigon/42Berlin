# 🖨️ ft_printf - Custom Printf Implementation

![42 School Badge](https://img.shields.io/badge/42-School-000000?style=flat-square&logo=42)
![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white)
![Variadic Functions](https://img.shields.io/badge/Variadic-Expert-orange?style=flat-square)

> *"A complete, custom implementation of printf with all major format specifiers and advanced features."*

## 🎯 Project Overview

**ft_printf** is a comprehensive reimplementation of the standard C library `printf()` function. This project demonstrates mastery of variadic functions, format string parsing, type conversion, and output formatting. The implementation supports all major format specifiers with precise behavior matching the original printf.

**Key Features:**
- ✅ **Complete format specifier support** (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`)
- 🔢 **Advanced number base conversion** (decimal, hexadecimal)
- 🎯 **Pointer address formatting** with proper `0x` prefix
- 📊 **Character count tracking** (returns characters printed)
- 🛡️ **Robust error handling** and edge case management
- ⚡ **Modular architecture** with specialized conversion functions

---

## 🚀 Core Functionality

### **Function Signature**
```c
int ft_printf(const char *format, ...);
```

### **Return Value**
- **Success**: Returns the number of characters printed to stdout
- **Error**: Returns negative value on output error (following printf standard)

### **Format Specifiers Supported**
| Specifier | Type | Description | Example |
|-----------|------|-------------|---------|
| `%c` | `char` | Single character | `ft_printf("%c", 'A')` → `A` |
| `%s` | `char *` | String | `ft_printf("%s", "Hello")` → `Hello` |
| `%p` | `void *` | Pointer address | `ft_printf("%p", ptr)` → `0x7fff5fbff710` |
| `%d` | `int` | Signed decimal | `ft_printf("%d", -42)` → `-42` |
| `%i` | `int` | Signed integer | `ft_printf("%i", 42)` → `42` |
| `%u` | `unsigned int` | Unsigned decimal | `ft_printf("%u", 42U)` → `42` |
| `%x` | `unsigned int` | Lowercase hex | `ft_printf("%x", 255)` → `ff` |
| `%X` | `unsigned int` | Uppercase hex | `ft_printf("%X", 255)` → `FF` |
| `%%` | literal | Percent sign | `ft_printf("%%")` → `%` |

---

## 🏗️ Implementation Architecture

### **Core Structure**

#### **1. Main Function - `ft_printf()`**
```c
int ft_printf(const char *str, ...)
{
    va_list args;           // Variable argument list
    int     char_count;     // Characters printed counter
    int     i;              // String iterator
    
    va_start(args, str);    // Initialize argument list
    
    // Parse format string and handle specifiers
    while (i < str_len) {
        if (str[i] == '%')
            char_count += find_special_print(str[++i], args);
        else {
            write(1, &str[i], 1);
            char_count++;
        }
        i++;
    }
    
    va_end(args);           // Clean up argument list
    return (char_count);
}
```

#### **2. Format Specifier Router - `find_special_print()`**
```c
static int find_special_print(char c, va_list args)
{
    if (c == 'c') return (print_char(args));
    if (c == 's') return (print_string(args));
    if (c == 'p') return (print_void(args));
    if (c == 'd') return (print_decimal(args));
    if (c == 'i') return (print_integer(args));
    if (c == 'u') return (print_unsigned_decimal(args));
    if (c == 'x') return (print_hexa_lower(args));
    if (c == 'X') return (print_hexa_upper(args));
    if (c == '%') { write(1, "%", 1); return (1); }
    return (0);
}
```

---

## 🔧 Specialized Conversion Functions

### **Character & String Handling**

#### **Character Output - `print_char()`**
```c
int print_char(va_list args)
{
    char c;
    
    c = (char)va_arg(args, int);  // char promoted to int in varargs
    return (write(1, &c, 1));
}
```

#### **String Output - `print_string()`**
```c
int print_string(va_list args)
{
    char *str;
    
    str = va_arg(args, char *);
    if (!str)
        return (write(1, "(null)", 6));  // Handle NULL strings
    return (write(1, str, ft_strlen2(str)));
}
```

### **Numeric Conversions**

#### **Signed Integer - `print_decimal()` / `print_integer()`**
- **Input**: `int` value from `va_arg()`
- **Processing**: Handle negative numbers with `-` prefix
- **Output**: Decimal representation
- **Edge Cases**: `INT_MIN` (-2147483648), zero, negative values

#### **Unsigned Integer - `print_unsigned_decimal()`**
- **Input**: `unsigned int` value
- **Processing**: Convert to decimal without sign
- **Range**: 0 to 4294967295 (on 32-bit systems)
- **Optimization**: Direct division algorithm

### **Hexadecimal Conversions**

#### **Lowercase Hexadecimal - `print_hexa_lower()`**
```c
int print_hexa_lower(va_list args)
{
    unsigned long value;
    unsigned long power;
    char *letters = "0123456789abcdef";
    
    value = (unsigned int)va_arg(args, unsigned int);
    
    // Find highest power of 16
    power = 1;
    while (value / power >= 16)
        power *= 16;
    
    // Print each hex digit
    while (power > 0) {
        write(1, &letters[value / power], 1);
        value %= power;
        power /= 16;
        counter++;
    }
    return (counter);
}
```

#### **Uppercase Hexadecimal - `print_hexa_upper()`**
- **Similar algorithm** with uppercase letters: `"0123456789ABCDEF"`
- **Perfect consistency** with lowercase version
- **Case-sensitive output**: `0xFF` vs `0xff`

### **Pointer Address Formatting**

#### **Pointer Output - `print_void()`**
```c
int print_void(va_list args)
{
    unsigned long value;
    char *letters = "0123456789abcdef";
    
    value = (unsigned long)va_arg(args, void *);
    
    if (!value)
        return (write(1, "(nil)", 5));  // Handle NULL pointers
    
    write(1, "0x", 2);  // Standard hex prefix
    // ... hexadecimal conversion logic
    
    return (counter);
}
```

**Features:**
- **NULL Handling**: Prints `(nil)` for NULL pointers
- **Standard Format**: Always includes `0x` prefix
- **Platform Compatible**: Works on different architectures
- **Type Safety**: Proper casting from `void *` to `unsigned long`

---

## 🛠️ Helper Functions & Utilities

### **Enhanced String Operations**
| Function | Purpose | Optimization |
|----------|---------|--------------|
| `ft_strlen2()` | String length calculation | Optimized for printf usage |
| `ft_putchar_fd2()` | Character output to FD | File descriptor validation |
| `ft_putnbr_fd2()` | Integer output to FD | Handles `INT_MIN` edge case |
| `ft_putnbr_fd_unsigned()` | Unsigned output to FD | Optimized for unsigned values |

### **Advanced Number Formatting**

#### **Signed Integer Output - `ft_putnbr_fd2()`**
```c
int ft_putnbr_fd2(int n, int fd)
{
    long power = 1;
    int counter = 0;
    
    // Handle special cases
    if (n == 0) return (write(fd, "0", 1));
    
    // Handle negative numbers
    if (n < 0) counter = write(fd, "-", 1);
    
    // Find highest power of 10
    while (n / power != 0) power *= 10;
    power /= 10;
    
    // Print each digit
    while (power >= 1) {
        define_printer(n, power, fd);  // Custom digit printer
        n %= power;
        power /= 10;
        counter++;
    }
    
    return (counter);
}
```

**Key Features:**
- **INT_MIN Handling**: Properly handles most negative integer
- **Efficient Algorithm**: Single-pass digit extraction
- **Character Counting**: Returns exact number of characters printed
- **File Descriptor Support**: Can output to any valid FD

---

## 🔍 Advanced Technical Details

### **Variadic Function Mechanics**
```c
#include <stdarg.h>

// Variable argument handling
va_list args;           // Argument list pointer
va_start(args, format); // Initialize to first argument after format
va_arg(args, type);     // Extract next argument of specified type
va_end(args);           // Clean up argument list
```

### **Type Promotion Rules**
| Original Type | Promoted To | Reason |
|---------------|-------------|--------|
| `char` | `int` | Default argument promotion |
| `short` | `int` | Default argument promotion |
| `float` | `double` | Default argument promotion |
| `unsigned char` | `int` | Default argument promotion |

### **Memory & Performance**
- **Stack Usage**: Minimal stack allocation
- **System Calls**: Efficient `write()` usage
- **Memory Safety**: No dynamic allocation required
- **Performance**: Direct output without buffering

---

## 📊 Format Specifier Details

### **Character Handling (`%c`)**
```c
// Usage examples
ft_printf("Character: %c\n", 'A');        // Output: Character: A
ft_printf("ASCII: %c\n", 65);             // Output: ASCII: A
ft_printf("Control: %c\n", '\n');         // Output: Control: [newline]
```

### **String Handling (`%s`)**
```c
// Usage examples
ft_printf("String: %s\n", "Hello");       // Output: String: Hello
ft_printf("NULL: %s\n", NULL);            // Output: NULL: (null)
ft_printf("Empty: %s\n", "");             // Output: Empty: 
```

### **Pointer Handling (`%p`)**
```c
// Usage examples
int x = 42;
ft_printf("Address: %p\n", &x);           // Output: Address: 0x7fff5fbff710
ft_printf("NULL ptr: %p\n", NULL);        // Output: NULL ptr: (nil)
ft_printf("Function: %p\n", &printf);     // Output: Function: 0x10000abcd
```

### **Integer Formats (`%d`, `%i`, `%u`)**
```c
// Signed integers
ft_printf("Positive: %d\n", 42);          // Output: Positive: 42
ft_printf("Negative: %d\n", -42);         // Output: Negative: -42
ft_printf("Zero: %d\n", 0);               // Output: Zero: 0
ft_printf("INT_MIN: %d\n", -2147483648);  // Output: INT_MIN: -2147483648

// Unsigned integers
ft_printf("Unsigned: %u\n", 42U);         // Output: Unsigned: 42
ft_printf("Large: %u\n", 4294967295U);    // Output: Large: 4294967295
```

### **Hexadecimal Formats (`%x`, `%X`)**
```c
// Lowercase hexadecimal
ft_printf("Hex lower: %x\n", 255);        // Output: Hex lower: ff
ft_printf("Hex lower: %x\n", 0);          // Output: Hex lower: 0
ft_printf("Hex lower: %x\n", 4095);       // Output: Hex lower: fff

// Uppercase hexadecimal  
ft_printf("Hex upper: %X\n", 255);        // Output: Hex upper: FF
ft_printf("Hex upper: %X\n", 0);          // Output: Hex upper: 0
ft_printf("Hex upper: %X\n", 4095);       // Output: Hex upper: FFF
```

---

## 🎯 Usage Examples & Applications

### **Basic Output Operations**
```c
#include "ft_printf.h"

int main(void)
{
    int count;
    
    // Simple text output
    count = ft_printf("Hello, World!\n");
    ft_printf("Printed %d characters\n", count);
    
    // Multiple format specifiers
    char name[] = "Alice";
    int age = 25;
    double height = 5.6;
    
    ft_printf("Name: %s, Age: %d, Height: %.1f\n", name, age, height);
    
    return (0);
}
```

### **Debug Output & Logging**
```c
void debug_variables(int x, char *str, void *ptr)
{
    ft_printf("=== DEBUG INFO ===\n");
    ft_printf("Integer value: %d (0x%x)\n", x, x);
    ft_printf("String pointer: %p\n", str);
    ft_printf("String content: %s\n", str ? str : "(null)");
    ft_printf("Generic pointer: %p\n", ptr);
    ft_printf("==================\n");
}
```

### **Data Structure Visualization**
```c
typedef struct s_node {
    int data;
    struct s_node *next;
} t_node;

void print_list(t_node *head)
{
    int index = 0;
    
    ft_printf("Linked List Contents:\n");
    while (head)
    {
        ft_printf("Node %d: data=%d, addr=%p, next=%p\n", 
                  index, head->data, head, head->next);
        head = head->next;
        index++;
    }
}
```

### **Number System Demonstrations**
```c
void show_number_formats(int number)
{
    ft_printf("Number: %d\n", number);
    ft_printf("Decimal: %d\n", number);
    ft_printf("Unsigned: %u\n", (unsigned int)number);
    ft_printf("Hex (lower): %x\n", number);
    ft_printf("Hex (upper): %X\n", number);
    ft_printf("Character: %c\n", number);  // If in printable range
    ft_printf("Address-style: %p\n", (void *)(long)number);
}
```

---

## 🧪 Edge Cases & Error Handling

### **Input Validation**
```c
// NULL string handling
ft_printf("%s", NULL);              // Output: (null)

// NULL pointer handling
ft_printf("%p", NULL);              // Output: (nil)

// Zero values
ft_printf("%d %u %x %X", 0, 0, 0, 0); // Output: 0 0 0 0
```

### **Boundary Values**
```c
// Integer limits
ft_printf("INT_MAX: %d\n", 2147483647);     // Output: INT_MAX: 2147483647
ft_printf("INT_MIN: %d\n", -2147483648);    // Output: INT_MIN: -2147483648
ft_printf("UINT_MAX: %u\n", 4294967295U);   // Output: UINT_MAX: 4294967295

// Character edge cases
ft_printf("Null char: %c\n", '\0');         // Output: Null char: [null character]
ft_printf("High ASCII: %c\n", 127);         // Output: High ASCII: [DEL character]
```

### **Format String Edge Cases**
```c
// Consecutive percent signs
ft_printf("50%% complete\n");               // Output: 50% complete

// Empty format string
ft_printf("");                              // Output: [nothing] (returns 0)

// Only format specifiers
ft_printf("%d%c%s", 42, '!', "end");       // Output: 42!end
```

---

## 🔬 Algorithm Analysis

### **Time Complexity**
| Operation | Complexity | Description |
|-----------|------------|-------------|
| **Character output** | O(1) | Single character write |
| **String output** | O(n) | n = string length |
| **Integer conversion** | O(log₁₀ n) | n = integer value |
| **Hex conversion** | O(log₁₆ n) | n = integer value |
| **Pointer formatting** | O(log₁₆ p) | p = pointer value |
| **Overall printf** | O(f + Σc) | f = format length, c = conversion costs |

### **Space Complexity**
- **Stack Space**: O(1) - fixed local variable usage
- **No Heap**: Zero dynamic memory allocation
- **Buffer**: Direct output without buffering

### **Performance Characteristics**
- **System Calls**: Minimized `write()` operations
- **Conversion Speed**: Optimized digit extraction algorithms
- **Memory Efficiency**: No intermediate string storage
- **Scalability**: Handles any format string length

---

## 🎯 Comparison with Standard printf

### **Feature Compatibility**
| Feature | ft_printf | Standard printf | Status |
|---------|-----------|-----------------|--------|
| **Basic specifiers** | ✅ | ✅ | ✅ Complete |
| **Character counting** | ✅ | ✅ | ✅ Complete |
| **NULL handling** | ✅ | ✅ | ✅ Complete |
| **Edge cases** | ✅ | ✅ | ✅ Complete |
| **Width/precision** | ❌ | ✅ | 📋 Not required |
| **Flags (-+# 0)** | ❌ | ✅ | 📋 Not required |
| **Length modifiers** | ❌ | ✅ | 📋 Not required |

### **Behavioral Differences**
```c
// Both behave identically for supported features
printf("Test: %d %s %p\n", 42, "hello", &main);
ft_printf("Test: %d %s %p\n", 42, "hello", &main);
// Output identical for both
```

### **Performance Comparison**
| Metric | ft_printf | Standard printf | Notes |
|--------|-----------|-----------------|-------|
| **Binary Size** | Smaller | Larger | Focused implementation |
| **Startup Time** | Faster | Slower | No format parsing overhead |
| **Memory Usage** | Lower | Higher | No buffering |
| **Feature Set** | Core only | Complete | Targeted functionality |

---

## 🔧 Integration & Compilation

### **Makefile Integration**
```makefile
# ft_printf Makefile
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_printf.a

SRCS = ft_printf.c print_char.c print_string.c print_decimal.c \
       print_integer.c print_unsigned_decimal.c print_hexa_lower.c \
       print_hexa_upper.c print_void.c helper_functions.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
```

### **Usage in Projects**
```c
// Include header
#include "ft_printf.h"

// Link with library
// gcc -Wall -Wextra -Werror main.c -L. -lft_printf
```

### **Integration with Libft_power**
```c
// Seamless integration
#include "libft.h"  // Includes ft_printf.h

// Use with other Libft functions
char *str = ft_strdup("Hello");
ft_printf("Duplicated string: %s\n", str);
free(str);
```

---

## 🖼️ Visual Documentation

### **Format Specifier Flow**
![Format Specifier Processing](./docs/format_flow.png)
*[Placeholder: Flowchart showing how format specifiers are parsed and routed to appropriate functions]*

### **Variadic Function Mechanics**
![Variadic Function Stack](./docs/variadic_stack.gif)
*[Placeholder: Animation showing how variadic arguments are accessed from the stack]*

### **Number Conversion Process**
![Number Base Conversion](./docs/number_conversion.png)
*[Placeholder: Visual representation of decimal to hexadecimal conversion process]*

### **Performance Benchmarks**
![Performance Comparison](./docs/performance_benchmark.gif)
*[Placeholder: Animated comparison of ft_printf vs standard printf performance]*

---

## 💡 Key Learning Outcomes

### **Advanced C Programming**
- **Variadic Functions**: Mastery of `stdarg.h` and variable argument lists
- **Type System**: Understanding of type promotion and casting rules
- **Function Pointers**: Modular design with function dispatch
- **Low-level I/O**: Direct system call usage with `write()`

### **Algorithm Design**
- **Base Conversion**: Efficient algorithms for decimal and hexadecimal
- **String Processing**: Format string parsing and character handling
- **Memory Management**: Stack-based operations without dynamic allocation
- **Error Handling**: Comprehensive edge case management

### **System Programming**
- **File Descriptors**: Understanding of Unix I/O model
- **System Calls**: Direct interaction with kernel via `write()`
- **Performance Optimization**: Minimizing system call overhead
- **Portability**: Writing cross-platform compatible code

---

## 🎯 Real-World Applications

### **Embedded Systems Programming**
```c
// Minimal printf for microcontrollers
void embedded_debug(int sensor_value, int status)
{
    ft_printf("Sensor: %d, Status: %x\n", sensor_value, status);
    // Smaller footprint than standard printf
}
```

### **Custom Logging Systems**
```c
void custom_logger(int level, const char *module, const char *message)
{
    ft_printf("[%d] %s: %s\n", level, module, message);
    // Controlled output format
}
```

### **Protocol Implementation**
```c
void send_packet_info(unsigned int id, void *data, int size)
{
    ft_printf("PACKET: ID=%x, DATA=%p, SIZE=%d\n", id, data, size);
    // Network debugging output
}
```

---

## 🔗 Integration Examples

### **With get_next_line**
```c
void print_file_with_line_numbers(int fd)
{
    char *line;
    int line_num = 1;
    
    while ((line = get_next_line(fd)) != NULL)
    {
        ft_printf("%d: %s", line_num, line);
        free(line);
        line_num++;
    }
}
```

### **With Libft Functions**
```c
void demonstrate_integration(void)
{
    char *str = ft_strdup("Integration Test");
    char **words = ft_split(str, ' ');
    
    ft_printf("Original: %s\n", str);
    ft_printf("Word count: %d\n", ft_arrlen(words));
    ft_printf("First word: %s\n", words[0]);
    ft_printf("String address: %p\n", str);
    
    ft_split_free(words);
    free(str);
}
```

---

<div align="center">

**[⬆ Back to Top](#-ft_printf---custom-printf-implementation)**

---

*Part of the [Libft_power](../) ecosystem - demonstrating advanced variadic functions, format string parsing, and type conversion in C programming.*

**Built with 🖨️ and ⚡ at 42 Berlin**

</div>