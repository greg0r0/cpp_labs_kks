CC = g++

info:
	@echo " [?] \`make info\` - this info :D"
	@echo " [?] \`make test\` - compile and run all tests"
	@echo "   [~] \`make compile-test\` - compile tests"
	@echo "   [~] \`make run-test\` - run tests"

	@echo " [?] \`make clear\` - delete all trash"

test: compile-test run-test

compile-test:
	@mkdir -p ./bin
	@$(CC) ./tests/*.cpp -lgtest_main -lgtest -pthread -o ./bin/tests

run-test:
	@./bin/tests &2>/dev/null

clear:
	rm -rf ./bin/