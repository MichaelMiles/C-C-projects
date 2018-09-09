/*
 * Copyright ©2018 Justin Hsia.  All rights reserved.  Permission is
 * hereby granted to students registered for University of Washington
 * CSE 333 for use solely during Spring Quarter 2018 for purposes of
 * the course.  No other use, copying, distribution, or modification
 * is permitted without prior written consent. Copyrights for
 * third-party components of this work must be honored.  Instructors
 * interested in reusing these course materials should contact the
 * author.
 */

// Chenyang Fang
// ex17 modifed

#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <string>
#include <ctime>

#include "SimpleQueue.h"

using std::cout;
using std::endl;
using std::string;
using std::thread;

const int NUM_PIES = 6;
static SimpleQueue queue;
static unsigned int seed = time(NULL);
static pthread_mutex_t write_lock;

// Thread safe print that prints the given str on a line
void thread_safe_print(string str) {
  pthread_mutex_lock(&write_lock);
  // Only one thread can hold the lock at a time, making it safe to
  // use cout. If we didn't lock before using cout, the order of things
  // put into the stream could be mixed up.
  cout << str << endl;
  pthread_mutex_unlock(&write_lock);
}

// Produces NUM_PIES pies of the given type
// You should NOT modify this method at all
void producer(string pie_type) {
  for (int i = 0; i < NUM_PIES; i++) {
    queue.Enqueue(pie_type);
    thread_safe_print(pie_type + " pie ready!");
    int sleep_time = rand_r(&seed) % 500 + 1;
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
  }
}

// Eats 2 * NUM_PIES pies
// You should NOT modify this method at all
void consumer() {
  for (int i = 0; i < NUM_PIES * 2; i++) {
    bool successful = false;
    string pie_type;
    while (!successful) {
      while (queue.IsEmpty()) {
        // Sleep for a bit and then check again
        int sleep_time = rand_r(&seed) % 800 + 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
      }
      successful = queue.Dequeue(&pie_type);
    }
    thread_safe_print(pie_type + " pie eaten!");
  }
}

// Wrapper function for producer
void* thread_producer(void* arg) {
    string* str = reinterpret_cast<string*>(arg);
    // call producer
    producer(*str);
    return NULL;
}

// Wrapper function for consumer
void* thread_consumer(void* arg) {
    // call consumer
    consumer();
    return NULL;
}

// print out error message and exit
void errorMes() {
    // print out error and exit
    cout << "thread create or join faill" << endl;
    exit(EXIT_FAILURE);
}

// wrapper function for starting the concurrent
// version of produce and consume pattern
void startProduceConsume();

int main(int argc, char **argv) {
  pthread_mutex_init(&write_lock, NULL);
  // Your task: Make the two producers and the single consumer
  // all run concurrently (hint: use pthreads)
  startProduceConsume();

  pthread_mutex_destroy(&write_lock);

  return EXIT_SUCCESS;
}

void startProduceConsume() {
  // create Apple and Blackberry arguments
  string apple("Apple");
  string berry("Blackberry");

  // create threads
  pthread_t produceApple;
  pthread_t produceBerry;
  pthread_t consumer;

  if (pthread_create(&produceApple, NULL, &thread_producer,
                    reinterpret_cast<void*>(&apple)) != 0) {
    // error
    errorMes();
  }
  if (pthread_create(&produceBerry, NULL, &thread_producer,
                    reinterpret_cast<void*>(&berry)) != 0) {
    // error
    errorMes();
  }
  if (pthread_create(&consumer, NULL, &thread_consumer, NULL) != 0) {
    errorMes();
  }

  // wait for join of all threads
  if (pthread_join(produceApple, NULL) != 0) {
    errorMes();
  }

  if (pthread_join(produceBerry, NULL) != 0) {
    errorMes();
  }

  if (pthread_join(consumer, NULL) != 0) {
    errorMes();
  }
}
