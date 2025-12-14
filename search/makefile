cc = clang
c_flags = -Wall -Wextra -g
src = binary_2
target = a

all: $(target)

$(target): $(src)
	$(cc) $(c_flags) $(src).c -o $(target)

run:
	./$(target)

clear:
	rm -f *~ $(target) $(src)
