all: urlSummary.o 
		g++ -o urlSummary urlSummary.o 
urlSummary.o: urlSummary.cpp 
		g++ -c urlSummary.cpp -std=c++14
clean:
		rm -rf *.o urlSummary

