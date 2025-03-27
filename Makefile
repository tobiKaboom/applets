SOURCE1 = src/pwgen/pwgen.c
SOURCE2 = src/qc/qc.c
SOURCE3 = src/open/open.c

TARGET1 = bin/pwgen.bin
TARGET2 = bin/qc.bin
TARGET3 = bin/open.bin

all: create_bin_dir
	cc -o $(TARGET1) $(SOURCE1)
	cc -o $(TARGET2) $(SOURCE2)
	cc -o $(TARGET3) $(SOURCE3)

clean:
	rm -f $(TARGET1)
	rm -f $(TARGET2)
	rm -f $(TARGET3)

create_bin_dir:
	mkdir -p bin

.PHONY: clean all create_bin_dir
