# MicrocontrollerCPUBenchmark
A simple benchmark designed to test the raw CPU power of microcontrollers. 
The test was designed to run on Arduinos, but can be run on a huge range of microcontrollers 
due to it's tiny memory footprint (4.25kB of programming space and 354B of RAM. Could be reduced 
further by removing the output strings.)
The test functions by finding prime numbers via brute force. The program starts at 2 then tests 
every integer by attempting to divide that number with every integer from 2 to the square root 
of the number. If none of the divisors result in a remainder of 0, the number is prime.

RESULTS:

Arduino Mega 2560 16MHz 5V - 17789 primes found in 300 seconds
Arduino Uno 16MHz 5V - 17837 primes found in 300 seconds
Arduino Pro Mini 168 16MHz 5V - 17836 primes found in 300 seconds