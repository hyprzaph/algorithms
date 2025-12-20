cc = clang
c_flags = -Wall -Wextra -g
src = divide
target = a

all: $(target)

$(target): $(src)
	$(cc) $(c_flags) $(src).c -o $(target)

run:
	./$(target)

