#include "msg2bin.h"

// ******************************************************************
//
//	Header
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const std_msgs::Header dat)
{
	vector<int> seq;
	seq.push_back(dat.seq);
	stream << seq;									// seq
	vector<int> tim;
	tim.push_back(dat.stamp.sec);
	tim.push_back(dat.stamp.nsec);
	stream << tim;									// stamp
	stream << dat.frame_id;					// frame_id
	return stream;
}
ifstream& operator >> (ifstream& stream, std_msgs::Header &dat)
{
	vector<int> seq;
	stream >> seq;	
	dat.seq = seq[0];
	vector<int> tim;
	stream >> tim;
	dat.stamp.sec = tim[0];
	dat.stamp.nsec = tim[1];
	stream >> dat.frame_id;
	return stream;	
}
// ******************************************************************
//
//	Duration
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const ros::Duration dat)
{
	vector<int> dur;
	dur.push_back(dat.sec);
	dur.push_back(dat.nsec);
	stream << dur;
	return stream;
}
ifstream& operator >> (ifstream& stream, ros::Duration &dat)
{
	vector<int> dur;
	stream >> dur;
	dat.sec = dur[0];
	dat.nsec = dur[1];
	return stream;
}
// ******************************************************************
//
//	vector<int>
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const vector<int> dat)
{
	int count = dat.size();
	stream.write(reinterpret_cast<const char*>(&count), sizeof(count));
	stream.write(reinterpret_cast<const char*>(&dat[0]), dat.size() * sizeof(int));
	return stream;
}
ifstream& operator >> (ifstream& stream, vector<int> &dat)
{
	int count;
	stream.read(reinterpret_cast<char*>(&count), sizeof(count));
	dat.assign(count, 0);
	stream.read(reinterpret_cast<char*>(&dat[0]), dat.size() * sizeof(int));
	return stream;
}
// ******************************************************************
//
//	vector<double>
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const vector<double> dat)
{
	int count = dat.size();
	stream.write(reinterpret_cast<const char*>(&count), sizeof(count));
	stream.write(reinterpret_cast<const char*>(&dat[0]), dat.size() * sizeof(double));
	return stream;
}
ifstream& operator >> (ifstream& stream, vector<double> &dat)
{
	int count;
	stream.read(reinterpret_cast<char*>(&count), sizeof(count));
	dat.assign(count, 0);
	stream.read(reinterpret_cast<char*>(&dat[0]), dat.size() * sizeof(double));
	return stream;
}

// ******************************************************************
//
//	vector<string>
//
// ******************************************************************
ofstream& operator << (ofstream& stream, const vector<string> dat)
{
	// データサイズ
	vector<int> N;	N.push_back(dat.size());
	stream << N;
	
	for(auto p : dat)
		stream << p;
	return stream;
}
ifstream& operator >> (ifstream& stream, vector<string> &dat)
{
	dat.clear();
	vector<int> N;	stream >> N;	// データサイズ
	
	for(int i=0; i<N[0]; i++)
	{
		string str;
		stream >> str;
		dat.push_back(str);
	}
	return stream;	
}

ofstream& operator << (ofstream& stream, const string dat)
{
	int count = dat.size();
	stream.write(reinterpret_cast<const char*>(&count), sizeof(count));
	stream.write(reinterpret_cast<const char*>(&dat[0]), dat.size() * sizeof(char));
	return stream;
}
ifstream& operator >> (ifstream& stream, string &dat)
{
	int count;
	stream.read(reinterpret_cast<char*>(&count), sizeof(count));
	dat.assign(count, 0);
	stream.read(reinterpret_cast<char*>(&dat[0]), dat.size() * sizeof(char));
	return stream;
}

