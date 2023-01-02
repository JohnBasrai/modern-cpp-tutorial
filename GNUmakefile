INC  :=	-I ../include
LIBS := -pthread

default: all

SRCS := $(filter-out Override.cpp,$(wildcard *.cpp))
X1_  := $(subst .cpp,,$(SRCS))
EXES := $(foreach x,$(X1_),bin/$(x))

# $(warning EXES : $(EXES))

all:  bin $(EXES)

bin:
	mkdir -p bin

OPT ?= -O3
STD ?= c++17

CXX      := g++ -std=$(STD)
CXXFLAGS := $(OPT) $(INC) $(LIBS) -Wall 

define BUILD
	@echo building $@ ...
	$(CXX) $(CXXFLAGS) -o $@ $^
endef

bin/UniquePtr : UniquePtr.cpp
	$(call BUILD,$@)

bin/UniquePtrCustomDeleter : UniquePtrCustomDeleter.cpp
	$(call BUILD,$@)

bin/WithLambda : WithLambda.cpp
	$(call BUILD,$@)

bin/SmartPtr : SmartPtr.cpp
	$(call BUILD,$@)

bin/Thread : Thread.cpp
	$(call BUILD,$@)

bin/CaptureDefault : CaptureDefault.cpp
	$(call BUILD,$@)

bin/BeforeLambda : BeforeLambda.cpp
	$(call BUILD,$@)

bin/Override : Override.cpp
	$(call BUILD,$@)

bin/ForEach2 : ForEach2.cpp
	$(call BUILD,$@)

bin/enums : enums.cpp
	$(call BUILD,$@)

bin/ForEach : ForEach.cpp
	$(call BUILD,$@)

bin/Refcountable : Refcountable.cpp Refcountable.hh
	$(call BUILD,$@)

bin/InheritedCtor : InheritedCtor.cpp
	$(call BUILD,$@)

bin/Nullptr : Nullptr.cpp
	$(call BUILD,$@)

bin/Capture : Capture.cpp
	$(call BUILD,$@)

bin/Final : Final.cpp
	$(call BUILD,$@)

bin/SmartPtrII : SmartPtrII.cpp
	$(call BUILD,$@)

bin/Nonecopyable : Nonecopyable.cpp
	$(call BUILD,$@)

bin/FuturePromiseI : FuturePromiseI.cpp
	$(call BUILD,$@)

bin/FuturePromiseII : FuturePromiseII.cpp
	$(call BUILD,$@)

bin/MoveSemantics: MoveSemantics.cpp
	$(call BUILD,$@)

bin/auto-iterator: auto-iterator.cpp
	$(call BUILD,$@)

bin/BeginEnd: BeginEnd.cpp
	$(call BUILD,$@)

distclean clean :
	rm -f $(EXES) *.o
