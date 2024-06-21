#pragma once

#include <viam/sdk/components/arm/arm.hpp>
#include <viam/sdk/components/component.hpp>
#include <viam/sdk/config/resource.hpp>
#include <viam/sdk/resource/resource.hpp>

using namespace viam::sdk;

namespace viam {
namespace trossen {

class TrossenArm : public Arm {
    public : 
    TrossenArm(Dependencies deps, ResourceConfig cfg) : Arm(cfg.name()) {
        this ->reconfigure(deps, cfg)
    };
    void reconfigure(Dependencies deps, ResourceConfig cfg) override;
    static std::vector<std::string> validate(ResourceConfig cfg);

    bool is_moving() override;
    void stop(const AttributeMap& extra) override;

    AttributeMap do_command(const AttributeMap& command) override;
    std::vector<GeometryConfig> get_geometries(const AttributeMap& extra) override;

    void move_to_joint_positions(const std::vector<double>& positions,
                                         const AttributeMap& extra) override;
    
    void move_to_joint_positions(const std::vector<double>& positions,
                                         const AttributeMap& extra) override;
    
    sdk::Arm::KinematicsData get_kinematics(const AttributeMap& extra) override;
    
    void get_end_position(const AttributeMap& extra) override {
        throw std::runtime_error("get_end_position unimplemented");
    }
    void move_to_position(const pose& pose, const AttributeMap& extra) override {
        throw std::runtime_error("move_to_position unimplemented");
    }
};

}  // namespace trossen
}  // namespace viam