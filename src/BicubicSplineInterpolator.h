//
// Created by devel on 2023-06-17.
//

#ifndef VULK_BICUBICSPLINEINTERPOLATOR_H
#define VULK_BICUBICSPLINEINTERPOLATOR_H

#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>
#include "QueueFamilyIndices.h"
#include "SwapChainSupportDetails.h"

const uint32_t WIDTH = 1280;
const uint32_t HEIGHT = 720;

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

class BicubicSplineInterpolator
{
 public:
	void run();

 private:
	VkPipelineLayout pipelineLayout;
	VkPipeline computePipeline;
	VkCommandPool commandPool;
	VkCommandBuffer commandBuffer;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkSurfaceKHR surface;
	VkInstance instance;
	VkDescriptorSetLayout descriptorSetLayout;
	VkDescriptorSet descriptorSet;
	uint32_t currentFrame = 0;
	std::vector<VkSemaphore> renderFinishedSemaphores;
	std::vector<VkSemaphore> computeFinishedSemaphores;
	std::vector<VkFence> inFlightFences;
	std::vector<VkFence> computeInFlightFences;
	std::vector<VkCommandBuffer> computeCommandBuffers;
	std::vector<VkDescriptorSet> computeDescriptorSets;

	GLFWwindow* window;
	VkDevice device;
	VkQueue computeQueue;

	void initWindow();

	void initVulkan();

	void createInstance();

	void mainLoop();

	void cleanup();

	void pickPhysicalDevice();

	bool isDeviceSuitable(VkPhysicalDevice vkPhysDevice);

	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice vkPhysDevice);

	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice vkPhysDevice);

	VkShaderModule createShaderModule(const std::vector<char>& code);

	bool checkDeviceExtensionSupport(VkPhysicalDevice vkPhysDevice);

	void createLogicalDevice();

	void createSurface();

	void createComputePipeline();

	void createCommandPool();

	void createCommandBuffer();

	void createSyncObjects();

	void recordCommandBuffer();

	void recordComputeCommandBuffer(VkCommandBuffer commandBuffer);

	void setup_descriptor_set_layout();

	void setup_descriptor_set();

	void updateUniformBuffer(uint32_t currentImage);

	void conduct();
};
#endif //VULK_BICUBICSPLINEINTERPOLATOR_H
