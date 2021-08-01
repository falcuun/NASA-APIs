
#include "GlobalHeader.h"
#include "Endpoints.h"
#include "APOD_Model.h"


const char CURL[9] = "curl -s ";


using namespace nlohmann;

std::string curl_execute_command_with_output(std::string command) {
	// Declaring Result string (Method return). Should return output of the command.
	std::string result;
	// Defining the name of the file that command output will be written to.
	const char file_name[19] = "command_output.txt";
	// Declaring the right-side of the command (Pipe to the file).
	char command_output_destination[4 + sizeof(file_name) * sizeof(char*)] = " > ";
	// Concatenating the file name to the right side of the pipe.
	strcat_s(command_output_destination, file_name);
	// Declaring empty buffer that will whole the entire command signature (Command + File destination).
	std::stringstream buffer;
	// Concatenating the command to the buffer.
	// Concatenating pipe and file destination to the command.
	// Concatenating zero-termination to the buffer.
	buffer << command << command_output_destination << "\0\r";
	// Running the System command.
	system(buffer.str().c_str());
	// Opening File Input Stream to read the text from the output file.
	std::ifstream command_file(file_name);
	// Assigning the text from the output file to the result string. 
	result = std::string((std::istreambuf_iterator<char>(command_file.rdbuf())), std::istreambuf_iterator<char>());
	// Clears out the contents of the output file.
	std::ofstream{ file_name };
	// Returns the Command Result Contents.
	return result;
}


std::string curl_get_request(std::string url) {
	std::stringstream command;
	command << CURL << url << "\0\r";
	return curl_execute_command_with_output(command.str());
}

// TODO: Don't Try To Download if it's not an image (Check for .jpg)

void curl_execute_command_download_jpg(std::string url, std::string image_name) {
	std::stringstream command;
	command << CURL << url << '>';
	std::remove_if(image_name.begin(), image_name.end(), ::isspace);
	command << image_name << ".jpg" << "\0\r";
	system(command.str().c_str());
}

std::string json_object_toString(json json_object, std::string param) {
	return json_object[param].is_null() ? "" : json_object[param];
}

void jsonObjectToAPODObject(json jsonParsed) {
	APOD_Model apodMod(
		json_object_toString(jsonParsed, "copyright"),
		json_object_toString(jsonParsed, "date"),
		json_object_toString(jsonParsed, "explanation"),
		json_object_toString(jsonParsed, "hdurl"),
		json_object_toString(jsonParsed, "media_type"),
		json_object_toString(jsonParsed, "service_version"),
		json_object_toString(jsonParsed, "title"),
		json_object_toString(jsonParsed, "url"));
	std::cout << apodMod.get_copyright() << std::endl << apodMod.get_date() << std::endl << apodMod.get_explanation() << std::endl
		<< apodMod.get_hdurl() << std::endl << apodMod.get_media_type() << std::endl << apodMod.get_service_version() << std::endl
		<< apodMod.get_title() << std::endl << apodMod.get_url() << std::endl;
	curl_execute_command_download_jpg(apodMod.get_hdurl(), apodMod.get_date());
}


void APOD_API_test() {
	APOD_Endpoint apod("", "", "", 50, true);
	try {
		auto jsonParsed = json::parse(curl_get_request(apod.toString()));
		if (jsonParsed.is_object()) {
			jsonObjectToAPODObject(jsonParsed);
		}
		if (jsonParsed.is_array()) {
			for (auto jo : jsonParsed) {
				jsonObjectToAPODObject(jo);
			}
		}
	}
	catch (std::exception err) {
		std::cout << "There was an error processing this parameter combination" << std::endl;
		std::cout << err.what() << std::endl;
	}

}


int main() {
	APOD_API_test();
	return 0;
}


// NASA API KEY 5d1KyFnmGDKbtJYgl9jDBMnvF6LiMq3CHUpbs703