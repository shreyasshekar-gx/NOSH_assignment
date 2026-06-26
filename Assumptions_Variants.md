Assumptions:

Simulate a two-thread pipeline in standard C:

ThreadBehaviourSensorFires every 1 second. Adds 0–5 random bytes to a shared buffer.WakerFires every 10 seconds. If buffer has ≥ 50 bytes, prints the latest 50 (in hex) and removes them.


Variants

Three implementations are provided, each adding a layer of engineering depth.
------------------------------------------------------------------------------------------------------------
Variant A 

Clean, well-commented solution that satisfies every requirement.
Thread-safe ring buffer (head/tail/count + pthread_mutex)
"Latest 50 bytes" = the 50 most recently pushed bytes (tail-end)
Sensor thread + waker in main thread
Hex dump output

-------------------------------------------------------------------------------------------------------------
Variant B 

Models how real embedded sensor data actually flows — as framed packets.
Each sensor burst is stored as a frame: [4-byte timestamp | 1-byte length | data]
(mirrors how I2C/UART sensor drivers package data in production firmware)
Power-of-2 buffer (BUF_MASK bitmask) — eliminates modulo divisions, common in RTOS and bare-metal code for cycle efficiency
Drop-oldest on overflow — discards stale frames first so the buffer always holds the freshest data (relevant for EV telemetry, IMU streams)
Drop counter for observability
Embedded log viewer hex dump with address offset column and ASCII sidebar

---------------------------------------------------------------------------------------------------------------------
Variant C 

Configurable at compile time — one #define block controls all parameters (buffer size, threshold, rates, cycles)
Statistics module — tracks bytes received, dropped, printed, and buffer high-water mark; reported on exit
Graceful SIGINT shutdown — Ctrl+C cleanly joins threads instead of crashing
Separated concerns — ring buffer API, sensor logic, stats, and waker are in distinct labelled sections (matches how you'd structure a multi-file embedded C project)
Defensive programming — every mutex pair is explicit, every path is guarded


Author

Shreyas — Electronics & Communication Engineering, BNMIT Bengaluru
