# Producer-Consumer Problem with Shared Memory

This repository contains an implementation of the **Producer-Consumer problem** using shared memory, semaphores, and mutexes in C. The program simulates a scenario where a producer generates items and adds them to a shared buffer, while a consumer consumes those items from the buffer. The producer and consumer processes synchronize access to the buffer using semaphores and mutexes to ensure safe operations in a multi-process environment.

## Overview

The **Producer-Consumer problem** is a classic synchronization problem where a producer generates items and places them in a shared buffer, while a consumer consumes those items. This implementation uses:

- **Shared memory** to store the buffer and item count.
- **Semaphores** to manage empty and full slots in the buffer.
- **Mutexes** to ensure mutual exclusion while accessing the shared buffer.

### Key Components

- **Producer**: Generates random items and adds them to the buffer.
- **Consumer**: Consumes items from the buffer, printing the item consumed.
- **Shared Memory**: The buffer and item count are stored in shared memory, accessible by both the producer and consumer processes.
- **Semaphores**:
  - `empty`: Tracks the number of empty slots in the buffer.
  - `full`: Tracks the number of filled slots in the buffer.
- **Mutex**: Ensures mutual exclusion for operations on the buffer.

### Buffer Size: `N = 4`
The buffer size is set to 4, meaning it can hold up to 4 items at a time.

## Setup

1. Clone this repository to your local machine.
2. Compile the code:
    ```bash
    gcc producer.c shared.c -o producer -lpthread
    gcc consumer.c shared.c -o consumer -lpthread
    ```
3. Run the producer and consumer processes:
    ```bash
    ./producer
    ./consumer
    ```

## Code Structure

### `producer.c`

The producer generates random items and places them in the buffer. It checks if the buffer is full using semaphores and waits for space if necessary.

### `consumer.c`

The consumer removes items from the buffer. It waits if the buffer is empty and consumes items sequentially.

### `shared.h`

Contains the shared memory setup and definitions for the buffer, item count, semaphores, and mutex.

### `shared.c`

Handles the shared memory setup, cleanup, and initialization of semaphores and mutexes.

## Example Output

### Producer Output:

```
Producer arrived, buffer before: [Fri Nov  8 17:44:21 2024] before [ _ _ _ _ ]
Producer produced: 83
Buffer after: [Fri Nov  8 17:44:21 2024] after [ 83 _ _ _ ]

Producer arrived, buffer before: [Fri Nov  8 17:44:21 2024] before [ 83 _ _ _ ]
Producer produced: 86
Buffer after: [Fri Nov  8 17:44:21 2024] after [ 86 _ _ _ ]

Producer waiting, buffer is full...
Producer arrived, buffer before: [Fri Nov  8 17:44:23 2024] before [ 15 93 35 _ ]
Producer produced: 86
Buffer after: [Fri Nov  8 17:44:23 2024] after [ 15 93 35 86 ]
```

### Consumer Output:

```
Consumer waiting, buffer is empty...
Consumer arrived, buffer before: [Fri Nov  8 17:44:21 2024] before [ 83 _ _ _ ]
Consumer consumed: 83
Buffer after: [Fri Nov  8 17:44:21 2024] after [ _ _ _ _ ]

Consumer arrived, buffer before: [Fri Nov  8 17:44:22 2024] before [ 86 77 15 93 ]
Consumer consumed: 86
Buffer after: [Fri Nov  8 17:44:22 2024] after [ 77 15 93 _ ]

Consumer arrived, buffer before: [Fri Nov  8 17:44:23 2024] before [ 77 15 93 35 ]
Consumer consumed: 77
Buffer after: [Fri Nov  8 17:44:23 2024] after [ 15 93 35 _ ]
```

## How It Works

- The **producer** waits for an empty slot in the buffer using the `empty` semaphore. Once space is available, it produces a random item, adds it to the buffer, and increments the item count. After modifying the buffer, it signals the `full` semaphore to notify the consumer that a new item is available.
  
- The **consumer** waits for a full slot in the buffer using the `full` semaphore. Once an item is available, it consumes it, shifts the remaining items in the buffer to the left, and decrements the item count. After consuming the item, it signals the `empty` semaphore to notify the producer that space has become available.

## Concurrency & Synchronization

- **Semaphores** (`empty` and `full`) ensure that the producer does not add items when the buffer is full and that the consumer does not attempt to consume when the buffer is empty.
- **Mutex** is used to ensure that only one process (producer or consumer) accesses the buffer at a time, preventing race conditions.

## Requirements

- GCC (GNU Compiler Collection)
- POSIX threads (`pthread`) and real-time library (`librt`)
- A UNIX-like operating system (Linux or macOS)

## Clean Up

After execution, the shared memory and synchronization resources are cleaned up by the `cleanup_shared_memory` function to prevent resource leaks.
