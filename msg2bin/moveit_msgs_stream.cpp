#include "msg2bin.h"

// ******************************************************************
//
// moveit_msgs/DisplayTrajectory
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const moveit_msgs::DisplayTrajectory dat)
{
	stream << dat.model_id;
	vector<int> N(dat.trajectory.size());
	stream << N;
	for(auto p : dat.trajectory)
		stream << p;
	stream << dat.trajectory_start;
	return stream;
}
ifstream& operator >> (ifstream& stream, moveit_msgs::DisplayTrajectory &dat)
{
	stream >> dat.model_id;
	vector<int> N;	stream >> N;	// trajectoryサイズ
	dat.trajectory.resize(N[0]);
	for(int i=0; i<N[0]; i++)
		stream >> dat.trajectory[i];
	stream >> dat.trajectory_start;
	return stream;
}

// ******************************************************************
//
// moveit_msgs/RobotState
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const moveit_msgs::RobotState dat)
{
	stream << dat.joint_state;
	stream << dat.multi_dof_joint_state;
	vector<int> N1(dat.attached_collision_objects.size());
	stream << N1;
	for(auto p : dat.attached_collision_objects)
		stream << p;

	vector<int> N2(static_cast<int>(dat.is_diff));
	stream << N2;
	return stream;
}
ifstream& operator >> (ifstream& stream, moveit_msgs::RobotState &dat)
{
	stream >> dat.joint_state;
	stream >> dat.multi_dof_joint_state;
	vector<int> N1;	stream >> N1;
	dat.attached_collision_objects.resize(N1[0]);
	for(int i=0; i<N1[0]; i++)
		stream >> dat.attached_collision_objects[i];

	vector<int> N2;	stream >> N2;
	dat.is_diff = static_cast<bool>(N2[0]);
	return stream;
}
// ******************************************************************
//
// moveit_msgs/RobotTrajectory
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const moveit_msgs::RobotTrajectory dat)
{
	stream << dat.joint_trajectory;
	stream << dat.multi_dof_joint_trajectory;
	return stream;
}
ifstream& operator >> (ifstream& stream, moveit_msgs::RobotTrajectory &dat)
{
	stream >> dat.joint_trajectory;
	stream >> dat.multi_dof_joint_trajectory;
	return stream;
}
// ******************************************************************
//
// moveit_msgs/AttachedCollisionObject
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const moveit_msgs::AttachedCollisionObject dat)
{
	stream << dat.link_name;
	stream << dat.object;
	stream << dat.touch_links;
	stream << dat.detach_posture;
	vector<double> v(dat.weight);
	stream << v;
	return stream;
}
ifstream& operator >> (ifstream& stream, moveit_msgs::AttachedCollisionObject &dat)
{
	stream >> dat.link_name;
	stream >> dat.object;
	stream >> dat.touch_links;
	stream >> dat.detach_posture;
	vector<double> v;	stream >> v;
	dat.weight = v[0];
	return stream;
}
// ******************************************************************
//
// moveit_msgs/CollisionObject
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const moveit_msgs::CollisionObject dat)
{
	stream << dat.header;
//	stream << dat.pose;		// メンバがない　ROSWikiと異なる
	stream << dat.id;
	stream << dat.type;

	vector<int> N1(dat.primitives.size());
	stream << N1;
	for( auto p : dat.primitives)
		stream << p;

	vector<int> N2(dat.primitive_poses.size());
	stream << N2;
	for( auto p : dat.primitive_poses)
		stream << p;

	vector<int> N3(dat.meshes.size());
	stream << N3;
	for( auto p : dat.meshes)
		stream << p;

	vector<int> N4(dat.mesh_poses.size());
	stream << N4;
	for( auto p : dat.mesh_poses)
		stream << p;

	vector<int> N5(dat.planes.size());
	stream << N5;
	for( auto p : dat.planes)
		stream << p;

	vector<int> N6(dat.plane_poses.size());
	stream << N6;
	for( auto p : dat.plane_poses)
		stream << p;

// メンバがない　ROSWikiと異なる
//	stream << dat.subframe_names;
//	vector<int> N7(dat.subframe_poses.size());
//	stream << N7;
//	for( auto p : dat.subframe_poses)
//		stream << p;

	vector<int> N8(static_cast<int>(dat.operation));
	stream << N8;
	return stream;	
}
ifstream& operator >> (ifstream& stream, moveit_msgs::CollisionObject &dat)
{
	stream >> dat.header;
//	stream >> dat.pose;		// メンバがない　ROSWikiと異なる
	stream >> dat.id;
	stream >> dat.type;

	vector<int> N1;	stream >> N1;
	dat.primitives.resize(N1[0]);
	for( int i=0; i<N1[0]; i++)
		stream >> dat.primitives[i];

	vector<int> N2;	stream >> N2;
	dat.primitive_poses.resize(N2[0]);
	for( int i=0; i<N2[0]; i++)
		stream >> dat.primitive_poses[i];
	
	vector<int> N3;	stream >> N3;
	dat.meshes.resize(N3[0]);
	for( int i=0; i<N3[0]; i++)
		stream >> dat.meshes[i];
	
	vector<int> N4;	stream >> N4;
	dat.mesh_poses.resize(N4[0]);
	for( int i=0; i<N4[0]; i++)
		stream >> dat.mesh_poses[i];

	vector<int> N5;	stream >> N5;
	dat.planes.resize(N5[0]);
	for( int i=0; i<N5[0]; i++)
		stream >> dat.planes[i];

	vector<int> N6;	stream >> N6;
	dat.plane_poses.resize(N6[0]);
	for( int i=0; i<N6[0]; i++)
		stream >> dat.plane_poses[i];

// メンバがない　ROSWikiと異なる
//	stream >> dat.subframe_names;
//	vector<int> N7;	stream >> N7;
//	dat.subframe_poses.resize(N7[0]);
//	for( int i=0; i<N7[0]; i++)
//		stream >> dat.subframe_poses[i];

	vector<int> N8;	stream >> N8;
	dat.operation = static_cast<unsigned char>(N8[0]);
	return stream;	
}
