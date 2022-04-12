#pragma once

#ifdef _WIN32
#define NOGDICAPMASKS     // CC_*, LC_*, PC_*, CP_*, TC_*, RC_
#define NOVIRTUALKEYCODES // VK_*
#define NOWINMESSAGES     // WM_*, EM_*, LB_*, CB_*
#define NOWINSTYLES       // WS_*, CS_*, ES_*, LBS_*, SBS_*, CBS_*
#define NOSYSMETRICS      // SM_*
#define NOMENUS           // MF_*
#define NOICONS           // IDI_*
#define NOKEYSTATES       // MK_*
#define NOSYSCOMMANDS     // SC_*
#define NORASTEROPS       // Binary and Tertiary raster ops
#define NOSHOWWINDOW      // SW_*
#define OEMRESOURCE       // OEM Resource values
#define NOATOM            // Atom Manager routines
#define NOCLIPBOARD       // Clipboard routines
#define NOCOLOR           // Screen colors
#define NOCTLMGR          // Control and Dialog routines
#define NODRAWTEXT        // DrawText() and DT_*
#define NOGDI             // All GDI defines and routines
#define NOKERNEL          // All KERNEL defines and routines
#define NOUSER            // All USER defines and routines
#define NONLS             // All NLS defines and routines
#define NOMB              // MB_* and MessageBox()
#define NOMEMMGR          // GMEM_*, LMEM_*, GHND, LHND, associated routines
#define NOMETAFILE        // typedef METAFILEPICT
#define NOMINMAX          // Macros min(a,b) and max(a,b)
#define NOMSG             // typedef MSG and associated routines
#define NOOPENFILE        // OpenFile(), OemToAnsi, AnsiToOem, and OF_*
#define NOSCROLL          // SB_* and scrolling routines
#define NOSERVICE         // All Service Controller routines, SERVICE_ equates, etc.
#define NOSOUND           // Sound driver routines
#define NOTEXTMETRIC      // typedef TEXTMETRIC and associated routines
#define NOWH              // SetWindowsHook and WH_*
#define NOWINOFFSETS      // GWL_*, GCL_*, associated routines
#define NOCOMM            // COMM driver routines
#define NOKANJI           // Kanji support stuff.
#define NOHELP            // Help engine interface.
#define NOPROFILER        // Profiler interface.
#define NODEFERWINDOWPOS  // DeferWindowPos routines
#define NOMCX             // Modem Configuration Extensions
#define NOIME
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef CreateSemaphore
#undef CreateEvent
#endif

#pragma warning(push)
#pragma warning(disable:4820) // S: N bytes padding added after data member M
#define VK_NO_PROTOTYPES 1
#define VK_LAYER_KHRONOS_VALIDATION_NAME "VK_LAYER_KHRONOS_validation"
#include <vulkan/vulkan.h>
#pragma warning(pop)

namespace fvkw
{

