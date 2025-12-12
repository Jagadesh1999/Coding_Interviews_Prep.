Recursion (Definition) : 
-- A function calling itself is called as recursion.

// Example 1 :
// void solve(int n) {
//   if(n==0) return;
//   cout << "Hi" << n << endl;
//   solve(n-1);
// }

// Hi 5
// Hi 4
// Hi 3
// Hi 2
// Hi 1

// Example 2 :
// void solve(int n) {
//   if(n<=0) return;
//   solve(n-2);
//   cout << "Hi" << n << endl;
//   solve(n-1);
// }

// Homework : Trace the output for the above code.

Trace Recursion : 
=================
There are 3 levels to trace recursion.
1. Intuitive
2. Recursion Tree
3. Recursion Stack

First start with Level 3 and then move up the levels. 
// Understand Basics. Build intuition. Level up.

1. Fibonacci Series.
// 0 1 1 2 3 5 8...and so on.

int fib(int n) {
  if(n <= 1) return n; // Base Case : Place where the recursion stops.
  return fib(n-1) + fib(n-2); // Recursive Case 
}

Recursion Tree for fib(3) :
===============================
        (3) - Value: 2
       /   \
      /     \
    fib(2)  fib(1)
    / \      |
   /   \     1 (Base Case)
fib(1) fib(0)
  |      |
  1      0 (Base Case)
(Base Case)


Recursion stack and flow for fib(3) :
======================================
// Know what is a stack frame?
// Know about how stack frames are created and deleted?
[Value of fib(3) is 2, sequence is 0, 1, 1, 2]

                (3)
                |
                | Calculates: 1 + 1 = 2
                |
     /---------|----------\
     |                    |
  Fib(2)                Fib(1)
  |                     |
  | Calculates: 1 + 0 = 1 | Return 1 (to Fib(3))
  |                     |
  /----\                (Base Case)
  |    |
Fib(1) Fib(0)
  |    |
  |    |
  | Return 0 (to Fib(2))
  |
  Return 1 (to Fib(2))
  (Base Case)

1. Call fib(3). Needs fib(2) and fib(1).
2. Call fib(2). Needs fib(1) and fib(0).
3. Call fib(1) -> Returns 1. (Base Case)
4. Call fib(0) -> Returns 0. (Base Case)
5. fib(2) completes: 1 + 0 = 1 -> Returns 1 to fib(3).
6. fib(1) completes: Returns 1 to fib(3).
7. fib(3) completes: 1 + 1 = 2 -> Returns 2.

// Recursion Categories : 
  // Divide and Conquer
  // Backtrack
  // K-th Logic
  // Print Factors/ Fractals.

Building the Recursive Code : 
=============================
1. Check if the string is palindromic using the recursion.
// In Recursion, we usually break one bigger problem into smaller problems.
