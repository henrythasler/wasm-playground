extern int inc(int number);
extern int myPrintf(const char *msg, ...);

int simplePrint() {
  return myPrintf("%d %d %llu\n", 1, 2, (unsigned long long)0x7fffffffffffffff);
}

int complexPrint() {
  myPrintf("hello, world\n");
  myPrintf("[numbers] %d %d %d %d\n", 1, 2, 3, -10);
  myPrintf("[i64] %X %X %X\n", (unsigned long long)0xdead, (unsigned long long)0xbeef, (unsigned long long)0x1234);
  return myPrintf("[mixed] %d %d %llu %llu %d %d\n", 1, 2, (unsigned long long)0x7fffffffffffffff, (unsigned long long)0xbeef, 3, 4);
}

int _start() {
  return simplePrint();
  // return inc(0);
}