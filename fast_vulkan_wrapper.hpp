#pragma once

#ifdef _WIN32
#  define VK_USE_PLATFORM_WIN32_KHR
#  define WIN32_LEAN_AND_MEAN
#endif

#pragma warning(push)
#pragma warning(disable:4820) // S: N bytes padding added after data member M
#define VK_NO_PROTOTYPES 1
#define VK_LAYER_KHRONOS_VALIDATION_NAME "VK_LAYER_KHRONOS_validation"
#include <vulkan/vulkan.h>
#pragma warning(pop)

#ifdef _WIN32
#  undef CreateSemaphore
#  undef CreateEvent
#endif

namespace fvkw
{

    void Initialize();
    void Terminate();

    VkResult EnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties);
    VkResult EnumerateInstanceExtensionProperties(const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties);

    struct PhysicalDevice
    {
        VkPhysicalDevice                   physicalDevice;
        VkPhysicalDeviceMemoryProperties   memory_properties;
        VkPhysicalDeviceProperties2        properties2;
        VkPhysicalDeviceVulkan11Properties vulkan11_properties;
        VkPhysicalDeviceVulkan12Properties vulkan12_properties;
        VkPhysicalDeviceVulkan13Properties vulkan13_properties;
        VkPhysicalDeviceFeatures2          features2;
        VkPhysicalDeviceVulkan11Features   vulkan11_features;
        VkPhysicalDeviceVulkan12Features   vulkan12_features;
        VkPhysicalDeviceVulkan13Features   vulkan13_features;
        inline operator VkPhysicalDevice() { return physicalDevice; }
    };

    class Instance
    {
    public:
        inline operator VkInstance() { return instance; }
        inline VkResult Create(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks *pAllocator);
        inline void Destroy(const VkAllocationCallbacks *pAllocator);
        // VK_VERSION_1_0
        inline VkResult EnumeratePhysicalDevices(uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices);
        inline void GetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures);
        inline void GetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties);
        inline VkResult GetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties);
        inline void GetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties);
        inline void GetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties);
        inline void GetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties);
        inline VkResult EnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties);
        inline VkResult EnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkLayerProperties* pProperties);
        inline void GetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties);
        // VK_VERSION_1_1
        inline VkResult EnumerateInstanceVersion(uint32_t* pApiVersion);
        inline VkResult EnumeratePhysicalDeviceGroups(uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties);
        inline void GetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures);
        inline void GetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties);
        inline void GetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties);
        inline VkResult GetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties);
        inline void GetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties);
        inline void GetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties);
        inline void GetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties);
        inline void GetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties);
        inline void GetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties);
        inline void GetPhysicalDeviceExternalSemaphoreProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties);
        // VK_VERSION_1_3
        inline VkResult GetPhysicalDeviceToolProperties(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties);
        // VK_KHR_surface
        inline void DestroySurface(VkSurfaceKHR surface, VkAllocationCallbacks* pAllocator);
        inline VkResult GetPhysicalDeviceSurfaceSupport(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported);
        inline VkResult GetPhysicalDeviceSurfaceCapabilities(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities);
        inline VkResult GetPhysicalDeviceSurfaceFormats(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats);
        inline VkResult GetPhysicalDeviceSurfacePresentModes(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);
        // VK_KHR_get_surface_capabilities2
        inline VkResult GetPhysicalDeviceSurfaceCapabilities2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities);
        inline VkResult GetPhysicalDeviceSurfaceFormats2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats);
        // VK_EXT_debug_utils
        inline VkResult CreateDebugUtilsMessenger(const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger);
        inline void DestroyDebugUtilsMessenger(VkDebugUtilsMessengerEXT messenger, VkAllocationCallbacks* pAllocator);
        inline void SubmitDebugUtilsMessage(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, VkDebugUtilsMessengerCallbackDataEXT* pCallbackData);
    #ifdef _WIN32
        inline VkResult CreateWin32Surface(const VkWin32SurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
        inline VkBool32 GetPhysicalDeviceWin32PresentationSupport(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex);
    #endif
    public:
        // Custom
        inline void CreatePhysicalDevice(VkPhysicalDevice physicalDevice, PhysicalDevice *pPhysicalDevice);
        // Specializations
    #ifdef _WIN32
        inline VkResult CreateWin32Surface(HINSTANCE hinstance, HWND hwnd, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
    #endif
    private:
        friend class Device;
        VkInstance                                          instance;
        // VK_VERSION_1_0
        PFN_vkDestroyInstance                               vkDestroyInstance;
        PFN_vkEnumeratePhysicalDevices                      vkEnumeratePhysicalDevices;
        PFN_vkGetPhysicalDeviceFeatures                     vkGetPhysicalDeviceFeatures;
        PFN_vkGetPhysicalDeviceFormatProperties             vkGetPhysicalDeviceFormatProperties;
        PFN_vkGetPhysicalDeviceImageFormatProperties        vkGetPhysicalDeviceImageFormatProperties;
        PFN_vkGetPhysicalDeviceProperties                   vkGetPhysicalDeviceProperties;
        PFN_vkGetPhysicalDeviceQueueFamilyProperties        vkGetPhysicalDeviceQueueFamilyProperties;
        PFN_vkGetPhysicalDeviceMemoryProperties             vkGetPhysicalDeviceMemoryProperties;
        PFN_vkGetDeviceProcAddr                             vkGetDeviceProcAddr;
        PFN_vkCreateDevice                                  vkCreateDevice;
        PFN_vkEnumerateDeviceExtensionProperties            vkEnumerateDeviceExtensionProperties;
        PFN_vkEnumerateDeviceLayerProperties                vkEnumerateDeviceLayerProperties;
        PFN_vkGetPhysicalDeviceSparseImageFormatProperties  vkGetPhysicalDeviceSparseImageFormatProperties;
        // VK_VERSION_1_1
        PFN_vkEnumerateInstanceVersion                      vkEnumerateInstanceVersion;
        PFN_vkEnumeratePhysicalDeviceGroups                 vkEnumeratePhysicalDeviceGroups;
        PFN_vkGetPhysicalDeviceFeatures2                    vkGetPhysicalDeviceFeatures2;
        PFN_vkGetPhysicalDeviceProperties2                  vkGetPhysicalDeviceProperties2;
        PFN_vkGetPhysicalDeviceFormatProperties2            vkGetPhysicalDeviceFormatProperties2;
        PFN_vkGetPhysicalDeviceImageFormatProperties2       vkGetPhysicalDeviceImageFormatProperties2;
        PFN_vkGetPhysicalDeviceQueueFamilyProperties2       vkGetPhysicalDeviceQueueFamilyProperties2;
        PFN_vkGetPhysicalDeviceMemoryProperties2            vkGetPhysicalDeviceMemoryProperties2;
        PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 vkGetPhysicalDeviceSparseImageFormatProperties2;
        PFN_vkGetPhysicalDeviceExternalBufferProperties     vkGetPhysicalDeviceExternalBufferProperties;
        PFN_vkGetPhysicalDeviceExternalFenceProperties      vkGetPhysicalDeviceExternalFenceProperties;
        PFN_vkGetPhysicalDeviceExternalSemaphoreProperties  vkGetPhysicalDeviceExternalSemaphoreProperties;
        // VK_VERSION_1_3
        PFN_vkGetPhysicalDeviceToolProperties               vkGetPhysicalDeviceToolProperties;
        // VK_KHR_surface
        PFN_vkDestroySurfaceKHR                             vkDestroySurfaceKHR;
        PFN_vkGetPhysicalDeviceSurfaceSupportKHR            vkGetPhysicalDeviceSurfaceSupportKHR;
        PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR       vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
        PFN_vkGetPhysicalDeviceSurfaceFormatsKHR            vkGetPhysicalDeviceSurfaceFormatsKHR;
        PFN_vkGetPhysicalDeviceSurfacePresentModesKHR       vkGetPhysicalDeviceSurfacePresentModesKHR;
        // VK_KHR_get_surface_capabilities2
        PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR      vkGetPhysicalDeviceSurfaceCapabilities2KHR;
        PFN_vkGetPhysicalDeviceSurfaceFormats2KHR           vkGetPhysicalDeviceSurfaceFormats2KHR;
        // VK_EXT_debug_utils
        PFN_vkCreateDebugUtilsMessengerEXT                  vkCreateDebugUtilsMessengerEXT;
        PFN_vkDestroyDebugUtilsMessengerEXT                 vkDestroyDebugUtilsMessengerEXT;
        PFN_vkSubmitDebugUtilsMessageEXT                    vkSubmitDebugUtilsMessageEXT;
    #if defined(VK_USE_PLATFORM_WIN32_KHR)
        PFN_vkCreateWin32SurfaceKHR                         vkCreateWin32SurfaceKHR;
        PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR  vkGetPhysicalDeviceWin32PresentationSupportKHR;
    #endif
    };

    struct Image
    {
        VkImage    image;
        VkFormat   format;
        VkExtent3D extent;
        uint32_t   levels;
        uint32_t   layers;
        operator VkImage() { return image; }
    };

    class Device
    {
    public:
        operator VkDevice() { return device; }
        inline VkResult Create(const Instance *pInstance, VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator);
        inline void Destroy(const VkAllocationCallbacks *pAllocator);
        // VK_VERSION_1_0
        inline void GetQueue(uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue);
        inline VkResult QueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);
        inline VkResult QueueWaitIdle(VkQueue queue);
        inline VkResult WaitIdle();
        inline VkResult AllocateMemory(const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory);
        inline void FreeMemory(VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);
        inline VkResult MapMemory(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData);
        inline void UnmapMemory(VkDeviceMemory memory);
        inline VkResult FlushMappedMemoryRanges(uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
        inline VkResult InvalidateMappedMemoryRanges(uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
        inline void GetDeviceMemoryCommitment(VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes);
        inline VkResult BindBufferMemory(VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);
        inline VkResult BindImageMemory(VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);
        inline void GetBufferMemoryRequirements(VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements);
        inline void GetImageMemoryRequirements(VkImage image, VkMemoryRequirements* pMemoryRequirements);
        inline void GetImageSparseMemoryRequirements(VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements);
        inline VkResult QueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence);
        inline VkResult CreateFence(const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);
        inline void DestroyFence(VkFence fence, const VkAllocationCallbacks* pAllocator);
        inline VkResult ResetFences(uint32_t fenceCount, const VkFence* pFences);
        inline VkResult GetFenceStatus(VkFence fence);
        inline VkResult WaitForFences(uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout);
        inline VkResult CreateSemaphore(const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore);
        inline void DestroySemaphore(VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator);
        inline VkResult CreateEvent(const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent);
        inline void DestroyEvent(VkEvent event, const VkAllocationCallbacks* pAllocator);
        inline VkResult GetEventStatus(VkEvent event);
        inline VkResult SetEvent(VkEvent event);
        inline VkResult ResetEvent(VkEvent event);
        inline VkResult CreateQueryPool(const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool);
        inline void DestroyQueryPool(VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator);
        inline VkResult GetQueryPoolResults(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags);
        inline VkResult CreateBuffer(const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer);
        inline void DestroyBuffer(VkBuffer buffer, const VkAllocationCallbacks* pAllocator);
        inline VkResult CreateBufferView(const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView);
        inline void DestroyBufferView(VkBufferView bufferView, const VkAllocationCallbacks* pAllocator);
        inline VkResult CreateImage(const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage);
        inline void DestroyImage(VkImage image, const VkAllocationCallbacks* pAllocator);
        inline void GetImageSubresourceLayout(VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout);
        inline VkResult CreateImageView(const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView);
        inline void DestroyImageView(VkImageView imageView, const VkAllocationCallbacks* pAllocator);
        inline VkResult CreateShaderModule(const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule);
        inline void DestroyShaderModule(VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator);
        inline VkResult CreatePipelineCache(const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache);
        inline void DestroyPipelineCache(VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator);
        inline VkResult GetPipelineCacheData(VkPipelineCache pipelineCache, size_t* pDataSize, void* pData);
        inline VkResult MergePipelineCaches(VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches);
        inline VkResult CreateGraphicsPipelines(VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
        inline VkResult CreateComputePipelines(VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
        inline void DestroyPipeline(VkPipeline pipeline, const VkAllocationCallbacks* pAllocator);
        inline VkResult CreatePipelineLayout(const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout);
        inline void DestroyPipelineLayout(VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator);
        inline VkResult CreateSampler(const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler);
        inline void DestroySampler(VkSampler sampler, const VkAllocationCallbacks* pAllocator);
        inline VkResult CreateDescriptorSetLayout(const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout);
        inline void DestroyDescriptorSetLayout(VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator);
        inline VkResult CreateDescriptorPool(const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool);
        inline void DestroyDescriptorPool(VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator);
        inline VkResult ResetDescriptorPool(VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags);
        inline VkResult AllocateDescriptorSets(const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets);
        inline VkResult FreeDescriptorSets(VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets);
        inline void UpdateDescriptorSets(uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies);
        inline VkResult CreateFramebuffer(const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer);
        inline void DestroyFramebuffer(VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator);
        inline VkResult CreateRenderPass(const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
        inline void DestroyRenderPass(VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator);
        inline void GetRenderAreaGranularity(VkRenderPass renderPass, VkExtent2D* pGranularity);
        inline VkResult CreateCommandPool(const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool);
        inline void DestroyCommandPool(VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator);
        inline VkResult ResetCommandPool(VkCommandPool commandPool, VkCommandPoolResetFlags flags);
        inline VkResult AllocateCommandBuffers(const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers);
        inline void FreeCommandBuffers(VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);
        inline VkResult BeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo);
        inline VkResult EndCommandBuffer(VkCommandBuffer commandBuffer);
        inline VkResult ResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags);
        inline void CmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline);
        inline void CmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports);
        inline void CmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors);
        inline void CmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth);
        inline void CmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor);
        inline void CmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]);
        inline void CmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds);
        inline void CmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask);
        inline void CmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask);
        inline void CmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference);
        inline void CmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets);
        inline void CmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType);
        inline void CmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets);
        inline void CmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
        inline void CmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance);
        inline void CmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
        inline void CmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
        inline void CmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
        inline void CmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);
        inline void CmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions);
        inline void CmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions);
        inline void CmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter);
        inline void CmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions);
        inline void CmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions);
        inline void CmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData);
        inline void CmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data);
        inline void CmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);
        inline void CmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);
        inline void CmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects);
        inline void CmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions);
        inline void CmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
        inline void CmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
        inline void CmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
        inline void CmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
        inline void CmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags);
        inline void CmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query);
        inline void CmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
        inline void CmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query);
        inline void CmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags);
        inline void CmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues);
        inline void CmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents);
        inline void CmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents);
        inline void CmdEndRenderPass(VkCommandBuffer commandBuffer);
        inline void CmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);
        // VK_VERSION_1_1
        inline VkResult BindBufferMemory2(uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos);
        inline VkResult BindImageMemory2(uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos);
        inline void GetDeviceGroupPeerMemoryFeatures(uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures);
        inline void CmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask);
        inline void CmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
        inline void GetImageMemoryRequirements2(const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
        inline void GetBufferMemoryRequirements2(const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
        inline void GetImageSparseMemoryRequirements2(const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
        inline void TrimCommandPool(VkCommandPool commandPool, VkCommandPoolTrimFlags flags);
        inline void GetQueue2(const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue);
        inline VkResult CreateSamplerYcbcrConversion(const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion);
        inline void DestroySamplerYcbcrConversion(VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator);
        inline VkResult CreateDescriptorUpdateTemplate(const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);
        inline void DestroyDescriptorUpdateTemplate(VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator);
        inline void UpdateDescriptorSetWithTemplate(VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData);
        inline void GetDescriptorSetLayoutSupport(const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport);
        // VK_VERSION_1_2
        inline void CmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
        inline void CmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
        inline VkResult CreateRenderPass2(const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
        inline void CmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo);
        inline void CmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo);
        inline void CmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);
        inline void ResetQueryPool(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
        inline VkResult GetSemaphoreCounterValue(VkSemaphore semaphore, uint64_t* pValue);
        inline VkResult WaitSemaphores(const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout);
        inline VkResult SignalSemaphore(const VkSemaphoreSignalInfo* pSignalInfo);
        inline VkDeviceAddress GetBufferDeviceAddress(const VkBufferDeviceAddressInfo* pInfo);
        inline VkDeviceAddress GetBufferOpaqueCaptureAddress(const VkBufferDeviceAddressInfo* pInfo);
        inline VkDeviceAddress GetDeviceMemoryOpaqueCaptureAddress(const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo);
        // VK_VERSION_1_3
        inline VkResult CreatePrivateDataSlot(const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot);
        inline void DestroyPrivateDataSlot(VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator);
        inline VkResult SetPrivateData(VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data);
        inline void GetPrivateData(VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData);
        inline void CmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);
        inline void CmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);
        inline void CmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);
        inline void CmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);
        inline void CmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query);
        inline VkResult QueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);
        inline void CmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);
        inline void CmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);
        inline void CmdCopyBufferToImage2(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);
        inline void CmdCopyImageToBuffer2(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);
        inline void CmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);
        inline void CmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);
        inline void CmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);
        inline void CmdEndRendering(VkCommandBuffer commandBuffer);
        inline void CmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);
        inline void CmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace);
        inline void CmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);
        inline void CmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports);
        inline void CmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors);
        inline void CmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides);
        inline void CmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);
        inline void CmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);
        inline void CmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);
        inline void CmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);
        inline void CmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);
        inline void CmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);
        inline void CmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);
        inline void CmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);
        inline void CmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);
        inline void GetDeviceBufferMemoryRequirements(const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);
        inline void GetDeviceImageMemoryRequirements(const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);
        inline void GetDeviceImageSparseMemoryRequirements(const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
        // VK_KHR_swapchain
        inline VkResult GetSwapchainImages(VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages);
        inline VkResult AcquireNextImage(VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex);
        inline VkResult QueuePresent(VkQueue queue, const VkPresentInfoKHR* pPresentInfo);
        inline VkResult GetDeviceGroupPresentCapabilities(VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities);
        inline VkResult GetDeviceGroupSurfacePresentModes(VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes);
        inline VkResult GetPhysicalDevicePresentRectangles(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects);
        inline VkResult AcquireNextImage2(const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex);
        // VK_EXT_debug_utils
        inline VkResult SetDebugUtilsObjectName(const VkDebugUtilsObjectNameInfoEXT* pNameInfo);
        inline VkResult SetDebugUtilsObjectTag(const VkDebugUtilsObjectTagInfoEXT* pTagInfo);
        inline void QueueBeginDebugUtilsLabel(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo);
        inline void QueueEndDebugUtilsLabel(VkQueue queue);
        inline void QueueInsertDebugUtilsLabel(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo);
        inline void CmdBeginDebugUtilsLabel(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);
        inline void CmdEndDebugUtilsLabel(VkCommandBuffer commandBuffer);
        inline void CmdInsertDebugUtilsLabel(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);
        inline VkResult CreateSwapchain(const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain);
        inline void DestroySwapchain(VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator);
    public:
        // Specializations
        inline VkResult CreateSemaphore(VkSemaphoreType semaphoreType, uint64_t initialValue, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore);
        inline VkResult CreateImage(const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Image* pImage);
        inline VkResult CreateCommandPool(VkCommandPoolCreateFlags flags, uint32_t queueFamilyIndex, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool);
        inline VkResult BeginCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferUsageFlags flags);
        inline VkResult AllocateCommandBuffers(VkCommandPool commandPool, VkCommandBufferLevel level, uint32_t commandBufferCount, VkCommandBuffer* pCommandBuffers);
    private:
        VkDevice                                     device;
        // VK_VERSION_1_0
        PFN_vkDestroyDevice                          vkDestroyDevice;
        PFN_vkGetDeviceQueue                         vkGetDeviceQueue;
        PFN_vkQueueSubmit                            vkQueueSubmit;
        PFN_vkQueueWaitIdle                          vkQueueWaitIdle;
        PFN_vkDeviceWaitIdle                         vkDeviceWaitIdle;
        PFN_vkAllocateMemory                         vkAllocateMemory;
        PFN_vkFreeMemory                             vkFreeMemory;
        PFN_vkMapMemory                              vkMapMemory;
        PFN_vkUnmapMemory                            vkUnmapMemory;
        PFN_vkFlushMappedMemoryRanges                vkFlushMappedMemoryRanges;
        PFN_vkInvalidateMappedMemoryRanges           vkInvalidateMappedMemoryRanges;
        PFN_vkGetDeviceMemoryCommitment              vkGetDeviceMemoryCommitment;
        PFN_vkBindBufferMemory                       vkBindBufferMemory;
        PFN_vkBindImageMemory                        vkBindImageMemory;
        PFN_vkGetBufferMemoryRequirements            vkGetBufferMemoryRequirements;
        PFN_vkGetImageMemoryRequirements             vkGetImageMemoryRequirements;
        PFN_vkGetImageSparseMemoryRequirements       vkGetImageSparseMemoryRequirements;
        PFN_vkQueueBindSparse                        vkQueueBindSparse;
        PFN_vkCreateFence                            vkCreateFence;
        PFN_vkDestroyFence                           vkDestroyFence;
        PFN_vkResetFences                            vkResetFences;
        PFN_vkGetFenceStatus                         vkGetFenceStatus;
        PFN_vkWaitForFences                          vkWaitForFences;
        PFN_vkCreateSemaphore                        vkCreateSemaphore;
        PFN_vkDestroySemaphore                       vkDestroySemaphore;
        PFN_vkCreateEvent                            vkCreateEvent;
        PFN_vkDestroyEvent                           vkDestroyEvent;
        PFN_vkGetEventStatus                         vkGetEventStatus;
        PFN_vkSetEvent                               vkSetEvent;
        PFN_vkResetEvent                             vkResetEvent;
        PFN_vkCreateQueryPool                        vkCreateQueryPool;
        PFN_vkDestroyQueryPool                       vkDestroyQueryPool;
        PFN_vkGetQueryPoolResults                    vkGetQueryPoolResults;
        PFN_vkCreateBuffer                           vkCreateBuffer;
        PFN_vkDestroyBuffer                          vkDestroyBuffer;
        PFN_vkCreateBufferView                       vkCreateBufferView;
        PFN_vkDestroyBufferView                      vkDestroyBufferView;
        PFN_vkCreateImage                            vkCreateImage;
        PFN_vkDestroyImage                           vkDestroyImage;
        PFN_vkGetImageSubresourceLayout              vkGetImageSubresourceLayout;
        PFN_vkCreateImageView                        vkCreateImageView;
        PFN_vkDestroyImageView                       vkDestroyImageView;
        PFN_vkCreateShaderModule                     vkCreateShaderModule;
        PFN_vkDestroyShaderModule                    vkDestroyShaderModule;
        PFN_vkCreatePipelineCache                    vkCreatePipelineCache;
        PFN_vkDestroyPipelineCache                   vkDestroyPipelineCache;
        PFN_vkGetPipelineCacheData                   vkGetPipelineCacheData;
        PFN_vkMergePipelineCaches                    vkMergePipelineCaches;
        PFN_vkCreateGraphicsPipelines                vkCreateGraphicsPipelines;
        PFN_vkCreateComputePipelines                 vkCreateComputePipelines;
        PFN_vkDestroyPipeline                        vkDestroyPipeline;
        PFN_vkCreatePipelineLayout                   vkCreatePipelineLayout;
        PFN_vkDestroyPipelineLayout                  vkDestroyPipelineLayout;
        PFN_vkCreateSampler                          vkCreateSampler;
        PFN_vkDestroySampler                         vkDestroySampler;
        PFN_vkCreateDescriptorSetLayout              vkCreateDescriptorSetLayout;
        PFN_vkDestroyDescriptorSetLayout             vkDestroyDescriptorSetLayout;
        PFN_vkCreateDescriptorPool                   vkCreateDescriptorPool;
        PFN_vkDestroyDescriptorPool                  vkDestroyDescriptorPool;
        PFN_vkResetDescriptorPool                    vkResetDescriptorPool;
        PFN_vkAllocateDescriptorSets                 vkAllocateDescriptorSets;
        PFN_vkFreeDescriptorSets                     vkFreeDescriptorSets;
        PFN_vkUpdateDescriptorSets                   vkUpdateDescriptorSets;
        PFN_vkCreateFramebuffer                      vkCreateFramebuffer;
        PFN_vkDestroyFramebuffer                     vkDestroyFramebuffer;
        PFN_vkCreateRenderPass                       vkCreateRenderPass;
        PFN_vkDestroyRenderPass                      vkDestroyRenderPass;
        PFN_vkGetRenderAreaGranularity               vkGetRenderAreaGranularity;
        PFN_vkCreateCommandPool                      vkCreateCommandPool;
        PFN_vkDestroyCommandPool                     vkDestroyCommandPool;
        PFN_vkResetCommandPool                       vkResetCommandPool;
        PFN_vkAllocateCommandBuffers                 vkAllocateCommandBuffers;
        PFN_vkFreeCommandBuffers                     vkFreeCommandBuffers;
        PFN_vkBeginCommandBuffer                     vkBeginCommandBuffer;
        PFN_vkEndCommandBuffer                       vkEndCommandBuffer;
        PFN_vkResetCommandBuffer                     vkResetCommandBuffer;
        PFN_vkCmdBindPipeline                        vkCmdBindPipeline;
        PFN_vkCmdSetViewport                         vkCmdSetViewport;
        PFN_vkCmdSetScissor                          vkCmdSetScissor;
        PFN_vkCmdSetLineWidth                        vkCmdSetLineWidth;
        PFN_vkCmdSetDepthBias                        vkCmdSetDepthBias;
        PFN_vkCmdSetBlendConstants                   vkCmdSetBlendConstants;
        PFN_vkCmdSetDepthBounds                      vkCmdSetDepthBounds;
        PFN_vkCmdSetStencilCompareMask               vkCmdSetStencilCompareMask;
        PFN_vkCmdSetStencilWriteMask                 vkCmdSetStencilWriteMask;
        PFN_vkCmdSetStencilReference                 vkCmdSetStencilReference;
        PFN_vkCmdBindDescriptorSets                  vkCmdBindDescriptorSets;
        PFN_vkCmdBindIndexBuffer                     vkCmdBindIndexBuffer;
        PFN_vkCmdBindVertexBuffers                   vkCmdBindVertexBuffers;
        PFN_vkCmdDraw                                vkCmdDraw;
        PFN_vkCmdDrawIndexed                         vkCmdDrawIndexed;
        PFN_vkCmdDrawIndirect                        vkCmdDrawIndirect;
        PFN_vkCmdDrawIndexedIndirect                 vkCmdDrawIndexedIndirect;
        PFN_vkCmdDispatch                            vkCmdDispatch;
        PFN_vkCmdDispatchIndirect                    vkCmdDispatchIndirect;
        PFN_vkCmdCopyBuffer                          vkCmdCopyBuffer;
        PFN_vkCmdCopyImage                           vkCmdCopyImage;
        PFN_vkCmdBlitImage                           vkCmdBlitImage;
        PFN_vkCmdCopyBufferToImage                   vkCmdCopyBufferToImage;
        PFN_vkCmdCopyImageToBuffer                   vkCmdCopyImageToBuffer;
        PFN_vkCmdUpdateBuffer                        vkCmdUpdateBuffer;
        PFN_vkCmdFillBuffer                          vkCmdFillBuffer;
        PFN_vkCmdClearColorImage                     vkCmdClearColorImage;
        PFN_vkCmdClearDepthStencilImage              vkCmdClearDepthStencilImage;
        PFN_vkCmdClearAttachments                    vkCmdClearAttachments;
        PFN_vkCmdResolveImage                        vkCmdResolveImage;
        PFN_vkCmdSetEvent                            vkCmdSetEvent;
        PFN_vkCmdResetEvent                          vkCmdResetEvent;
        PFN_vkCmdWaitEvents                          vkCmdWaitEvents;
        PFN_vkCmdPipelineBarrier                     vkCmdPipelineBarrier;
        PFN_vkCmdBeginQuery                          vkCmdBeginQuery;
        PFN_vkCmdEndQuery                            vkCmdEndQuery;
        PFN_vkCmdResetQueryPool                      vkCmdResetQueryPool;
        PFN_vkCmdWriteTimestamp                      vkCmdWriteTimestamp;
        PFN_vkCmdCopyQueryPoolResults                vkCmdCopyQueryPoolResults;
        PFN_vkCmdPushConstants                       vkCmdPushConstants;
        PFN_vkCmdBeginRenderPass                     vkCmdBeginRenderPass;
        PFN_vkCmdNextSubpass                         vkCmdNextSubpass;
        PFN_vkCmdEndRenderPass                       vkCmdEndRenderPass;
        PFN_vkCmdExecuteCommands                     vkCmdExecuteCommands;
        // VK_VERSION_1_1
        PFN_vkBindBufferMemory2                      vkBindBufferMemory2;
        PFN_vkBindImageMemory2                       vkBindImageMemory2;
        PFN_vkGetDeviceGroupPeerMemoryFeatures       vkGetDeviceGroupPeerMemoryFeatures;
        PFN_vkCmdSetDeviceMask                       vkCmdSetDeviceMask;
        PFN_vkCmdDispatchBase                        vkCmdDispatchBase;
        PFN_vkGetImageMemoryRequirements2            vkGetImageMemoryRequirements2;
        PFN_vkGetBufferMemoryRequirements2           vkGetBufferMemoryRequirements2;
        PFN_vkGetImageSparseMemoryRequirements2      vkGetImageSparseMemoryRequirements2;
        PFN_vkTrimCommandPool                        vkTrimCommandPool;
        PFN_vkGetDeviceQueue2                        vkGetDeviceQueue2;
        PFN_vkCreateSamplerYcbcrConversion           vkCreateSamplerYcbcrConversion;
        PFN_vkDestroySamplerYcbcrConversion          vkDestroySamplerYcbcrConversion;
        PFN_vkCreateDescriptorUpdateTemplate         vkCreateDescriptorUpdateTemplate;
        PFN_vkDestroyDescriptorUpdateTemplate        vkDestroyDescriptorUpdateTemplate;
        PFN_vkUpdateDescriptorSetWithTemplate        vkUpdateDescriptorSetWithTemplate;
        PFN_vkGetDescriptorSetLayoutSupport          vkGetDescriptorSetLayoutSupport;
        // VK_VERSION_1_2
        PFN_vkCmdDrawIndirectCount                   vkCmdDrawIndirectCount;
        PFN_vkCmdDrawIndexedIndirectCount            vkCmdDrawIndexedIndirectCount;
        PFN_vkCreateRenderPass2                      vkCreateRenderPass2;
        PFN_vkCmdBeginRenderPass2                    vkCmdBeginRenderPass2;
        PFN_vkCmdNextSubpass2                        vkCmdNextSubpass2;
        PFN_vkCmdEndRenderPass2                      vkCmdEndRenderPass2;
        PFN_vkResetQueryPool                         vkResetQueryPool;
        PFN_vkGetSemaphoreCounterValue               vkGetSemaphoreCounterValue;
        PFN_vkWaitSemaphores                         vkWaitSemaphores;
        PFN_vkSignalSemaphore                        vkSignalSemaphore;
        PFN_vkGetBufferDeviceAddress                 vkGetBufferDeviceAddress;
        PFN_vkGetBufferOpaqueCaptureAddress          vkGetBufferOpaqueCaptureAddress;
        PFN_vkGetDeviceMemoryOpaqueCaptureAddress    vkGetDeviceMemoryOpaqueCaptureAddress;
        // VK_VERSION_1_3
        PFN_vkCreatePrivateDataSlot                  vkCreatePrivateDataSlot;
        PFN_vkDestroyPrivateDataSlot                 vkDestroyPrivateDataSlot;
        PFN_vkSetPrivateData                         vkSetPrivateData;
        PFN_vkGetPrivateData                         vkGetPrivateData;
        PFN_vkCmdSetEvent2                           vkCmdSetEvent2;
        PFN_vkCmdResetEvent2                         vkCmdResetEvent2;
        PFN_vkCmdWaitEvents2                         vkCmdWaitEvents2;
        PFN_vkCmdPipelineBarrier2                    vkCmdPipelineBarrier2;
        PFN_vkCmdWriteTimestamp2                     vkCmdWriteTimestamp2;
        PFN_vkQueueSubmit2                           vkQueueSubmit2;
        PFN_vkCmdCopyBuffer2                         vkCmdCopyBuffer2;
        PFN_vkCmdCopyImage2                          vkCmdCopyImage2;
        PFN_vkCmdCopyBufferToImage2                  vkCmdCopyBufferToImage2;
        PFN_vkCmdCopyImageToBuffer2                  vkCmdCopyImageToBuffer2;
        PFN_vkCmdBlitImage2                          vkCmdBlitImage2;
        PFN_vkCmdResolveImage2                       vkCmdResolveImage2;
        PFN_vkCmdBeginRendering                      vkCmdBeginRendering;
        PFN_vkCmdEndRendering                        vkCmdEndRendering;
        PFN_vkCmdSetCullMode                         vkCmdSetCullMode;
        PFN_vkCmdSetFrontFace                        vkCmdSetFrontFace;
        PFN_vkCmdSetPrimitiveTopology                vkCmdSetPrimitiveTopology;
        PFN_vkCmdSetViewportWithCount                vkCmdSetViewportWithCount;
        PFN_vkCmdSetScissorWithCount                 vkCmdSetScissorWithCount;
        PFN_vkCmdBindVertexBuffers2                  vkCmdBindVertexBuffers2;
        PFN_vkCmdSetDepthTestEnable                  vkCmdSetDepthTestEnable;
        PFN_vkCmdSetDepthWriteEnable                 vkCmdSetDepthWriteEnable;
        PFN_vkCmdSetDepthCompareOp                   vkCmdSetDepthCompareOp;
        PFN_vkCmdSetDepthBoundsTestEnable            vkCmdSetDepthBoundsTestEnable;
        PFN_vkCmdSetStencilTestEnable                vkCmdSetStencilTestEnable;
        PFN_vkCmdSetStencilOp                        vkCmdSetStencilOp;
        PFN_vkCmdSetRasterizerDiscardEnable          vkCmdSetRasterizerDiscardEnable;
        PFN_vkCmdSetDepthBiasEnable                  vkCmdSetDepthBiasEnable;
        PFN_vkCmdSetPrimitiveRestartEnable           vkCmdSetPrimitiveRestartEnable;
        PFN_vkGetDeviceBufferMemoryRequirements      vkGetDeviceBufferMemoryRequirements;
        PFN_vkGetDeviceImageMemoryRequirements       vkGetDeviceImageMemoryRequirements;
        PFN_vkGetDeviceImageSparseMemoryRequirements vkGetDeviceImageSparseMemoryRequirements;
        // VK_KHR_swapchain
        PFN_vkCreateSwapchainKHR                     vkCreateSwapchainKHR;
        PFN_vkDestroySwapchainKHR                    vkDestroySwapchainKHR;
        PFN_vkGetSwapchainImagesKHR                  vkGetSwapchainImagesKHR;
        PFN_vkAcquireNextImageKHR                    vkAcquireNextImageKHR;
        PFN_vkQueuePresentKHR                        vkQueuePresentKHR;
        PFN_vkGetDeviceGroupPresentCapabilitiesKHR   vkGetDeviceGroupPresentCapabilitiesKHR;
        PFN_vkGetDeviceGroupSurfacePresentModesKHR   vkGetDeviceGroupSurfacePresentModesKHR;
        PFN_vkGetPhysicalDevicePresentRectanglesKHR  vkGetPhysicalDevicePresentRectanglesKHR;
        PFN_vkAcquireNextImage2KHR                   vkAcquireNextImage2KHR;
        // VK_EXT_debug_utils
        PFN_vkSetDebugUtilsObjectNameEXT             vkSetDebugUtilsObjectNameEXT;
        PFN_vkSetDebugUtilsObjectTagEXT              vkSetDebugUtilsObjectTagEXT;
        PFN_vkQueueBeginDebugUtilsLabelEXT           vkQueueBeginDebugUtilsLabelEXT;
        PFN_vkQueueEndDebugUtilsLabelEXT             vkQueueEndDebugUtilsLabelEXT;
        PFN_vkQueueInsertDebugUtilsLabelEXT          vkQueueInsertDebugUtilsLabelEXT;
        PFN_vkCmdBeginDebugUtilsLabelEXT             vkCmdBeginDebugUtilsLabelEXT;
        PFN_vkCmdEndDebugUtilsLabelEXT               vkCmdEndDebugUtilsLabelEXT;
        PFN_vkCmdInsertDebugUtilsLabelEXT            vkCmdInsertDebugUtilsLabelEXT;
    };

}

#include "fast_vulkan_wrapper.inl"
