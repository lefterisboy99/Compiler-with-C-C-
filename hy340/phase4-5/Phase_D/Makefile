all: bison flex manage_actions symbol_table target_code u
	@g++ f_l p_s m_g s_t t_c utilities/util -o al -Wall -std=c++11 -g

flex: al.l
	@flex --outfile=scanner.cpp al.l 
	@g++ scanner.cpp -c -o f_l -Wall -std=c++11 -g

bison: grammar.y
	@bison --yacc --defines=parser.h --output=parser.cpp grammar.y -v --report=all -rall -t 
	@g++ parser.cpp -c -o p_s -Wall -std=c++11 -g

manage_actions: manage_g_action.cpp manage_g_action.h
	@g++ manage_g_action.cpp -o m_g -c -Wall -std=c++11 -g

symbol_table: symbol_table.cpp symbol_table.h
	@g++ symbol_table.cpp -o s_t -c -Wall -std=c++11  -g

target_code: target_code.cpp vm_def.h
	@g++ target_code.cpp -o t_c -c -Wall -std=c++11  -g

u: utilities/util.cpp utilities/def.h
	g++ utilities/util.cpp -o utilities/util -c -Wall -std=c++11  -g


	

clean:
	@echo "rm useless files"
	@rm parser.h || true
	@rm parser.cpp || true
	@rm scanner.cpp || true
	@rm parser.output || true
	@rm al || true
	@rm m_g || true
	@rm s_t || true
	@rm f_l || true
	@rm p_s || true
	@rm t_c || true
	@rm utilities/util

git_add: 
	git add al.l header.h grammar.y Makefile symbol_table.cpp TODO_LIST
	git commit -m "init of phase C"
	git push 

run:
	@rm results.txt || true
	./run_all.sh 
