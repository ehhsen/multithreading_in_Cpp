// There are multiple ways to create threads in C++11.
// In this file, we create threads by passing functions to std::thread.

#include<thread>
#include<chrono> 
#include<algorithm>

#include<iostream>
using namespace std;
using namespace std::chrono;

typedef unsigned  long long  ull;

// These variables count the number of even and odd numbers found.
ull  even_count = 0, odd_count = 0;

// Checks every number in the given range and counts the even numbers.
// (i & 1) checks the least significant bit:
// 0 -> even, 1 -> odd.
void find_even(ull start, ull stop) {
	for (ull i = start; i <= stop; ++i) {
		if ((i & 1) == 0) {
			even_count += 1;
		}
	}
}

// Checks every number in the given range and counts the odd numbers.
void find_odd(ull start, ull stop) {
	for (ull i = start; i <= stop; ++i) {
		if ((i & 1) == 1) {
			odd_count += 1;
		}
	}
}

int main() {
	std::cout << "started";
	ull start = 0, stop = 1900000000;

	// Start measuring execution time before creating the threads.
	auto start_time = high_resolution_clock::now();

	// Create two threads.
	// Each thread starts executing its assigned function concurrently.
	std::thread t1(find_even, start, stop);
	std::thread t2(find_odd, start, stop);

	// join() makes the main thread wait until the worker threads finish.
	// We must join the threads before accessing their final results.
	t1.join();
	t2.join();

	// Sequential version for comparison:
	// These would execute one after another instead of concurrently.
	//find_even(start, stop); 
	//find_odd(start, stop);

	// Stop measuring after both threads have completed.
	auto stop_time = high_resolution_clock::now();

	// Calculate the elapsed time in seconds.
	auto duration = duration_cast<seconds>(stop_time - start_time);

	std::cout << "\nSum of even numbers: " << even_count << "\nSum of odd numbers: " << odd_count << std::endl;
	std::cout << " duration: " << duration;
	return 0;
}