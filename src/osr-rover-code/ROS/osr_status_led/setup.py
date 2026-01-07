from setuptools import setup

package_name = 'osr_status_led'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
         ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch',
         ['launch/status_led.launch.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='MarsRover Team',
    maintainer_email='noreply@fh-aachen.de',
    description='RViz status LED marker for Mars Rover',
    license='Apache-2.0',
    entry_points={
        'console_scripts': [
            'led_marker_node = osr_status_led.led_marker_node:main',
        ],
    },
)
