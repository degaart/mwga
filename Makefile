.PHONY: all clean run
.SUFFIXES:

CXX := x86_64-w64-mingw32-g++
CXXFLAGS := -DWIN32_LEAN_AND_MEAN -municode
LDFLAGS := -municode
WINEPREFIX := wine

all: obj obj/mwga.exe

obj:
	@mkdir -p obj

obj/mwga.exe: obj/main.o
	@$(CXX) -o $@ $< $(LDFLAGS)

obj/main.o: main.cpp
	@$(CXX) -c -o $@ $^ $(CXXFLAGS)

clean:
	@rm -rf obj

run: obj obj/mwga.exe
	@WINEPREFIX=\${PWD}/$(WINEPREFIX) \
		WINEDEBUG=-all \
		wine64 obj/mwga.exe







