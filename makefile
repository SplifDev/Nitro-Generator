files = *.cpp

exec = bin/BOTool

linux64 = g++  -o $(exec) $(files) 

windows32 = i686-w64-mingw32-g++  -o $(exec)_x32.exe $(files) --static

windows64 = x86_64-w64-mingw32-g++ -o $(exec)_x64.exe $(files) --static

all:
	$(linux64)

allPlatforms:
	$(linux64)
	$(windows64)
	$(windows32)

windows32:
	$(windows32)

windows64:
	$(windows64)
clean:
	rm -f $(OBJS) $(OUT)