#include <condition_variable>
#include <cstdlib>
#include <ctime>
#include <future>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

std::mutex mut;
std::condition_variable reporter;
bool finished_1st = false;
bool finished_2nd = false;
bool finished_3rd = false;
double arr_fill(double *nums, int size) {
  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    int ran = rand() % 1000;
    nums[i] = ran + 1;
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;
  return *nums;
}

void sorter(double *nums, int start_point, int end_point,
            const std::string name) {
  int temp = 0;
  for (int i = start_point; i < end_point - 1; i++) {
    int min = i;
    for (int j = i + 1; j < end_point; j++) {
      if (nums[j] < nums[min]) {
        min = j;
      }
    }
    temp = nums[i];
    nums[i] = nums[min];
    nums[min] = temp;
  }
  for (size_t i = start_point; i < end_point; ++i) {
    std::cout << name << " ";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << nums[i] << std::endl;
  }
  if (name == "threads_1" or name == "asyncs_1") {
    finished_1st = true;
    reporter.notify_one();
  }
  if (name == "threads_2" or name == "asyncs_2") {
    finished_2nd = true;
    reporter.notify_one();
  }
  if (name == "threads_3" or name == "asyncs_3") {
    finished_3rd = true;
    reporter.notify_one();
  }
}

int main() {
  int size = 12;
  double *arr_async = new double[size];
  double *arr_thread = new double[size];
  std::cout << "Array for async" << std::endl;
  arr_fill(arr_async, size);
  std::cout << std::endl;
  {
    std::unique_lock<std::mutex> lock(mut);
    std::future<void> async_1 = std::async(sorter, arr_async, 0, 6, "asyncs_1");
    while (!finished_1st) {
      reporter.wait(lock);
    }
    finished_1st = false;
    std::cout << "\nFirst async ready\n" << std::endl;
    std::future<void> async_2 =
        std::async(sorter, arr_async, 6, 12, "asyncs_2");
    while (!finished_2nd) {
      reporter.wait(lock);
    }
    finished_2nd = false;
    std::cout << "\nSecond async ready\n" << std::endl;
    std::future<void> async_3 =
        std::async(sorter, arr_async, 0, 12, "asyncs_3");
    while (!finished_3rd) {
      reporter.wait(lock);
    }
    finished_3rd = false;
    std::cout << "\nThird async ready\n" << std::endl;
    std::cout << "Array for async after sort" << std::endl;
    for (int i = 0; i < size; i++) {
      std::cout << arr_async[i] << " ";
    }
    std::cout << std::endl << std::endl;
  }
  std::cout << "Array for thread" << std::endl;
  arr_fill(arr_thread, size);
  std::cout << std::endl;
  {
    std::unique_lock<std::mutex> lock(mut);
    std::thread thread_1(sorter, arr_thread, 0, 6, "threads_1");
    while (!finished_1st) {
      reporter.wait(lock);
    }
    thread_1.join();
    std::cout << "\nFirst thread ready\n" << std::endl;
    std::thread thread_2(sorter, arr_thread, 6, 12, "threads_2");
    while (!finished_2nd) {
      reporter.wait(lock);
    }
    thread_2.join();
    std::cout << "\nSecond thread ready\n" << std::endl;
    std::thread thread_3(sorter, arr_thread, 0, 12, "threads_3");
    while (!finished_3rd) {
      reporter.wait(lock);
    }
    thread_3.join();
    std::cout << "\nThird thread ready\n" << std::endl;
    std::cout << "Array for thread after sort" << std::endl;
    for (int i = 0; i < size; i++) {
      std::cout << arr_thread[i] << " ";
    }
    std::cout << std::endl;
  }
}