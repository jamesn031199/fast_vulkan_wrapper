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

#ifdef FVKW_FORCE_INLINE
#  define FVKW_INLINE __forceinline
#else
#  define FVKW_INLINE inline
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
        FVKW_INLINE operator VkPhysicalDevice() { return physicalDevice; }
    };

    class Instance
    {
    public:
        FVKW_INLINE operator VkInstance() { return instance; }
        VkResult Create(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks *pAllocator);
        FVKW_INLINE void Destroy(const VkAllocationCallbacks *pAllocator);
        // VK_VERSION_1_0
        FVKW_INLINE VkResult EnumeratePhysicalDevices(uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices);
        FVKW_INLINE void GetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures);
        FVKW_INLINE void GetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties);
        FVKW_INLINE VkResult GetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties);
        FVKW_INLINE void GetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties);
        FVKW_INLINE void GetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties);
        FVKW_INLINE void GetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties);
        FVKW_INLINE VkResult EnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties);
        FVKW_INLINE VkResult EnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkLayerProperties* pProperties);
        FVKW_INLINE void GetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties);
        // VK_VERSION_1_1
        FVKW_INLINE VkResult EnumerateInstanceVersion(uint32_t* pApiVersion);
        FVKW_INLINE VkResult EnumeratePhysicalDeviceGroups(uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties);
        FVKW_INLINE void GetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures);
        FVKW_INLINE void GetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties);
        FVKW_INLINE void GetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties);
        FVKW_INLINE VkResult GetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties);
        FVKW_INLINE void GetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties);
        FVKW_INLINE void GetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties);
        FVKW_INLINE void GetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties);
        FVKW_INLINE void GetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties);
        FVKW_INLINE void GetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties);
        FVKW_INLINE void GetPhysicalDeviceExternalSemaphoreProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties);
        // VK_VERSION_1_3
        FVKW_INLINE VkResult GetPhysicalDeviceToolProperties(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties);
        // VK_KHR_surface
        FVKW_INLINE void DestroySurface(VkSurfaceKHR surface, VkAllocationCallbacks* pAllocator);
        FVKW_INLINE VkResult GetPhysicalDeviceSurfaceSupport(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported);
        FVKW_INLINE VkResult GetPhysicalDeviceSurfaceCapabilities(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities);
        FVKW_INLINE VkResult GetPhysicalDeviceSurfaceFormats(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats);
        FVKW_INLINE VkResult GetPhysicalDeviceSurfacePresentModes(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);
        // VK_KHR_get_surface_capabilities2
        FVKW_INLINE VkResult GetPhysicalDeviceSurfaceCapabilities2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities);
        FVKW_INLINE VkResult GetPhysicalDeviceSurfaceFormats2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats);
        // VK_EXT_debug_utils
        FVKW_INLINE VkResult CreateDebugUtilsMessenger(const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger);
        FVKW_INLINE void DestroyDebugUtilsMessenger(VkDebugUtilsMessengerEXT messenger, VkAllocationCallbacks* pAllocator);
        FVKW_INLINE void SubmitDebugUtilsMessage(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, VkDebugUtilsMessengerCallbackDataEXT* pCallbackData);
    #ifdef _WIN32
        FVKW_INLINE VkResult CreateWin32Surface(const VkWin32SurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
        FVKW_INLINE VkBool32 GetPhysicalDeviceWin32PresentationSupport(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex);
    #endif
    public:
        // Custom
        FVKW_INLINE void CreatePhysicalDevice(VkPhysicalDevice physicalDevice, PhysicalDevice *pPhysicalDevice);
        // Specializations
    #ifdef _WIN32
        FVKW_INLINE VkResult CreateWin32Surface(HINSTANCE hinstance, HWND hwnd, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
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
        FVKW_INLINE operator VkImage() { return image; }
    };

    class Device
    {
    public:
        FVKW_INLINE operator VkDevice() { return device; }
        VkResult Create(const Instance *pInstance, VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator);
        FVKW_INLINE void Destroy(const VkAllocationCallbacks *pAllocator);
        // VK_VERSION_1_0
        FVKW_INLINE void GetQueue(uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue);
        FVKW_INLINE VkResult QueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);
        FVKW_INLINE VkResult QueueWaitIdle(VkQueue queue);
        FVKW_INLINE VkResult WaitIdle();
        FVKW_INLINE VkResult AllocateMemory(const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory);
        FVKW_INLINE void FreeMemory(VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE VkResult MapMemory(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData);
        FVKW_INLINE void UnmapMemory(VkDeviceMemory memory);
        FVKW_INLINE VkResult FlushMappedMemoryRanges(uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
        FVKW_INLINE VkResult InvalidateMappedMemoryRanges(uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
        FVKW_INLINE void GetDeviceMemoryCommitment(VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes);
        FVKW_INLINE VkResult BindBufferMemory(VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);
        FVKW_INLINE VkResult BindImageMemory(VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);
        FVKW_INLINE void GetBufferMemoryRequirements(VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements);
        FVKW_INLINE void GetImageMemoryRequirements(VkImage image, VkMemoryRequirements* pMemoryRequirements);
        FVKW_INLINE void GetImageSparseMemoryRequirements(VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements);
        FVKW_INLINE VkResult QueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence);
        FVKW_INLINE VkResult CreateFence(const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);
        FVKW_INLINE void DestroyFence(VkFence fence, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE VkResult ResetFences(uint32_t fenceCount, const VkFence* pFences);
        FVKW_INLINE VkResult GetFenceStatus(VkFence fence);
        FVKW_INLINE VkResult WaitForFences(uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout);
        FVKW_INLINE VkResult CreateSemaphore(const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore);
        FVKW_INLINE void DestroySemaphore(VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE VkResult CreateEvent(const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent);
        FVKW_INLINE void DestroyEvent(VkEvent event, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE VkResult GetEventStatus(VkEvent event);
        FVKW_INLINE VkResult SetEvent(VkEvent event);
        FVKW_INLINE VkResult ResetEvent(VkEvent event);
        FVKW_INLINE VkResult CreateQueryPool(const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool);
        FVKW_INLINE void DestroyQueryPool(VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE VkResult GetQueryPoolResults(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags);
        FVKW_INLINE VkResult CreateBuffer(const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer);
        FVKW_INLINE void DestroyBuffer(VkBuffer buffer, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE VkResult CreateBufferView(const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView);
        FVKW_INLINE void DestroyBufferView(VkBufferView bufferView, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE VkResult CreateImage(const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage);
        FVKW_INLINE void DestroyImage(VkImage image, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE void GetImageSubresourceLayout(VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout);
        FVKW_INLINE VkResult CreateImageView(const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView);
        FVKW_INLINE void DestroyImageView(VkImageView imageView, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE VkResult CreateShaderModule(const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule);
        FVKW_INLINE void DestroyShaderModule(VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE VkResult CreatePipelineCache(const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache);
        FVKW_INLINE void DestroyPipelineCache(VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE VkResult GetPipelineCacheData(VkPipelineCache pipelineCache, size_t* pDataSize, void* pData);
        FVKW_INLINE VkResult MergePipelineCaches(VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches);
        FVKW_INLINE VkResult CreateGraphicsPipelines(VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
        FVKW_INLINE VkResult CreateComputePipelines(VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
        FVKW_INLINE void DestroyPipeline(VkPipeline pipeline, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE VkResult CreatePipelineLayout(const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout);
        FVKW_INLINE void DestroyPipelineLayout(VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE VkResult CreateSampler(const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler);
        FVKW_INLINE void DestroySampler(VkSampler sampler, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE VkResult CreateDescriptorSetLayout(const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout);
        FVKW_INLINE void DestroyDescriptorSetLayout(VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE VkResult CreateDescriptorPool(const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool);
        FVKW_INLINE void DestroyDescriptorPool(VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE VkResult ResetDescriptorPool(VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags);
        FVKW_INLINE VkResult AllocateDescriptorSets(const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets);
        FVKW_INLINE VkResult FreeDescriptorSets(VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets);
        FVKW_INLINE void UpdateDescriptorSets(uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies);
        FVKW_INLINE VkResult CreateFramebuffer(const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer);
        FVKW_INLINE void DestroyFramebuffer(VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE VkResult CreateRenderPass(const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
        FVKW_INLINE void DestroyRenderPass(VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE void GetRenderAreaGranularity(VkRenderPass renderPass, VkExtent2D* pGranularity);
        FVKW_INLINE VkResult CreateCommandPool(const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool);
        FVKW_INLINE void DestroyCommandPool(VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE VkResult ResetCommandPool(VkCommandPool commandPool, VkCommandPoolResetFlags flags);
        FVKW_INLINE VkResult AllocateCommandBuffers(const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers);
        FVKW_INLINE void FreeCommandBuffers(VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);
        FVKW_INLINE VkResult BeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo);
        FVKW_INLINE VkResult EndCommandBuffer(VkCommandBuffer commandBuffer);
        FVKW_INLINE VkResult ResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags);
        FVKW_INLINE void CmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline);
        FVKW_INLINE void CmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports);
        FVKW_INLINE void CmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors);
        FVKW_INLINE void CmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth);
        FVKW_INLINE void CmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor);
        FVKW_INLINE void CmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]);
        FVKW_INLINE void CmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds);
        FVKW_INLINE void CmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask);
        FVKW_INLINE void CmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask);
        FVKW_INLINE void CmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference);
        FVKW_INLINE void CmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets);
        FVKW_INLINE void CmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType);
        FVKW_INLINE void CmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets);
        FVKW_INLINE void CmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
        FVKW_INLINE void CmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance);
        FVKW_INLINE void CmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
        FVKW_INLINE void CmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
        FVKW_INLINE void CmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
        FVKW_INLINE void CmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);
        FVKW_INLINE void CmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions);
        FVKW_INLINE void CmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions);
        FVKW_INLINE void CmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter);
        FVKW_INLINE void CmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions);
        FVKW_INLINE void CmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions);
        FVKW_INLINE void CmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData);
        FVKW_INLINE void CmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data);
        FVKW_INLINE void CmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);
        FVKW_INLINE void CmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);
        FVKW_INLINE void CmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects);
        FVKW_INLINE void CmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions);
        FVKW_INLINE void CmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
        FVKW_INLINE void CmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
        FVKW_INLINE void CmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
        FVKW_INLINE void CmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
        FVKW_INLINE void CmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags);
        FVKW_INLINE void CmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query);
        FVKW_INLINE void CmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
        FVKW_INLINE void CmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query);
        FVKW_INLINE void CmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags);
        FVKW_INLINE void CmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues);
        FVKW_INLINE void CmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents);
        FVKW_INLINE void CmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents);
        FVKW_INLINE void CmdEndRenderPass(VkCommandBuffer commandBuffer);
        FVKW_INLINE void CmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);
        // VK_VERSION_1_1
        FVKW_INLINE VkResult BindBufferMemory2(uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos);
        FVKW_INLINE VkResult BindImageMemory2(uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos);
        FVKW_INLINE void GetDeviceGroupPeerMemoryFeatures(uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures);
        FVKW_INLINE void CmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask);
        FVKW_INLINE void CmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
        FVKW_INLINE void GetImageMemoryRequirements2(const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
        FVKW_INLINE void GetBufferMemoryRequirements2(const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
        FVKW_INLINE void GetImageSparseMemoryRequirements2(const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
        FVKW_INLINE void TrimCommandPool(VkCommandPool commandPool, VkCommandPoolTrimFlags flags);
        FVKW_INLINE void GetQueue2(const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue);
        FVKW_INLINE VkResult CreateSamplerYcbcrConversion(const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion);
        FVKW_INLINE void DestroySamplerYcbcrConversion(VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE VkResult CreateDescriptorUpdateTemplate(const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);
        FVKW_INLINE void DestroyDescriptorUpdateTemplate(VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE void UpdateDescriptorSetWithTemplate(VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData);
        FVKW_INLINE void GetDescriptorSetLayoutSupport(const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport);
        // VK_VERSION_1_2
        FVKW_INLINE void CmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
        FVKW_INLINE void CmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
        FVKW_INLINE VkResult CreateRenderPass2(const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
        FVKW_INLINE void CmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo);
        FVKW_INLINE void CmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo);
        FVKW_INLINE void CmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);
        FVKW_INLINE void ResetQueryPool(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
        FVKW_INLINE VkResult GetSemaphoreCounterValue(VkSemaphore semaphore, uint64_t* pValue);
        FVKW_INLINE VkResult WaitSemaphores(const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout);
        FVKW_INLINE VkResult SignalSemaphore(const VkSemaphoreSignalInfo* pSignalInfo);
        FVKW_INLINE VkDeviceAddress GetBufferDeviceAddress(const VkBufferDeviceAddressInfo* pInfo);
        FVKW_INLINE VkDeviceAddress GetBufferOpaqueCaptureAddress(const VkBufferDeviceAddressInfo* pInfo);
        FVKW_INLINE VkDeviceAddress GetDeviceMemoryOpaqueCaptureAddress(const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo);
        // VK_VERSION_1_3
        FVKW_INLINE VkResult CreatePrivateDataSlot(const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot);
        FVKW_INLINE void DestroyPrivateDataSlot(VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator);
        FVKW_INLINE VkResult SetPrivateData(VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data);
        FVKW_INLINE void GetPrivateData(VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData);
        FVKW_INLINE void CmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);
        FVKW_INLINE void CmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);
        FVKW_INLINE void CmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);
        FVKW_INLINE void CmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);
        FVKW_INLINE void CmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query);
        FVKW_INLINE VkResult QueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);
        FVKW_INLINE void CmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);
        FVKW_INLINE void CmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);
        FVKW_INLINE void CmdCopyBufferToImage2(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);
        FVKW_INLINE void CmdCopyImageToBuffer2(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);
        FVKW_INLINE void CmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);
        FVKW_INLINE void CmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);
        FVKW_INLINE void CmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);
        FVKW_INLINE void CmdEndRendering(VkCommandBuffer commandBuffer);
        FVKW_INLINE void CmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);
        FVKW_INLINE void CmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace);
        FVKW_INLINE void CmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);
        FVKW_INLINE void CmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports);
        FVKW_INLINE void CmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors);
        FVKW_INLINE void CmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides);
        FVKW_INLINE void CmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);
        FVKW_INLINE void CmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);
        FVKW_INLINE void CmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);
        FVKW_INLINE void CmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);
        FVKW_INLINE void CmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);
        FVKW_INLINE void CmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);
        FVKW_INLINE void CmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);
        FVKW_INLINE void CmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);
        FVKW_INLINE void CmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);
        FVKW_INLINE void GetDeviceBufferMemoryRequirements(const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);
        FVKW_INLINE void GetDeviceImageMemoryRequirements(const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);
        FVKW_INLINE void GetDeviceImageSparseMemoryRequirements(const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
        // VK_KHR_swapchain
        FVKW_INLINE VkResult GetSwapchainImages(VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages);
        FVKW_INLINE VkResult AcquireNextImage(VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex);
        FVKW_INLINE VkResult QueuePresent(VkQueue queue, const VkPresentInfoKHR* pPresentInfo);
        FVKW_INLINE VkResult GetDeviceGroupPresentCapabilities(VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities);
        FVKW_INLINE VkResult GetDeviceGroupSurfacePresentModes(VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes);
        FVKW_INLINE VkResult GetPhysicalDevicePresentRectangles(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects);
        FVKW_INLINE VkResult AcquireNextImage2(const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex);
        // VK_EXT_debug_utils
        FVKW_INLINE VkResult SetDebugUtilsObjectName(const VkDebugUtilsObjectNameInfoEXT* pNameInfo);
        FVKW_INLINE VkResult SetDebugUtilsObjectTag(const VkDebugUtilsObjectTagInfoEXT* pTagInfo);
        FVKW_INLINE void QueueBeginDebugUtilsLabel(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo);
        FVKW_INLINE void QueueEndDebugUtilsLabel(VkQueue queue);
        FVKW_INLINE void QueueInsertDebugUtilsLabel(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo);
        FVKW_INLINE void CmdBeginDebugUtilsLabel(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);
        FVKW_INLINE void CmdEndDebugUtilsLabel(VkCommandBuffer commandBuffer);
        FVKW_INLINE void CmdInsertDebugUtilsLabel(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);
        FVKW_INLINE VkResult CreateSwapchain(const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain);
        FVKW_INLINE void DestroySwapchain(VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator);
    public:
        // Specializations
        FVKW_INLINE VkResult CreateSemaphore(VkSemaphoreType semaphoreType, uint64_t initialValue, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore);
        FVKW_INLINE VkResult CreateImage(const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Image* pImage);
        FVKW_INLINE VkResult CreateCommandPool(VkCommandPoolCreateFlags flags, uint32_t queueFamilyIndex, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool);
        FVKW_INLINE VkResult BeginCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferUsageFlags flags);
        FVKW_INLINE VkResult AllocateDescriptorSets(VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSetLayout* pSetLayouts, VkDescriptorSet* pDescriptorSets);
        FVKW_INLINE VkResult AllocateCommandBuffers(VkCommandPool commandPool, VkCommandBufferLevel level, uint32_t commandBufferCount, VkCommandBuffer* pCommandBuffers);
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
