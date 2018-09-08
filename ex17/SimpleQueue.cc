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
// 1663051
// chenyf@uw.edu

#include "SimpleQueue.h"

SimpleQueue::SimpleQueue() {
  size = 0;
  front = nullptr;
  end = nullptr;
  // initialize the lock
  pthread_mutex_init(&lock, NULL);
}

SimpleQueue::~SimpleQueue() {
  while (front != nullptr) {
    node *next = front->next;
    delete front;
    front = next;
  }
  // destroy the lock
  pthread_mutex_destroy(&lock);
}

void SimpleQueue::Enqueue(string item) {
  // lock to prevent data race
  pthread_mutex_lock(&lock);
  node *new_node = new node();
  new_node->next = nullptr;
  new_node->item = item;
  if (end != nullptr) {
    end->next = new_node;
  } else  {
    front = new_node;
  }
  end = new_node;
  size++;
  // release our lock
  pthread_mutex_unlock(&lock);
}

bool SimpleQueue::Dequeue(string *result) {
  // lock to prevent data race
  pthread_mutex_lock(&lock);
  if (size == 0) {
    return false;
  }
  *result = front->item;
  node *next = front->next;
  delete front;
  if (end == front) {
    end = front = next;
  } else {
    front = next;
  }
  size--;
  // release our lock
  pthread_mutex_unlock(&lock);
  return true;
}

int SimpleQueue::Size() const {
  // since we are accessing the size
  // we need to lock first
  pthread_mutex_lock(&lock);
  int retval = size;
  pthread_mutex_unlock(&lock);

  return retval;
}

bool SimpleQueue::IsEmpty() const {
  // since we are accessing the size
  // we need to lock first
  pthread_mutex_lock(&lock);
  bool ret = (size == 0);
  pthread_mutex_unlock(&lock);

  return ret;
}
