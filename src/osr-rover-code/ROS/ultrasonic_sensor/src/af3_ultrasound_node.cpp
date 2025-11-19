#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/bool.hpp"

extern "C" {
#include "af3_ultrasound_wrapper.h"
}

using namespace std::chrono_literals;

class AF3UltrasoundNode : public rclcpp::Node {
public:
    AF3UltrasoundNode()
    : Node("af3_ultrasound_node"), distance_(999.0f)
    {
        af3_ultrasound_init();

        distance_sub_ = this->create_subscription<std_msgs::msg::Float32>(
            "/sim/ultrasound/distance",   // Topic aus Gazebo (ggf. anpassen/remappen)
            10,
            [this](std_msgs::msg::Float32::SharedPtr msg) {
                distance_ = msg->data;
            }
        );

        too_close_pub_ = this->create_publisher<std_msgs::msg::Bool>(
            "/rover/ultrasound/too_close",
            10
        );

        timer_ = this->create_wall_timer(
            50ms, std::bind(&AF3UltrasoundNode::step, this)
        );
    }

private:
    void step() {
        bool too_close = af3_ultrasound_step(true, distance_);
        auto msg = std_msgs::msg::Bool();
        msg.data = too_close;
        too_close_pub_->publish(msg);
    }

    float distance_;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr distance_sub_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr too_close_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<AF3UltrasoundNode>());
    rclcpp::shutdown();
    return 0;
}