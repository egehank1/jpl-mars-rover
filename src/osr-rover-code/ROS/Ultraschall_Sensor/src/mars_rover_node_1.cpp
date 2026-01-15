//Author:Abdulrahman Al-qathmi
#include <chrono>
#include <memory>
#include <string>
#include <vector>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/bool.hpp"

// Hier kommt dein bestehender Header-Code
extern "C" {
#include "Component_Architecture1_ID_420.h"
#include "data_dictionary.h"
#include "Echo_ID_431.h"
#include "Kontext_Rover_ID_704.h"
#include "Timer10_ID_579.h"
#include "TriggerFunk_ID_427.h"
#include "UltraschalSensor_HW_Componete_ID_435.h"
}
  

using namespace std::chrono_literals;

class MarsRoverNode : public rclcpp::Node {
public:
    MarsRoverNode()
        : Node("mars_rover_node"), current_scenario_(0)
    {
        publisher_ = this->create_publisher<std_msgs::msg::Bool>("too_close", 10);

        scenarios_ = {
            {"i", 30, true},
            {"i",40, true},
            {"i",50, true},
            {"i", 120, true},
            {"i", 130, true},
            {"i",140, true},
            {"i",150, true},
                      {"i", 160, true},
            {"i",170, true},
            {"i",180, true},
            {"i", 190, true},
            {"i", 200, true},
        };

        init_Component_Architecture1_ID_420();

        timer_ = this->create_wall_timer(
            500ms,
            std::bind(&MarsRoverNode::run_measurement_cycle, this)
        );
    }

private:
    struct measurement_scenario {
        const char *name;
        int echo_ticks;
        bool emit_echo;
    };

    std::vector<measurement_scenario> scenarios_;
    size_t current_scenario_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    void step_with_echo(bool value) {
        noval_Echo_Signal_ID_542 = false;
        Echo_Signal_ID_542 = value;
        perform_step_Component_Architecture1_ID_420();
    }

    void advance_without_echo(int steps,auto scenario) {
        for (int i = 0; i < steps; ++i) {
            step_with_echo(false);
if ((noval_Impuls_Signal_ID_508 == false && Impuls_Signal_ID_508 == false) && (noval_Runde_ID_872 == false && Runde_ID_872 == true)){
 // Kein gültiger Wert vorhanden
        RCLCPP_WARN(this->get_logger(),
                    "[%s] ticks=%d TimeOut von der Funktion Advanced",
                    scenario.name,
                    scenario.echo_ticks);
                     
        return;  // nichts publizieren
        }
    }
}
    bool wait_for_impulse_rising_edge() {
        int guard = 0;
        while (!noval_Impuls_Signal_ID_665 && Impuls_Signal_ID_665) {
            step_with_echo(false);
            if (++guard > 2000) return false;
        }
        guard = 0;
        while (noval_Impuls_Signal_ID_665 || !Impuls_Signal_ID_665) {
            step_with_echo(false);
            if (++guard > 2000) return false;
        }
        return true;
    }




    void report_distance(const measurement_scenario &scenario) {
  RCLCPP_WARN(this->get_logger(),
                    "[%s] ticks=%d , Distance=%f",
                    scenario.name,
                    scenario.echo_ticks,scratch_paper_distance); // 10 us für die Modell Step Zeit  
  if (noval_TooClose_ID_712) {
        // Kein gültiger Wert vorhanden
        RCLCPP_WARN(this->get_logger(),
                    "[%s] ticks=%d Novla TooClose-Wert",
                    scenario.name,
                    scenario.echo_ticks);
        return;  // nichts publizieren
    }
        auto msg = std_msgs::msg::Bool();
        msg.data = TooClose_ID_712;  // <- vom Modell gesetzt
        publisher_->publish(msg);

        RCLCPP_INFO(this->get_logger(),
                    "[%s] ticks=%d TooClose=%s",
                    scenario.name,
                    scenario.echo_ticks,
                    TooClose_ID_712 ? "true" : "false");
    }

    void run_measurement_cycle() {
        if (current_scenario_ >= scenarios_.size()) {
            current_scenario_ = 0;  // wieder von vorn
        }

        auto &scenario = scenarios_[current_scenario_];

        if (!wait_for_impulse_rising_edge()) {
            RCLCPP_WARN(this->get_logger(), "Keine Trigger-Flanke erkannt.");
            current_scenario_++;
            return;
        }

        advance_without_echo(scenario.echo_ticks,scenario);

        if (scenario.emit_echo) {
            step_with_echo(true);
            step_with_echo(false);
            advance_without_echo(2,scenario);  // Wartezeit für TooClose Berechnung
        } else {
            // advance_without_echo(1500);
        }

        report_distance(scenario);
        current_scenario_++;
    }
};

int main(int argc, char **argv) {
    TooClose_ID_712 = false; // Anfangszustand
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MarsRoverNode>());
    rclcpp::shutdown();
    return 0;
}

