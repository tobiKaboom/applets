#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "openconf.h"

void* getextension(char fullfilename[]) {
	static char extension[128];
	char dotenc = 0;
	short i;
	short e = 0; 

	for (i = 0; fullfilename[i] != '\0'; ++i) {
		if (dotenc == 0) {
			if (fullfilename[i] == '.') {
				dotenc++;
			}
		} else if (e < sizeof(extension) - 1) {
			extension[e] = fullfilename[i];
			++e;
		}
	}
	extension[e] = '\0';
	return extension;
}

void openfilewith(char fullfile[], char extension[]) {
	char command[256];
	if (strcmp(extension, "txt") == 0) {
		snprintf(command, sizeof(command), "%s %s &", TXTOPEN, fullfile);
		system(command);
	} else if (strcmp(extension, "c") == 0 || strcmp(extension, "cpp") == 0 || strcmp(extension, "py") == 0 || strcmp(extension, "sh") == 0 || strcmp(extension, "rs") == 0) {
		snprintf(command, sizeof(command), "%s %s", CODEOPEN, fullfile);
		system(command);
	} else if (strcmp(extension, "jpg") == 0 || strcmp(extension, "png") == 0 || strcmp(extension, "heic") == 0) {
		snprintf(command, sizeof(command), "%s %s &", IMGOPEN, fullfile);
		system(command);	
	}
}

int main(int argc, char *argv[]) {
	int filepos;
	filepos = 1;

	if (argv[1][0] == '-') {
		switch (argv[1][1]) {
			case 'h':
				printf("open - opens files\n");
				break;
			default:
				printf("unrecognized flag\n");
				break;
		}
		++filepos;
	}
	
	char* extension = getextension(argv[filepos]);
	openfilewith(argv[filepos], extension);
}
