lisp:
	# If you don't link editline, you'll get "undefine reference to 'readline'"
	# The linking process allows the compiler to directly embed calls to editline
	# in your program. You can make it line by adding -ledit to the compile command
	cc -std=c99 -Wall -ledit main.c -o lisp