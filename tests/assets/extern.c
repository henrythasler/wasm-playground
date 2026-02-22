extern int inc(int number);
extern int myPrintf(const char *msg, ...);
int _start() {
  myPrintf("hello, world\n");
  myPrintf("[numbers] %d %d %d %d\n", 1, 2, 3, -10);
  myPrintf("[i64] %llu %llu %llu\n", (unsigned long long)0xdead, (unsigned long long)0xbeef, (unsigned long long)0x1234);
  myPrintf("[mixed] %c %c %c %lld\n", 'X', 'Y', 'Z', (long long)-1024);
  return inc(0);
}