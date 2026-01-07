from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='osr_status_led',
            executable='led_marker_node',
            name='status_led',
            output='screen',
            parameters=[{
                'frame_id': 'base_link',
                'status_topic': '/rover/status',
                'marker_topic': '/rover/status_led/marker',
                'rate_hz': 20.0
            }]
        )
    ])