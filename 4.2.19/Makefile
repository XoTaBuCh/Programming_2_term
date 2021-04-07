all: clean buildMain buildTest runTest valgrindCheck linterCheck

buildMain:
	mkdir -p project/main
	gcc -o project/main/file main.c -lm

buildTest:
	mkdir -p project/test
	gcc -o project/test/tester -Dmain=_main main.c main_test.c -lm

runTest:
	./project/test/tester
	
valgrindCheck:
	mkdir -p project/temp
	echo "gossamer bumblebee sunshine mignonette gossamer lullaby bumblebee gossamer" > input.txt
	valgrind ./project/main/file

linterCheck:
	cpplint *.c

clean:
	rm -rf project