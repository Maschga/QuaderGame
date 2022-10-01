all:
	g++ -Wall -g -c 2D_Game/main.cpp -o build/main.o

	g++ -Wall -g -c 2D_Game/Helper.cpp -o build/Helper.o

	g++ -Wall -g -c 2D_Game/Game/Player.cpp -o build/Player.o
	g++ -Wall -g -c 2D_Game/Game/Game.cpp -o build/Game.o

	g++ -Wall -g -c 2D_Game/Game/Ground/Ground.cpp -o build/Ground.o

	g++ -Wall -g -c 2D_Game/Game/Ground/Structures/Structure.cpp -o build/Structure.o
	g++ -Wall -g -c 2D_Game/Game/Ground/Structures/Spawn.cpp -o build/Spawn.o
	g++ -Wall -g -c 2D_Game/Game/Ground/Structures/Obesity1.cpp -o build/Obesity1.o

	g++ -Wall -g -c 2D_Game/Game/Ground/Structures/Blocks/Block.cpp -o build/Block.o
	g++ -Wall -g -c 2D_Game/Game/Ground/Structures/Blocks/Grass.cpp -o build/Grass.o
	g++ -Wall -g -c 2D_Game/Game/Ground/Structures/Blocks/Platform_X.cpp -o build/Platform_X.o


	g++ -I src/include -L src/lib \
	build/main.o build/Helper.o build/Player.o build/Game.o build/Ground.o build/Structure.o build/Spawn.o build/Obesity1.o build/Block.o build/Grass.o build/Platform_X.o \
	-o MAIN -l SDL2main -l SDL2