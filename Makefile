CC := g++-11

CFLAGS := -std=c++20 -I./iutest-master/include/

SRCS :=\
	./src/types/expressions.cpp\
	./src/types/expressions/literals.cpp\
	./src/types/expressions/variable.cpp\
	./src/types/tokens.cpp\

TESTS :=\
	./src/tests/evaluator.test.cpp\
	./src/tests/interpreter.test.cpp\
	./src/tests/lexical-analyzer.test.cpp\
	./src/tests/parser.test.cpp\
	./src/tests/tokens.test.cpp\
	./src/type-tests/expressions.test.cpp\
	./src/type-tests/statements.test.cpp\

OBJS :=\
  expressions.o\
	literals.o\
	variable.o\
	tokens.o\

TEST_OBJS :=\
	evaluator.test.o\
	interpreter.test.o\
	lexical-analyzer.test.o\
	parser.test.o\
	tokens.test.o\
	expressions.test.o\
	statements.test.o\

TARGET :=\
	interpreter

FILE :=\
	interpreter.cpp

only-build:
	$(CC) $(CFLAGS) -c $(FILE)

build: $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) $(TESTS)

clean:
	rm -rf $(OBJS) $(TEST_OBJS) a.out

test:
	$(CC) $(CFLAGS) $(OBJS) $(TARGET).test.o
	./a.out

all: clean build test

.PHONY: only-build build clean test all