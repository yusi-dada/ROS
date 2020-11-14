#include "msg2bin.h"


// ******************************************************************
//
// shape_msgs/SolidPrimitive
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const shape_msgs::SolidPrimitive dat)
{
	vector<int> N(static_cast<int>(dat.type));
	stream << N;
	stream << dat.dimensions;
	return stream;
}
ifstream& operator >> (ifstream& stream, shape_msgs::SolidPrimitive &dat)
{
	vector<int> N;	stream >> N;
	dat.type = static_cast<unsigned char>(N[0]);
	stream >> dat.dimensions;
	return stream;
}
// ******************************************************************
//
// shape_msgs/Mesh
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const shape_msgs::Mesh dat)
{
	vector<int> N1(dat.triangles.size());
	stream << N1;
	for ( auto p : dat.triangles )
		stream << p;
	vector<int> N2(dat.vertices.size());
	stream << N2;
	for ( auto p : dat.vertices )
		stream << p;
	return stream;
}
ifstream& operator >> (ifstream& stream, shape_msgs::Mesh &dat)
{
	vector<int> N1;	stream >> N1;
	dat.triangles.resize(N1[0]);
	for( int i=0; i<N1[0]; i++)
		stream >> dat.triangles[i];
	vector<int> N2;	stream >> N2;
	dat.vertices.resize(N2[0]);
	for ( int i=0; i<N2[0]; i++ )
		stream >> dat.vertices[i];
	return stream;
}
// ******************************************************************
//
// shape_msgs/MeshTriangle
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const shape_msgs::MeshTriangle dat)
{
	vector<int> N;
	N.push_back(static_cast<int>(dat.vertex_indices[0]));
	N.push_back(static_cast<int>(dat.vertex_indices[1]));
	N.push_back(static_cast<int>(dat.vertex_indices[2]));
	stream << N;
	return stream;
}
ifstream& operator >> (ifstream& stream, shape_msgs::MeshTriangle &dat)
{
	vector<int> N;	stream >> N;
	for(int i=0; i<3; i++)
		dat.vertex_indices[i] = static_cast<unsigned int>(N[i]);
	return stream;
}

// ******************************************************************
//
// shape_msgs/Plane
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const shape_msgs::Plane dat)
{
	vector<double> N;
	N.push_back(dat.coef[0]);
	N.push_back(dat.coef[1]);
	N.push_back(dat.coef[2]);
	N.push_back(dat.coef[3]);
	stream << N;
	return stream;
}
ifstream& operator >> (ifstream& stream, shape_msgs::Plane &dat)
{
	vector<double> N;	stream >> N;
	for(int i=0; i<4; i++)
		dat.coef[i] = N[i];
	return stream;
}

