#include <chrono>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/u_int8.hpp"

extern "C" {
#include "status_controller.h"
}

using namespace std::chrono_literals;

static std::string status_to_string(StatusEnum s)
{
  switch (s) {
    case STATUS_IDLE:     return "IDLE";
    case STATUS_DRIVING:  return "DRIVING";
    case STATUS_ERROR:    return "ERROR";
    case STATUS_MANUAL:   return "MANUAL";
    case STATUS_AUTONOMY: return "AUTONOMY";
    default:              return "UNKNOWN";
  }
}

class AfStatusAdapterNode : public rclcpp::Node
{
public:
  AfStatusAdapterNode()
  : Node("af_status_adapter")
  {
    this->declare_parameter<double>("rate_hz", 10.0);

    pub_status_ =
      this->create_publisher<std_msgs::msg::String>(
        "/rover/status", 10);

    sub_cmd_ =
      this->create_subscription<std_msgs::msg::UInt8>(
        "/rover/status_cmd", 10,
        [this](const std_msgs::msg::UInt8::SharedPtr msg) {
          if (msg->data <= 4) {
            controller_.in_cmd =
              static_cast<StatusEnum>(msg->data);
          }
        }
      );

    StatusController_init(&controller_);

    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(100),
      std::bind(&AfStatusAdapterNode::on_tick, this)
    );
  }

private:
  void on_tick()
  {
    controller_.in_tick = 1u;
    StatusController_step(&controller_);

    std_msgs::msg::String out;
    out.data = status_to_string(controller_.out_status);
    pub_status_->publish(out);
  }

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_status_;
  rclcpp::Subscription<std_msgs::msg::UInt8>::SharedPtr sub_cmd_;
  rclcpp::TimerBase::SharedPtr timer_;

  StatusController controller_{};
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<AfStatusAdapterNode>());
  rclcpp::shutdown();
  return 0;
}