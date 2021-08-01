#include "APOD_Endpoint.h"

void APOD_Endpoint::setDate(std::string date)
{
	this->date = date;
}

void APOD_Endpoint::setStartDate(std::string date)
{
	this->start_date = date;
}

void APOD_Endpoint::setEndDate(std::string date)
{
	this->end_date = date;
}

void APOD_Endpoint::setCount(int count)
{
	this->count = count;
}

void APOD_Endpoint::setThumbs(bool thumbs)
{
	this->thumbs = thumbs;
}


APOD_Endpoint::APOD_Endpoint(std::string date, std::string start_date, std::string end_date, int count, bool thumbs)
{
	this->date = date;
	this->start_date = start_date;
	this->end_date = end_date;
	this->count = count;
	this->thumbs = thumbs;
}

std::string APOD_Endpoint::getDate(std::string date)
{
	return this->date;
}

std::string APOD_Endpoint::getStartDate(std::string date)
{
	return this->start_date;
}

std::string APOD_Endpoint::getEndDate(std::string date)
{
	return this->end_date;
}

int APOD_Endpoint::getCount(int count)
{
	return this->count;
}

bool APOD_Endpoint::getThumbs(bool thumbs)
{
	return this->thumbs;
}


std::string APOD_Endpoint::toString() {
	std::stringstream ss;
	ss << '"' << APOD::ENDPOINT;
	if (!date.empty()) {
		ss << "date=" << date << "&";
	}
	else {
		if (!start_date.empty() && !end_date.empty()) {
			ss << "start_date=" << start_date << "&";
			ss << "end_date=" << end_date << "&";
		}
	}
	if (count > 0 && count <= 100 && date.empty() && start_date.empty() && end_date.empty())
		ss << "count=" << count << "&";
	ss << "thumbs=" << (thumbs ? "true" : "false") << "&";
	ss << "api_key=" << API_KEY << '"';
	return ss.str();
}
