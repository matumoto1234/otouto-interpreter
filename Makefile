CC := g++-11

CFLAGS := -std=c++20 -c -I./iutest-master/include/

SRCS :=\
	./src/types/expressions.cpp\
	./src/types/expressions/literals.cpp\
	./src/types/expressions/variable.cpp\
	./src/types/tokens.cpp\

OBJS :=\
  expressions.o\
	literals.o\
	variable.o\
	tokens.o\
	evaluator.test.o\
	interpreter.test.o\
	lexical-analyzer.test.o\
	parser-types.test.o\
	parser.test.o\

TESTS :=\
	./src/tests/evaluator.test.cpp\
	./src/tests/interpreter.test.cpp\
	./src/tests/lexical-analyzer.test.cpp\
	./src/tests/parser-types.test.cpp\
	./src/tests/parser.test.cpp\

TARGET :=\
	interpreter

build: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(TESTS)

clean:
	rm -rf $(OBJS) a.out

test:
	$(CC) $(CFLAGS) $(OBJS) $(TARGET).test.o
	./a.out

all: clean build test

.PHONY: build clean test all