all: clean buildMain buildTest runTest valgrindCheck linterCheck

buildMain:
	mkdir -p project/main
	gcc -o project/main/taylor main.c -lm

buildTest:
	mkdir -p project/test
	gcc -o project/test/tester -Dmain=_main main.c main_test.c -lm

runTest:
	./project/test/tester
	
valgrindCheck:
	mkdir -p project/temp
	echo "4 0.01" > project/temp/input.txt
	valgrind ./project/main/taylor < project/temp/input.txt

linterCheck:
	cpplint *.c

clean:
	rm -rf project
