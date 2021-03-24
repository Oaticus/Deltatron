add_library("gpu")

find_package("Vulkan")

if (NOT ${VULKAN_FOUND})
  message("Could not locate Vulkan library. Did you set the VULKAN_SDK environment variable?")
endif()

target_link_libraries(gpu
  PRIVATE
    buildinfo
    cmd
    fs
    json
  PUBLIC
    log
    Vulkan::Vulkan)

target_include_directories(gpu
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_sources(gpu
  PRIVATE
    "include/dt/gpu/util/function_lookup.hh"

    "include/dt/gpu/devices/logical_device/queue_info/requested_queues.hh"

    "include/dt/gpu/devices/logical_device/queue_info/priorities.hh"
    "src/gpu/devices/logical_device/queue_info/priorities.cc"

    "include/dt/gpu/devices/logical_device/queue_info.hh"
    "src/gpu/devices/logical_device/queue_info.cc"

    "include/dt/gpu/devices/logical_device.hh"
    "src/gpu/devices/logical_device.cc"

    "include/dt/gpu/devices/physical_device.hh"
    "src/gpu/devices/physical_device.cc"

    "include/dt/gpu/devices.hh"
    "src/gpu/devices.cc"

    "include/dt/gpu/instance/validation_layers.hh"
    "src/gpu/instance/validation_layers.cc"

    "include/dt/gpu/instance.hh"
    "src/gpu/instance.cc"

    "include/dt/gpu/error.hh"
    "src/gpu/error.cc"

    "include/dt/gpu.hh"
    "src/gpu.cc")
