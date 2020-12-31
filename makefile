matcha:
	g++ -o matcha ./src/lexer.cpp ./src/token.cpp ./src/main.cpp -std=c++11

clean:
	rm ./matcha