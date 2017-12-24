all:
	g++ -o BinaryKnapsack BinaryKnapsack.cpp
	g++ -o MakeChangeGreedy MakeChangeGreedy.cpp
	g++ -o MakeChangeDP MakeChangeDP.cpp

clean:
	rm -rf BinaryKnapsack MakeChangeGreedy MakeChangeDP
