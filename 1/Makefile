all: clean buildMain buildTest runTest linterCheck valgrindCheck

buildMain:
	mkdir -p project/main
	gcc -o project/main/double main.c -lm

buildTest:
	mkdir -p project/test
	gcc -o project/test/tester -Dmain=_main main.c main_test.c -lm

runTest:
	./project/test/tester
	
valgrindCheck:
	mkdir -p project/temp
	echo "1546.1" > project/temp/input.txt
	valgrind ./project/main/double < project/temp/input.txt

linterCheck:
	cpplint *.c

clean:
	rm -rf project
