build asteroid.cpp:
	g++ -g asteroid.cpp $$(pkg-config --libs --cflags raylib) -o asteroid

debug:
	lldb asteroid

clean:
	rm -f asteroid
