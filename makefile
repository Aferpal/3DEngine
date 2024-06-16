all: compile link 

TARGET = app

CXX = g++

CXXFLAGS = -Wall -g

OBJS_FOLDER = ./objects

SOURCE_FOLDER = ./Engine

OUTPUT_FOLDER = ./output

OBJS = Shape.o Triange.o Vector3d.o Matrix.o Engine.o main.o

OBJS_WITH_FOLDER = $(OBJS_FOLDER)/Shape.o $(OBJS_FOLDER)/Triange.o $(OBJS_FOLDER)/Vector3d.o $(OBJS_FOLDER)/Matrix.o $(OBJS_FOLDER)/Engine.o $(OBJS_FOLDER)/main.o

LINK_DEPENDENCIES = -L"C:\projects\sfml\SFML-2.6.0\lib" -lsfml-graphics -lsfml-window -lsfml-system

COMPILE_DEPENDENCIES = -I"C:\projects\sfml\SFML-2.6.0\include"



$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS_WITH_FOLDER) -o $(OUTPUT_FOLDER)/$(TARGET) $(LINK_DEPENDENCIES)
link: 
	$(CXX) $(OBJS) -o ./output/app $(LINK_DEPENDENCIES)

Shape.o: $(SOURCE_FOLDER)/Shape.cpp $(SOURCE_FOLDER)/Shape.h
	$(CXX) -c $(SOURCE_FOLDER)/Shape.cpp -o $(OBJS_FOLDER)/Shape.o

Vector3d.o: $(SOURCE_FOLDER)/Vector3d.cpp $(SOURCE_FOLDER)/Vector3d.h
	$(CXX) -c $(SOURCE_FOLDER)/Vector3d.cpp -o $(OBJS_FOLDER)/Vector3d.o

Triange.o: $(SOURCE_FOLDER)/Triange.cpp $(SOURCE_FOLDER)/Triangle.h
	$(CXX) -c $(SOURCE_FOLDER)/Triange.cpp -o $(OBJS_FOLDER)/Triange.o

Matrix.o: $(SOURCE_FOLDER)/Matrix.cpp $(SOURCE_FOLDER)/Matrix.h
	$(CXX) -c $(SOURCE_FOLDER)/Matrix.cpp -o $(OBJS_FOLDER)/Matrix.o

Engine.o: $(SOURCE_FOLDER)/Engine.cpp $(SOURCE_FOLDER)/Engine.h
	$(CXX) -c $(SOURCE_FOLDER)/Engine.cpp -o $(OBJS_FOLDER)/Engine.o

main.o: main.cpp 
	$(CXX) -c main.cpp -o $(OBJS_FOLDER)/main.o $(COMPILE_DEPENDENCIES)
clean:
	del .\objects\*.o
