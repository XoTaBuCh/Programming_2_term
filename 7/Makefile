all: clean buildMain buildTest runTest

buildMain:
	mkdir -p project/main
	g++ -o project/main/hotel main.cpp -lm

buildTest:
	mkdir -p project/test
	g++ -ftest-coverage -fprofile-arcs -O0 -o project/test/tester -Dmain=_main main.cpp main_test.cpp -lm
runTest:
	./project/test/tester < test.txt
	gcov -abcfu main.cpp

clean:
	rm -rf project