    VkResult EnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties);
    VkResult EnumerateInstanceExtensionProperties(const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties);

    class Instance
    {
    public:
        operator VkInstance() { return instance; }
        VkResult Create(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks *pAllocator);
        void Destroy(const VkAllocationCallbacks *pAllocator);
        // VK_VERSION_1_0
        VkResult EnumeratePhysicalDevices(uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices);
        void GetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures);
        void GetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties);
        VkResult GetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties);
        void GetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties);
        void GetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties);
        void GetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties);
        VkResult EnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties);
        VkResult EnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkLayerProperties* pProperties);
        void GetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties);
        // VK_VERSION_1_1
        VkResult EnumerateInstanceVersion(uint32_t* pApiVersion);
        VkResult EnumeratePhysicalDeviceGroups(uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties);
        void GetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures);
        void GetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties);
        void GetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties);
        VkResult GetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties);
        void GetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties);
        void GetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties);
        void GetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties);
        void GetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties);
        void GetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties);
        void GetPhysicalDeviceExternalSemaphoreProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties);
        // VK_VERSION_1_3
        VkResult GetPhysicalDeviceToolProperties(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties);
        // VK_KHR_surface
        void DestroySurface(VkSurfaceKHR surface, VkAllocationCallbacks* pAllocator);
        VkResult GetPhysicalDeviceSurfaceSupport(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported);
        VkResult GetPhysicalDeviceSurfaceCapabilities(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities);
        VkResult GetPhysicalDeviceSurfaceFormats(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats);
        VkResult GetPhysicalDeviceSurfacePresentModes(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);
        // VK_KHR_get_surface_capabilities2
        VkResult GetPhysicalDeviceSurfaceCapabilities2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities);
        VkResult GetPhysicalDeviceSurfaceFormats2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats);
        // VK_EXT_debug_utils
        VkResult CreateDebugUtilsMessenger(const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger);
        void DestroyDebugUtilsMessenger(VkDebugUtilsMessengerEXT messenger, VkAllocationCallbacks* pAllocator);
        void SubmitDebugUtilsMessage(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, VkDebugUtilsMessengerCallbackDataEXT* pCallbackData);
    #if defined(VK_KHR_win32_surface)
        VkResult CreateWin32Surface(const VkWin32SurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
        VkBool32 GetPhysicalDeviceWin32PresentationSupport(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex);
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

    class Device
    {
    public:
        operator VkDevice() { return device; }
        VkResult Create(const Instance *pInstance, VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator);
        void Destroy(const VkAllocationCallbacks *pAllocator);
        // VK_VERSION_1_0
        void GetQueue(uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue);
        VkResult QueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);
        VkResult QueueWaitIdle(VkQueue queue);
        VkResult WaitIdle();
        VkResult AllocateMemory(const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory);
        void FreeMemory(VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);
        VkResult MapMemory(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData);
        void UnmapMemory(VkDeviceMemory memory);
        VkResult FlushMappedMemoryRanges(uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
        VkResult InvalidateMappedMemoryRanges(uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
        void GetDeviceMemoryCommitment(VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes);
        VkResult BindBufferMemory(VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);
        VkResult BindImageMemory(VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);
        void GetBufferMemoryRequirements(VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements);
        void GetImageMemoryRequirements(VkImage image, VkMemoryRequirements* pMemoryRequirements);
        void GetImageSparseMemoryRequirements(VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements);
        VkResult QueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence);
        VkResult CreateFence(const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);
        void DestroyFence(VkFence fence, const VkAllocationCallbacks* pAllocator);
        VkResult ResetFences(uint32_t fenceCount, const VkFence* pFences);
        VkResult GetFenceStatus(VkFence fence);
        VkResult WaitForFences(uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout);
        VkResult CreateSemaphore(const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore);
        void DestroySemaphore(VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator);
        VkResult CreateEvent(const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent);
        void DestroyEvent(VkEvent event, const VkAllocationCallbacks* pAllocator);
        VkResult GetEventStatus(VkEvent event);
        VkResult SetEvent(VkEvent event);
        VkResult ResetEvent(VkEvent event);
        VkResult CreateQueryPool(const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool);
        void DestroyQueryPool(VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator);
        VkResult GetQueryPoolResults(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags);
        VkResult CreateBuffer(const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer);
        void DestroyBuffer(VkBuffer buffer, const VkAllocationCallbacks* pAllocator);
        VkResult CreateBufferView(const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView);
        void DestroyBufferView(VkBufferView bufferView, const VkAllocationCallbacks* pAllocator);
        VkResult CreateImage(const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage);
        void DestroyImage(VkImage image, const VkAllocationCallbacks* pAllocator);
        void GetImageSubresourceLayout(VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout);
        VkResult CreateImageView(const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView);
        void DestroyImageView(VkImageView imageView, const VkAllocationCallbacks* pAllocator);
        VkResult CreateShaderModule(const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule);
        void DestroyShaderModule(VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator);
        VkResult CreatePipelineCache(const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache);
        void DestroyPipelineCache(VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator);
        VkResult GetPipelineCacheData(VkPipelineCache pipelineCache, size_t* pDataSize, void* pData);
        VkResult MergePipelineCaches(VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches);
        VkResult CreateGraphicsPipelines(VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
        VkResult CreateComputePipelines(VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
        void DestroyPipeline(VkPipeline pipeline, const VkAllocationCallbacks* pAllocator);
        VkResult CreatePipelineLayout(const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout);
        void DestroyPipelineLayout(VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator);
        VkResult CreateSampler(const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler);
        void DestroySampler(VkSampler sampler, const VkAllocationCallbacks* pAllocator);
        VkResult CreateDescriptorSetLayout(const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout);
        void DestroyDescriptorSetLayout(VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator);
        VkResult CreateDescriptorPool(const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool);
        void DestroyDescriptorPool(VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator);
        VkResult ResetDescriptorPool(VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags);
        VkResult AllocateDescriptorSets(const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets);
        VkResult FreeDescriptorSets(VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets);
        void UpdateDescriptorSets(uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies);
        VkResult CreateFramebuffer(const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer);
        void DestroyFramebuffer(VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator);
        VkResult CreateRenderPass(const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
        void DestroyRenderPass(VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator);
        void GetRenderAreaGranularity(VkRenderPass renderPass, VkExtent2D* pGranularity);
        VkResult CreateCommandPool(const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool);
        void DestroyCommandPool(VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator);
        VkResult ResetCommandPool(VkCommandPool commandPool, VkCommandPoolResetFlags flags);
        VkResult AllocateCommandBuffers(const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers);
        void FreeCommandBuffers(VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);
        VkResult BeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo);
        VkResult EndCommandBuffer(VkCommandBuffer commandBuffer);
        VkResult ResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags);
        void CmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline);
        void CmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports);
        void CmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors);
        void CmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth);
        void CmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor);
        void CmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]);
        void CmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds);
        void CmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask);
        void CmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask);
        void CmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference);
        void CmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets);
        void CmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType);
        void CmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets);
        void CmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
        void CmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance);
        void CmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
        void CmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
        void CmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
        void CmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);
        void CmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions);
        void CmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions);
        void CmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter);
        void CmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions);
        void CmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions);
        void CmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData);
        void CmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data);
        void CmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);
        void CmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);
        void CmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects);
        void CmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions);
        void CmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
        void CmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
        void CmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
        void CmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
        void CmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags);
        void CmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query);
        void CmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
        void CmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query);
        void CmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags);
        void CmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues);
        void CmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents);
        void CmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents);
        void CmdEndRenderPass(VkCommandBuffer commandBuffer);
        void CmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);
        // VK_VERSION_1_1
        VkResult BindBufferMemory2(uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos);
        VkResult BindImageMemory2(uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos);
        void GetDeviceGroupPeerMemoryFeatures(uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures);
        void CmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask);
        void CmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
        void GetImageMemoryRequirements2(const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
        void GetBufferMemoryRequirements2(const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
        void GetImageSparseMemoryRequirements2(const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
        void TrimCommandPool(VkCommandPool commandPool, VkCommandPoolTrimFlags flags);
        void GetQueue2(const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue);
        VkResult CreateSamplerYcbcrConversion(const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion);
        void DestroySamplerYcbcrConversion(VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator);
        VkResult CreateDescriptorUpdateTemplate(const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);
        void DestroyDescriptorUpdateTemplate(VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator);
        void UpdateDescriptorSetWithTemplate(VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData);
        void GetDescriptorSetLayoutSupport(const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport);
        // VK_VERSION_1_2
        void CmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
        void CmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
        VkResult CreateRenderPass2(const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
        void CmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo);
        void CmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo);
        void CmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);
        void ResetQueryPool(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
        VkResult GetSemaphoreCounterValue(VkSemaphore semaphore, uint64_t* pValue);
        VkResult WaitSemaphores(const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout);
        VkResult SignalSemaphore(const VkSemaphoreSignalInfo* pSignalInfo);
        VkDeviceAddress GetBufferDeviceAddress(const VkBufferDeviceAddressInfo* pInfo);
        VkDeviceAddress GetBufferOpaqueCaptureAddress(const VkBufferDeviceAddressInfo* pInfo);
        VkDeviceAddress GetDeviceMemoryOpaqueCaptureAddress(const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo);
        // VK_VERSION_1_3
        VkResult CreatePrivateDataSlot(const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot);
        void DestroyPrivateDataSlot(VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator);
        VkResult SetPrivateData(VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data);
        void GetPrivateData(VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData);
        void CmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);
        void CmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);
        void CmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);
        void CmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);
        void CmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query);
        VkResult QueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);
        void CmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);
        void CmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);
        void CmdCopyBufferToImage2(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);
        void CmdCopyImageToBuffer2(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);
        void CmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);
        void CmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);
        void CmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);
        void CmdEndRendering(VkCommandBuffer commandBuffer);
        void CmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);
        void CmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace);
        void CmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);
        void CmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports);
        void CmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors);
        void CmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides);
        void CmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);
        void CmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);
        void CmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);
        void CmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);
        void CmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);
        void CmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);
        void CmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);
        void CmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);
        void CmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);
        void GetDeviceBufferMemoryRequirements(const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);
        void GetDeviceImageMemoryRequirements(const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);
        void GetDeviceImageSparseMemoryRequirements(const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
        // VK_KHR_swapchain
        VkResult GetSwapchainImages(VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages);
        VkResult AcquireNextImage(VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex);
        VkResult QueuePresent(VkQueue queue, const VkPresentInfoKHR* pPresentInfo);
        VkResult GetDeviceGroupPresentCapabilities(VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities);
        VkResult GetDeviceGroupSurfacePresentModes(VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes);
        VkResult GetPhysicalDevicePresentRectangles(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects);
        VkResult AcquireNextImage2(const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex);
        // VK_EXT_debug_utils
        VkResult SetDebugUtilsObjectName(const VkDebugUtilsObjectNameInfoEXT* pNameInfo);
        VkResult SetDebugUtilsObjectTag(const VkDebugUtilsObjectTagInfoEXT* pTagInfo);
        void QueueBeginDebugUtilsLabel(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo);
        void QueueEndDebugUtilsLabel(VkQueue queue);
        void QueueInsertDebugUtilsLabel(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo);
        void CmdBeginDebugUtilsLabel(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);
        void CmdEndDebugUtilsLabel(VkCommandBuffer commandBuffer);
        void CmdInsertDebugUtilsLabel(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);
        VkResult CreateSwapchain(const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain);
        void DestroySwapchain(VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator);
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
