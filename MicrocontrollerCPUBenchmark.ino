long start = 0;
long max_seconds = 300000; //in ms
long i = 2; // Start at 2

void setup() {
  Serial.begin(9600); 

  while (!Serial) { }

  start = millis();
  String boardName = "Arduino Pro Mini";
  Serial.print("This is the ");Serial.println(boardName);
  Serial.print("Stress testing device. Calculating prime numbers for ");Serial.print(max_seconds/1000);Serial.println(" seconds.");
  
}

long found = 0; // Number we found

void loop() {
  int prime = is_prime(i); // Check if the number we're on is prime

  if (prime == 1) { 
//    Serial.print(i);
//    Serial.println(" is prime ");
    found++;
  }

  long running_seconds = millis() - start;
  //This block prints out the current status of the test at irregular intervals (due to the irregular times of finding a prime)
  if (running_seconds%(max_seconds/20) < 4 && prime == 1) {
    Serial.print("Found ");
    Serial.print(found);
    Serial.print(" primes in ");
    Serial.print(running_seconds);
    Serial.println(" ms");
    Serial.print("Last prime found: ");
    Serial.println(i);
  }
  if (max_seconds > 0 && (running_seconds >= max_seconds)) {
    Serial.print("Found ");
    Serial.print(found);
    Serial.print(" primes in ");
    Serial.print(max_seconds/1000);
    Serial.println(" seconds");
    while(1) { } 
  }
  i++;
}

int is_prime(long num) {
  // Only have to check for divisible for the sqrt(number)
  int upper = sqrt(num);

  // Check if the number is evenly divisible (start at 2 going up)
  for (long cnum = 2; cnum <= upper; cnum++) {
    long mod = num % cnum; // Remainder

    if (mod == 0) { 
      return 0; 
    } // If the remainer is 0 it's evenly divisible
  }

  return 1; // If you get this far it's prime
}
