create_cpp:
	g++ -o parser al.cpp parser.cpp

create_flex:
	flex Scanner.l

create_bison:
	bison --yacc --defines --output=parser.cpp -v parser.y

remove:
	rm al.cpp al.out
