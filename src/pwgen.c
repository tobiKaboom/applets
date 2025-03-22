#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomnumber(int max) {
	struct timespec ts;
    	timespec_get(&ts, TIME_UTC);
	unsigned int seed = ts.tv_sec ^ ts.tv_nsec;
	srand(seed);

    	return (rand() % max);
}

void* pwgen(int charcount) {
	static char pw[1024];
	pw[1023] = "/0";
	char characters[76] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+'}; 
	int i;

	for (i = 0; i < charcount; i++) {
		pw[i] = characters[randomnumber(76)];
	}

	return pw; 
}

int main(/* int argc, char *argv[] */) {
	printf("%s\n", pwgen(13));
}
