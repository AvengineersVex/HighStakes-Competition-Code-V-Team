/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       mohitrk                                                   */
/*    Created:      2/14/2025, 10:36:47 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "robot-config.h"
using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
bool intakerunning;
bool clamp;
bool climbratchet;


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encodeers, setting servo positions, ...
  intakerunning = false;
  clamp = false;
  climbratchet = false;
  Clamp1.set(true);
  Clamp2.set(true);
  LeftRatchet.set(false);
  RightRatchet.set(false);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  /*Left Blue Alliance; Donut, Stake, Load, Ladder, Arm Up*/
    Clamp1.set(true);
    Clamp2.set(true);
    LeftBottom.spin(forward, 50, pct);
    LeftTop.spin(forward, 50, pct);
    RightBottom.spin(reverse, 50, pct);
    RightTop.spin(reverse, 50, pct);
    Intake.spin(reverse, 60, pct);
    wait(850, msec);
    wait(525, msec);
    LeftBottom.stop();
    LeftTop.stop();
    RightBottom.stop();
    RightTop.stop();
    wait(250, msec);
    Conveyor.spin(forward, 30, pct);
    wait(1.3, sec);
    Conveyor.stop();
    wait(1, sec);
    Intake.stop();
    wait(100, msec);
    LeftBottom.spin(reverse, 50, pct);
    LeftTop.spin(reverse, 50, pct);
    RightBottom.spin(reverse, 50, pct);
    RightTop.spin(reverse, 50, pct);
    wait(350,msec);
    LeftBottom.stop();
    LeftTop.stop();
    RightBottom.stop();
    RightTop.stop();
    wait(100, msec);
    LeftBottom.spin(reverse, 50, pct);
    LeftTop.spin(reverse, 50, pct);
    RightBottom.spin(forward, 50, pct);
    RightTop.spin(forward, 50, pct);
    wait(0.9, sec);
    LeftBottom.stop();
    LeftTop.stop();
    RightBottom.stop();
    RightTop.stop();
    Clamp1.set(false);
    Clamp2.set(false);
    wait(500, msec);
    LeftBottom.spin(forward, 40, pct);
    LeftTop.spin(forward, 40, pct);
    RightBottom.spin(reverse, 40, pct);
    RightTop.spin(reverse, 40, pct);
    wait(500, msec);
    LeftBottom.stop();
    LeftTop.stop();
    RightBottom.stop();
    RightTop.stop();
    wait(500, msec);
    Conveyor.spin(forward, 55, pct);
    wait(1.5, sec);
    Conveyor.stop();
    wait(100, msec);
    LeftBottom.spin(forward, 50, pct);
    LeftTop.spin(forward, 50, pct);
    RightBottom.spin(forward, 50, pct);
    RightTop.spin(forward, 50, pct);
    wait(850, msec);
    LeftBottom.stop();
    LeftTop.stop();
    RightBottom.stop();
    RightTop.stop();
    wait(200, msec);
    LeftBottom.spin(forward, 40, pct);
    LeftTop.spin(forward, 40, pct);
    RightBottom.spin(reverse, 40, pct);
    RightTop.spin(reverse, 40, pct);
    wait(1.1, sec);
    LeftBottom.stop();
    LeftTop.stop();
    RightBottom.stop();
    RightTop.stop();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void move()
{

  LeftTop.spin(forward, Controller1.Axis3.position(pct), percent);
  LeftBottom.spin(forward, Controller1.Axis3.position(pct), percent);
  RightTop.spin(reverse, Controller1.Axis3.position(pct), percent);
  RightBottom.spin(reverse, Controller1.Axis3.position(pct), percent);

  if (Controller1.Axis1.position() > 0)
  {
    LeftTop.spin(forward, Controller1.Axis1.position(pct), percent);
    LeftBottom.spin(forward, Controller1.Axis1.position(pct), percent);
    RightTop.spin(forward, Controller1.Axis1.position(pct), percent);
    RightBottom.spin(forward, Controller1.Axis1.position(pct), percent);
  }
  else if (Controller1.Axis1.position() < 0)
  {
    LeftTop.spin(forward, Controller1.Axis1.position(pct), percent);
    LeftBottom.spin(forward, Controller1.Axis1.position(pct), percent);
    RightTop.spin(forward, Controller1.Axis1.position(pct), percent);
    RightBottom.spin(forward, Controller1.Axis1.position(pct), percent);
  }
}

void setMotors()
{
  LeftTop.setStopping(coast);
  LeftBottom.setStopping(coast);
  RightTop.setStopping(coast);
  RightBottom.setStopping(coast);
  Intake.setStopping(brake);
  Conveyor.setStopping(brake);
  RightArm.setStopping(hold);
  LeftArm.setStopping(hold);
}

void diskintake()
{
  if (intakerunning == false){
    Intake.spin(reverse, 70, percent);
    Conveyor.spin(forward, 55, percent);
    intakerunning = true;
  }
  else {
    Intake.stop();
    Conveyor.stop();
    intakerunning = false;
  }
}

void conveyorup()
{
  Conveyor.spin(forward, 25, percent);
}

void conveyordown()
{
  Conveyor.spin(reverse, 25, percent);
}

void conveyorstop()
{
  Conveyor.stop();
}

void intakerun()
{
  Intake.spin(reverse, 70, percent);
}

void intakestop()
{
  Intake.stop();
}

void arm_up()
{
  RightArm.spin(reverse, 60, pct);
  LeftArm.spin(forward, 60, pct);
}

void arm_stop()
{
  RightArm.stop();
  LeftArm.stop();
}

void arm_down()
{
  RightArm.spin(forward, 60, pct);
  LeftArm.spin(reverse,60,pct);
}

void piston_control()
{
  if (clamp == false)
  {
    Clamp1.set(false);
    Clamp2.set(false);
    clamp = true;
  }
  else
  {
    Clamp1.set(true);
    Clamp2.set(true);
    clamp = false;
  }
}

void ratchet()
{
  if (climbratchet == false)
  {
    LeftRatchet.set(false);
    RightRatchet.set(false);
    climbratchet = true;
  }
  else
  {
    LeftRatchet.set(true);
    RightRatchet.set(true);
    climbratchet = false;
  }
}

void usercontrol(void) {
  // User control code here, inside the loop
  setMotors();
  while (1) {
    move();
    Controller1.ButtonR1.pressed(arm_up);
    Controller1.ButtonR1.released(arm_stop);
    Controller1.ButtonL1.pressed(arm_down);
    Controller1.ButtonL1.released(arm_stop);
    Controller1.ButtonR2.pressed(ratchet);
    Controller1.ButtonA.pressed(diskintake);
    Controller1.ButtonY.pressed(piston_control);
    Controller1.ButtonB.pressed(intakerun);
    Controller1.ButtonB.released(intakestop);
    Controller1.ButtonRight.pressed(conveyorup);
    Controller1.ButtonRight.released(conveyorstop);
    Controller1.ButtonLeft.pressed(conveyordown);
    Controller1.ButtonLeft.released(conveyorstop);
    wait(20, msec);
  }
}


//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}