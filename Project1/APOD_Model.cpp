#pragma once
#include "APOD_Model.h"

void APOD_Model::set_copyright(std::string copyright)
{
	this->copyright = copyright;
}

void APOD_Model::set_date(std::string date)
{
	this->date = date;
}

void APOD_Model::set_explanation(std::string explanation)
{
	this->explanation = explanation;
}

void APOD_Model::set_hdurl(std::string hdurl)
{
	this->hdurl = hdurl;
}

void APOD_Model::set_media_type(std::string media_type)
{
	this->media_type = media_type;
}

void APOD_Model::set_service_version(std::string service_version)
{
	this->service_version = service_version;
}

void APOD_Model::set_title(std::string title)
{
	this->title = title;
}

void APOD_Model::set_url(std::string url)
{
	this->url = url;
}

std::string APOD_Model::get_copyright()
{
	return this->copyright;
}

std::string APOD_Model::get_date()
{
	return this->date;
}

std::string APOD_Model::get_explanation()
{
	return this->explanation;
}

std::string APOD_Model::get_hdurl()
{
	return this->hdurl;
}

std::string APOD_Model::get_media_type()
{
	return this->media_type;
}

std::string APOD_Model::get_service_version()
{
	return this->service_version;
}

std::string APOD_Model::get_title()
{
	return this->title;
}

std::string APOD_Model::get_url()
{
	return this->url;
}

APOD_Model::APOD_Model()
{
}

APOD_Model::APOD_Model(std::string copyright, std::string date, std::string explanation, std::string hdurl, std::string media_type, std::string service_version, std::string title, std::string url)
{
	this->copyright = copyright;
	this->date = date;
	this->explanation = explanation;
	this->hdurl = hdurl;
	this->media_type = media_type;
	this->service_version = service_version;
	this->title = title;
	this->url = url;
}
