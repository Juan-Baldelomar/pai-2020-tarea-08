all: specs main clean

main: 
	gcc -g -Wall -Wpedantic -lm main.c heap.c median.c -o main.app
	./main.app input.txt > output.tmp 
	diff --side-by-side --report-identical-files output.txt output.tmp 
specs:
	gcc -g -Wall -Wpedantic -lm specs.c heap.c median.c -o specs.app
	./specs.app 

clean:
	rm -rf *.app *.tmp
