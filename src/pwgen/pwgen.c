#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void helpmessage() {
	printf("  \033[1;0m\n");
	printf("  \033[1;33mpwgen - generate (insecure) passwords!\n");
	printf("  \033[1;0musage: pwgen [flags] [password lenght] [amount of passwords]\n");
	printf("  \n");
	printf("  flags:\n");
	printf("  -h: displays this help message\n");
	printf("  \n");
}

int randomnumber(int max) {
	struct timespec ts;
    	timespec_get(&ts, TIME_UTC);
	unsigned int seed = ts.tv_sec ^ ts.tv_nsec;
	srand(seed);

    	return (rand() % max);
}

void* pwgen(int charcount) {
	static char pw[2048];
	char characters[77] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '?'}; 
	int i;

	for (i = 0; i < charcount; i++) {
		pw[i] = characters[randomnumber(77)];
	}

	return pw; 
}

int main(int argc, char *argv[]) {
	int i;
	int pwamount;
	int pwlen;
	
	if (argc > 1 && argv[1][0] == '-') {
		switch (argv[1][1]) {
			case 'h':
				helpmessage();
				return 0;
		}
	}

	if (argc == 1) {
		pwlen = 12;
		pwamount = 5;
	} else if (argc == 2) {
		pwlen = atoi(argv[1]);
		pwamount = 5;
	} else {
		pwlen = atoi(argv[1]);
		pwamount = atoi(argv[2]);
	}

	for (i = 0; i < pwamount; i++) {
		printf("%s\n", pwgen(pwlen));
	}

	return 0;
}
