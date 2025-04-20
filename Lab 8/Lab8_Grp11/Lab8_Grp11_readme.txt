# Lab 8: IPC (Local) created by Jade Ramos, Rafael Sese, and Gian Valencia

## Description
This program implements a producer-consumer system using shared memory and semaphores. The code includes:
- Shared memory segments for data, status, and byte count
- A semaphore to ensure synchronized access between producer and consumer
- Status flags to coordinate reading and writing between processes

## How to Run
1. Compile the program using: 

g++ -o producer Lab8_Grp11_codeProducer.cpp
g++ -o consumer Lab8_Grp11_codeConsumer.cpp

2. Run the executable:

./producer input.txt 64 & ./consumer copy.txt 64

Note: The commands can also be ran on separate terminals

3. Check the output file if it has the same contents