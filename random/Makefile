CC := gcc
MY_CFLAGS := -I. -Wall -g -DNDEBUG

%.o: %.c 
	$(CC) -g $(MY_CFLAGS) -c $< -o $@

%.bin: %.o
	$(CC) $(MY_DEPS) $< -o $@

programs := reverse.bin lonely.bin sreducedstr.bin binarystr.bin alternate.bin and.bin loop.bin palindrome.bin example.bin 2str.bin strcontruct.bin \
	pipe.bin rotate.bin concepts.bin subarray.bin rotation_count.bin group.bin diffleaf.bin \
	ismatch.bin gdb.bin cache.bin maxdiff.bin random.bin heap.bin permute.bin island.bin urlify.bin \
	addlist.bin struct.bin
	#ptrace.bin sigpipe.bin

.PHONY : all
all : $(programs)

.PHONY : clean
clean:
	rm -rf *.o
	rm -rf $(programs)
