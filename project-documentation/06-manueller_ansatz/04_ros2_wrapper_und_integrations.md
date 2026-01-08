---

# 📄 `04_ros2_wrapper_und_integration.md`

```md
# ROS2 Wrapper / Adapter

## Aufgabe des Wrappers

Der Wrapper verbindet:

- AutoFOCUS-Code (C)
- mit ROS2 (C++)

Er übernimmt:

- Topic-Subscription
- Typkonvertierung
- zeitgesteuerten Aufruf (`tick`)
- Publishing des Status

---

## Wrapper Node

### Datei: `af_status_node.cpp`

```cpp
#include <chrono>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/u_int8.hpp"

extern "C" {
#include "status_controller/status_controller.h"
}

using namespace std::chrono_literals;

static std::string status_to_string(StatusEnum s)
{
  switch (s) {
    case STATUS_IDLE: return "IDLE";
    case STATUS_DRIVING: return "DRIVING";
    case STATUS_ERROR: return "ERROR";
    case STATUS_MANUAL: return "MANUAL";
    case STATUS_AUTONOMY: return "AUTONOMY";
    default: return "UNKNOWN";
  }
}

class AfStatusAdapterNode : public rclcpp::Node
{
public:
  AfStatusAdapterNode() : Node("af_status_adapter")
  {
    pub_ = create_publisher<std_msgs::msg::String>("/rover/status", 10);

    StatusController_init(&controller_);

    timer_ = create_wall_timer(
      100ms,
      std::bind(&AfStatusAdapterNode::on_tick, this)
    );
  }

private:
  void on_tick()
  {
    controller_.in_tick = 1u;
    StatusController_step(&controller_);

    std_msgs::msg::String msg;
    msg.data = status_to_string(controller_.out_status);
    pub_->publish(msg);
  }

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
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