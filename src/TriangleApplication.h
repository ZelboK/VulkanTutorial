//
// Created by devel on 2023-06-11.
//

#ifndef VULK_TRIANGLEAPPLICATION_H
#define VULK_TRIANGLEAPPLICATION_H

#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>
#include "QueueFamilyIndices.h"
#include "SwapChainSupportDetails.h"

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = false;
#endif

const std::vector<const char*> validationLayers = {
	"VK_LAYER_KHRONOS_validation"
};

const std::vector<const char*> deviceExtensions = {
	VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

class TriangleApplication
{
 public:

	void run();

 private:
    GLFWwindow* window;
	VkInstance instance;
	VkDevice device;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkQueue graphicsQueue;
	VkSurfaceKHR surface;
	VkQueue presentQueue;
	VkSwapchainKHR swapChain;
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;
	VkRenderPass renderPass;
	VkPipelineLayout pipelineLayout;
	VkPipeline graphicsPipeline;
    VkCommandPool commandPool;
    VkCommandBuffer commandBuffer;
	VkSemaphore imageAvailableSemaphore;
	VkSemaphore renderFinishedSemaphore;
	VkFence inFlightFence;
    std::vector<VkImage> swapChainImages;
    std::vector<VkImageView> swapChainImageViews;
    std::vector<VkFramebuffer> swapChainFramebuffers;


    void initWindow();

	void initVulkan();

	void createInstance();

	void mainLoop();

	void cleanup();

	void pickPhysicalDevice();

	bool isDeviceSuitable(VkPhysicalDevice device);

	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

	bool checkDeviceExtensionSupport(VkPhysicalDevice device);


	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);

	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);

	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

	VkShaderModule createShaderModule(const std::vector<char>& code);



	void createLogicalDevice();

	void createSurface();



	void createSwapChain();

	void createImageViews();

	void createGraphicsPipeline();

	void createRenderPass();


    void createFramebuffers();

    void createCommandPool();

    void createCommandBuffer();

    void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
    void drawFrame();

	void createSyncObjects();
};

#endif //VULK_TRIANGLEAPPLICATION_H
