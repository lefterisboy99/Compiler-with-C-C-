create:
	flex Scanner.l
	bison --yacc --defines --output=parser.cpp -v parser.y
	g++ -std=c++11 -o parser al.cpp parser.cpp
	./parser test.txt
	g++ -std=c++11 -o avm avm.cpp
	./avm binary.abc

remove:
	rm al.cpp parser.cpp parser.hpp parser.output parser binary.abc avm parser
