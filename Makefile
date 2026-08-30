build main.cpp:
	g++ -g  main.cpp gameplay.cpp gameover.cpp assets.cpp $$(pkg-config --libs --cflags raylib) -o GetOffMyLawn

package: build
	zip GetOffMyLawn.zip GetOffMyLawn


clean:
	rm -f GetOffMyLawn
