#include <stdio.h>
#include <stdlib.h>

void helpmessage() {
	printf("\033[1;0m\n");
	printf("  ,___________,\t \033[1;33mqc - quickcalc 0.2\033[1;0m\n");
	printf("  | ._______. |\t usage: qc [flag] [a] [b]\n");
	printf("  | |       | |\t flags:\n");
	printf("  | '-------' |\t -h: displays this help message\n");
	printf("  |  7 8 9\033[1;33m +\033[1;0m  |\t -p: sums [a] and [b]\n");
	printf("  |  4 5 6\033[1;33m -\033[1;0m  |\t -m: subtracs [b] from [a]\n");
	printf("  |  1 2 3\033[1;33m *\033[1;0m  |\t -t: multiplies [a] and [b]\n");
	printf("  |  0 \033[1;33m. = : \033[1;0m |\t -d: divides [a] by [b]\n");
	printf("  '-----------'\t -w: raises [a] to the [b]th power\n");
	printf("               \t\t ~ascii art by me\n\n");
}

void power(double l1, double l2) {
	long i;
        double p;
	p = 1;
	for (i = 1; i <= l2; ++i) {
		p = p * l1;
	}
	printf("  %f ^ %f = %f\n", l1, l2, p);
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		helpmessage();
		return 1;
	}
	if (argv[1][0] == '-') {
		char* end;
		double n1;
		double n2;
		switch (argv[1][1]) {
			case 'h':
				helpmessage();	
				return 0;
			case 'p':
				n1 = strtod(argv[2], &end);
				n2 = strtod(argv[3], &end);
				printf("  %f + %f = %f\n", n1, n2, n1+n2);
				return 0;
			case 'm':
				n1 = strtod(argv[2], &end);
				n2 = strtod(argv[3], &end);
				printf("  %ld - %f = %f\n", n1, n2, n1-n2);
				return 0;
			case 't':
				n1 = strtod(argv[2], &end);
				n2 = strtod(argv[3], &end);
				printf("  %f * %f = %f\n", n1, n2, n1*n2);
				return 0;
			case 'd':
				n1 = strtod(argv[2], &end);
				n2 = strtod(argv[3], &end);
				printf("  %f : %f = %f\n", n1, n2, n1/n2);
				return 0;
			case 'w':
				n1 = strtod(argv[2], &end);
				n2 = strtod(argv[3], &end);
				power(n1, n2);
				return 0;
			default:
				printf("unknown flag\n");
				return 1;
		}
	} else {
		helpmessage();
		return 1;
	}
}
