OBJS =		main.o Glogin.o SDLWidget.o

LIBS =		$(shell sdl2-config --libs) -lSDL2_ttf

INCLUDES = 	$(shell sdl2-config --cflags)

TARGET =	glogin

CXXFLAGS =	-O2 -g -Wall -std=c++11 -fmessage-length=0 $(INCLUDES) 

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f *.o $(TARGET)
