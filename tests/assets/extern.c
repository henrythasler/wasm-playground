extern int inc(int number);
extern int myPrintf(const char *msg, ...);
int _start() {
  // myPrintf("hello, world");
  // myPrintf("[test] %c %c %c %d\n", 'X', 'Y', 'Z', -88);                    
  // myPrintf("[test] %c %c %c %llu\n", 'J', 'K', 'L', (unsigned long long)88); 
  // myPrintf("[test] %c %c %c %lld\n", 'X', 'Y', 'Z', (long long)-1024);      
  return inc(0);
}