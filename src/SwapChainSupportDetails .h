//
// Created by devel on 2023-06-11.
//

#ifndef VULK_SWAPCHAINSUPPORTDETAILS_H
#define VULK_SWAPCHAINSUPPORTDETAILS_H

#include <vector>

struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

#endif //VULK_SWAPCHAINSUPPORTDETAILS_H
