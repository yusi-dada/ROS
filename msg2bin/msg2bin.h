#pragma once

#include <ros/ros.h>
#include <ros/console.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//******************************************************************************************
//
// moveit_msgs
//
//******************************************************************************************
// DisplayTrajectory
ofstream& operator << (ofstream& stream, const moveit_msgs::DisplayTrajectory dat);
ifstream& operator >> (ifstream& stream, moveit_msgs::DisplayTrajectory &dat);
// RobotState
ofstream& operator << (ofstream& stream, const moveit_msgs::RobotState dat);
ifstream& operator >> (ifstream& stream, moveit_msgs::RobotState &dat);
// RobotTrajectory
ofstream& operator << (ofstream& stream, const moveit_msgs::RobotTrajectory dat);
ifstream& operator >> (ifstream& stream, moveit_msgs::RobotTrajectory &dat);
// AttachedCollisionObject
ofstream& operator << (ofstream& stream, const moveit_msgs::AttachedCollisionObject dat);
ifstream& operator >> (ifstream& stream, moveit_msgs::AttachedCollisionObject &dat);
// CollisionObject
ofstream& operator << (ofstream& stream, const moveit_msgs::CollisionObject dat);
ifstream& operator >> (ifstream& stream, moveit_msgs::CollisionObject &dat);

//******************************************************************************************
//
// trajectory_msgs
//
//******************************************************************************************
// JointTrajectory
ofstream& operator << (ofstream& stream, const trajectory_msgs::JointTrajectory dat);
ifstream& operator >> (ifstream& stream, trajectory_msgs::JointTrajectory &dat);
// JointTrajectoryPoint
ofstream& operator << (ofstream& stream, const trajectory_msgs::JointTrajectoryPoint dat);
ifstream& operator >> (ifstream& stream, trajectory_msgs::JointTrajectoryPoint &dat);
// MultiDOFJointTrajectory
ofstream& operator << (ofstream& stream, const trajectory_msgs::MultiDOFJointTrajectory dat);
ifstream& operator >> (ifstream& stream, trajectory_msgs::MultiDOFJointTrajectory &dat);
// MultiDOFJointTrajectoryPoint
ofstream& operator << (ofstream& stream, const trajectory_msgs::MultiDOFJointTrajectoryPoint dat);
ifstream& operator >> (ifstream& stream, trajectory_msgs::MultiDOFJointTrajectoryPoint &dat);

//******************************************************************************************
//
// shape_msgs
//
//******************************************************************************************
// SolidPrimitive
ofstream& operator << (ofstream& stream, const shape_msgs::SolidPrimitive dat);
ifstream& operator >> (ifstream& stream, shape_msgs::SolidPrimitive &dat);
// Mesh
ofstream& operator << (ofstream& stream, const shape_msgs::Mesh dat);
ifstream& operator >> (ifstream& stream, shape_msgs::Mesh &dat);
// MeshTriangle
ofstream& operator << (ofstream& stream, const shape_msgs::MeshTriangle dat);
ifstream& operator >> (ifstream& stream, shape_msgs::MeshTriangle &dat);
// Plane
ofstream& operator << (ofstream& stream, const shape_msgs::Plane dat);
ifstream& operator >> (ifstream& stream, shape_msgs::Plane &dat);

//******************************************************************************************
//
// sensor_msgs
//
//******************************************************************************************
// JointState
ofstream& operator << (ofstream& stream, const sensor_msgs::JointState dat);
ifstream& operator >> (ifstream& stream, sensor_msgs::JointState &dat);
// MultiDOFJointState
ofstream& operator << (ofstream& stream, const sensor_msgs::MultiDOFJointState dat);
ifstream& operator >> (ifstream& stream, sensor_msgs::MultiDOFJointState &dat);
//******************************************************************************************
//
// geometry_msgs
//
//******************************************************************************************
// Pose
ofstream& operator << (ofstream& stream, const geometry_msgs::Pose dat);
ifstream& operator >> (ifstream& stream, geometry_msgs::Pose &dat);
// Wrench
ofstream& operator << (ofstream& stream, const geometry_msgs::Wrench dat);
ifstream& operator >> (ifstream& stream, geometry_msgs::Wrench &dat);
// Twist
ofstream& operator << (ofstream& stream, const geometry_msgs::Twist dat);
ifstream& operator >> (ifstream& stream, geometry_msgs::Twist &dat);
// Transform
ofstream& operator << (ofstream& stream, const geometry_msgs::Transform dat);
ifstream& operator >> (ifstream& stream, geometry_msgs::Transform &dat);
// Quaternion
ofstream& operator << (ofstream& stream, const geometry_msgs::Quaternion dat);
ifstream& operator >> (ifstream& stream, geometry_msgs::Quaternion &dat);
// Point
ofstream& operator << (ofstream& stream, const geometry_msgs::Point dat);
ifstream& operator >> (ifstream& stream, geometry_msgs::Point &dat);
// Vector3
ofstream& operator << (ofstream& stream, const geometry_msgs::Vector3 dat);
ifstream& operator >> (ifstream& stream, geometry_msgs::Vector3 &dat);

//******************************************************************************************
//
// object_recognition_msgs
//
//******************************************************************************************
//ObjectType
ofstream& operator << (ofstream& stream, const object_recognition_msgs::ObjectType dat);
ifstream& operator >> (ifstream& stream, object_recognition_msgs::ObjectType &dat);

//******************************************************************************************
//
// std_msgs
//
//******************************************************************************************
// Header
ofstream& operator << (ofstream& stream, const std_msgs::Header dat);
ifstream& operator >> (ifstream& stream, std_msgs::Header &dat);
// Duration
ofstream& operator << (ofstream& stream, const ros::Duration dat);
ifstream& operator >> (ifstream& stream, ros::Duration &dat);
// Int配列
ofstream& operator << (ofstream& stream, const vector<int> dat);
ifstream& operator >> (ifstream& stream, vector<int> &dat);
// Double配列
ofstream& operator << (ofstream& stream, const vector<double> dat);
ifstream& operator >> (ifstream& stream, vector<double> &dat);
// String配列
ofstream& operator << (ofstream& stream, const vector<string> dat);
ifstream& operator >> (ifstream& stream, vector<string> &dat);
// String
ofstream& operator << (ofstream& stream, const string dat);
ifstream& operator >> (ifstream& stream, string &dat);

