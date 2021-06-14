#include <dt/render/gpu/util/result_to_string.hh>

std::string dt::vk_result_to_string(VkResult const& result) noexcept {
  switch (result) {
    case VK_ERROR_OUT_OF_DEVICE_MEMORY:                         return "\"Out of device memory\"";
    case VK_ERROR_INITIALIZATION_FAILED:                        return "\"Initialization failed\"";
    case VK_ERROR_DEVICE_LOST:                                  return "\"Device lost\"";
    case VK_ERROR_MEMORY_MAP_FAILED:                            return "\"Memory map failed\"";
    case VK_ERROR_LAYER_NOT_PRESENT:                            return "\"Layer not present\"";
    case VK_ERROR_EXTENSION_NOT_PRESENT:                        return "\"Extension not present\"";
    case VK_ERROR_FEATURE_NOT_PRESENT:                          return "\"Feature not present\"";
    case VK_ERROR_INCOMPATIBLE_DRIVER:                          return "\"Incompatible driver\"";
    case VK_ERROR_TOO_MANY_OBJECTS:                             return "\"Too many objects\"";
    case VK_ERROR_FORMAT_NOT_SUPPORTED:                         return "\"Format not supported\"";
    case VK_ERROR_FRAGMENTED_POOL:                              return "\"Fragmented pool\"";
    case VK_ERROR_UNKNOWN:                                      return "\"Unknown error\"";
    case VK_ERROR_OUT_OF_POOL_MEMORY:                           return "\"Out of pool memory\"";
    case VK_ERROR_INVALID_EXTERNAL_HANDLE:                      return "\"Invalid external handle\"";
    case VK_ERROR_FRAGMENTATION:                                return "\"Fragmentation\"";
    case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS:               return "\"Invalid opaque capture address\"";
    case VK_ERROR_SURFACE_LOST_KHR:                             return "\"Surface lost\"";
    case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR:                     return "\"Native window in use\"";
    case VK_ERROR_OUT_OF_DATE_KHR:                              return "\"Out of date\"";
    case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR:                     return "\"Incompatible display\"";
    case VK_ERROR_VALIDATION_FAILED_EXT:                        return "\"Validation failed\"";
    case VK_ERROR_INVALID_SHADER_NV:                            return "\"Invalid shader\"";
    case VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT: return "\"Invalid DRM format modifier plane layout extension\"";
    case VK_ERROR_NOT_PERMITTED_EXT:                            return "\"Error not permitted\"";
    case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT:          return "\"Full screen exclusive mode lost\"";
    default:                                                    return "\"Undefined error\"";
  }
}
