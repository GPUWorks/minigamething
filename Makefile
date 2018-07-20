target=build/game.exe
cc=i686-w64-mingw32-gcc-win32 
cxx=i686-w64-mingw32-g++-win32 
strip=i686-w64-mingw32-strip
cflags=-Os -ffunction-sections -fdata-sections -Ibuild/ -DGLEW_STATIC
cxxflags=-std=c++11 -fno-exceptions -fno-rtti $(cflags)
ldflags=-nostdlib -nodefaultlibs -luser32 -lkernel32 -lopengl32 -lgdi32 -Wl,--gc-sections
upx=./upx.exe

src=$(shell find src/ -maxdepth 1 -name "*.cpp")
header=$(shell find src/ -maxdepth 1 -name "*.h")
obj=$(patsubst src/%.cpp, build/%.o, $(src)) build/resources.o


rcfiles=$(shell find resources/ -maxdepth 1 -name "*.*")
rcdeps=$(rcfiles:=.rcdep)

print-%  : ; @echo $* = $($*)

.PHONY=default clean all

$(target): $(obj)
	$(cxx) $(cxxflags) -o $(target) $(obj) $(ldflags) 
	$(strip) -s -R .comment -R .gnu.version $(target)
	$(upx) --best $(target)
	
build/%.o: src/%.cpp $(header) 
	$(cxx) $(cxxflags) -c $< -o $@
	
clean: 
	rm -f $(obj)
	rm -f $(target)
	rm -f build/*

build/resources.o: $(rcfiles)
	bash xxdscript.bash $^ > build/resources.cpp
	$(cxx) $(cxxflags) -c build/resources.cpp -o $@

run: $(target)
	$(target)