#pragma warning(disable:4191)

#include "fast_vulkan_wrapper.hpp"

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

namespace fvkw
{


#ifdef _WIN32
    struct Library
    {
        HMODULE lib;
        Library() { lib = LoadLibrary("vulkan-1.dll"); }
        ~Library() { FreeLibrary(lib); }
    } static const Lib;
    static PFN_vkGetInstanceProcAddr                  const vkGetInstanceProcAddr                  = (PFN_vkGetInstanceProcAddr)GetProcAddress(Lib.lib, "vkGetInstanceProcAddr");
#endif
    static PFN_vkEnumerateInstanceLayerProperties     const vkEnumerateInstanceLayerProperties     = (PFN_vkEnumerateInstanceLayerProperties)vkGetInstanceProcAddr(VK_NULL_HANDLE, "vkEnumerateInstanceLayerProperties");
    static PFN_vkEnumerateInstanceExtensionProperties const vkEnumerateInstanceExtensionProperties = (PFN_vkEnumerateInstanceExtensionProperties)vkGetInstanceProcAddr(VK_NULL_HANDLE, "vkEnumerateInstanceExtensionProperties");
    static PFN_vkCreateInstance                       const vkCreateInstance                       = (PFN_vkCreateInstance)vkGetInstanceProcAddr(VK_NULL_HANDLE, "vkCreateInstance");

