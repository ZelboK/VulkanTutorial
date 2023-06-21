
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "src/BicubicSplineInterpolator.h"
#include <filesystem>
#include <opencv2/opencv.hpp>

int main() {

    cv::Mat image = cv::imread("resources/gabimaru.jpg", cv::IMREAD_COLOR);

	BicubicSplineInterpolator app;
    try {
        app.run(image);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}