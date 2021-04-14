all: clean buildMain buildTest runTest valgrindCheck linterCheck

buildMain:
	mkdir -p project/main
	gcc -o project/main/tree main.c -lm

buildTest:
	mkdir -p project/test
	echo "111000 011000 101010 000111 110011 110001 110010" > test1.txt
	echo "111000 011000 101010 000111 110011" > test2.txt
	gcc -o project/test/tester -Dmain=_main main.c main_test.c -lm

runTest:
	./project/test/tester
	
valgrindCheck:
	mkdir -p project/temp
	echo "111000 011000 101010 000111 110011 110001 110010" > project/temp/input.txt
	valgrind ./project/main/tree < project/temp/input.txt

linterCheck:
	cpplint *.c

clean:
	rm -rf project