#include <dt/render/gpu/util/result_to_string.hh>

std::string dt::vk_result_to_string(VkResult const& result) noexcept {
  switch (result) {
    case VK_ERROR_OUT_OF_DEVICE_MEMORY:                         return "\"out of device memory\"";
    case VK_ERROR_INITIALIZATION_FAILED:                        return "\"initialization failed\"";
    case VK_ERROR_DEVICE_LOST:                                  return "\"device lost\"";
    case VK_ERROR_MEMORY_MAP_FAILED:                            return "\"memory map failed\"";
    case VK_ERROR_LAYER_NOT_PRESENT:                            return "\"layer not present\"";
    case VK_ERROR_EXTENSION_NOT_PRESENT:                        return "\"extension not present\"";
    case VK_ERROR_FEATURE_NOT_PRESENT:                          return "\"feature not present\"";
    case VK_ERROR_INCOMPATIBLE_DRIVER:                          return "\"incompatible driver\"";
    case VK_ERROR_TOO_MANY_OBJECTS:                             return "\"too many objects\"";
    case VK_ERROR_FORMAT_NOT_SUPPORTED:                         return "\"format not supported\"";
    case VK_ERROR_FRAGMENTED_POOL:                              return "\"fragmented pool\"";
    case VK_ERROR_UNKNOWN:                                      return "\"unknown error\"";
    case VK_ERROR_OUT_OF_POOL_MEMORY:                           return "\"out of pool memory\"";
    case VK_ERROR_INVALID_EXTERNAL_HANDLE:                      return "\"invalid external handle\"";
    case VK_ERROR_FRAGMENTATION:                                return "\"fragmentation\"";
    case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS:               return "\"invalid opaque capture address\"";
    case VK_ERROR_SURFACE_LOST_KHR:                             return "\"surface lost\"";
    case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR:                     return "\"native window in use\"";
    case VK_ERROR_OUT_OF_DATE_KHR:                              return "\"out of date\"";
    case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR:                     return "\"incompatible display\"";
    case VK_ERROR_VALIDATION_FAILED_EXT:                        return "\"validation failed\"";
    case VK_ERROR_INVALID_SHADER_NV:                            return "\"invalid shader\"";
    case VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT: return "\"invalid DRM format modifier plane layout extension\"";
    case VK_ERROR_NOT_PERMITTED_EXT:                            return "\"error not permitted\"";
    case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT:          return "\"full screen exclusive mode lost\"";
    default:                                                    return "\"unknown error\"";
  }
}
