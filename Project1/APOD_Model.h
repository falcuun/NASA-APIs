#pragma once
#include "GlobalHeader.h"

class APOD_Model {
private:
	std::string copyright;
	std::string date;
	std::string explanation;
	std::string hdurl;
	std::string media_type;
	std::string service_version;
	std::string title;
	std::string url;

public:
	void set_copyright(std::string copyright);
	void set_date(std::string date);
	void set_explanation(std::string explanation);
	void set_hdurl(std::string hdurl);
	void set_media_type(std::string media_type);
	void set_service_version(std::string service_version);
	void set_title(std::string title);
	void set_url(std::string url);

	std::string get_copyright();
	std::string get_date();
	std::string get_explanation();
	std::string get_hdurl();
	std::string get_media_type();
	std::string get_service_version();
	std::string get_title();
	std::string get_url();

	//TODO: Add these two.
	std::string toJson();
	std::string toString();

	APOD_Model();
	APOD_Model(std::string copyright,
		std::string date,
		std::string explanation,
		std::string hdurl,
		std::string media_type,
		std::string service_version,
		std::string title,
		std::string url);
};