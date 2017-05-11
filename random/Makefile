CC := gcc
MY_CFLAGS := -I. -Wall -g -DNDEBUG

%.o: %.c 
	$(CC) -g $(MY_CFLAGS) -c $< -o $@

%.bin: %.o
	$(CC) $(MY_DEPS) $< -o $@

programs := reverse.bin lonely.bin sreducedstr.bin binarystr.bin alternate.bin and.bin loop.bin palindrome.bin example.bin 2str.bin strcontruct.bin \
	pipe.bin rotate.bin concepts.bin subarray.bin
	#ptrace.bin sigpipe.bin

.PHONY : all
all : $(programs)

.PHONY : clean
clean:
	rm -rf *.o
	rm -rf $(programs)
