#include <ctime>
#include <chrono>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "logger.h"


/**
 * 日志写入回调。
 * 
 */
void clona::logger::logging(
	void* userdata,
	int category,
	SDL_LogPriority priority,
	const char* message) {
	using namespace std;

	logger* me = reinterpret_cast<logger*>(userdata);
	ofstream file;
	stringstream path;
	tm timestamp;
	time_t timer = time(nullptr);
	localtime_s(&timestamp, &timer);
	path << "archive" << '/' << put_time(&timestamp, "%Y-%m-%d.log");
	file.open(path.str(), ios::out | ios::app);
	if (file.is_open()) {
		file << put_time(&timestamp, "[%X]") << endl
			<< message << endl;
		file.close();
	}
}

/**
 * 启用 SDL 的日志方法。
 * 
 */
void clona::logger::attach()
{
	SDL_LogSetOutputFunction(&logging, this);
}

/**
 * 
 * 
 */
void clona::logger::detach()
{
}