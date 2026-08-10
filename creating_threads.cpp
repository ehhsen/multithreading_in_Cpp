#include<iostream>
#include<thread>


// Type 1: Function pointer
//
// std::thread can take a normal function and its arguments.
// Here, t1 starts a new thread that executes func(10).

//void func(int x) {
//	std::cout << x << std::endl;
//}
//int main() {
//	std::thread t1(func, 10);
//	t1.join();
//	return 0;
//}


// Type 2: Lambda function
//
// A lambda can be used directly as the function executed by a thread.
// It is useful when the function is small and only needed locally.

//int main() {
//	auto func = [](int x) {
//		std::cout << x << std::endl;
//		};
//	std::thread t(func, 10);
//	t.join();
//	return 0; 
//}


// The lambda does not have to be stored in a variable.
// It can be passed directly to std::thread.

//int main() {
//	//auto func = 
//	std::thread t([](int x) {
//		std::cout << x << std::endl;
//		} , 10);
//	t.join();
//	return 0;
//}