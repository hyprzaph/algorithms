cc = clang
c_flags = -Wall -Wextra -g
src = backtracking
target = a

all: $(target)

$(target): $(src)
	$(cc) $(c_flags) $(src).c -o $(target)

run:
	./$(target)

