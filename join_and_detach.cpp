#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

// JOIN: waits for the thread to finish , if we dont use it we may lost the compute of the thread and the main() might terminate before we get the final results

//void run(int count) {
//	while ( count --> 0) {
//		std::cout << "Elif Shafak" << std::endl;
//	}
//	std::this_thread::sleep_for(chrono::seconds(5));
//}
//int main() {
//	std::cout << "\nmain() started "<<std::endl;
//	std::thread t(run, 10);
//	if (t.joinable()) {  // checks if the thread is joinable or not, it helps to avoid double joining in large programs and add an extra seurity to avoid the runtime error
//		t.join();  // always use joinable() in complex programs
//	}
//	//t.join(); two  time joins leads to a run time error cuz what does double waiting mean??? 
//	std::cout << "\nmain() ended ";
//	return 0;
//}

void run(int count) {
	while (count-- > 0) {
		std::cout << "Elif Shafak" << std::endl;
	}
	/*std::this_thread::sleep_for(chrono::seconds(5));*/
	std::cout << "thread finished" << std::endl;
}
int main() {
	std::thread t(run, 10);
	std::cout << "\nmain() started " << std::endl;
	
	t.detach();
	std::this_thread::sleep_for(chrono::seconds(5));
	std::cout << "\nmain() ended ";
	return 0;
}