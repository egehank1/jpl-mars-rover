

#!/usr/bin/env python3
import math

import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from visualization_msgs.msg import Marker


class StatusLedNode(Node):
    """
    Subscribes:
      /rover/status   (std_msgs/String)

    Publishes:
      /rover/status_led/marker (visualization_msgs/Marker)

    Visualizes a status LED as a blinking / colored sphere in RViz.
    """

    def __init__(self):
        super().__init__('osr_status_led')

        # Parameters (können überschrieben werden via launch file)
        self.declare_parameter('frame_id', 'base_link')
        self.declare_parameter('status_topic', '/rover/status')
        self.declare_parameter('marker_topic', '/rover/status_led/marker')
        self.declare_parameter('rate_hz', 20.0)

        self.frame_id = self.get_parameter('frame_id').value
        self.status_topic = self.get_parameter('status_topic').value
        self.marker_topic = self.get_parameter('marker_topic').value
        self.rate_hz = self.get_parameter('rate_hz').value

        # ROS interfaces
        self.sub = self.create_subscription(
            String,
            self.status_topic,
            self.on_status,
            10
        )
        self.pub = self.create_publisher(Marker, self.marker_topic, 10)

        # LED state
        self.r = 0.1
        self.g = 0.3
        self.b = 1.0
        self.blink = False
        self.blink_hz = 2.0
        self.time = 0.0

        self.timer = self.create_timer(1.0 / self.rate_hz, self.update)

        self.get_logger().info(
            f"Status LED started (frame={self.frame_id}, topic={self.status_topic})"
        )

    def on_status(self, msg: String):
        status = msg.data.strip().upper()

        if status == 'IDLE':
            self.set_led(0.1, 0.3, 1.0, False)
        elif status == 'DRIVING':
            self.set_led(0.1, 1.0, 0.2, False)
        elif status == 'MANUAL':
            self.set_led(1.0, 1.0, 0.1, True, 1.0)
        elif status == 'AUTONOMY':
            self.set_led(0.1, 1.0, 1.0, False)
        elif status == 'ERROR':
            self.set_led(1.0, 0.1, 0.1, True, 2.0)
        else:
            # unknown state
            self.set_led(1.0, 0.0, 1.0, True, 3.0)

        self.get_logger().info(f"Status set to {status}")

    def set_led(self, r, g, b, blink=False, blink_hz=2.0):
        self.r = r
        self.g = g
        self.b = b
        self.blink = blink
        self.blink_hz = blink_hz

    def update(self):
        self.time += 1.0 / self.rate_hz

        marker = Marker()
        marker.header.frame_id = self.frame_id
        marker.header.stamp = self.get_clock().now().to_msg()

        marker.ns = 'osr_status_led'
        marker.id = 0
        marker.type = Marker.SPHERE
        marker.action = Marker.ADD

        # Position relative to rover base
        marker.pose.position.x = 0.0
        marker.pose.position.y = 0.0
        marker.pose.position.z = 0.6
        marker.pose.orientation.w = 1.0

        # Size
        marker.scale.x = 0.12
        marker.scale.y = 0.12
        marker.scale.z = 0.12

        # Blinking via alpha
        if self.blink:
            phase = math.sin(2.0 * math.pi * self.blink_hz * self.time)
            marker.color.a = 1.0 if phase >= 0.0 else 0.05
        else:
            marker.color.a = 1.0

        marker.color.r = self.r
        marker.color.g = self.g
        marker.color.b = self.b

        marker.lifetime.sec = 0
        marker.lifetime.nanosec = 0

        self.pub.publish(marker)


def main():
    rclpy.init()
    node = StatusLedNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
