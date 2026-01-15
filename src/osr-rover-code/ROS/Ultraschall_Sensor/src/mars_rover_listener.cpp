#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/bool.hpp"

class MarsRoverListener : public rclcpp::Node {
public:
    MarsRoverListener() : Node("mars_rover_listener") {
        subscription_ = this->create_subscription<std_msgs::msg::Bool>(
            "too_close", 10,
            std::bind(&MarsRoverListener::topic_callback, this, std::placeholders::_1));
    }

private:
    void topic_callback(const std_msgs::msg::Bool::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "TooClose: %s", msg->data ? "true" : "false");
    }

    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr subscription_;
};
int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);  // ROS2 initialisieren
    auto node = std::make_shared<MarsRoverListener>();
    rclcpp::spin(node);        // Node laufen lassen
    rclcpp::shutdown();
    return 0;
}
