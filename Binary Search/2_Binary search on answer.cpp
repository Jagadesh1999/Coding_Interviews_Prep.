// Binary Search on answer :
// This means the search space is the answer itself.

// 1. CSES - Factory Machines Problem.
// A factory has n machines which can be used to make products. Your goal is to make a total of t products.
// For each machine, you know the number of seconds it needs to make a single product. The machines can work simultaneously, and you can freely decide their schedule.
// What is the shortest time needed to make t products?

// Input : The first input line has two integers n and t: the number of machines and products.
//         The next line has n integers k_1,k_2,\dots,k_n: the time needed to make a product using each machine.

// Output : Print one integer: the minimum time needed to make t products.

// Input:
// 3 7
// 3 2 5

// Output:
// 8
// Explanation: By the end of 8 seconds, machine 1 makes two products, machine 2 makes four products and machine 3 makes one product.

// Tip : We do get the essence of "How much is enough?" in the question. Thats a good indication that is a BS Problem.

// Observations :
// -- The time will be the search space in this problem.
// -- We will create a check(t), that tells, is t seconds enough?
// -- In the above problem, everything from 8 seconds is enough. So, they will be the sequence of 1s.
// -- Everything before that will be the sequence of 0s. 
// -- Hence, we have reframed the problem statement in such a way that finding the first 1 is the ans.

// low = 0; 
// high = any k value * t (because that machine will be able produce t products)
//        but preferred is min k value because this makes the search space smaller.


