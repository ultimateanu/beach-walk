#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/flags/usage.h"
#include <iostream>
#include <stb_image.h>
#include <string>
#include <string_view>

bool process_image(const std::string_view path) {
  int width, height, channels;
  unsigned char *data = stbi_load(path.data(), &width, &height, &channels, 0);
  if (!data) {
    std::cerr << "Error: failed to load image" << std::endl;
    return false;
  }
  stbi_image_free(data);

  std::cout << "\theight:" << height << " width:" << width << std::endl;
  return true;
}

int main(int argc, char *argv[]) {
  absl::SetProgramUsageMessage(
      "A tool to compute perceptual hashes of images.\nUsage: ./beach-walk "
      "[options] <image1> <image2> ...");
  const std::vector<char *> input_paths = absl::ParseCommandLine(argc, argv);
  if (input_paths.size() < 2) {
    std::cerr << "Error: expected image paths" << std::endl;
    return 1;
  }

  // Process input paths.
  if (!input_paths.empty()) {
    for (size_t i = 1; i < input_paths.size(); ++i) {
      const auto &path = input_paths[i];
      std::cout << " - " << path << std::endl;
      process_image(path);
    }
  }

  return 0;
}
