//
// Created by devel on 2023-06-11.
//

#ifndef VULK_QUEUEFAMILYINDICES_H
#define VULK_QUEUEFAMILYINDICES_H

#include <cstdint>
#include <vulkan/vulkan_core.h>
#include <optional>
#include <vector>

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};



#endif //VULK_QUEUEFAMILYINDICES_H
