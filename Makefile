build main.cpp:
	g++ -g  main.cpp gameplay.cpp gameover.cpp assets.cpp $$(pkg-config --libs --cflags raylib) -o main

debug:
	lldb main

clean:
	rm -f main
