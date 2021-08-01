#pragma once
#include "GlobalHeader.h"
/*
	Header Containing Definition for Astronomy Picture of the Day
	(APOD) API
*/

class APOD_Endpoint {
private:
	std::string date;
	std::string start_date;
	std::string end_date;
	int count;
	bool thumbs;

public:
	void setDate(std::string date);
	void setStartDate(std::string date);
	void setEndDate(std::string date);
	void setCount(int count);
	void setThumbs(bool thumbs);
	APOD_Endpoint(std::string date, std::string start_date, std::string end_date,int count,
		bool thumbs);

	std::string getDate(std::string date);
	std::string getStartDate(std::string date);
	std::string getEndDate(std::string date);
	int getCount(int count);
	bool getThumbs(bool thumbs);

	std::string toString();
};