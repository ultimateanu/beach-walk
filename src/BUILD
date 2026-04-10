load("@rules_cc//cc:cc_binary.bzl", "cc_binary")

cc_binary(
    name = "beach-walk",
    srcs = ["main.cpp"],
    deps = [
        "@@stb+//:stb_image",
        "@abseil-cpp//absl/flags:flag",
        "@abseil-cpp//absl/flags:parse",
    ],
)
