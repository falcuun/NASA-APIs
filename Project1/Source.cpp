#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>


const char CURL[9] = "curl -s ";


std::string curl_execute_command_with_output(char* command) {
	// Declaring Result string (Method return). Should return output of the command.
	std::string result;
	// Defining the name of the file that command output will be written to.
	const char file_name[19] = "command_output.txt";
	// Declaring the right-side of the command (Pipe to the file).
	char command_output_destination[4 + sizeof(file_name) * sizeof(char*)] = " > ";
	// Concatenating the file name to the right side of the pipe.
	strcat_s(command_output_destination, file_name);
	// Declaring empty buffer that will whole the entire command signature (Command + File destination).
	char buffer[496] = { 0 };
	// Concatenating the command to the buffer.
	strcat_s(buffer, command);
	// Concatenating pipe and file destination to the command.
	strcat_s(buffer, command_output_destination);
	// Concatenating zero-termination to the buffer.
	strcat_s(buffer, "\0\r");
	// Running the System command.
	system(buffer);
	// Opening File Input Stream to read the text from the output file.
	std::ifstream command_file(file_name);
	// Assigning the text from the output file to the result string. 
	result = std::string((std::istreambuf_iterator<char>(command_file.rdbuf())), std::istreambuf_iterator<char>());
	// Clears out the contents of the output file.
	std::ofstream{ file_name };
	// Returns the Command Result Contents.
	return result;
}


std::string curl_get_request(const char* url) {
	char command[496] = { 0 };
	strcat_s(command, CURL);
	strcat_s(command, url);
	strcat_s(command, "\0\r");
	return curl_execute_command_with_output(command);
}

void curl_execute_command_download_jpg(const char* url, std::string image_name) {
	char command[2048] = { 0 };
	strcat_s(command, CURL);
	strcat_s(command, url);
	strcat_s(command, " > ");
	std::remove_if(image_name.begin(), image_name.end(), ::isspace);
	strcat_s(command, image_name.c_str());
	strcat_s(command, ".jpg");
	strcat_s(command, "\0\r");
	system(command);
}



int main() {
	 std::string ss = curl_get_request("https://jsonplaceholder.typicode.com/todos/2\0\r");
	 std::cout << ss;
	return 0;
}