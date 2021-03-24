#include <dt/gpu.hh>

dt::gpu::gpu(cmd const& c, fs const& f)
: _log(f.root().mkdir("log").cd("log"), "vulkan.txt"),
  _instance(c, f),
  _devices(_instance, c, f) {}

dt::gpu::~gpu() noexcept {}

dt::vk_logical_device dt::gpu::create_logical_device(vk_physical_device const& physical_device, vk_device_queue_request_list_t const& requested_queues) const {
  return _devices.create_device(physical_device, requested_queues);
}
