CXXFLAGS=-O2 -Wall `pkg-config lua5.1 --cflags` -fPIC
LDFLAGS=`pkg-config lua5.1 --libs` -lluabindd

TARGET=overload.so
OBJS=overload.o

$(TARGET): $(OBJS)
	g++ $(CXXFLAGS) $(LDFLAGS) -shared -o overload.so $(OBJS)

.cpp.o:
	g++ $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	rm $(OBJS)