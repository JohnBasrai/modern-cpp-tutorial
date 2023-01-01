
OPT      ?= -O0 -g
CXX      := g++ -std=gnu++11 
CXXFLAGS := $(OPT) $(INC) $(LIBS) -Wall \
	-lCOS4 \
	-lomniDynamic4 \
	-lomniORB4 \
	-lomnithread   \
	-lCOS4 \
	-lomniDynamic4 \
	-lomniORB4 \
	-lomnithread \
	-pthread

beginend: beginend.cpp
	omniidl -I . -bcxx -Wba -Wbd=DynSK.cpp -Wbh=.h -Wbs=SK.cpp -Wbkeep_inc_path demo.idl
	$(CXX) $(CXXFLAGS) -c -O1 *.cpp
	$(CXX) $(CXXFLAGS) -o beginend beginend.o

clean:
	rm -f *.o beginend
