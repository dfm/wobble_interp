CXX := g++
PYTHON_BIN_PATH = python

SRCS = $(wildcard wobble_interp/cc/kernels/*.cc) $(wildcard wobble_interp/cc/ops/*.cc)

TF_CFLAGS := $(shell $(PYTHON_BIN_PATH) -c 'import tensorflow as tf; print(" ".join(tf.sysconfig.get_compile_flags()))')
TF_LFLAGS := $(shell $(PYTHON_BIN_PATH) -c 'import tensorflow as tf; print(" ".join(tf.sysconfig.get_link_flags()))')

CFLAGS = ${TF_CFLAGS} -fPIC -O2 -std=c++11
LDFLAGS = -shared ${TF_LFLAGS}

TARGET_LIB = wobble_interp/python/ops/_interp_ops.so

interp_op: $(TARGET_LIB)

$(TARGET_LIB): $(SRCS)
	$(CXX) $(CFLAGS) -o $@ $^ ${LDFLAGS}

pip_pkg: $(TARGET_LIB)
	./build_pip_pkg.sh make artifacts

clean:
	rm -f $(TARGET_LIB)
