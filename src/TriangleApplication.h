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

class TriangleApplication {
public:

    void run();

private:
    VkInstance instance;
    GLFWwindow *window;
    VkDevice device;


    void initWindow();

    void initVulkan();

    void createInstance();

    void mainLoop();

    void cleanup();

    void pickPhysicalDevice();

    bool isDeviceSuitable(VkPhysicalDevice device);

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
    void createLogicalDevice();
};


#endif //VULK_TRIANGLEAPPLICATION_H
