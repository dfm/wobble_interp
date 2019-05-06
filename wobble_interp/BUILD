licenses(["notice"])

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = 'python/ops/_interp_ops.so',
    srcs = [
        "cc/kernels/interp_kernel.cc",
        "cc/kernels/interp_rev_kernel.cc",
        "cc/ops/interp_ops.cc",
    ],
    linkshared = 1,
    deps = [
        "@local_config_tf//:libtensorflow_framework",
        "@local_config_tf//:tf_header_lib",
    ],
    copts = ["-pthread", "-std=c++11", "-D_GLIBCXX_USE_CXX11_ABI=0"]
)

py_library(
    name = "interp_ops_py",
    srcs = ([
        "python/ops/interp_ops.py",
    ]),
    data = [
        ":python/ops/_interp_ops.so"
    ],
    srcs_version = "PY2AND3",
)

py_library(
    name = "interp_py",
    srcs = ([
        "__init__.py",
        "python/__init__.py",
        "python/ops/__init__.py",
    ]),
    deps = [
        ":interp_ops_py"
    ],
    srcs_version = "PY2AND3",
)
