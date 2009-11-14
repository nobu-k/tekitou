CXXFLAGS=-O2 -Wall `pkg-config lua5.1 --cflags` -fPIC
LDFLAGS=`pkg-config lua5.1 --libs` -lluabindd

TARGET=object.so
OBJS=object.o

$(TARGET): $(OBJS)
	g++ $(CXXFLAGS) $(LDFLAGS) -shared -o object.so $(OBJS)

.cpp.o:
	g++ $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	rm $(OBJS)