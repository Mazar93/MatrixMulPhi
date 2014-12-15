INCLUDES =
CXX = icc
CXXFLAGS = $(INCLUDES) -std=c++11 -Wall -openmp
LDFLAGS = -openmp -tbb
OUT = MatrixMulPhi
SRCS = main.cpp MatrixMulCilk.cpp MatrixMulOMP.cpp MatrixMulTBB.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all: release

release-mic: CXXFLAGS += -mmic -DNDEBUG -O3
release-mic: LDFLAGS += -mmic
release-mic: $(OUT)

release: CXXFLAGS += -DNDEBUG -O3
release: $(OUT)
	strip $(OUT)

debug: CXXFLAGS += -g
debug: $(OUT)

run: $(OUT)
	@`pwd`/$(OUT)

.PHONY: clean
clean:
	-rm $(OUT) $(OBJS) $(DEPS)

$(OUT): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

%.d: %.cpp
	$(CXX) $(CXXFLAGS) -MM -MF $@ $^

-include $(DEPS)
