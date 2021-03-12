CC = g++

info:
	@echo " [?] \`make info\` - this info :D\n"
	@echo " [?] \`make test\` - compile and run all tests (need gtest lib)"
	@echo "   [~] \`make compile-test\` - compile tests"
	@echo "   [~] \`make run-test\` - run tests\n"
	@echo " [?] \`make example\` - compile and run example"
	@echo "   [~] \`make compile-example\` - compile example"
	@echo "   [~] \`make run-example\` - run example\n"
	@echo " [?] \`make clear\` - delete all trash"

test: compile-test run-test

compile-test:
	@mkdir -p ./bin
	@$(CC) ./tests/*.cpp -lgtest_main -lgtest -pthread -o ./bin/tests

run-test:
	@./bin/tests 

example: compile-example run-example

compile-example:
	@mkdir -p ./bin/
	@g++ ./sources/example.cpp -o ./bin/example

run-example:
	@./bin/example

clear:
	rm -rf ./bin/