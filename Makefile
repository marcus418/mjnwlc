simulator: bin/main.o bin/decodeinstruction.o bin/Instructions.o bin/memory.o bin/ProgramCounter.o bin/RegisterFile.o bin/simulator.o bin/r_type.o bin/j_type.o bin/i_type.o
	g++ -o2 bin/main.o bin/decodeinstruction.o bin/Instructions.o bin/memory.o bin/ProgramCounter.o bin/RegisterFile.o bin/simulator.o bin/r_type.o bin/j_type.o bin/i_type.o -o bin/mips_simulator

testbench: src/mips_testbench
	cp src/mips_testbench bin/mips_testbench

bin/main.o: src/main.cpp
	g++ -c src/main.cpp -o bin/main.o

bin/decodeinstruction.o: src/decodeinstruction.cpp
	g++ -c src/decodeinstruction.cpp -o bin/decodeinstruction.o

bin/Instructions.o: src/Instructions.cpp
	g++ -c src/Instructions.cpp -o bin/Instructions.o

bin/memory.o: src/memory.cpp
	g++ -c src/memory.cpp -o bin/memory.o

bin/ProgramCounter.o: src/ProgramCounter.cpp
	g++ -c src/ProgramCounter.cpp -o bin/ProgramCounter.o

bin/RegisterFile.o: src/RegisterFile.cpp
	g++ -c src/RegisterFile.cpp -o bin/RegisterFile.o

bin/simulator.o: src/simulator.cpp
	g++ -c src/simulator.cpp -o bin/simulator.o

bin/r_type.o: src/instructions/r_type.cpp
	g++ -c src/instructions/r_type.cpp -o bin/r_type.o

bin/j_type.o: src/instructions/j_type.cpp
	g++ -c src/instructions/j_type.cpp -o bin/j_type.o

bin/i_type.o: src/instructions/i_type.cpp
	g++ -c src/instructions/i_type.cpp -o bin/i_type.o

run:
	./bin/mips_simulator

clean:
	rm bin/*.o bin/mips_simulator