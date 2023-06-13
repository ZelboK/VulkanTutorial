
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "src/TriangleApplication.h"

#include <filesystem>

int main() {
	std::filesystem::path working_dir = std::filesystem::current_path();
	std::cout << "Working directory: " << working_dir << "\n";

	TriangleApplication app;

    try {
        app.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}