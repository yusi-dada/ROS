#include "msg2bin.h"

// ******************************************************************
//
//	geometry_msgs::Pose
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const geometry_msgs::Pose dat)
{
	stream << dat.position;
	stream << dat.orientation;
	return stream;
}
ifstream& operator >> (ifstream& stream, geometry_msgs::Pose &dat)
{
	stream >> dat.position;
	stream >> dat.orientation;
	return stream;
}
// ******************************************************************
//
//	geometry_msgs::Wrench
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const geometry_msgs::Wrench dat)
{
	stream << dat.force;
	stream << dat.torque;
	return stream;	
}
ifstream& operator >> (ifstream& stream, geometry_msgs::Wrench &dat)
{
	stream >> dat.force;
	stream >> dat.torque;
	return stream;	
}
// ******************************************************************
//
//	geometry_msgs::Twist
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const geometry_msgs::Twist dat)
{
	stream << dat.linear;
	stream << dat.angular;
	return stream;
}
ifstream& operator >> (ifstream& stream, geometry_msgs::Twist &dat)
{
	stream >> dat.linear;
	stream >> dat.angular;
	return stream;
}
// ******************************************************************
//
//	geometry_msgs::Transform
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const geometry_msgs::Transform dat)
{
	stream << dat.translation;
	stream << dat.rotation;
	return stream;
}
ifstream& operator >> (ifstream& stream, geometry_msgs::Transform &dat)
{
	stream >> dat.translation;
	stream >> dat.rotation;
	return stream;
}
// ******************************************************************
//
//	geometry_msgs::Quaternion
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const geometry_msgs::Quaternion dat)
{
	vector<double> vec;
	vec.push_back(dat.x);
	vec.push_back(dat.y);
	vec.push_back(dat.z);
	vec.push_back(dat.w);
	stream << vec;
	return stream;
}
ifstream& operator >> (ifstream& stream, geometry_msgs::Quaternion &dat)
{
	vector<double> vec;
	stream >> vec;
	dat.x = vec[0];
	dat.y = vec[1];
	dat.z = vec[2];
	dat.w = vec[3];
	return stream;
}
// ******************************************************************
//
//	geometry_msgs::Point
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const geometry_msgs::Point dat)
{
	vector<double> vec;
	vec.push_back(dat.x);
	vec.push_back(dat.y);
	vec.push_back(dat.z);
	stream << vec;
	return stream;
}
ifstream& operator >> (ifstream& stream, geometry_msgs::Point &dat)
{
	vector<double> vec;
	stream >> vec;
	dat.x = vec[0];
	dat.y = vec[1];
	dat.z = vec[2];
	return stream;
}

// ******************************************************************
//
//	geometry_msgs::Vector3
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const geometry_msgs::Vector3 dat)
{
	vector<double> vec;
	vec.push_back(dat.x);
	vec.push_back(dat.y);
	vec.push_back(dat.z);
	stream << vec;
	return stream;
}
ifstream& operator >> (ifstream& stream, geometry_msgs::Vector3 &dat)
{
	vector<double> vec;
	stream >> vec;
	dat.x = vec[0];
	dat.y = vec[1];
	dat.z = vec[2];
	return stream;
}

