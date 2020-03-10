all:
	g++ demo.cpp mylib.cpp -o demo

test:
	g++ runtests.cpp mylib.cpp -o test -I. -std=c++11 -w

clean:
	rm -f demo test
