extern int inc(int number);
extern int myPrintf(const char *msg, ...);

__attribute__((export_name("increment")))
int increment(int number) {
  return inc(number);
}

__attribute__((export_name("simplePrint")))
int simplePrint() {
  return myPrintf("%d %d %llu\n", 1, 2, (unsigned long long)0x7fffffffffffffff);
}

__attribute__((export_name("mixedPrint")))
int mixedPrint() {
  myPrintf("[i64] %llx %llx %llx\n", (unsigned long long)0xdead, (unsigned long long)0xbeef, (unsigned long long)0x1234);
  return myPrintf("[mixed] %d %d %llu %llu %i %i\n", 1, 2, (unsigned long long)0x7fffffffffffffff, (unsigned long long)0xbeef, -3, -4);
}

__attribute__((export_name("complexPrint")))
int complexPrint() {
  myPrintf("hello, world\n");
  myPrintf("[numbers] %d %d %d %d\n", 1, 2, 3, -10);
  myPrintf("[char] %c %c %i %i\n", 'A', 'B', -1, -2);
  myPrintf("[string] %s %i %i\n", "ABC", -1, -2);
  myPrintf("[i64] %llx %llx %llx\n", (unsigned long long)0xdead, (unsigned long long)0xbeef, (unsigned long long)0x1234);
  return myPrintf("[mixed] %d %d %llu %llu %i %i\n", 1, 2, (unsigned long long)0x7fffffffffffffff, (unsigned long long)0xbeef, -3, -4);
}

int _start() {
  increment(0);
  simplePrint();
  mixedPrint();
  return complexPrint();
}