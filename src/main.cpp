#include <iostream>
#include <string>
#include "car.h"
#include "militarycar.h"
#include "truck.h"

#include <vector>    // for std::vector (dynamic array)
#include <thread>    // provides classes and functions for managing a parallel execution
#include <semaphore> //for controlling concurrent access to a shared resource (c++20)

#include <mutex>  // for std::mutex
#include <memory> // for smart pointers

/*-----------------------------------------------*****fire de executie si semafoare*****-----------------------------------------------*/

// Define the function to be executed by the thread. It shows how a semaphore can be used to control access to a critical section
// Parameters: semaphore - reference (&) to a semaphore object
void threadFunction(std::counting_semaphore<> &semaphore)
{
    // Wait (acquire semaphore)
    semaphore.acquire(); // decrement the count of the semaphore. If count == 0, block the thread until count > 0 (release() increments the count)
    // Limit the number of threads that can enter a critical section at a time.

    // Critical section (access shared resource)
    // Do not access it by more than a certain number of threads at a time
    // The shared resouce is the standard output stream (std::cout)
    std::cout << "Thread " << std::this_thread::get_id() << " is running\n";
    //^identify the current thread (std::this_thread::get_id())
    // Signal (release semaphore)
    semaphore.release(); // increments the semaphore count. If count > 0, unblock a thread waiting on the semaphore
}
/*-----------------------------------------------*****mutex-uri/semafoare RAII*****-----------------------------------------------*/

class LockGuard
{
public:
    LockGuard(std::mutex &mtx) : mutex_(mtx)
    {
        mutex_.lock();
    }

    ~LockGuard()
    {
        mutex_.unlock();
    }

    // Delete copy constructor and assignment operator to prevent copying
    LockGuard(const LockGuard &) = delete;
    LockGuard &operator=(const LockGuard &) = delete;

private:
    std::mutex &mutex_;
};

void threadFunctionMUTEX(std::counting_semaphore<> &semaphore, std::mutex &mtx, int &shared_data)
{
    semaphore.acquire(); // Acquire semaphore to enter the critical section

    // Critical section protected by the mutex using RAII LockGuard
    {
        LockGuard lock(mtx);
        // Safely modify the shared data
        shared_data++;
        std::cout << "Thread " << std::this_thread::get_id() << " incremented shared_data to " << shared_data << "\n";
    }

    semaphore.release(); // Release semaphore after exiting the critical section
}

/*-----------------------------------------------*****pointeri RAII (i.e., smart pointers)*****-----------------------------------------------*/

int main()
{
    std::cout << "/*----------------------------------*****fire de executie si semafoare*****-----------------------------------*/" << std::endl;
    const int numThreads = 5;             // Number of threads to be created
    std::vector<std::thread> threads;     // dynamic array of threads
    std::counting_semaphore semaphore(2); // Semaphore with 2 as the initial count. Maximum of 2 threads can enter the critical section at a time

    // Create and start threads
    for (int i = 0; i < numThreads; ++i)
    {
        threads.emplace_back(threadFunction, std::ref(semaphore)); // emplace_back - creates a new thread and adds it to the vector of threads
    }                                                              // std::ref(semaphore) - reference to the semaphore object, ensures that they will execute threadFunction()
                                                                   // on the same semaphore object

    // Join threads - main thread waits for the completion of the child threads
    for (auto &thread : threads) // for each thread in the vector of threads
    {
        thread.join(); // join the thread with the calling thread (main thread)
    }

    threads.clear(); // clear the vector of threads, otherwise std::system_error
    /*-----------------------------------------------**********-----------------------------------------------*/
    std::cout << "/*----------------------------------*****mutex-uri/semafoare RAII*****-----------------------------------*/" << std::endl;
    std::mutex mtx;      // Mutex to protect shared data
    int shared_data = 0; // Shared data among threads

    // Create threads (2nd set)
    for (int i = 0; i < numThreads; ++i)
    {
        threads.emplace_back(threadFunctionMUTEX, std::ref(semaphore), std::ref(mtx), std::ref(shared_data));
    }

    // Join threads
    for (auto &thread : threads)
    {
        thread.join();
    }

    std::cout << "Final value of shared_data: " << shared_data << std::endl;

    /*-----------------------------------------------**********-----------------------------------------------*/
    std::cout << "/*----------------------------------*****pointeri RAII (i.e., smart pointers)*****-----------------------------------*/" << std::endl;

    // unique_ptr variant 1:
    // Car *car_ptr = new Car("Porsche", "Carrera4GTS", 2024); // dynamically allocated object
    // std::unique_ptr<Car> UniqueCar(car_ptr);                // uniq_ptr is not copyable, but it is movable, expects a dynamically allocated object

    // unique_ptr variant 2:
    std::unique_ptr<Car> UniqueCar = std::make_unique<Car>("Porsche", "Carrera4GTS", 2024); // make_unique() is a function that creates a unique_ptr

    UniqueCar->Drive();
    // UniqueCar is automatically destroyed here

    // shared_ptr
    std::shared_ptr<Car> SharedCar = std::make_shared<Car>("Toyota", "Corolla", 2024);
    SharedCar->Drive();
    std::shared_ptr<Car> anotherSharedCar = SharedCar; // Reference count is incremented
    anotherSharedCar->Drive();
    // mySharedCar and anotherSharedCar are automatically destroyed here, and the Car is deleted
    return 0;
}

