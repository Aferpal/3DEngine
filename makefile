
TARGET = app

SFML_LIB = C:\projects\sfml\SFML-2.6.0\lib

SFML_INCLUDE = C:\projects\sfml\SFML-2.6.0\include

CXX = g++

CXXFLAGS = -Wall -g

OBJS_FOLDER = ./objects

SOURCE_FOLDER = ./Engine

OUTPUT_FOLDER = ./output

EXCEPTION_FOLDER = ./Exceptions

GAME_FOLDER = ./Game

OBJS = Game.o Interface.o Shape.o Triangle.o Vector3d.o Matrix.o Engine.o main.o Camera.o

OBJS_WITH_FOLDER = $(OBJS_FOLDER)/Camera.o $(OBJS_FOLDER)/Game.o $(OBJS_FOLDER)/Interface.o $(OBJS_FOLDER)/Shape.o $(OBJS_FOLDER)/Triangle.o $(OBJS_FOLDER)/Vector3d.o $(OBJS_FOLDER)/Matrix.o $(OBJS_FOLDER)/Engine.o $(OBJS_FOLDER)/main.o 

LINK_DEPENDENCIES = -L$(SFML_LIB) -lsfml-graphics -lsfml-window -lsfml-system

COMPILE_DEPENDENCIES = -I$(SFML_INCLUDE)



$(TARGET): $(OBJS_WITH_FOLDER)
	$(CXX) $(CXXFLAGS) $(OBJS_WITH_FOLDER) -o $(OUTPUT_FOLDER)/$(TARGET) $(LINK_DEPENDENCIES)

$(OBJS_FOLDER)/Shape.o: $(SOURCE_FOLDER)/Shape.cpp $(SOURCE_FOLDER)/Shape.h
	$(CXX) -c $(SOURCE_FOLDER)/Shape.cpp -o $(OBJS_FOLDER)/Shape.o

$(OBJS_FOLDER)/Vector3d.o: $(SOURCE_FOLDER)/Vector3d.cpp $(SOURCE_FOLDER)/Vector3d.h
	$(CXX) -c $(SOURCE_FOLDER)/Vector3d.cpp -o $(OBJS_FOLDER)/Vector3d.o

$(OBJS_FOLDER)/Triangle.o: $(SOURCE_FOLDER)/Triangle.cpp $(SOURCE_FOLDER)/Triangle.h
	$(CXX) -c $(SOURCE_FOLDER)/Triangle.cpp -o $(OBJS_FOLDER)/Triangle.o

$(OBJS_FOLDER)/Matrix.o: $(SOURCE_FOLDER)/Matrix.cpp $(SOURCE_FOLDER)/Matrix.h
	$(CXX) -c $(SOURCE_FOLDER)/Matrix.cpp -o $(OBJS_FOLDER)/Matrix.o

$(OBJS_FOLDER)/Engine.o: $(SOURCE_FOLDER)/Engine.cpp $(SOURCE_FOLDER)/Engine.h
	$(CXX) -c $(SOURCE_FOLDER)/Engine.cpp -o $(OBJS_FOLDER)/Engine.o

$(OBJS_FOLDER)/main.o: main.cpp 
	$(CXX) -c main.cpp -o $(OBJS_FOLDER)/main.o $(COMPILE_DEPENDENCIES)

$(OBJS_FOLDER)/Game.o: $(GAME_FOLDER)/Game.cpp $(GAME_FOLDER)/Game.h $(EXCEPTION_FOLDER)/GameException.h
	$(CXX) -c $(GAME_FOLDER)/Game.cpp -o $(OBJS_FOLDER)/Game.o

$(OBJS_FOLDER)/Interface.o: $(GAME_FOLDER)/Interface.cpp $(GAME_FOLDER)/Interface.h
	$(CXX) -c $(GAME_FOLDER)/Interface.cpp -o $(OBJS_FOLDER)/Interface.o $(COMPILE_DEPENDENCIES)

$(OBJS_FOLDER)/Camera.o: $(SOURCE_FOLDER)/Camera.cpp $(SOURCE_FOLDER)/Camera.h
	$(CXX) -c $(SOURCE_FOLDER)/Camera.cpp -o $(OBJS_FOLDER)/Camera.o

clean:
	del .\objects\*.o
