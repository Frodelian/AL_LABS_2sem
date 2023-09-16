#include <cstdlib>
#include <ctime>
#include <future>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

std::mutex mut;
double arr_fill(double *numbers, int size) {
  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    int ran = rand() % 1000;
    numbers[i] = ran + 1;
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;
  return *numbers;
}
void sorter(double *numbers, int starting, int ending, const std::string name) {
  int temp = 0;
  std::lock_guard<std::mutex> lock(mut);
  for (int i = starting; i < ending - 1; i++) {
    int min = i;
    for (int j = i + 1; j < ending; j++) {
      if (numbers[j] < numbers[min]) {
        min = j;
      }
    }
    temp = numbers[i];
    numbers[i] = numbers[min];
    numbers[min] = temp;
  }
  for (size_t i = starting; i < ending; ++i) {
    std::cout << name << " ";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << numbers[i] << std::endl;
  }
}
int main() {
  int size = 12;
  double *arr_async = new double[size];
  double *arr_thread = new double[size];
  std::cout << "Array for async" << std::endl;
  arr_fill(arr_async, size);
  std::cout << std::endl;
  std::future<void> async_1 = std::async(sorter, arr_async, 0, 6, "async_1");
  std::future<void> async_2 = std::async(sorter, arr_async, 5, 12, "async_2");
  async_1.get();
  async_2.get();
  std::future<void> async_3 = std::async(sorter, arr_async, 0, 12, "async_3");
  async_3.get();
  std::cout << "Array for async after sort" << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << arr_async[i] << " ";
  }
  std::cout << std::endl << std::endl;
  std::cout << "Array for thread" << std::endl;
  arr_fill(arr_thread, size);
  std::cout << std::endl;
  std::thread thread_1(sorter, arr_thread, 0, 6, "thread_1");
  std::thread thread_2(sorter, arr_thread, 5, 12, "thread_2");
  thread_1.join();
  thread_2.join();
  std::thread thread_3(sorter, arr_thread, 0, 12, "thread_3");
  thread_3.join();
  std::cout << "Array for thread after sort" << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << arr_thread[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}