    VkResult EnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties)
    {
        return vkEnumerateInstanceLayerProperties(pPropertyCount, pProperties);
    }

    VkResult EnumerateInstanceExtensionProperties(const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties)
    {
        return vkEnumerateInstanceExtensionProperties(pLayerName, pPropertyCount, pProperties);
    }

    VkResult Instance::Create(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks *pAllocator)
    {
        VkResult result;
        result = vkCreateInstance(pCreateInfo, pAllocator, &instance);
        if (result != VK_SUCCESS) return result;
        // VK_VERSION_1_0
        vkDestroyInstance                               = (PFN_vkDestroyInstance                              )vkGetInstanceProcAddr(instance, "vkDestroyInstance"                              );
        vkEnumeratePhysicalDevices                      = (PFN_vkEnumeratePhysicalDevices                     )vkGetInstanceProcAddr(instance, "vkEnumeratePhysicalDevices"                     );
        vkGetPhysicalDeviceFeatures                     = (PFN_vkGetPhysicalDeviceFeatures                    )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceFeatures"                    );
        vkGetPhysicalDeviceFormatProperties             = (PFN_vkGetPhysicalDeviceFormatProperties            )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceFormatProperties"            );
        vkGetPhysicalDeviceImageFormatProperties        = (PFN_vkGetPhysicalDeviceImageFormatProperties       )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceImageFormatProperties"       );
        vkGetPhysicalDeviceProperties                   = (PFN_vkGetPhysicalDeviceProperties                  )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceProperties"                  );
        vkGetPhysicalDeviceQueueFamilyProperties        = (PFN_vkGetPhysicalDeviceQueueFamilyProperties       )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceQueueFamilyProperties"       );
        vkGetPhysicalDeviceMemoryProperties             = (PFN_vkGetPhysicalDeviceMemoryProperties            )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceMemoryProperties"            );
        vkGetDeviceProcAddr                             = (PFN_vkGetDeviceProcAddr                            )vkGetInstanceProcAddr(instance, "vkGetDeviceProcAddr"                            );
        vkCreateDevice                                  = (PFN_vkCreateDevice                                 )vkGetInstanceProcAddr(instance, "vkCreateDevice"                                 );
        vkEnumerateDeviceExtensionProperties            = (PFN_vkEnumerateDeviceExtensionProperties           )vkGetInstanceProcAddr(instance, "vkEnumerateDeviceExtensionProperties"           );
        vkEnumerateDeviceLayerProperties                = (PFN_vkEnumerateDeviceLayerProperties               )vkGetInstanceProcAddr(instance, "vkEnumerateDeviceLayerProperties"               );
        vkGetPhysicalDeviceSparseImageFormatProperties  = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSparseImageFormatProperties" );
        // VK_VERSION_1_1
        vkEnumerateInstanceVersion                      = (PFN_vkEnumerateInstanceVersion                     )vkGetInstanceProcAddr(instance, "vkEnumerateInstanceVersion"                     );
        vkEnumeratePhysicalDeviceGroups                 = (PFN_vkEnumeratePhysicalDeviceGroups                )vkGetInstanceProcAddr(instance, "vkEnumeratePhysicalDeviceGroups"                );
        vkGetPhysicalDeviceFeatures2                    = (PFN_vkGetPhysicalDeviceFeatures2                   )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceFeatures2"                   );
        vkGetPhysicalDeviceProperties2                  = (PFN_vkGetPhysicalDeviceProperties2                 )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceProperties2"                 );
        vkGetPhysicalDeviceFormatProperties2            = (PFN_vkGetPhysicalDeviceFormatProperties2           )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceFormatProperties2"           );
        vkGetPhysicalDeviceImageFormatProperties2       = (PFN_vkGetPhysicalDeviceImageFormatProperties2      )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceImageFormatProperties2"      );
        vkGetPhysicalDeviceQueueFamilyProperties2       = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2      )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceQueueFamilyProperties2"      );
        vkGetPhysicalDeviceMemoryProperties2            = (PFN_vkGetPhysicalDeviceMemoryProperties2           )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceMemoryProperties2"           );
        vkGetPhysicalDeviceSparseImageFormatProperties2 = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2)vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSparseImageFormatProperties2");
        vkGetPhysicalDeviceExternalBufferProperties     = (PFN_vkGetPhysicalDeviceExternalBufferProperties    )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceExternalBufferProperties"    );
        vkGetPhysicalDeviceExternalFenceProperties      = (PFN_vkGetPhysicalDeviceExternalFenceProperties     )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceExternalFenceProperties"     );
        vkGetPhysicalDeviceExternalSemaphoreProperties  = (PFN_vkGetPhysicalDeviceExternalSemaphoreProperties )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceExternalSemaphoreProperties" );
        // VK_VERSION_1_3
        vkGetPhysicalDeviceToolProperties               = (PFN_vkGetPhysicalDeviceToolProperties              )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceToolProperties"              );
        // VK_KHR_surface
        vkDestroySurfaceKHR                             = (PFN_vkDestroySurfaceKHR                            )vkGetInstanceProcAddr(instance, "vkDestroySurfaceKHR"                            );
        vkGetPhysicalDeviceSurfaceSupportKHR            = (PFN_vkGetPhysicalDeviceSurfaceSupportKHR           )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceSupportKHR"           );
        vkGetPhysicalDeviceSurfaceCapabilitiesKHR       = (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR      )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR"      );
        vkGetPhysicalDeviceSurfaceFormatsKHR            = (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR           )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceFormatsKHR"           );
        vkGetPhysicalDeviceSurfacePresentModesKHR       = (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR      )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfacePresentModesKHR"      );
        // VK_KHR_get_surface_capabilities2
        vkGetPhysicalDeviceSurfaceCapabilities2KHR      = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR     )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceCapabilities2KHR"     );
        vkGetPhysicalDeviceSurfaceFormats2KHR           = (PFN_vkGetPhysicalDeviceSurfaceFormats2KHR          )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceFormats2KHR"          );
        // VK_EXT_debug_utils
        vkCreateDebugUtilsMessengerEXT                  = (PFN_vkCreateDebugUtilsMessengerEXT                 )vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT"                 );
        vkDestroyDebugUtilsMessengerEXT                 = (PFN_vkDestroyDebugUtilsMessengerEXT                )vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT"                );
        vkSubmitDebugUtilsMessageEXT                    = (PFN_vkSubmitDebugUtilsMessageEXT                   )vkGetInstanceProcAddr(instance, "vkSubmitDebugUtilsMessageEXT"                   );
    #if defined(VK_KHR_win32_surface)
        vkCreateWin32SurfaceKHR                         = (PFN_vkCreateWin32SurfaceKHR                        )vkGetInstanceProcAddr(instance, "vkCreateWin32SurfaceKHR"                        );
        vkGetPhysicalDeviceWin32PresentationSupportKHR  = (PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR )vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceWin32PresentationSupportKHR" );
    #endif
        return result;
    }

    void Instance::Destroy(const VkAllocationCallbacks *pAllocator)
    {
        vkDestroyInstance(instance, pAllocator);
    }

    VkResult Instance::EnumeratePhysicalDevices(uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices)
    {
        return vkEnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);
    }

    void Instance::GetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures)
    {
        return vkGetPhysicalDeviceFeatures(physicalDevice, pFeatures);
    }

    void Instance::GetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties)
    {
        return vkGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
    }

    VkResult Instance::GetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties)
    {
        return vkGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
    }

    void Instance::GetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties)
    {
        return vkGetPhysicalDeviceProperties(physicalDevice, pProperties);
    }

    void Instance::GetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties)
    {
        return vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    }

    void Instance::GetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties)
    {
        return vkGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
    }

    VkResult Instance::EnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties)
    {
        return vkEnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pPropertyCount, pProperties);
    }

    VkResult Instance::EnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkLayerProperties* pProperties)
    {
        return vkEnumerateDeviceLayerProperties(physicalDevice, pPropertyCount, pProperties);
    }

    void Instance::GetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties)
    {
        return vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
    }

    VkResult Instance::EnumerateInstanceVersion(uint32_t* pApiVersion)
    {
        return vkEnumerateInstanceVersion(pApiVersion);
    }

    VkResult Instance::EnumeratePhysicalDeviceGroups(uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties)
    {
        return vkEnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    }

    void Instance::GetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures)
    {
        return vkGetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
    }

    void Instance::GetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties)
    {
        return vkGetPhysicalDeviceProperties2(physicalDevice, pProperties);
    }

    void Instance::GetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties)
    {
        return vkGetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);
    }

    VkResult Instance::GetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties)
    {
        return vkGetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);
    }

    void Instance::GetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties)
    {
        return vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    }

    void Instance::GetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties)
    {
        return vkGetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);
    }

    void Instance::GetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties)
    {
        return vkGetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
    }

    void Instance::GetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties)
    {
        return vkGetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
    }

    void Instance::GetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties)
    {
        return vkGetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
    }

    void Instance::GetPhysicalDeviceExternalSemaphoreProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties)
    {
        return vkGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
    }

    VkResult Instance::GetPhysicalDeviceToolProperties(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties)
    {
        return vkGetPhysicalDeviceToolProperties(physicalDevice, pToolCount, pToolProperties);
    }

    void Instance::DestroySurface(VkSurfaceKHR surface, VkAllocationCallbacks* pAllocator)
    {
        return vkDestroySurfaceKHR(instance, surface, pAllocator);
    }

    VkResult Instance::GetPhysicalDeviceSurfaceSupport(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported)
    {
        return vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);
    }

    VkResult Instance::GetPhysicalDeviceSurfaceCapabilities(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities)
    {
        return vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);
    }

    VkResult Instance::GetPhysicalDeviceSurfaceFormats(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats)
    {
        return vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
    }

    VkResult Instance::GetPhysicalDeviceSurfacePresentModes(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes)
    {
        return vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);
    }

    VkResult Instance::GetPhysicalDeviceSurfaceCapabilities2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities)
    {
        return vkGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
    }

    VkResult Instance::GetPhysicalDeviceSurfaceFormats2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats)
    {
        return vkGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
    }

    VkResult Instance::CreateDebugUtilsMessenger(const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger)
    {
        return vkCreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);
    }

    void Instance::DestroyDebugUtilsMessenger(VkDebugUtilsMessengerEXT messenger, VkAllocationCallbacks* pAllocator)
    {
        return vkDestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);
    }

    void Instance::SubmitDebugUtilsMessage(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, VkDebugUtilsMessengerCallbackDataEXT* pCallbackData)
    {
        return vkSubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);
    }

    VkResult Instance::CreateWin32Surface(const VkWin32SurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
    {
        return vkCreateWin32SurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    }

    VkBool32 Instance::GetPhysicalDeviceWin32PresentationSupport(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex)
    {
        return vkGetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice, queueFamilyIndex);
    }

    void Instance::CreatePhysicalDevice(VkPhysicalDevice physicalDevice, PhysicalDevice *pPhysicalDevice)
    {
        pPhysicalDevice->physicalDevice = physicalDevice;

        pPhysicalDevice->properties2.sType         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;
        pPhysicalDevice->vulkan11_properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES;
        pPhysicalDevice->vulkan12_properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES;
        pPhysicalDevice->vulkan13_properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES;
        pPhysicalDevice->features2.sType           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2;
        pPhysicalDevice->vulkan11_features.sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
        pPhysicalDevice->vulkan12_features.sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
        pPhysicalDevice->vulkan13_features.sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES;

        pPhysicalDevice->properties2.pNext         = &pPhysicalDevice->vulkan11_properties;
        pPhysicalDevice->vulkan11_properties.pNext = &pPhysicalDevice->vulkan12_properties;
        pPhysicalDevice->vulkan12_properties.pNext = &pPhysicalDevice->vulkan13_properties;
        pPhysicalDevice->vulkan13_properties.pNext = nullptr;
        pPhysicalDevice->features2.pNext           = &pPhysicalDevice->vulkan11_features;
        pPhysicalDevice->vulkan11_features.pNext   = &pPhysicalDevice->vulkan12_features;
        pPhysicalDevice->vulkan12_features.pNext   = &pPhysicalDevice->vulkan13_features;
        pPhysicalDevice->vulkan13_features.pNext   = nullptr;

        GetPhysicalDeviceMemoryProperties(physicalDevice, &pPhysicalDevice->memory_properties);
        GetPhysicalDeviceProperties2(physicalDevice, &pPhysicalDevice->properties2);
        GetPhysicalDeviceFeatures2(physicalDevice, &pPhysicalDevice->features2);
    }

    VkResult Instance::CreateWin32Surface(HINSTANCE hinstance, HWND hwnd, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
    {
        VkWin32SurfaceCreateInfoKHR ci ={ VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR, nullptr, 0, hinstance, hwnd };
        return CreateWin32Surface(&ci, pAllocator, pSurface);
    }

    VkResult Device::Create(const Instance *pInstance, VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator)
    {
        VkResult result;
        result = pInstance->vkCreateDevice(physicalDevice, pCreateInfo, pAllocator, &device);
        if (result != VK_SUCCESS) return result;
        // VK_VERSION_1_0
        vkDestroyDevice                          = (PFN_vkDestroyDevice                         )pInstance->vkGetDeviceProcAddr(device, "vkDestroyDevice"                         );
        vkGetDeviceQueue                         = (PFN_vkGetDeviceQueue                        )pInstance->vkGetDeviceProcAddr(device, "vkGetDeviceQueue"                        );
        vkQueueSubmit                            = (PFN_vkQueueSubmit                           )pInstance->vkGetDeviceProcAddr(device, "vkQueueSubmit"                           );
        vkQueueWaitIdle                          = (PFN_vkQueueWaitIdle                         )pInstance->vkGetDeviceProcAddr(device, "vkQueueWaitIdle"                         );
        vkDeviceWaitIdle                         = (PFN_vkDeviceWaitIdle                        )pInstance->vkGetDeviceProcAddr(device, "vkDeviceWaitIdle"                        );
        vkAllocateMemory                         = (PFN_vkAllocateMemory                        )pInstance->vkGetDeviceProcAddr(device, "vkAllocateMemory"                        );
        vkFreeMemory                             = (PFN_vkFreeMemory                            )pInstance->vkGetDeviceProcAddr(device, "vkFreeMemory"                            );
        vkMapMemory                              = (PFN_vkMapMemory                             )pInstance->vkGetDeviceProcAddr(device, "vkMapMemory"                             );
        vkUnmapMemory                            = (PFN_vkUnmapMemory                           )pInstance->vkGetDeviceProcAddr(device, "vkUnmapMemory"                           );
        vkFlushMappedMemoryRanges                = (PFN_vkFlushMappedMemoryRanges               )pInstance->vkGetDeviceProcAddr(device, "vkFlushMappedMemoryRanges"               );
        vkInvalidateMappedMemoryRanges           = (PFN_vkInvalidateMappedMemoryRanges          )pInstance->vkGetDeviceProcAddr(device, "vkInvalidateMappedMemoryRanges"          );
        vkGetDeviceMemoryCommitment              = (PFN_vkGetDeviceMemoryCommitment             )pInstance->vkGetDeviceProcAddr(device, "vkGetDeviceMemoryCommitment"             );
        vkBindBufferMemory                       = (PFN_vkBindBufferMemory                      )pInstance->vkGetDeviceProcAddr(device, "vkBindBufferMemory"                      );
        vkBindImageMemory                        = (PFN_vkBindImageMemory                       )pInstance->vkGetDeviceProcAddr(device, "vkBindImageMemory"                       );
        vkGetBufferMemoryRequirements            = (PFN_vkGetBufferMemoryRequirements           )pInstance->vkGetDeviceProcAddr(device, "vkGetBufferMemoryRequirements"           );
        vkGetImageMemoryRequirements             = (PFN_vkGetImageMemoryRequirements            )pInstance->vkGetDeviceProcAddr(device, "vkGetImageMemoryRequirements"            );
        vkGetImageSparseMemoryRequirements       = (PFN_vkGetImageSparseMemoryRequirements      )pInstance->vkGetDeviceProcAddr(device, "vkGetImageSparseMemoryRequirements"      );
        vkQueueBindSparse                        = (PFN_vkQueueBindSparse                       )pInstance->vkGetDeviceProcAddr(device, "vkQueueBindSparse"                       );
        vkCreateFence                            = (PFN_vkCreateFence                           )pInstance->vkGetDeviceProcAddr(device, "vkCreateFence"                           );
        vkDestroyFence                           = (PFN_vkDestroyFence                          )pInstance->vkGetDeviceProcAddr(device, "vkDestroyFence"                          );
        vkResetFences                            = (PFN_vkResetFences                           )pInstance->vkGetDeviceProcAddr(device, "vkResetFences"                           );
        vkGetFenceStatus                         = (PFN_vkGetFenceStatus                        )pInstance->vkGetDeviceProcAddr(device, "vkGetFenceStatus"                        );
        vkWaitForFences                          = (PFN_vkWaitForFences                         )pInstance->vkGetDeviceProcAddr(device, "vkWaitForFences"                         );
        vkCreateSemaphore                        = (PFN_vkCreateSemaphore                       )pInstance->vkGetDeviceProcAddr(device, "vkCreateSemaphore"                       );
        vkDestroySemaphore                       = (PFN_vkDestroySemaphore                      )pInstance->vkGetDeviceProcAddr(device, "vkDestroySemaphore"                      );
        vkCreateEvent                            = (PFN_vkCreateEvent                           )pInstance->vkGetDeviceProcAddr(device, "vkCreateEvent"                           );
        vkDestroyEvent                           = (PFN_vkDestroyEvent                          )pInstance->vkGetDeviceProcAddr(device, "vkDestroyEvent"                          );
        vkGetEventStatus                         = (PFN_vkGetEventStatus                        )pInstance->vkGetDeviceProcAddr(device, "vkGetEventStatus"                        );
        vkSetEvent                               = (PFN_vkSetEvent                              )pInstance->vkGetDeviceProcAddr(device, "vkSetEvent"                              );
        vkResetEvent                             = (PFN_vkResetEvent                            )pInstance->vkGetDeviceProcAddr(device, "vkResetEvent"                            );
        vkCreateQueryPool                        = (PFN_vkCreateQueryPool                       )pInstance->vkGetDeviceProcAddr(device, "vkCreateQueryPool"                       );
        vkDestroyQueryPool                       = (PFN_vkDestroyQueryPool                      )pInstance->vkGetDeviceProcAddr(device, "vkDestroyQueryPool"                      );
        vkGetQueryPoolResults                    = (PFN_vkGetQueryPoolResults                   )pInstance->vkGetDeviceProcAddr(device, "vkGetQueryPoolResults"                   );
        vkCreateBuffer                           = (PFN_vkCreateBuffer                          )pInstance->vkGetDeviceProcAddr(device, "vkCreateBuffer"                          );
        vkDestroyBuffer                          = (PFN_vkDestroyBuffer                         )pInstance->vkGetDeviceProcAddr(device, "vkDestroyBuffer"                         );
        vkCreateBufferView                       = (PFN_vkCreateBufferView                      )pInstance->vkGetDeviceProcAddr(device, "vkCreateBufferView"                      );
        vkDestroyBufferView                      = (PFN_vkDestroyBufferView                     )pInstance->vkGetDeviceProcAddr(device, "vkDestroyBufferView"                     );
        vkCreateImage                            = (PFN_vkCreateImage                           )pInstance->vkGetDeviceProcAddr(device, "vkCreateImage"                           );
        vkDestroyImage                           = (PFN_vkDestroyImage                          )pInstance->vkGetDeviceProcAddr(device, "vkDestroyImage"                          );
        vkGetImageSubresourceLayout              = (PFN_vkGetImageSubresourceLayout             )pInstance->vkGetDeviceProcAddr(device, "vkGetImageSubresourceLayout"             );
        vkCreateImageView                        = (PFN_vkCreateImageView                       )pInstance->vkGetDeviceProcAddr(device, "vkCreateImageView"                       );
        vkDestroyImageView                       = (PFN_vkDestroyImageView                      )pInstance->vkGetDeviceProcAddr(device, "vkDestroyImageView"                      );
        vkCreateShaderModule                     = (PFN_vkCreateShaderModule                    )pInstance->vkGetDeviceProcAddr(device, "vkCreateShaderModule"                    );
        vkDestroyShaderModule                    = (PFN_vkDestroyShaderModule                   )pInstance->vkGetDeviceProcAddr(device, "vkDestroyShaderModule"                   );
        vkCreatePipelineCache                    = (PFN_vkCreatePipelineCache                   )pInstance->vkGetDeviceProcAddr(device, "vkCreatePipelineCache"                   );
        vkDestroyPipelineCache                   = (PFN_vkDestroyPipelineCache                  )pInstance->vkGetDeviceProcAddr(device, "vkDestroyPipelineCache"                  );
        vkGetPipelineCacheData                   = (PFN_vkGetPipelineCacheData                  )pInstance->vkGetDeviceProcAddr(device, "vkGetPipelineCacheData"                  );
        vkMergePipelineCaches                    = (PFN_vkMergePipelineCaches                   )pInstance->vkGetDeviceProcAddr(device, "vkMergePipelineCaches"                   );
        vkCreateGraphicsPipelines                = (PFN_vkCreateGraphicsPipelines               )pInstance->vkGetDeviceProcAddr(device, "vkCreateGraphicsPipelines"               );
        vkCreateComputePipelines                 = (PFN_vkCreateComputePipelines                )pInstance->vkGetDeviceProcAddr(device, "vkCreateComputePipelines"                );
        vkDestroyPipeline                        = (PFN_vkDestroyPipeline                       )pInstance->vkGetDeviceProcAddr(device, "vkDestroyPipeline"                       );
        vkCreatePipelineLayout                   = (PFN_vkCreatePipelineLayout                  )pInstance->vkGetDeviceProcAddr(device, "vkCreatePipelineLayout"                  );
        vkDestroyPipelineLayout                  = (PFN_vkDestroyPipelineLayout                 )pInstance->vkGetDeviceProcAddr(device, "vkDestroyPipelineLayout"                 );
        vkCreateSampler                          = (PFN_vkCreateSampler                         )pInstance->vkGetDeviceProcAddr(device, "vkCreateSampler"                         );
        vkDestroySampler                         = (PFN_vkDestroySampler                        )pInstance->vkGetDeviceProcAddr(device, "vkDestroySampler"                        );
        vkCreateDescriptorSetLayout              = (PFN_vkCreateDescriptorSetLayout             )pInstance->vkGetDeviceProcAddr(device, "vkCreateDescriptorSetLayout"             );
        vkDestroyDescriptorSetLayout             = (PFN_vkDestroyDescriptorSetLayout            )pInstance->vkGetDeviceProcAddr(device, "vkDestroyDescriptorSetLayout"            );
        vkCreateDescriptorPool                   = (PFN_vkCreateDescriptorPool                  )pInstance->vkGetDeviceProcAddr(device, "vkCreateDescriptorPool"                  );
        vkDestroyDescriptorPool                  = (PFN_vkDestroyDescriptorPool                 )pInstance->vkGetDeviceProcAddr(device, "vkDestroyDescriptorPool"                 );
        vkResetDescriptorPool                    = (PFN_vkResetDescriptorPool                   )pInstance->vkGetDeviceProcAddr(device, "vkResetDescriptorPool"                   );
        vkAllocateDescriptorSets                 = (PFN_vkAllocateDescriptorSets                )pInstance->vkGetDeviceProcAddr(device, "vkAllocateDescriptorSets"                );
        vkFreeDescriptorSets                     = (PFN_vkFreeDescriptorSets                    )pInstance->vkGetDeviceProcAddr(device, "vkFreeDescriptorSets"                    );
        vkUpdateDescriptorSets                   = (PFN_vkUpdateDescriptorSets                  )pInstance->vkGetDeviceProcAddr(device, "vkUpdateDescriptorSets"                  );
        vkCreateFramebuffer                      = (PFN_vkCreateFramebuffer                     )pInstance->vkGetDeviceProcAddr(device, "vkCreateFramebuffer"                     );
        vkDestroyFramebuffer                     = (PFN_vkDestroyFramebuffer                    )pInstance->vkGetDeviceProcAddr(device, "vkDestroyFramebuffer"                    );
        vkCreateRenderPass                       = (PFN_vkCreateRenderPass                      )pInstance->vkGetDeviceProcAddr(device, "vkCreateRenderPass"                      );
        vkDestroyRenderPass                      = (PFN_vkDestroyRenderPass                     )pInstance->vkGetDeviceProcAddr(device, "vkDestroyRenderPass"                     );
        vkGetRenderAreaGranularity               = (PFN_vkGetRenderAreaGranularity              )pInstance->vkGetDeviceProcAddr(device, "vkGetRenderAreaGranularity"              );
        vkCreateCommandPool                      = (PFN_vkCreateCommandPool                     )pInstance->vkGetDeviceProcAddr(device, "vkCreateCommandPool"                     );
        vkDestroyCommandPool                     = (PFN_vkDestroyCommandPool                    )pInstance->vkGetDeviceProcAddr(device, "vkDestroyCommandPool"                    );
        vkResetCommandPool                       = (PFN_vkResetCommandPool                      )pInstance->vkGetDeviceProcAddr(device, "vkResetCommandPool"                      );
        vkAllocateCommandBuffers                 = (PFN_vkAllocateCommandBuffers                )pInstance->vkGetDeviceProcAddr(device, "vkAllocateCommandBuffers"                );
        vkFreeCommandBuffers                     = (PFN_vkFreeCommandBuffers                    )pInstance->vkGetDeviceProcAddr(device, "vkFreeCommandBuffers"                    );
        vkBeginCommandBuffer                     = (PFN_vkBeginCommandBuffer                    )pInstance->vkGetDeviceProcAddr(device, "vkBeginCommandBuffer"                    );
        vkEndCommandBuffer                       = (PFN_vkEndCommandBuffer                      )pInstance->vkGetDeviceProcAddr(device, "vkEndCommandBuffer"                      );
        vkResetCommandBuffer                     = (PFN_vkResetCommandBuffer                    )pInstance->vkGetDeviceProcAddr(device, "vkResetCommandBuffer"                    );
        vkCmdBindPipeline                        = (PFN_vkCmdBindPipeline                       )pInstance->vkGetDeviceProcAddr(device, "vkCmdBindPipeline"                       );
        vkCmdSetViewport                         = (PFN_vkCmdSetViewport                        )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetViewport"                        );
        vkCmdSetScissor                          = (PFN_vkCmdSetScissor                         )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetScissor"                         );
        vkCmdSetLineWidth                        = (PFN_vkCmdSetLineWidth                       )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetLineWidth"                       );
        vkCmdSetDepthBias                        = (PFN_vkCmdSetDepthBias                       )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetDepthBias"                       );
        vkCmdSetBlendConstants                   = (PFN_vkCmdSetBlendConstants                  )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetBlendConstants"                  );
        vkCmdSetDepthBounds                      = (PFN_vkCmdSetDepthBounds                     )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetDepthBounds"                     );
        vkCmdSetStencilCompareMask               = (PFN_vkCmdSetStencilCompareMask              )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetStencilCompareMask"              );
        vkCmdSetStencilWriteMask                 = (PFN_vkCmdSetStencilWriteMask                )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetStencilWriteMask"                );
        vkCmdSetStencilReference                 = (PFN_vkCmdSetStencilReference                )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetStencilReference"                );
        vkCmdBindDescriptorSets                  = (PFN_vkCmdBindDescriptorSets                 )pInstance->vkGetDeviceProcAddr(device, "vkCmdBindDescriptorSets"                 );
        vkCmdBindIndexBuffer                     = (PFN_vkCmdBindIndexBuffer                    )pInstance->vkGetDeviceProcAddr(device, "vkCmdBindIndexBuffer"                    );
        vkCmdBindVertexBuffers                   = (PFN_vkCmdBindVertexBuffers                  )pInstance->vkGetDeviceProcAddr(device, "vkCmdBindVertexBuffers"                  );
        vkCmdDraw                                = (PFN_vkCmdDraw                               )pInstance->vkGetDeviceProcAddr(device, "vkCmdDraw"                               );
        vkCmdDrawIndexed                         = (PFN_vkCmdDrawIndexed                        )pInstance->vkGetDeviceProcAddr(device, "vkCmdDrawIndexed"                        );
        vkCmdDrawIndirect                        = (PFN_vkCmdDrawIndirect                       )pInstance->vkGetDeviceProcAddr(device, "vkCmdDrawIndirect"                       );
        vkCmdDrawIndexedIndirect                 = (PFN_vkCmdDrawIndexedIndirect                )pInstance->vkGetDeviceProcAddr(device, "vkCmdDrawIndexedIndirect"                );
        vkCmdDispatch                            = (PFN_vkCmdDispatch                           )pInstance->vkGetDeviceProcAddr(device, "vkCmdDispatch"                           );
        vkCmdDispatchIndirect                    = (PFN_vkCmdDispatchIndirect                   )pInstance->vkGetDeviceProcAddr(device, "vkCmdDispatchIndirect"                   );
        vkCmdCopyBuffer                          = (PFN_vkCmdCopyBuffer                         )pInstance->vkGetDeviceProcAddr(device, "vkCmdCopyBuffer"                         );
        vkCmdCopyImage                           = (PFN_vkCmdCopyImage                          )pInstance->vkGetDeviceProcAddr(device, "vkCmdCopyImage"                          );
        vkCmdBlitImage                           = (PFN_vkCmdBlitImage                          )pInstance->vkGetDeviceProcAddr(device, "vkCmdBlitImage"                          );
        vkCmdCopyBufferToImage                   = (PFN_vkCmdCopyBufferToImage                  )pInstance->vkGetDeviceProcAddr(device, "vkCmdCopyBufferToImage"                  );
        vkCmdCopyImageToBuffer                   = (PFN_vkCmdCopyImageToBuffer                  )pInstance->vkGetDeviceProcAddr(device, "vkCmdCopyImageToBuffer"                  );
        vkCmdUpdateBuffer                        = (PFN_vkCmdUpdateBuffer                       )pInstance->vkGetDeviceProcAddr(device, "vkCmdUpdateBuffer"                       );
        vkCmdFillBuffer                          = (PFN_vkCmdFillBuffer                         )pInstance->vkGetDeviceProcAddr(device, "vkCmdFillBuffer"                         );
        vkCmdClearColorImage                     = (PFN_vkCmdClearColorImage                    )pInstance->vkGetDeviceProcAddr(device, "vkCmdClearColorImage"                    );
        vkCmdClearDepthStencilImage              = (PFN_vkCmdClearDepthStencilImage             )pInstance->vkGetDeviceProcAddr(device, "vkCmdClearDepthStencilImage"             );
        vkCmdClearAttachments                    = (PFN_vkCmdClearAttachments                   )pInstance->vkGetDeviceProcAddr(device, "vkCmdClearAttachments"                   );
        vkCmdResolveImage                        = (PFN_vkCmdResolveImage                       )pInstance->vkGetDeviceProcAddr(device, "vkCmdResolveImage"                       );
        vkCmdSetEvent                            = (PFN_vkCmdSetEvent                           )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetEvent"                           );
        vkCmdResetEvent                          = (PFN_vkCmdResetEvent                         )pInstance->vkGetDeviceProcAddr(device, "vkCmdResetEvent"                         );
        vkCmdWaitEvents                          = (PFN_vkCmdWaitEvents                         )pInstance->vkGetDeviceProcAddr(device, "vkCmdWaitEvents"                         );
        vkCmdPipelineBarrier                     = (PFN_vkCmdPipelineBarrier                    )pInstance->vkGetDeviceProcAddr(device, "vkCmdPipelineBarrier"                    );
        vkCmdBeginQuery                          = (PFN_vkCmdBeginQuery                         )pInstance->vkGetDeviceProcAddr(device, "vkCmdBeginQuery"                         );
        vkCmdEndQuery                            = (PFN_vkCmdEndQuery                           )pInstance->vkGetDeviceProcAddr(device, "vkCmdEndQuery"                           );
        vkCmdResetQueryPool                      = (PFN_vkCmdResetQueryPool                     )pInstance->vkGetDeviceProcAddr(device, "vkCmdResetQueryPool"                     );
        vkCmdWriteTimestamp                      = (PFN_vkCmdWriteTimestamp                     )pInstance->vkGetDeviceProcAddr(device, "vkCmdWriteTimestamp"                     );
        vkCmdCopyQueryPoolResults                = (PFN_vkCmdCopyQueryPoolResults               )pInstance->vkGetDeviceProcAddr(device, "vkCmdCopyQueryPoolResults"               );
        vkCmdPushConstants                       = (PFN_vkCmdPushConstants                      )pInstance->vkGetDeviceProcAddr(device, "vkCmdPushConstants"                      );
        vkCmdBeginRenderPass                     = (PFN_vkCmdBeginRenderPass                    )pInstance->vkGetDeviceProcAddr(device, "vkCmdBeginRenderPass"                    );
        vkCmdNextSubpass                         = (PFN_vkCmdNextSubpass                        )pInstance->vkGetDeviceProcAddr(device, "vkCmdNextSubpass"                        );
        vkCmdEndRenderPass                       = (PFN_vkCmdEndRenderPass                      )pInstance->vkGetDeviceProcAddr(device, "vkCmdEndRenderPass"                      );
        vkCmdExecuteCommands                     = (PFN_vkCmdExecuteCommands                    )pInstance->vkGetDeviceProcAddr(device, "vkCmdExecuteCommands"                    );
        // VK_VERSION_1_1
        vkBindBufferMemory2                      = (PFN_vkBindBufferMemory2                     )pInstance->vkGetDeviceProcAddr(device, "vkBindBufferMemory2"                     );
        vkBindImageMemory2                       = (PFN_vkBindImageMemory2                      )pInstance->vkGetDeviceProcAddr(device, "vkBindImageMemory2"                      );
        vkGetDeviceGroupPeerMemoryFeatures       = (PFN_vkGetDeviceGroupPeerMemoryFeatures      )pInstance->vkGetDeviceProcAddr(device, "vkGetDeviceGroupPeerMemoryFeatures"      );
        vkCmdSetDeviceMask                       = (PFN_vkCmdSetDeviceMask                      )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetDeviceMask"                      );
        vkCmdDispatchBase                        = (PFN_vkCmdDispatchBase                       )pInstance->vkGetDeviceProcAddr(device, "vkCmdDispatchBase"                       );
        vkGetImageMemoryRequirements2            = (PFN_vkGetImageMemoryRequirements2           )pInstance->vkGetDeviceProcAddr(device, "vkGetImageMemoryRequirements2"           );
        vkGetBufferMemoryRequirements2           = (PFN_vkGetBufferMemoryRequirements2          )pInstance->vkGetDeviceProcAddr(device, "vkGetBufferMemoryRequirements2"          );
        vkGetImageSparseMemoryRequirements2      = (PFN_vkGetImageSparseMemoryRequirements2     )pInstance->vkGetDeviceProcAddr(device, "vkGetImageSparseMemoryRequirements2"     );
        vkTrimCommandPool                        = (PFN_vkTrimCommandPool                       )pInstance->vkGetDeviceProcAddr(device, "vkTrimCommandPool"                       );
        vkGetDeviceQueue2                        = (PFN_vkGetDeviceQueue2                       )pInstance->vkGetDeviceProcAddr(device, "vkGetDeviceQueue2"                       );
        vkCreateSamplerYcbcrConversion           = (PFN_vkCreateSamplerYcbcrConversion          )pInstance->vkGetDeviceProcAddr(device, "vkCreateSamplerYcbcrConversion"          );
        vkDestroySamplerYcbcrConversion          = (PFN_vkDestroySamplerYcbcrConversion         )pInstance->vkGetDeviceProcAddr(device, "vkDestroySamplerYcbcrConversion"         );
        vkCreateDescriptorUpdateTemplate         = (PFN_vkCreateDescriptorUpdateTemplate        )pInstance->vkGetDeviceProcAddr(device, "vkCreateDescriptorUpdateTemplate"        );
        vkDestroyDescriptorUpdateTemplate        = (PFN_vkDestroyDescriptorUpdateTemplate       )pInstance->vkGetDeviceProcAddr(device, "vkDestroyDescriptorUpdateTemplate"       );
        vkUpdateDescriptorSetWithTemplate        = (PFN_vkUpdateDescriptorSetWithTemplate       )pInstance->vkGetDeviceProcAddr(device, "vkUpdateDescriptorSetWithTemplate"       );
        vkGetDescriptorSetLayoutSupport          = (PFN_vkGetDescriptorSetLayoutSupport         )pInstance->vkGetDeviceProcAddr(device, "vkGetDescriptorSetLayoutSupport"         );
        // VK_VERSION_1_2
        vkCmdDrawIndirectCount                   = (PFN_vkCmdDrawIndirectCount                  )pInstance->vkGetDeviceProcAddr(device, "vkCmdDrawIndirectCount"                  );
        vkCmdDrawIndexedIndirectCount            = (PFN_vkCmdDrawIndexedIndirectCount           )pInstance->vkGetDeviceProcAddr(device, "vkCmdDrawIndexedIndirectCount"           );
        vkCreateRenderPass2                      = (PFN_vkCreateRenderPass2                     )pInstance->vkGetDeviceProcAddr(device, "vkCreateRenderPass2"                     );
        vkCmdBeginRenderPass2                    = (PFN_vkCmdBeginRenderPass2                   )pInstance->vkGetDeviceProcAddr(device, "vkCmdBeginRenderPass2"                   );
        vkCmdNextSubpass2                        = (PFN_vkCmdNextSubpass2                       )pInstance->vkGetDeviceProcAddr(device, "vkCmdNextSubpass2"                       );
        vkCmdEndRenderPass2                      = (PFN_vkCmdEndRenderPass2                     )pInstance->vkGetDeviceProcAddr(device, "vkCmdEndRenderPass2"                     );
        vkResetQueryPool                         = (PFN_vkResetQueryPool                        )pInstance->vkGetDeviceProcAddr(device, "vkResetQueryPool"                        );
        vkGetSemaphoreCounterValue               = (PFN_vkGetSemaphoreCounterValue              )pInstance->vkGetDeviceProcAddr(device, "vkGetSemaphoreCounterValue"              );
        vkWaitSemaphores                         = (PFN_vkWaitSemaphores                        )pInstance->vkGetDeviceProcAddr(device, "vkWaitSemaphores"                        );
        vkSignalSemaphore                        = (PFN_vkSignalSemaphore                       )pInstance->vkGetDeviceProcAddr(device, "vkSignalSemaphore"                       );
        vkGetBufferDeviceAddress                 = (PFN_vkGetBufferDeviceAddress                )pInstance->vkGetDeviceProcAddr(device, "vkGetBufferDeviceAddress"                );
        vkGetBufferOpaqueCaptureAddress          = (PFN_vkGetBufferOpaqueCaptureAddress         )pInstance->vkGetDeviceProcAddr(device, "vkGetBufferOpaqueCaptureAddress"         );
        vkGetDeviceMemoryOpaqueCaptureAddress    = (PFN_vkGetDeviceMemoryOpaqueCaptureAddress   )pInstance->vkGetDeviceProcAddr(device, "vkGetDeviceMemoryOpaqueCaptureAddress"   );
        // VK_VERSION_1_3
        vkCreatePrivateDataSlot                  = (PFN_vkCreatePrivateDataSlot                 )pInstance->vkGetDeviceProcAddr(device, "vkCreatePrivateDataSlot"                 );
        vkDestroyPrivateDataSlot                 = (PFN_vkDestroyPrivateDataSlot                )pInstance->vkGetDeviceProcAddr(device, "vkDestroyPrivateDataSlot"                );
        vkSetPrivateData                         = (PFN_vkSetPrivateData                        )pInstance->vkGetDeviceProcAddr(device, "vkSetPrivateData"                        );
        vkGetPrivateData                         = (PFN_vkGetPrivateData                        )pInstance->vkGetDeviceProcAddr(device, "vkGetPrivateData"                        );
        vkCmdSetEvent2                           = (PFN_vkCmdSetEvent2                          )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetEvent2"                          );
        vkCmdResetEvent2                         = (PFN_vkCmdResetEvent2                        )pInstance->vkGetDeviceProcAddr(device, "vkCmdResetEvent2"                        );
        vkCmdWaitEvents2                         = (PFN_vkCmdWaitEvents2                        )pInstance->vkGetDeviceProcAddr(device, "vkCmdWaitEvents2"                        );
        vkCmdPipelineBarrier2                    = (PFN_vkCmdPipelineBarrier2                   )pInstance->vkGetDeviceProcAddr(device, "vkCmdPipelineBarrier2"                   );
        vkCmdWriteTimestamp2                     = (PFN_vkCmdWriteTimestamp2                    )pInstance->vkGetDeviceProcAddr(device, "vkCmdWriteTimestamp2"                    );
        vkQueueSubmit2                           = (PFN_vkQueueSubmit2                          )pInstance->vkGetDeviceProcAddr(device, "vkQueueSubmit2"                          );
        vkCmdCopyBuffer2                         = (PFN_vkCmdCopyBuffer2                        )pInstance->vkGetDeviceProcAddr(device, "vkCmdCopyBuffer2"                        );
        vkCmdCopyImage2                          = (PFN_vkCmdCopyImage2                         )pInstance->vkGetDeviceProcAddr(device, "vkCmdCopyImage2"                         );
        vkCmdCopyBufferToImage2                  = (PFN_vkCmdCopyBufferToImage2                 )pInstance->vkGetDeviceProcAddr(device, "vkCmdCopyBufferToImage2"                 );
        vkCmdCopyImageToBuffer2                  = (PFN_vkCmdCopyImageToBuffer2                 )pInstance->vkGetDeviceProcAddr(device, "vkCmdCopyImageToBuffer2"                 );
        vkCmdBlitImage2                          = (PFN_vkCmdBlitImage2                         )pInstance->vkGetDeviceProcAddr(device, "vkCmdBlitImage2"                         );
        vkCmdResolveImage2                       = (PFN_vkCmdResolveImage2                      )pInstance->vkGetDeviceProcAddr(device, "vkCmdResolveImage2"                      );
        vkCmdBeginRendering                      = (PFN_vkCmdBeginRendering                     )pInstance->vkGetDeviceProcAddr(device, "vkCmdBeginRendering"                     );
        vkCmdEndRendering                        = (PFN_vkCmdEndRendering                       )pInstance->vkGetDeviceProcAddr(device, "vkCmdEndRendering"                       );
        vkCmdSetCullMode                         = (PFN_vkCmdSetCullMode                        )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetCullMode"                        );
        vkCmdSetFrontFace                        = (PFN_vkCmdSetFrontFace                       )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetFrontFace"                       );
        vkCmdSetPrimitiveTopology                = (PFN_vkCmdSetPrimitiveTopology               )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetPrimitiveTopology"               );
        vkCmdSetViewportWithCount                = (PFN_vkCmdSetViewportWithCount               )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetViewportWithCount"               );
        vkCmdSetScissorWithCount                 = (PFN_vkCmdSetScissorWithCount                )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetScissorWithCount"                );
        vkCmdBindVertexBuffers2                  = (PFN_vkCmdBindVertexBuffers2                 )pInstance->vkGetDeviceProcAddr(device, "vkCmdBindVertexBuffers2"                 );
        vkCmdSetDepthTestEnable                  = (PFN_vkCmdSetDepthTestEnable                 )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetDepthTestEnable"                 );
        vkCmdSetDepthWriteEnable                 = (PFN_vkCmdSetDepthWriteEnable                )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetDepthWriteEnable"                );
        vkCmdSetDepthCompareOp                   = (PFN_vkCmdSetDepthCompareOp                  )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetDepthCompareOp"                  );
        vkCmdSetDepthBoundsTestEnable            = (PFN_vkCmdSetDepthBoundsTestEnable           )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetDepthBoundsTestEnable"           );
        vkCmdSetStencilTestEnable                = (PFN_vkCmdSetStencilTestEnable               )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetStencilTestEnable"               );
        vkCmdSetStencilOp                        = (PFN_vkCmdSetStencilOp                       )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetStencilOp"                       );
        vkCmdSetRasterizerDiscardEnable          = (PFN_vkCmdSetRasterizerDiscardEnable         )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetRasterizerDiscardEnable"         );
        vkCmdSetDepthBiasEnable                  = (PFN_vkCmdSetDepthBiasEnable                 )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetDepthBiasEnable"                 );
        vkCmdSetPrimitiveRestartEnable           = (PFN_vkCmdSetPrimitiveRestartEnable          )pInstance->vkGetDeviceProcAddr(device, "vkCmdSetPrimitiveRestartEnable"          );
        vkGetDeviceBufferMemoryRequirements      = (PFN_vkGetDeviceBufferMemoryRequirements     )pInstance->vkGetDeviceProcAddr(device, "vkGetDeviceBufferMemoryRequirements"     );
        vkGetDeviceImageMemoryRequirements       = (PFN_vkGetDeviceImageMemoryRequirements      )pInstance->vkGetDeviceProcAddr(device, "vkGetDeviceImageMemoryRequirements"      );
        vkGetDeviceImageSparseMemoryRequirements = (PFN_vkGetDeviceImageSparseMemoryRequirements)pInstance->vkGetDeviceProcAddr(device, "vkGetDeviceImageSparseMemoryRequirements");
        // VK_KHR_swapchain
        vkCreateSwapchainKHR                     = (PFN_vkCreateSwapchainKHR                    )pInstance->vkGetDeviceProcAddr(device, "vkCreateSwapchainKHR"                    );
        vkDestroySwapchainKHR                    = (PFN_vkDestroySwapchainKHR                   )pInstance->vkGetDeviceProcAddr(device, "vkDestroySwapchainKHR"                   );
        vkGetSwapchainImagesKHR                  = (PFN_vkGetSwapchainImagesKHR                 )pInstance->vkGetDeviceProcAddr(device, "vkGetSwapchainImagesKHR"                 );
        vkAcquireNextImageKHR                    = (PFN_vkAcquireNextImageKHR                   )pInstance->vkGetDeviceProcAddr(device, "vkAcquireNextImageKHR"                   );
        vkQueuePresentKHR                        = (PFN_vkQueuePresentKHR                       )pInstance->vkGetDeviceProcAddr(device, "vkQueuePresentKHR"                       );
        vkGetDeviceGroupPresentCapabilitiesKHR   = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR  )pInstance->vkGetDeviceProcAddr(device, "vkGetDeviceGroupPresentCapabilitiesKHR"  );
        vkGetDeviceGroupSurfacePresentModesKHR   = (PFN_vkGetDeviceGroupSurfacePresentModesKHR  )pInstance->vkGetDeviceProcAddr(device, "vkGetDeviceGroupSurfacePresentModesKHR"  );
        vkGetPhysicalDevicePresentRectanglesKHR  = (PFN_vkGetPhysicalDevicePresentRectanglesKHR )pInstance->vkGetDeviceProcAddr(device, "vkGetPhysicalDevicePresentRectanglesKHR" );
        vkAcquireNextImage2KHR                   = (PFN_vkAcquireNextImage2KHR                  )pInstance->vkGetDeviceProcAddr(device, "vkAcquireNextImage2KHR"                  );
        // VK_EXT_debug_utils
        vkSetDebugUtilsObjectNameEXT             = (PFN_vkSetDebugUtilsObjectNameEXT            )pInstance->vkGetDeviceProcAddr(device, "vkSetDebugUtilsObjectNameEXT"            );
        vkSetDebugUtilsObjectTagEXT              = (PFN_vkSetDebugUtilsObjectTagEXT             )pInstance->vkGetDeviceProcAddr(device, "vkSetDebugUtilsObjectTagEXT"             );
        vkQueueBeginDebugUtilsLabelEXT           = (PFN_vkQueueBeginDebugUtilsLabelEXT          )pInstance->vkGetDeviceProcAddr(device, "vkQueueBeginDebugUtilsLabelEXT"          );
        vkQueueEndDebugUtilsLabelEXT             = (PFN_vkQueueEndDebugUtilsLabelEXT            )pInstance->vkGetDeviceProcAddr(device, "vkQueueEndDebugUtilsLabelEXT"            );
        vkQueueInsertDebugUtilsLabelEXT          = (PFN_vkQueueInsertDebugUtilsLabelEXT         )pInstance->vkGetDeviceProcAddr(device, "vkQueueInsertDebugUtilsLabelEXT"         );
        vkCmdBeginDebugUtilsLabelEXT             = (PFN_vkCmdBeginDebugUtilsLabelEXT            )pInstance->vkGetDeviceProcAddr(device, "vkCmdBeginDebugUtilsLabelEXT"            );
        vkCmdEndDebugUtilsLabelEXT               = (PFN_vkCmdEndDebugUtilsLabelEXT              )pInstance->vkGetDeviceProcAddr(device, "vkCmdEndDebugUtilsLabelEXT"              );
        vkCmdInsertDebugUtilsLabelEXT            = (PFN_vkCmdInsertDebugUtilsLabelEXT           )pInstance->vkGetDeviceProcAddr(device, "vkCmdInsertDebugUtilsLabelEXT"           );
        return result;
    }

    void Device::Destroy(const VkAllocationCallbacks *pAllocator)
    {
        vkDestroyDevice(device, pAllocator);
    }

    void Device::GetQueue(uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue)
    {
        return vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
    }

    VkResult Device::QueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence)
    {
        return vkQueueSubmit(queue, submitCount, pSubmits, fence);
    }

    VkResult Device::QueueWaitIdle(VkQueue queue)
    {
        return vkQueueWaitIdle(queue);
    }

    VkResult Device::WaitIdle()
    {
        return vkDeviceWaitIdle(device);
    }

    VkResult Device::AllocateMemory(const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory)
    {
        return vkAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
    }

    void Device::FreeMemory(VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator)
    {
        return vkFreeMemory(device, memory, pAllocator);
    }

    VkResult Device::MapMemory(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData)
    {
        return vkMapMemory(device, memory, offset, size, flags, ppData);
    }

    void Device::UnmapMemory(VkDeviceMemory memory)
    {
        return vkUnmapMemory(device, memory);
    }

    VkResult Device::FlushMappedMemoryRanges(uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges)
    {
        return vkFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    }

    VkResult Device::InvalidateMappedMemoryRanges(uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges)
    {
        return vkInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    }

    void Device::GetDeviceMemoryCommitment(VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes)
    {
        return vkGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
    }

    VkResult Device::BindBufferMemory(VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset)
    {
        return vkBindBufferMemory(device, buffer, memory, memoryOffset);
    }

    VkResult Device::BindImageMemory(VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset)
    {
        return vkBindImageMemory(device, image, memory, memoryOffset);
    }

    void Device::GetBufferMemoryRequirements(VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements)
    {
        return vkGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
    }

    void Device::GetImageMemoryRequirements(VkImage image, VkMemoryRequirements* pMemoryRequirements)
    {
        return vkGetImageMemoryRequirements(device, image, pMemoryRequirements);
    }

    void Device::GetImageSparseMemoryRequirements(VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements)
    {
        return vkGetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    }

    VkResult Device::QueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence)
    {
        return vkQueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
    }

    VkResult Device::CreateFence(const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence)
    {
        return vkCreateFence(device, pCreateInfo, pAllocator, pFence);
    }

    void Device::DestroyFence(VkFence fence, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroyFence(device, fence, pAllocator);
    }

    VkResult Device::ResetFences(uint32_t fenceCount, const VkFence* pFences)
    {
        return vkResetFences(device, fenceCount, pFences);
    }

    VkResult Device::GetFenceStatus(VkFence fence)
    {
        return vkGetFenceStatus(device, fence);
    }

    VkResult Device::WaitForFences(uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout)
    {
        return vkWaitForFences(device, fenceCount, pFences, waitAll, timeout);
    }

    VkResult Device::CreateSemaphore(const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore)
    {
        return vkCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
    }

    VkResult Device::CreateSemaphore(VkSemaphoreType semaphoreType, uint64_t initialValue, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore)
    {
        VkSemaphoreTypeCreateInfo stci ={ VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO, nullptr, semaphoreType, initialValue };
        VkSemaphoreCreateInfo ci ={ VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO, &stci, 0 };
        return CreateSemaphore(&ci, pAllocator, pSemaphore);
    }

    void Device::DestroySemaphore(VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroySemaphore(device, semaphore, pAllocator);
    }

    VkResult Device::CreateEvent(const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent)
    {
        return vkCreateEvent(device, pCreateInfo, pAllocator, pEvent);
    }

    void Device::DestroyEvent(VkEvent event, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroyEvent(device, event, pAllocator);
    }

    VkResult Device::GetEventStatus(VkEvent event)
    {
        return vkGetEventStatus(device, event);
    }

    VkResult Device::SetEvent(VkEvent event)
    {
        return vkSetEvent(device, event);
    }

    VkResult Device::ResetEvent(VkEvent event)
    {
        return vkResetEvent(device, event);
    }

    VkResult Device::CreateQueryPool(const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool)
    {
        return vkCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
    }

    void Device::DestroyQueryPool(VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroyQueryPool(device, queryPool, pAllocator);
    }

    VkResult Device::GetQueryPoolResults(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags)
    {
        return vkGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    }

    VkResult Device::CreateBuffer(const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer)
    {
        return vkCreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
    }

    void Device::DestroyBuffer(VkBuffer buffer, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroyBuffer(device, buffer, pAllocator);
    }

    VkResult Device::CreateBufferView(const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView)
    {
        return vkCreateBufferView(device, pCreateInfo, pAllocator, pView);
    }

    void Device::DestroyBufferView(VkBufferView bufferView, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroyBufferView(device, bufferView, pAllocator);
    }

    VkResult Device::CreateImage(const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage)
    {
        return vkCreateImage(device, pCreateInfo, pAllocator, pImage);
    }

    void Device::DestroyImage(VkImage image, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroyImage(device, image, pAllocator);
    }

    void Device::GetImageSubresourceLayout(VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout)
    {
        return vkGetImageSubresourceLayout(device, image, pSubresource, pLayout);
    }

    VkResult Device::CreateImageView(const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView)
    {
        return vkCreateImageView(device, pCreateInfo, pAllocator, pView);
    }

    void Device::DestroyImageView(VkImageView imageView, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroyImageView(device, imageView, pAllocator);
    }

    VkResult Device::CreateShaderModule(const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule)
    {
        return vkCreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);
    }

    void Device::DestroyShaderModule(VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroyShaderModule(device, shaderModule, pAllocator);
    }

    VkResult Device::CreatePipelineCache(const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache)
    {
        return vkCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
    }

    void Device::DestroyPipelineCache(VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroyPipelineCache(device, pipelineCache, pAllocator);
    }

    VkResult Device::GetPipelineCacheData(VkPipelineCache pipelineCache, size_t* pDataSize, void* pData)
    {
        return vkGetPipelineCacheData(device, pipelineCache, pDataSize, pData);
    }

    VkResult Device::MergePipelineCaches(VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches)
    {
        return vkMergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);
    }

    VkResult Device::CreateGraphicsPipelines(VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines)
    {
        return vkCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    }

    VkResult Device::CreateComputePipelines(VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines)
    {
        return vkCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    }

    void Device::DestroyPipeline(VkPipeline pipeline, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroyPipeline(device, pipeline, pAllocator);
    }

    VkResult Device::CreatePipelineLayout(const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout)
    {
        return vkCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);
    }

    void Device::DestroyPipelineLayout(VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroyPipelineLayout(device, pipelineLayout, pAllocator);
    }

    VkResult Device::CreateSampler(const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler)
    {
        return vkCreateSampler(device, pCreateInfo, pAllocator, pSampler);
    }

    void Device::DestroySampler(VkSampler sampler, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroySampler(device, sampler, pAllocator);
    }

    VkResult Device::CreateDescriptorSetLayout(const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout)
    {
        return vkCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
    }

    void Device::DestroyDescriptorSetLayout(VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
    }

    VkResult Device::CreateDescriptorPool(const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool)
    {
        return vkCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
    }

    void Device::DestroyDescriptorPool(VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroyDescriptorPool(device, descriptorPool, pAllocator);
    }

    VkResult Device::ResetDescriptorPool(VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags)
    {
        return vkResetDescriptorPool(device, descriptorPool, flags);
    }

    VkResult Device::AllocateDescriptorSets(const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets)
    {
        return vkAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
    }

    VkResult Device::FreeDescriptorSets(VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets)
    {
        return vkFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
    }

    void Device::UpdateDescriptorSets(uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies)
    {
        return vkUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
    }

    VkResult Device::CreateFramebuffer(const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer)
    {
        return vkCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
    }

    void Device::DestroyFramebuffer(VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroyFramebuffer(device, framebuffer, pAllocator);
    }

    VkResult Device::CreateRenderPass(const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass)
    {
        return vkCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
    }

    void Device::DestroyRenderPass(VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroyRenderPass(device, renderPass, pAllocator);
    }

    void Device::GetRenderAreaGranularity(VkRenderPass renderPass, VkExtent2D* pGranularity)
    {
        return vkGetRenderAreaGranularity(device, renderPass, pGranularity);
    }

    VkResult Device::CreateCommandPool(const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool)
    {
        return vkCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
    }

    void Device::DestroyCommandPool(VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroyCommandPool(device, commandPool, pAllocator);
    }

    VkResult Device::ResetCommandPool(VkCommandPool commandPool, VkCommandPoolResetFlags flags)
    {
        return vkResetCommandPool(device, commandPool, flags);
    }

    VkResult Device::AllocateCommandBuffers(const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers)
    {
        return vkAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
    }

    void Device::FreeCommandBuffers(VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers)
    {
        return vkFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
    }

    VkResult Device::BeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo)
    {
        return vkBeginCommandBuffer(commandBuffer, pBeginInfo);
    }

    VkResult Device::EndCommandBuffer(VkCommandBuffer commandBuffer)
    {
        return vkEndCommandBuffer(commandBuffer);
    }

    VkResult Device::ResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags)
    {
        return vkResetCommandBuffer(commandBuffer, flags);
    }

    void Device::CmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline)
    {
        return vkCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
    }

    void Device::CmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports)
    {
        return vkCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
    }

    void Device::CmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors)
    {
        return vkCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
    }

    void Device::CmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth)
    {
        return vkCmdSetLineWidth(commandBuffer, lineWidth);
    }

    void Device::CmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor)
    {
        return vkCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    }

    void Device::CmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4])
    {
        return vkCmdSetBlendConstants(commandBuffer, blendConstants);
    }

    void Device::CmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds)
    {
        return vkCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
    }

    void Device::CmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask)
    {
        return vkCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
    }

    void Device::CmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask)
    {
        return vkCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
    }

    void Device::CmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference)
    {
        return vkCmdSetStencilReference(commandBuffer, faceMask, reference);
    }

    void Device::CmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets)
    {
        return vkCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
    }

    void Device::CmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType)
    {
        return vkCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
    }

    void Device::CmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets)
    {
        return vkCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    }

    void Device::CmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance)
    {
        return vkCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    }

    void Device::CmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance)
    {
        return vkCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    }

    void Device::CmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
    {
        return vkCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    }

    void Device::CmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
    {
        return vkCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    }

    void Device::CmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
    {
        return vkCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
    }

    void Device::CmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset)
    {
        return vkCmdDispatchIndirect(commandBuffer, buffer, offset);
    }

    void Device::CmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions)
    {
        return vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    }

    void Device::CmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions)
    {
        return vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    }

    void Device::CmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter)
    {
        return vkCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
    }

    void Device::CmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions)
    {
        return vkCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    }

    void Device::CmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions)
    {
        return vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    }

    void Device::CmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData)
    {
        return vkCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    }

    void Device::CmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data)
    {
        return vkCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    }

    void Device::CmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges)
    {
        return vkCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    }

    void Device::CmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges)
    {
        return vkCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    }

    void Device::CmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects)
    {
        return vkCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    }

    void Device::CmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions)
    {
        return vkCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    }

    void Device::CmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask)
    {
        return vkCmdSetEvent(commandBuffer, event, stageMask);
    }

    void Device::CmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask)
    {
        return vkCmdResetEvent(commandBuffer, event, stageMask);
    }

    void Device::CmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)
    {
        return vkCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    }

    void Device::CmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)
    {
        return vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    }

    void Device::CmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags)
    {
        return vkCmdBeginQuery(commandBuffer, queryPool, query, flags);
    }

    void Device::CmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query)
    {
        return vkCmdEndQuery(commandBuffer, queryPool, query);
    }

    void Device::CmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)
    {
        return vkCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
    }

    void Device::CmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query)
    {
        return vkCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
    }

    void Device::CmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags)
    {
        return vkCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
    }

    void Device::CmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues)
    {
        return vkCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
    }

    void Device::CmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents)
    {
        return vkCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
    }

    void Device::CmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents)
    {
        return vkCmdNextSubpass(commandBuffer, contents);
    }

    void Device::CmdEndRenderPass(VkCommandBuffer commandBuffer)
    {
        return vkCmdEndRenderPass(commandBuffer);
    }

    void Device::CmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers)
    {
        return vkCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
    }

    VkResult Device::BindBufferMemory2(uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos)
    {
        return vkBindBufferMemory2(device, bindInfoCount, pBindInfos);
    }

    VkResult Device::BindImageMemory2(uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos)
    {
        return vkBindImageMemory2(device, bindInfoCount, pBindInfos);
    }

    void Device::GetDeviceGroupPeerMemoryFeatures(uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures)
    {
        return vkGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
    }

    void Device::CmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask)
    {
        return vkCmdSetDeviceMask(commandBuffer, deviceMask);
    }

    void Device::CmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
    {
        return vkCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    }

    void Device::GetImageMemoryRequirements2(const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements)
    {
        return vkGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
    }

    void Device::GetBufferMemoryRequirements2(const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements)
    {
        return vkGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
    }

    void Device::GetImageSparseMemoryRequirements2(const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements)
    {
        return vkGetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    }

    void Device::TrimCommandPool(VkCommandPool commandPool, VkCommandPoolTrimFlags flags)
    {
        return vkTrimCommandPool(device, commandPool, flags);
    }

    void Device::GetQueue2(const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue)
    {
        return vkGetDeviceQueue2(device, pQueueInfo, pQueue);
    }

    VkResult Device::CreateSamplerYcbcrConversion(const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion)
    {
        return vkCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);
    }

    void Device::DestroySamplerYcbcrConversion(VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);
    }

    VkResult Device::CreateDescriptorUpdateTemplate(const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate)
    {
        return vkCreateDescriptorUpdateTemplate(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    }

    void Device::DestroyDescriptorUpdateTemplate(VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);
    }

    void Device::UpdateDescriptorSetWithTemplate(VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData)
    {
        return vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
    }

    void Device::GetDescriptorSetLayoutSupport(const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport)
    {
        return vkGetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);
    }

    void Device::CmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
    {
        return vkCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    void Device::CmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
    {
        return vkCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    VkResult Device::CreateRenderPass2(const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass)
    {
        return vkCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass);
    }

    void Device::CmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo)
    {
        return vkCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    }

    void Device::CmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo)
    {
        return vkCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    }

    void Device::CmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo)
    {
        return vkCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
    }

    void Device::ResetQueryPool(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)
    {
        return vkResetQueryPool(device, queryPool, firstQuery, queryCount);
    }

    VkResult Device::GetSemaphoreCounterValue(VkSemaphore semaphore, uint64_t* pValue)
    {
        return vkGetSemaphoreCounterValue(device, semaphore, pValue);
    }

    VkResult Device::WaitSemaphores(const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout)
    {
        return vkWaitSemaphores(device, pWaitInfo, timeout);
    }

    VkResult Device::SignalSemaphore(const VkSemaphoreSignalInfo* pSignalInfo)
    {
        return vkSignalSemaphore(device, pSignalInfo);
    }

    VkDeviceAddress Device::GetBufferDeviceAddress(const VkBufferDeviceAddressInfo* pInfo)
    {
        return vkGetBufferDeviceAddress(device, pInfo);
    }

    VkDeviceAddress Device::GetBufferOpaqueCaptureAddress(const VkBufferDeviceAddressInfo* pInfo)
    {
        return vkGetBufferOpaqueCaptureAddress(device, pInfo);
    }

    VkDeviceAddress Device::GetDeviceMemoryOpaqueCaptureAddress(const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo)
    {
        return vkGetDeviceMemoryOpaqueCaptureAddress(device, pInfo);
    }

    VkResult Device::CreatePrivateDataSlot(const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot)
    {
        return vkCreatePrivateDataSlot(device, pCreateInfo, pAllocator, pPrivateDataSlot);
    }

    void Device::DestroyPrivateDataSlot(VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroyPrivateDataSlot(device, privateDataSlot, pAllocator);
    }

    VkResult Device::SetPrivateData(VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data)
    {
        return vkSetPrivateData(device, objectType, objectHandle, privateDataSlot, data);
    }

    void Device::GetPrivateData(VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData)
    {
        return vkGetPrivateData(device, objectType, objectHandle, privateDataSlot, pData);
    }

    void Device::CmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo)
    {
        return vkCmdSetEvent2(commandBuffer, event, pDependencyInfo);
    }

    void Device::CmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask)
    {
        return vkCmdResetEvent2(commandBuffer, event, stageMask);
    }

    void Device::CmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos)
    {
        return vkCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
    }

    void Device::CmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo)
    {
        return vkCmdPipelineBarrier2(commandBuffer, pDependencyInfo);
    }

    void Device::CmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query)
    {
        return vkCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
    }

    VkResult Device::QueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence)
    {
        return vkQueueSubmit2(queue, submitCount, pSubmits, fence);
    }

    void Device::CmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo)
    {
        return vkCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
    }

    void Device::CmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo)
    {
        return vkCmdCopyImage2(commandBuffer, pCopyImageInfo);
    }

    void Device::CmdCopyBufferToImage2(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)
    {
        return vkCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
    }

    void Device::CmdCopyImageToBuffer2(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)
    {
        return vkCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
    }

    void Device::CmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo)
    {
        return vkCmdBlitImage2(commandBuffer, pBlitImageInfo);
    }

    void Device::CmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo)
    {
        return vkCmdResolveImage2(commandBuffer, pResolveImageInfo);
    }

    void Device::CmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo)
    {
        return vkCmdBeginRendering(commandBuffer, pRenderingInfo);
    }

    void Device::CmdEndRendering(VkCommandBuffer commandBuffer)
    {
        return vkCmdEndRendering(commandBuffer);
    }

    void Device::CmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode)
    {
        return vkCmdSetCullMode(commandBuffer, cullMode);
    }

    void Device::CmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace)
    {
        return vkCmdSetFrontFace(commandBuffer, frontFace);
    }

    void Device::CmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology)
    {
        return vkCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
    }

    void Device::CmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports)
    {
        return vkCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
    }

    void Device::CmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors)
    {
        return vkCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
    }

    void Device::CmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides)
    {
        return vkCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
    }

    void Device::CmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable)
    {
        return vkCmdSetDepthTestEnable(commandBuffer, depthTestEnable);
    }

    void Device::CmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable)
    {
        return vkCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
    }

    void Device::CmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp)
    {
        return vkCmdSetDepthCompareOp(commandBuffer, depthCompareOp);
    }

    void Device::CmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable)
    {
        return vkCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
    }

    void Device::CmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable)
    {
        return vkCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
    }

    void Device::CmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp)
    {
        return vkCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    }

    void Device::CmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable)
    {
        return vkCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
    }

    void Device::CmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable)
    {
        return vkCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
    }

    void Device::CmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable)
    {
        return vkCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
    }

    void Device::GetDeviceBufferMemoryRequirements(const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements)
    {
        return vkGetDeviceBufferMemoryRequirements(device, pInfo, pMemoryRequirements);
    }

    void Device::GetDeviceImageMemoryRequirements(const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements)
    {
        return vkGetDeviceImageMemoryRequirements(device, pInfo, pMemoryRequirements);
    }

    void Device::GetDeviceImageSparseMemoryRequirements(const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements)
    {
        return vkGetDeviceImageSparseMemoryRequirements(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    }

    VkResult Device::CreateSwapchain(const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain)
    {
        return vkCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
    }

    void Device::DestroySwapchain(VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator)
    {
        return vkDestroySwapchainKHR(device, swapchain, pAllocator);
    }

    VkResult Device::GetSwapchainImages(VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages)
    {
        return vkGetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
    }

    VkResult Device::AcquireNextImage(VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex)
    {
        return vkAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
    }

    VkResult Device::QueuePresent(VkQueue queue, const VkPresentInfoKHR* pPresentInfo)
    {
        return vkQueuePresentKHR(queue, pPresentInfo);
    }

    VkResult Device::GetDeviceGroupPresentCapabilities(VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities)
    {
        return vkGetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);
    }

    VkResult Device::GetDeviceGroupSurfacePresentModes(VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes)
    {
        return vkGetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);
    }

    VkResult Device::GetPhysicalDevicePresentRectangles(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects)
    {
        return vkGetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects);
    }

    VkResult Device::AcquireNextImage2(const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex)
    {
        return vkAcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);
    }

    VkResult Device::SetDebugUtilsObjectName(const VkDebugUtilsObjectNameInfoEXT* pNameInfo)
    {
        return vkSetDebugUtilsObjectNameEXT(device, pNameInfo);
    }

    VkResult Device::SetDebugUtilsObjectTag(const VkDebugUtilsObjectTagInfoEXT* pTagInfo)
    {
        return vkSetDebugUtilsObjectTagEXT(device, pTagInfo);
    }

    void Device::QueueBeginDebugUtilsLabel(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo)
    {
        return vkQueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
    }

    void Device::QueueEndDebugUtilsLabel(VkQueue queue)
    {
        return vkQueueEndDebugUtilsLabelEXT(queue);
    }

    void Device::QueueInsertDebugUtilsLabel(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo)
    {
        return vkQueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
    }

    void Device::CmdBeginDebugUtilsLabel(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo)
    {
        return vkCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    }

    void Device::CmdEndDebugUtilsLabel(VkCommandBuffer commandBuffer)
    {
        return vkCmdEndDebugUtilsLabelEXT(commandBuffer);
    }

    void Device::CmdInsertDebugUtilsLabel(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo)
    {
        return vkCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    }

    VkResult Device::CreateImage(const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Image* pImage)
    {
        VkResult result;
        result = CreateImage(pCreateInfo, pAllocator, &pImage->image);
        if (result != VK_SUCCESS) return result;
        pImage->format = pCreateInfo->format;
        pImage->extent = pCreateInfo->extent;
        pImage->levels = pCreateInfo->mipLevels;
        pImage->layers = pCreateInfo->arrayLayers;
        return result;
    }

    VkResult Device::CreateCommandPool(VkCommandPoolCreateFlags flags, uint32_t queueFamilyIndex, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool)
    {
        VkCommandPoolCreateInfo ci ={ VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO, nullptr, flags, queueFamilyIndex };
        return CreateCommandPool(&ci, pAllocator, pCommandPool);
    }

    VkResult Device::BeginCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferUsageFlags flags)
    {
        VkCommandBufferBeginInfo cbbi ={ VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, flags, nullptr };
        return BeginCommandBuffer(commandBuffer, &cbbi);
    }

    VkResult Device::AllocateCommandBuffers(VkCommandPool commandPool, VkCommandBufferLevel level, uint32_t commandBufferCount, VkCommandBuffer* pCommandBuffers)
    {
        VkCommandBufferAllocateInfo cbai ={ VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO, nullptr, commandPool, level, commandBufferCount };
        return AllocateCommandBuffers(&cbai, pCommandBuffers);
    }

}