/*
-----------------------------------------------****fire de executie si semafoare******-----------------------------------------------
A semaphore is a synchronization mechanism that can control n number of threads where n is the count of the semaphore.
A semaphore with a count of one is often called a binary semaphore because it behaves similarly to a mutex.
A semaphore with a count greater than one is called a counting semaphore.
A semaphore is a generalization of a mutex. A mutex is a binary semaphore.

A mutex is a lock that only one thread can acquire at a time.

If the main thread were to exit before the child threads finish,
it would terminate the entire process, and the child threads would be stopped abruptly.
The problem which threads resolve is the synchronization of multiple tasks.

-----------------------------------------------*****mutex-uri/semafoare RAII*****-----------------------------------------------
Mutex is used to protect shared data from being simultaneously accessed by multiple threads
Mutexes and semaphores are resources that must be acquired and released (RAII).
In C++, this is usually done by creating a class that acquires the resource in its constructor and releases the resource in its destructor.
The LockGuard class is a simple example of a class that acquires a mutex in its constructor and releases the mutex in its destructor.

Only one thread can acquire the mutex at a time. If a thread tries to acquire a mutex that is already acquired by another thread,
the thread will block until the mutex is released by the other thread.

It is non-recursive, meaning that if a thread tries to acquire a mutex that it already owns, the thread will block forever.

Deadlock occurs when two or more threads are blocked forever, waiting for each other.

-----------------------------------------------*****pointeri RAII (i.e., smart pointers)*****-----------------------------------------------
These smart pointers are part of C++'s RAII idiom and manage dynamic memory allocation to ensure that memory is properly released when it's no longer needed.
std::unique_ptr is a smart pointer that owns and manages another object through a pointer and disposes of
that object when the unique_ptr goes out of scope.

std::shared_ptr is a smart pointer that retains shared ownership of an object through a pointer. Multiple shared_ptr objects may own the same object.
The object is destroyed and its memory deallocated when either of the following happens:

The last remaining shared_ptr owning the object is destroyed.
The last remaining shared_ptr owning the object is assigned another pointer via the operator= or reset().

unique and shared increment the reference count when created/copied. Decrement the reference count when destroyed.
When the reference count reaches 0, the object is destroyed.

*a *b *c point to the same object (shared_ptr). If *a *b *c are destroyed, the object is destroyed.
*a points to an object (unique_ptr). If *a is destroyed, the object is destroyed.

The reason for smart pointers is to avoid memory leaks. If you use raw pointers, you have to manually delete the object which might be
forgotten or done incorrectly. Smart pointers automatically delete the object when it goes out of scope.
*/
