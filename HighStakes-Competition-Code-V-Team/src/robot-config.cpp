#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LeftTop = motor(PORT12, ratio18_1, true);
motor LeftBottom = motor(PORT15, ratio18_1, true);
motor RightTop = motor(PORT13, ratio18_1, true);
motor RightBottom = motor(PORT14, ratio18_1, true);
motor Intake = motor(PORT16, ratio18_1, false);
motor RightArm = motor(PORT20, ratio18_1, false);
motor LeftArm = motor(PORT18, ratio18_1, false);
digital_out Clamp1 = digital_out(Brain.ThreeWirePort.G);
digital_out Clamp2 = digital_out(Brain.ThreeWirePort.G);
digital_out LeftRatchet = digital_out(Brain.ThreeWirePort.C);
digital_out RightRatchet = digital_out(Brain.ThreeWirePort.C);
motor Conveyor = motor(PORT17, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}