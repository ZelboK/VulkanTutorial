//
// Created by devel on 2023-06-11.
//

#ifndef VULK_TRIANGLEAPPLICATION_H
#define VULK_TRIANGLEAPPLICATION_H

#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>
#include "QueueFamilyIndices.h"


const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

const std::vector<const char*> validationLayers = {
	"VK_LAYER_KHRONOS_validation"
};

class TriangleApplication {
public:

    void run();

private:
    VkInstance instance;
    GLFWwindow *window;
    VkDevice device;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkQueue graphicsQueue;
	VkSurfaceKHR surface;
	VkQueue presentQueue;

	void initWindow();

    void initVulkan();

    void createInstance();

    void mainLoop();

    void cleanup();

    void pickPhysicalDevice();

    bool isDeviceSuitable(VkPhysicalDevice device);

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
    void createLogicalDevice();

	void createSurface();
};


#endif //VULK_TRIANGLEAPPLICATION_H
