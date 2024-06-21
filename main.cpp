#include <memory>
#include <signal.h>

#include <boost/log/trivial.hpp>
#include <grpcpp/grpcpp.h>
#include <grpcpp/server_context.h>


#include <viam/api/common/v1/common.grpc.pb.h>
#include <viam/api/component/generic/v1/generic.grpc.pb.h>
#include <viam/api/robot/v1/robot.pb.h>

#include <viam/sdk/components/arm/arm.hpp>
#include <viam/sdk/components/component.hpp>
#include <viam/sdk/config/resource.hpp>
#include <viam/sdk/module/module.hpp>
#include <viam/sdk/module/service.hpp>
#include <viam/sdk/registry/registry.hpp>
#include <viam/sdk/resource/resource.hpp>
#include <viam/sdk/rpc/dial.hpp>
#include <viam/sdk/rpc/server.hpp>

#include "trossen.hpp"

using namespace viam::sdk;

int main(int argc, char** argv) {
    API arm_api = Arm::static_api();
    Model arm_model("rand", "trossen", "arm");
    

    std::shared_ptr<ModelRegistration> trossen_arm = std::make_shared<ModelRegistration>(
        arm_api,
        arm_model,
        [](Dependencies deps, ResourceConfig cfg) { return std::make_unique<TrossenArm>(deps, cfg); },
        TrossenArm::validate);

    std::vector<std::shared_ptr<ModelRegistration>> mrs = {trossen_arm};
    auto my_mod = std::make_shared<ModuleService>(argc, argv, mrs);
    my_mod->serve();

    return EXIT_SUCCESS;
};