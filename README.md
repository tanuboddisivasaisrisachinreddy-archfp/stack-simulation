# stack-simulation
# Stack Simulation (Array Implementation in C)

This project demonstrates the internal working of a Stack Data Structure using a static array in the C programming language.  
It is designed for Data Structures & Algorithms (DSA) laboratory work, academic mini-projects, and for understanding how stack operations modify memory internally.

The program provides a menu-driven interface and prints step-by-step simulation messages for each operation (push, pop, peek), showing how the `top` pointer and the array change during execution.

---

## Features

### Core Stack Operations
- Push – Insert an element into the stack.
- Pop – Remove the top element.
- Peek – Display the top element without removing it.

### Display Capabilities
- Display Stack – Shows elements from top to bottom.
- Display Internal Array – Shows:
  - Current top index
  - Filled indices
  - Empty indices marked as `[empty]`

### Educational Simulation
Each operation prints detailed steps explaining:
- Overflow/underflow checking
- Update of the top pointer
- Where data is inserted or removed
- Full internal state after the operation

### Error Handling
- Stack Overflow detection
- Stack Underflow detection

---

## Project Structure

