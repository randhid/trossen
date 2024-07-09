#include "trossen_arm.hpp"

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>

#include <grpcpp/support/status.h>

#include <viam/sdk/components/arm/arm.hpp>
#include <viam/sdk/components/component.hpp>
#include <viam/sdk/config/resource.hpp>
#include <viam/sdk/resource/resource.hpp>

namespace viam{
namespace trossen{


bool TrossenArm::is_moving() {
    return false;
}

sdk::AttributeMap TrossenArm::do_command(const AttributeMap& command) {
    std::cout << "Received DoCommand request for MyBase " << Resource::name() << std::endl;
    return command;
}

// Unimplemented methods
sdk::Arm::

}  // namespace realsense
}  // namespace viam