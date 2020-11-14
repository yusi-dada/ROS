#include "msg2bin.h"


// ******************************************************************
//
// object_recognition_msgs/ObjectType
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const object_recognition_msgs::ObjectType dat)
{
	stream << dat.key;
	stream << dat.db;
	return stream;
}
ifstream& operator >> (ifstream& stream, object_recognition_msgs::ObjectType &dat)
{
	stream >> dat.key;
	stream >> dat.db;
	return stream;
}

