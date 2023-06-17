//
// Created by devel on 2023-06-11.
//

#ifndef VULK_QUEUEFAMILYINDICES_H
#define VULK_QUEUEFAMILYINDICES_H

#include <cstdint>
#include <optional>
#include <vector>

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;
    std::optional<uint32_t> computeFamily;

    bool isComplete() {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }

    bool isCompleteForCompute() {
        return computeFamily.has_value();
    }
};



#endif //VULK_QUEUEFAMILYINDICES_H
