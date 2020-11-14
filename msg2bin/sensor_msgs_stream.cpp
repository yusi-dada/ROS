#include "msg2bin.h"


// ******************************************************************
//
// sensor_msgs/JointState
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const sensor_msgs::JointState dat)
{
	stream << dat.header;
	stream << dat.name;
	stream << dat.position;
	stream << dat.velocity;
	stream << dat.effort;
	return stream;
}
ifstream& operator >> (ifstream& stream, sensor_msgs::JointState &dat)
{
	stream >> dat.header;
	stream >> dat.name;
	stream >> dat.position;
	stream >> dat.velocity;
	stream >> dat.effort;
	return stream;
}

// ******************************************************************
//
// sensor_msgs/MultiDOFJointState
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const sensor_msgs::MultiDOFJointState dat)
{
	stream << dat.header;
	stream << dat.joint_names;
	vector<int> N1;	N1.push_back(dat.transforms.size());
	vector<int> N2;	N2.push_back(dat.twist.size());
	vector<int> N3;	N3.push_back(dat.wrench.size());
	
	stream << N1;
	for(auto p : dat.transforms)
		stream << p;

	stream << N2;
	for(auto p : dat.twist)
		stream << p;

	stream << N2;
	for(auto p : dat.wrench)
		stream << p;
	
	return stream;	
}
ifstream& operator >> (ifstream& stream, sensor_msgs::MultiDOFJointState &dat)
{
	stream >> dat.header;
	stream >> dat.joint_names;

	vector<int> N1,N2,N3;
	
	stream >> N1;
	dat.transforms.resize(N1[0]);
	for(int i=0; i<N1[0]; i++)
		stream >> dat.transforms[i];

	stream >> N2;
	dat.twist.resize(N2[0]);
	for(int i=0; i<N2[0]; i++)
		stream >> dat.twist[i];

	stream >> N3;
	dat.wrench.resize(N3[0]);
	for(int i=0; i<N3[0]; i++)
		stream >> dat.wrench[i];
	
	return stream;
}
