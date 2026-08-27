build main.cpp:
	g++ -g main.cpp $$(pkg-config --libs --cflags raylib) -o main

dubug:
	lldb main

clean:
	rm -f main
