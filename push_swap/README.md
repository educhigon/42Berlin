# 🔄 Push_swap - Optimal Sorting Algorithm

![42 School Badge](https://img.shields.io/badge/42-School-000000?style=flat-square&logo=42)
![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white)
![Algorithm](https://img.shields.io/badge/Algorithm-Sorting_Optimization-yellow?style=flat-square)
![Grade](https://img.shields.io/badge/Grade-125%2F100-brightgreen?style=flat-square)

**Efficient stack-based sorting algorithm using minimal operations to sort integer arrays with optimal complexity.**

## 🎯 Overview

<div align="center">

**Push_swap** is an advanced sorting algorithm project that challenges you to sort data using only two stacks and a limited set of operations. The goal is to sort integers in ascending order using the **minimum number of operations** possible, demonstrating algorithmic optimization and computational efficiency.

<img src="assets/Push Swap - 800 numbers.gif" width="700" alt="Push Swap Demo with 800 numbers" style="border-radius: 8px; margin: 20px 0;">

</div>



## 🚀 Algorithm Overview

### **Two-Stack System**
- **Stack A**: Contains the initial unsorted integers
- **Stack B**: Empty helper stack for temporary storage
- **Goal**: Sort Stack A in ascending order (smallest at top)

### **Available Operations**
| Operation | Description | Example |
|-----------|-------------|---------|
| `sa` | Swap first two elements of Stack A | `[2,1,3]` → `[1,2,3]` |
| `sb` | Swap first two elements of Stack B | `[5,4]` → `[4,5]` |
| `ss` | Execute `sa` and `sb` simultaneously | Both stacks swap |
| `pa` | Push top element from B to A | B→A transfer |
| `pb` | Push top element from A to B | A→B transfer |
| `ra` | Rotate Stack A up (top → bottom) | `[1,2,3]` → `[2,3,1]` |
| `rb` | Rotate Stack B up | `[4,5]` → `[5,4]` |
| `rr` | Execute `ra` and `rb` simultaneously | Both stacks rotate |
| `rra` | Reverse rotate Stack A (bottom → top) | `[1,2,3]` → `[3,1,2]` |
| `rrb` | Reverse rotate Stack B | `[4,5]` → `[5,4]` |
| `rrr` | Execute `rra` and `rrb` simultaneously | Both reverse rotate |

## 🧠 Sorting Strategy

### **Phase 1: Intelligent Partitioning**
```c
// Move elements strategically to Stack B
while (!is_sorted(stack_a) && size_a > 3) {
    pb(arrays, sizes);  // Strategic element selection
    if (should_rotate_b) rb(arrays, sizes);
}
```

### **Phase 2: Small Set Optimization**
```c
// Optimize 3-element sorting in Stack A
if (a[0] > a[1] && a[0] > a[2]) ra();  // Largest on top
if (a[1] > a[2]) rra();               // Middle element handling
if (a[0] > a[1]) sa();                // Final swap if needed
```

### **Phase 3: Optimal Recombination**
```c
// Calculate minimum cost to merge elements back
for (element in stack_b) {
    cost = calculate_rotation_cost(element, target_position);
    if (cost < min_cost) optimal_element = element;
}
```

## 🏗️ Project Architecture

```
push_swap/
├── push_swap.c          # Main program and input handling
├── push_swap.h          # Function declarations and structures
├── start_sorting.c      # Core sorting algorithm logic
├── sorting_a.c          # Stack A specific operations
├── sorting_b.c          # Stack B specific operations
├── sorting_utils.c      # Cost calculation and optimization
├── function_*.c         # Implementation of 11 stack operations
├── verifications.c      # Input validation and error handling
├── checker.c           # Bonus: Operation sequence validator
└── Push-Swap-Tester/   # Comprehensive testing suite
```

## 💻 Usage

```bash
# Compile the project
make

# Sort integers (space or argument separated)
./push_swap 3 2 1 4 5
./push_swap "42 21 1 58 3"

# Expected output: sequence of operations
sa
pb
pb
ra
pa
pa

# Test with checker (bonus)
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
# Output: OK (if correctly sorted) or KO (if not)
```

## 📊 Performance Benchmarks

| Array Size | Max Operations | Achieved | Efficiency |
|------------|----------------|----------|------------|
| **3 elements** | 3 operations | ≤ 3 | 🟢 100% |
| **5 elements** | 12 operations | ≤ 12 | 🟢 100% |
| **100 elements** | 700 operations | < 700 | 🟢 Excellent |
| **500 elements** | 5,500 operations | < 5,500 | 🟢 Excellent |

### **Complexity Analysis**
- **Time Complexity**: O(n²) worst case, O(n log n) average
- **Space Complexity**: O(n) for two stacks
- **Operation Count**: Optimized to meet 42 School benchmarks

## 🎯 Advanced Optimization Techniques

### **1. Cost-Based Selection Algorithm**
```c
int calculate_movement_cost(int target_pos_a, int target_pos_b) {
    int cost_a = min(target_pos_a, size_a - target_pos_a);
    int cost_b = min(target_pos_b, size_b - target_pos_b);
    return cost_a + cost_b - mutual_rotations(target_pos_a, target_pos_b);
}
```

### **2. Mutual Rotation Optimization**
- **Simultaneous Operations**: Use `rr` and `rrr` when both stacks need rotation
- **Direction Analysis**: Calculate optimal rotation direction (up vs down)
- **Operation Reduction**: Minimize total moves through smart coordination

### **3. Strategic Element Placement**
- **Median Tracking**: Keep larger elements in Stack B for efficient retrieval
- **Position Mapping**: Pre-calculate optimal insertion points
- **Greedy Selection**: Always choose the cheapest operation sequence

## 🔍 Testing & Validation

### **Comprehensive Test Suite**
```bash
# Run automated tests with different array sizes
bash push_swap_test_linux.sh

# Performance testing
./push_swap $(shuf -i 1-100 -n 100 | tr '\n' ' ') | wc -l
./push_swap $(shuf -i 1-500 -n 500 | tr '\n' ' ') | wc -l

# Correctness validation
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

### **Edge Cases Handled**
- ✅ **Duplicate Numbers**: Error detection and handling
- ✅ **Invalid Input**: Non-numeric and out-of-range values
- ✅ **Already Sorted**: Immediate detection (0 operations)
- ✅ **Reverse Sorted**: Worst-case scenario optimization
- ✅ **Single/Empty**: Proper handling of trivial cases

## 🛠️ Technical Implementation

### **Memory Management**
- **Dynamic Allocation**: Efficient memory usage for variable array sizes
- **Leak Prevention**: Comprehensive cleanup in all execution paths
- **Error Handling**: Robust input validation and graceful failures

### **Algorithm Efficiency**
- **Early Termination**: Detect sorted state to avoid unnecessary operations
- **Pattern Recognition**: Special cases for 2, 3, and 5-element arrays
- **Heuristic Optimization**: Smart element selection based on position costs

### **Code Quality**
- **Norminette Compliant**: Follows 42 coding standards
- **Modular Design**: Clear separation of concerns
- **Comprehensive Testing**: Validated against multiple test suites

## 🏆 Skills Demonstrated

### **Algorithm Design**
- **Optimization Theory**: Minimizing operation count through mathematical analysis
- **Complexity Analysis**: Understanding time/space trade-offs
- **Heuristic Development**: Creating efficient decision-making strategies

### **Data Structures**
- **Stack Operations**: Mastery of LIFO data structure manipulation
- **Array Management**: Dynamic memory allocation and pointer arithmetic
- **State Tracking**: Monitoring multiple data structure states simultaneously

### **Problem Solving**
- **Constraint Programming**: Working within limited operation sets
- **Recursive Thinking**: Breaking complex problems into manageable subproblems
- **Performance Optimization**: Balancing correctness with efficiency

## 💡 Key Insights

### **1. Divide and Conquer Approach**
- **Problem Decomposition**: Large arrays split into manageable chunks
- **Subproblem Optimization**: Perfect solutions for small arrays (≤3 elements)
- **Efficient Combination**: Smart merging of sorted subsequences

### **2. Greedy Algorithm Principles**
- **Local Optimization**: Always choose the immediate best option
- **Cost Function**: Mathematical model for operation counting
- **Backtracking Avoidance**: Forward-only decision making

### **3. Real-World Applications**
This project demonstrates concepts directly applicable to:
- **Database Query Optimization**: Minimizing sort operations
- **Compiler Optimization**: Efficient register allocation
- **Game AI**: Pathfinding and decision trees
- **System Design**: Resource allocation algorithms

---

<div align="center">

**Built with algorithmic precision and optimization focus**

*A comprehensive exploration of sorting algorithms, complexity theory, and performance optimization.*

</div>
