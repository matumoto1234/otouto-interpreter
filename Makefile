CC := g++-11

CFLAGS := -std=c++20 -I./iutest-master/include/

SRCS :=\
	./src/types/expressions/expression.cpp\
	./src/types/expressions/literals.cpp\
	./src/types/expressions/variable.cpp\
	./src/types/tokens.cpp\
	./src/types/statements/assignment.cpp\
	./src/types/statements/define-function.cpp\
	./src/types/statements/statement.cpp\
	./src/types/statements/syntax-error.cpp\

TESTS :=\
	./src/tests/evaluator.test.cpp\
	./src/tests/interpreter.test.cpp\
	./src/tests/lexical-analyzer.test.cpp\
	./src/tests/parser.test.cpp\
	./src/tests/tokens.test.cpp\
	./src/tests/type-tests/expression.test.cpp\
	./src/tests/type-tests/statements.test.cpp\

OBJS :=\
  expression.o\
	literals.o\
	variable.o\
	tokens.o\
	assignment.o\
	define-function.o\
	statement.o\
	syntax-error.o\

TEST_OBJS :=\
	evaluator.test.o\
	interpreter.test.o\
	lexical-analyzer.test.o\
	parser.test.o\
	tokens.test.o\
	expression.test.o\
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