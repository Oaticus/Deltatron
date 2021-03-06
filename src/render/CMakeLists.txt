add_library("render")

target_link_libraries(render
  PRIVATE
    "buildinfo"
    "math"
    "command"
    "filesystem"
    "json"
    "Vulkan::Vulkan")

target_include_directories(render
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/private"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources(render
  PRIVATE
    "include/private/dt/render/gpu/util/result_to_string.hh"
    "src/render/gpu/util/result_to_string.cc"

    "include/public/dt/render/error.hh"
    "src/render/error.cc"

    "include/private/dt/render/gpu/physical_devices.hh"
    "src/render/gpu/physical_devices.cc"

    "include/private/dt/render/gpu/instance.hh"
    "src/render/gpu/instance.cc"

    "include/private/dt/render/gpu.hh"

    "include/private/dt/render/config.hh"
    "src/render/config.cc"

    "include/private/dt/render_imp.hh"
    "include/public/dt/render.hh"
    "src/render.cc")
