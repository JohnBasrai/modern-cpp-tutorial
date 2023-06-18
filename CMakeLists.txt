cmake_minimum_required(VERSION 3.18.0)
project (MODERN-CPP-TUTORIAL)

add_definitions("-std=c++17")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

foreach(prog auto-iterator 
	     BeforeLambda 
	     BeginEnd 
	     Capture 
	     CaptureDefault 
	     enums 
	     Final 
	     ForEach 
	     ForEach2 
	     FuturePromiseI 
	     FuturePromiseII 
	     InheritedCtor 
	     MoveSemantics 
	     Nonecopyable 
	     Nullptr 
#	     Override   This one has an intentional error
	     SmartPtr 
	     SmartPtrII 
	     Thread 
	     UniquePtr 
	     UniquePtrCustomDeleter 
	     WithLambda )
  add_executable(${prog} ${prog}.cpp)
  target_link_libraries(${prog} pthread)
endforeach()
