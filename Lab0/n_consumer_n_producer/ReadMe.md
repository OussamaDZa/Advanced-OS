# Producer-Consumer Problem with Multi-Threading

This project implements the **Producer-Consumer** problem using multi-threading in C, where multiple producers generate data and place it into a shared buffer, while multiple consumers retrieve and process that data. The program simulates the behavior of producers and consumers interacting with the buffer, with each producer and consumer running in its own thread.

## Problem Overview

The producer-consumer problem involves two types of processes:
- **Producers**: These generate data (in this case, random integers) and place them in a shared buffer.
- **Consumers**: These retrieve the data from the buffer and process it.

The shared buffer has a limited size, and both producers and consumers must wait if the buffer is full or empty.

## Features
- **Multiple Producers and Consumers**: The program supports multiple producer and consumer threads running concurrently.
- **Buffer Management**: The buffer can hold a maximum of 4 items at a time. Producers must wait if the buffer is full, and consumers must wait if the buffer is empty.
- **Logging**: The program prints the status of the buffer, along with timestamps, showing the actions of the producers and consumers (e.g., when an item is produced, consumed, or when they are waiting).

## Prerequisites

Make sure you have the following installed:
- A **C compiler** (e.g., GCC)
- The **pthread library** for multi-threading support (on most Unix-like systems, it is pre-installed).

## Compilation

To compile the program, use the following command:

```bash
gcc producer.c shared.c -o producer -lpthread
gcc consumer.c shared.c -o consumer -lpthread
```

## Usage

Once compiled, you can run the producer and consumer programs. You can run them in separate terminal windows or as background processes.

### Running the Producer

To start the producer program:

```bash
./producer
```

This program will simulate multiple producers that generate data and place it into the shared buffer.

### Running the Consumer

To start the consumer program:

```bash
./consumer
```

This program will simulate multiple consumers that consume data from the shared buffer.

### Example Output

Below is an example of how the output might look:

```
Producer 1 arrived, buffer before: [ _ _ _ _ ]
Producer 1 produced: 83
Buffer after: [ 83 _ _ _ ]

Consumer 1 arrived, buffer before: [ 83 _ _ _ ]
Consumer 1 consumed: 83
Buffer after: [ _ _ _ _ ]

Producer 2 arrived, buffer before: [ _ _ _ _ ]
Producer 2 produced: 15
Buffer after: [ 15 _ _ _ ]
...
```

## Customization

- **Buffer Size**: You can adjust the buffer size by modifying the buffer-related constants in the source code.
- **Producer/Consumer Count**: The number of producer and consumer threads can be modified by changing the values of `num_producers` and `num_consumers` in the code.

## Contributing

If you'd like to contribute to the project:
1. Fork the repository
2. Create a feature branch
3. Submit a pull request

## Acknowledgements

- The project was inspired by the classical **Producer-Consumer Problem** from operating systems.
- Thank you to the contributors who helped improve the project.

### Explanation:
- The **Problem Overview** explains the core logic of the producer-consumer model.
- **Features** section highlights key aspects like the shared buffer size and the logging functionality.
- The **Prerequisites** section mentions the dependencies required to compile and run the program.
- **Compilation** and **Usage** instructions are provided to help users run the program.
- The **Example Output** shows what the user can expect when running the program.
- The **Customization** section allows the user to understand how to tweak the program for their needs (like changing buffer size and the number of threads).
