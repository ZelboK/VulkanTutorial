#version 450

layout (binding = 0, r32f) uniform image2D img;

float getXGradient(ivec2 pos) {
    ivec2 size = imageSize(img);

    // Clamp to valid range
    int row = clamp(pos.y, 0, size.y - 1);
    int col = clamp(pos.x, 0, size.x - 1);

    // Calculate positions of adjacent pixels
    int leftPos = max(col - 1, 0);
    int rightPos = min(col + 1, size.x - 1);

    // Load pixel values
    float leftPixel = imageLoad(img, ivec2(leftPos, row)).r;
    float rightPixel = imageLoad(img, ivec2(rightPos, row)).r;

    // Calculate and return gradient
    return (rightPixel - leftPixel) / 2.0;
}

float getYGradient(ivec2 pos) {
    ivec2 size = imageSize(img);

    // Clamp to valid range
    int row = clamp(pos.y, 0, size.y - 1);
    int col = clamp(pos.x, 0, size.x - 1);

    // Calculate positions of adjacent pixels
    int abovePos = max(row - 1, 0);
    int belowPos = min(row + 1, size.y - 1);

    // Load pixel values
    float abovePixel = imageLoad(img, ivec2(abovePos, col)).r;
    float belowPixel = imageLoad(img, ivec2(belowPos, col)).r;

    // Calculate and return gradient
    return (belowPixel - abovePixel) / 2.0;
}
