using namespace vex;
extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LeftTop;
extern motor LeftBottom;
extern motor RightTop;
extern motor RightBottom;
extern motor Intake;
extern motor RightArm;
extern digital_out Clamp2;
extern motor LeftArm;
extern digital_out Clamp1;
extern digital_out LeftRatchet;
extern digital_out RightRatchet;
extern motor Conveyor;
extern optical Optical;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );