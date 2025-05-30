#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "openconf.h"

void helpmessage() {
	printf("  \n");
	printf("        __________ \t\033[1;33mopen 1.0 - opens your files with what you want!\033[1;0m\n");
	printf("      /          /|\tusage: open [optional flags] [filename.extension]\n");
	printf("    /__________/  |\t\n");
	printf("    |_________ |  |\tvalid flags:\n");
	printf("   /--._____ /||  |\t-h: show this help message\n");
	printf("  |\"._____.\"| ||  |\t\n");
	printf("  '_________'/_|  |\t\t~ascii art by Cristopher Johnson\n");
	printf("    ||\".____.\"||  /\t\n");
	printf("    |'--------'| / \t\n");
	printf("    '----------'/  \t\n  \n");

}

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
	} else {
		snprintf(command, sizeof(command), "%s %s", CODEOPEN, fullfile);
		system(command);
	}
}

int main(int argc, char *argv[]) {
	int filepos = 1;
	char filenameincluded = 1;

	if (argc < 2) {
		filenameincluded = 0;
		helpmessage();
		return 1;
	}

	if (argv[1][0] == '-') {
		switch (argv[1][1]) {
			case 'h':
				helpmessage();	
				return 0;
			default:
				printf("unrecognized flag\n");
				printf("run open -h for help\n");
				return 1;
		}
		if (argc < 3)
			filenameincluded = 0;
		++filepos;
	}

	if (filenameincluded) { 
		char* extension = getextension(argv[filepos]);
		openfilewith(argv[filepos], extension); 
	}

	return 0;
}
