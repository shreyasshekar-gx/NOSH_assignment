# Sensor + Waker Queue Simulation

## Overview
This project simulates a sensor generating random bytes every second and a waker process that consumes data every 10 seconds if at least 50 bytes are available.

## How to Run
- Copy `main.c` into [Programiz Online Compiler](https://www.programiz.com/c-programming/online-compiler/).
- Click **Run** to see the simulation output.

## Assumptions
- Sensor data is simulated using random numbers.
- Queue size is fixed at 256 bytes.
- Waker only processes data if at least 50 bytes are present.
- Simulation runs for 30 seconds by default.

## Sample Output
=== Sensor + Waker Simulation ===

Second  1: Sensor added 5 byte(s). Queue now has 5.
Second  2: Sensor added 1 byte(s). Queue now has 6.
Second  3: Sensor added 3 byte(s). Queue now has 9.
Second  4: Sensor added 4 byte(s). Queue now has 13.
Second  5: Sensor added 2 byte(s). Queue now has 15.
Second  6: Sensor added 4 byte(s). Queue now has 19.
Second  7: Sensor added 4 byte(s). Queue now has 23.
Second  8: Sensor added 3 byte(s). Queue now has 26.
Second  9: Sensor added 4 byte(s). Queue now has 30.
Second 10: Sensor added 4 byte(s). Queue now has 34.
Second 10: Waker checked, but only 34 in queue. Not enough.
Second 11: Sensor added 0 byte(s). Queue now has 34.
Second 12: Sensor added 5 byte(s). Queue now has 39.
Second 13: Sensor added 3 byte(s). Queue now has 42.
Second 14: Sensor added 4 byte(s). Queue now has 46.
Second 15: Sensor added 2 byte(s). Queue now has 48.
Second 16: Sensor added 1 byte(s). Queue now has 49.
Second 17: Sensor added 2 byte(s). Queue now has 51.
Second 18: Sensor added 5 byte(s). Queue now has 56.
Second 19: Sensor added 5 byte(s). Queue now has 61.
Second 20: Sensor added 0 byte(s). Queue now has 61.
Second 20: Waker took 50 bytes from queue.
Data (hex): 4C F2 A7 00 D5 06 5C 93 EE 23 B5 F9 4B 7C CB 42 
9E 01 04 DB 98 7D 25 68 71 9D 71 73 5B 77 B7 0B 
32 DE D7 79 85 54 44 96 E3 63 FD 3E 32 7A DD E2 
7A 47 
Second 21: Sensor added 2 byte(s). Queue now has 13.
Second 22: Sensor added 5 byte(s). Queue now has 18.
Second 23: Sensor added 0 byte(s). Queue now has 18.
Second 24: Sensor added 4 byte(s). Queue now has 22.
Second 25: Sensor added 3 byte(s). Queue now has 25.
Second 26: Sensor added 1 byte(s). Queue now has 26.
Second 27: Sensor added 1 byte(s). Queue now has 27.
Second 28: Sensor added 5 byte(s). Queue now has 32.
Second 29: Sensor added 1 byte(s). Queue now has 33.
Second 30: Sensor added 0 byte(s). Queue now has 33.
Second 30: Waker checked, but only 33 in queue. Not enough.

=== Simulation Complete ===


=== Code Execution Successful ===
