#include <iostream>
#include <stb_image.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Error: expected single input image" << std::endl;
    return 1;
  }

  int width, height, channels;
  unsigned char *data = stbi_load(argv[1], &width, &height, &channels, 0);
  if (!data) {
    std::cerr << "Error: failed to load image" << std::endl;
    return 1;
  }
  stbi_image_free(data);

  std::cout << "height:" << height << " width:" << width << std::endl;
  return 0;
}
