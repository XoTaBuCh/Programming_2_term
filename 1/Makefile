all: clean buildMain buildTest runTest

buildMain:
	mkdir -p project/main
	gcc -o project/main/double main.c -lm

buildTest:
	mkdir -p project/test
	gcc -o project/test/tester -Dmain=_main main.c main_test.c -lm

runTest:
	./project/test/tester

clean:
	rm -rf project