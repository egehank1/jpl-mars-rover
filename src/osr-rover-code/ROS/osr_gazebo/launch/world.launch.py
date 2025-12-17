import os

from ament_index_python.packages import get_package_share_directory


from launch import LaunchDescription
from launch.actions import ExecuteProcess, IncludeLaunchDescription, RegisterEventHandler, DeclareLaunchArgument
from launch.event_handlers import OnProcessExit
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution, LaunchConfiguration
from launch_ros.actions import Node

import xacro


def generate_launch_description():

    # Paket-Pfade
    osr_share = get_package_share_directory('osr_gazebo')
    gazebo_share = get_package_share_directory('gazebo_ros')

    # Launch-Konfiguration
    world = LaunchConfiguration('world')

    # World als Launch-Argument (von außen beim Starten überschreibbar)
    declare_world_arg = DeclareLaunchArgument(
        'world',
        default_value=PathJoinSubstitution([
                osr_share,
                'worlds',
                'blank_world.world'
        ]),
        description='Pfad zur Gazebo-World-Datei'
    )

    # Gazebo mit dynamischen World-Pfad starten
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(gazebo_share, 'launch', 'gazebo.launch.py')
        ),
        launch_arguments={
            'use_sim_time': 'true',
            'world': world
        }.items()
    )

    # URDF / Xacro verarbeiten
    osr_urdf_path = os.path.join(osr_share, 'urdf')
    xacro_file = os.path.join(osr_urdf_path, 'osr.urdf.xacro')

    doc = xacro.parse(open(xacro_file))
    xacro.process_doc(doc)
    params = {'robot_description': doc.toxml()}

    node_robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[params,{'use_sim_time': True}]
    )

    controller_spawn = Node(
        package='osr_gazebo',
        executable='osr_controller',
        output='screen',
	parameters=[{'use_sim_time': True}]
    )

    spawn_entity = Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        arguments=['-topic', 'robot_description',
                   '-entity', 'rover'],
        output='screen'
    )

    # Room-Model dynamisch aus dem Package laden
    room_model = PathJoinSubstitution([
        osr_share,
        'models',
        'room',
        'model.sdf'
    ])

    spawn_room = Node(
    package='gazebo_ros',
    executable='spawn_entity.py',
    arguments=[
        '-file', room_model, #hier wird nun dynamisch geladen
        '-entity', 'room',
        '-x',      '0',
        '-y',      '0',
        '-z',      '0',
        '-R',      '0',
        '-P',      '0',
        '-Y',      '0'
        ],
        output='screen'
    )


    # joint_state_controller
    load_joint_state_controller = ExecuteProcess(
        cmd=['ros2', 'control', 'load_controller', '--set-state', 'active', 'joint_state_broadcaster'],
        output='screen'
    )

    # wheel_velocity_controller
    rover_wheel_controller = ExecuteProcess(
        cmd=['ros2', 'control', 'load_controller', '--set-state', 'active', 'wheel_controller'],
        output='screen'
    )

    # servo_controller
    servo_controller = ExecuteProcess(
        cmd=['ros2', 'control', 'load_controller', '--set-state', 'active', 'servo_controller'],
        output='screen'
    )

    return LaunchDescription([
        controller_spawn,
        declare_world_arg,      # <-- neues Launch Argument zum dynamischen Laden
        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=spawn_entity,
                on_exit=[
                    load_joint_state_controller,
                    rover_wheel_controller,
                    servo_controller,
                ],
            )
        ),
        gazebo,
        node_robot_state_publisher,
        spawn_entity,
        spawn_room
    ])
