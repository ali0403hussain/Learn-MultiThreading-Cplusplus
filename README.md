# MultiThreading
One of the most potent and essential features of almost every computer processor on the market today is multithreading. Software can run multiple threads of code concurrently within the same application. Multithreading is essential to the smooth operation of nearly all production-grade software, including web servers, web browsers, databases, and mobile applications.

Multithreading is frequently perceived as being challenging. It's probably defensible when compared to other software development principles. But there aren't many differences between normal programming and multithreading. Simply said, there could be more danger. However, by learning to avoid the risk, you may create considerably more potent algorithms and programs than you could with a single threaded approach.

In order to understand multithreading, we must understand how computer works.

## How old computer works?

![Screenshot](HowOldComputerWorks.gif)     

The process by which the CPU (Central Processing Unit) fetches data and instructions from memory is fundamental to the operation of any computer. This process typically involves several steps:

1. Fetch: The CPU first fetches the next instruction to be executed from memory. It does this by sending a request to the memory subsystem, specifying the address of the instruction it needs.
2. Decode: Once the instruction is fetched, the CPU decodes it to determine what operation needs to be performed and what operands are involved.
3. Execute: After decoding the instruction, the CPU executes the operation specified by the instruction. This may involve performing arithmetic or logical operations, transferring data between registers or memory locations, or branching to a different part of the program.
4. Memory Access (if needed): Some instructions may require accessing data from memory. In this case, the CPU sends a memory access request to retrieve the necessary data from the specified memory address.
5. Write Back (if needed): After executing the instruction, the CPU may need to write the results back to memory or update internal registers.

Spending significant time transferring data between the CPU (Central Processing Unit) and RAM (Random Access Memory) can lead to several disadvantages, including:

1. Slow Performance: If the CPU has to wait for data to be transferred to or from RAM, it can slow down the overall performance of the system. This is especially noticeable in tasks that require frequent access to large amounts of data, such as video editing or gaming.
2. Increased Latency: Accessing data from RAM typically involves a certain amount of latency, as the CPU has to wait for the data to be retrieved from memory. This latency can add up, particularly in systems with slower RAM or when accessing data stored in distant memory locations.
3. Bottlenecking: The speed at which the CPU can process data may exceed the speed at which data can be transferred to and from RAM. This creates a bottleneck, limiting the overall performance of the system and preventing the CPU from reaching its full potential.
4. Power Consumption: Constantly transferring data between the CPU and RAM consumes energy, contributing to overall power consumption. In battery-powered devices like laptops or mobile devices, this can reduce battery life and lead to shorter usage times between charges.

## Process VS Thread
Processes and threads are fundamental concepts in operating systems and concurrent programming. Here are the main differences between them:

|                             | Process       | Thread |
|-----------------------------| ------------- | ------------- |
| Defination                  | A process is an independent unit of execution in a computer program that consists of its own memory space, resources, and a single thread of execution. Each process has its own address space, containing code, data, and system resources.|A thread is a subset of a process, representing an independent flow of execution within that process. Threads share the same memory space and resources as their parent process.               |
| Resource Allocation         |Each process has its own allocated system resources, including memory, file descriptors, and CPU time. Processes are typically isolated from each other and communicate through inter-process communication mechanisms.               |Threads within the same process share the same memory space and resources. They can communicate directly with each other through shared memory, making inter-thread communication more efficient than inter-process communication.               |
| Creation Overhead           | Creating a new process is relatively expensive in terms of system resources and time. This is because each process requires its own address space and resources, which must be allocated and initialized.|Creating a new thread within an existing process is generally faster and less resource-intensive than creating a new process. Since threads share the same address space and resources, thread creation typically involves less overhead.               |
| Concurrency and Parallelism |Processes provide a higher level of isolation and independence, making them suitable for achieving concurrency and parallelism in a program. Multiple processes can run concurrently on a multi-core CPU, leveraging parallelism to improve performance.               |Threads within the same process share resources and can execute concurrently. Threads are often used to perform tasks in parallel within a single program, utilizing multiple CPU cores efficiently.               |
| Fault Isolation             |Processes are isolated from each other, meaning that a failure in one process typically does not affect other processes. This isolation provides better fault tolerance and system stability.|Since threads share the same memory space and resources, a failure in one thread can potentially affect other threads within the same process. Care must be taken to ensure proper synchronization and error handling to prevent issues like race conditions and deadlock.|

In conclusion, while both processes and threads are computer program execution units, they differ in terms of resource allocation, creation overhead, concurrency paradigm, and fault separation capabilities. While threads offer lower overhead and more efficient communication, they also come with a larger overhead cost. As a result, threads must be carefully synchronized to prevent concurrency problems.
