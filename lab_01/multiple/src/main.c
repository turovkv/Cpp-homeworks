#include "algorithm.h"
#include "io.h"
#include "util.h"

int doComputation(int a, int b) {
  int c = max(a, b);
  logDebug('d');
  return c;
}

int main() {
  	int a = doComputation(5, 7);
  	int b = 5;
  	max(a, b);
  	logDebug('!');
	return 0;
}
