all: creategame addtile

# creategame.o: deps/json.hpp headers/database.h src/database.cpp src/create-game.cpp
# 	g++ -std=c++11 -Wall headers/database.h src/database.cpp src/create-game.cpp -o obj/create-game.o
#
# creategame: creategame.o
# 	g++ -std=c++11 -Wall obj/create-game.o -o bin/create-game

creategame: deps/json.hpp headers/database.h src/database.cpp src/create-game.cpp
	g++ -std=c++11 -Wall headers/database.h src/database.cpp src/create-game.cpp -o bin/create-game

addtile: deps/json.hpp headers/database.h src/database.cpp src/add-tile.cpp
	g++ -std=c++11 -Wall headers/database.h src/database.cpp src/add-tile.cpp -o bin/add-tile

clean:
	rm obj/create-game.o
	rm bin/create-game
