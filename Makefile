
CXX=g++
CFLAGS= -Iinc/ -Wall -Werror -fsanitize=undefined -std=c++20

run: $(file)
	./bin/$(file) > output.txt && cat output.txt

diff:
	- diff output.txt expected_output.txt -w --strip-trailing-cr -B -y

$(file): $(file).cpp
	$(CXX) $(CFLAGS) $< -o bin/$@

clean:
	rm -rf bin/*