#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int linenumber = 1;

size_t got_data(char *buffer, size_t itemsize, size_t nitems, void *ignore){
	size_t bytes = itemsize * nitems;
	printf("%d\t", linenumber);
	for(int i = 0; i < bytes; i++){
		printf("%c", buffer[i]);
		if(buffer[i] == '\n'){
			linenumber++;
			printf("%d:\t", linenumber);
		}
	}
	printf("\n\n");
	return bytes;
}

int main(){
	CURL *curl = curl_easy_init();

	if(!curl){
		fprintf(stderr, "init falied\n");
		return EXIT_FAILURE;
	}

	//set options
	curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.com/");
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, got_data);

	//preform out action
	CURLcode result = curl_easy_perform(curl);
	if(result!=CURLE_OK){
		fprintf(stderr, "download problem: %s\n", curl_easy_strerror(result));
	}


	curl_easy_cleanup(curl);
	return EXIT_SUCCESS;
}