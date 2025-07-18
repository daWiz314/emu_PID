objects = $(addprefix obj)/, main.o, message.o
obj_dir = obj
out_dir = rel
src_dir = src

modules = main.o, message.o
dep = main.cpp, message.cpp

exe := $(out_dir)/output
src := $(wildcard $(src_dir)/*.cpp)
obj := $(src:$(src_dir)/%.cpp=$(obj_dir)/%.o)

cppflags := -MMD -MP -std=c++17
cc := g++

.PHONEY: all clean

all: $(exe)

$(exe): $(obj) | $(out_dir)
	$(cc) $^ -o $@

$(obj_dir)/%.o:  $(src_dir)/%.cpp | $(obj_dir)
	$(cc) $(cppflags) -c $< -o $@

$(out_dir) $(obj_dir):
	mkdir -p $@

clean:
	@$(RM) -rv $(rel_dir) $(obj_dir)


#all: $(modules)
#	g++ $(@^)
#
#$(modules): $(src)%.cpp
#	g++ -c $(src)*.cpp #-o $(obj) $(output)
#
#%.o: $(src)%.cpp
#	g++ -c $(input) -o $(obj) $(output)

#cppfiles = $($(src)wildcard.cpp)
#cppobjs = $(patsubstr $(src)%.cpp, $(obj)%.o, $(cppfiles))
#
#all: $(obj) $(out)
#
#$(out): $(cppobjs)
#	g++ $(cppobjs) -o  $(out)
#
#$(cppobjs):
#	g++ -c $(patsubstr $(obj)%.0,$(src)%.cpp,$(@)) -o $(@)
#
#$(obj):
#	mkdir -p $@
#
#.PHONY: clean
#clean:
#	rm -rf $(cppobjs) $(out)

#output: main.o message.o
#	g++ ./obj/main.o ./obj/message.o -o ./rel/output
#
#main.o: main.cpp
#	g++ -c ./src/main.cpp -o ./obj/main.o
#
#message.o: message.cpp message.h
#	g++ -c ./src/message.cpp -o ./obj/message.o
#
#clean:
#	rm ./obj/*.o ./output
