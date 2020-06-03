CC := gcc
.PHONY:all clean
all:	glibc_call_android_so.c
	$(CC) glibc_call_android_so.c -lhybris-common -landroid-properties -o glibc_call_android_demo
.PHONY:	clean
clean:
	rm glibc_call_android_demo
