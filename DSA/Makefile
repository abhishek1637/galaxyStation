CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Pattern rule for building any .cpp file
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Clean up the generated files
clean:
	rm -f *