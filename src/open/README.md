To add another type of file and specify the program to open it with, here's what you have to do:

Add another else-if clause in the openfile function, including the snprintf line and system line (Copying the one just before should be fine). 

Then, replace the extension in quotes just after `extension,` with what you want it to be. (Note: if you want to use the same program with multiple extensions, you can add another `strcmp(extension,`, your extension, `) == 0` clause separated from the others using `||`

Replace the all-caps word which ends in `OPEN` between `"%s %s.%s",` and `fullfile` with either the extension followed by OPEN (all caps) or, if you are using a single program with multiple extensions, the file type also followed by OPEN. 

Here's an example of how your new lines should look:
```
else if (strcmp(extension, "svg") == 0 ) {
snprintf(command, sizeof(command), "%s %s &", SVGOPEN, fullfile);
system(command);	
}
```
Now, go in openconf.h and add a new line. this line should say `#define`, then the word ending in open from earlier, and the program you want to open it with.

Here's an example of how the new line should look:
```
#define SVGOPEN inkscape
```
Recompile open.c and you should be set!
