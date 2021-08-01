#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "libs/json/nlohmann/json.hpp"



#define API_KEY "YOUR_API_KEY"
#define API_DOMAIN "https://api.nasa.gov/"


namespace APOD {
	const static char* ENDPOINT = "https://api.nasa.gov/planetary/apod?";
}

namespace AsteroidsNeoWs {
	// Retrieve a list of Asteroids based on their closest approach date to Earth.
#define ASTEROIDS_NEO_WS_FEED_ENDPOINT "https://api.nasa.gov/neo/rest/v1/feed?"
	// Lookup a specific Asteroid based on its NASA JPL small body (SPK-ID) ID
#define ASTEROIDS_NEO_WS_LOOKUP_ENDPOINT "https://api.nasa.gov/neo/rest/v1/neo/"
	// Browse the overall Asteroid data-set 
#define ASTEROIDS_NEO_WS_BROWSE_ENDPOINT "https://api.nasa.gov/neo/rest/v1/neo/browse?"
}
