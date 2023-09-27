# Compiler to use
CC = gcc

# Compiler flags, e.g. -Wall for warnings, -g for debug info
CFLAGS = -Wall

# Names of your target executables
TARGETS = binary2bmp bmp2binary

# Rule to build all targets (default rule)
all: $(TARGETS)

# Rule to build bmp_to_bin from bmp_to_bin.c
binary2bmp: binary2bmp.c
	$(CC) $(CFLAGS) -o $@ $<

# Rule to build bin_to_bmp from bin_to_bmp.c
bmp2binary: bmp2binary.c
	$(CC) $(CFLAGS) -o $@ $<

# Rule to clean up generated files
clean:
	rm -f $(TARGETS)
