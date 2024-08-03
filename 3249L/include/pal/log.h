/* Data Logger library for PROS V5
 * Copyright (c) 2022 Andrew Palardy
 * This code is subject to the BSD 2-clause 'Simplified' license
 * See the LICENSE file for complete terms
 */

#ifndef _LOG_H_
#define _LOG_H_


#ifdef __cplusplus
extern "C" {
#endif

/* If the file does not set a log level, set it to WARN */
#ifndef LOG_LEVEL_FILE
#define LOG_LEVEL_FILE LOG_LEVEL_WARN
#endif

/* Headers required by log.h macros */
#include <stdio.h>

/* File descriptors for logfiles
 * fd is the log file descriptor
 * dd is the data file descriptor
 * Not to be used directly, but used by macros in this header
 */
extern FILE* fd;
extern FILE* dd;

/* Log Verbosity Level enumeration */
typedef enum
{
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_ALWAYS
} log_level_t;


/**
 *  Functions which are exported by the logger module
 **/


/* Functions to print a message at the specified log levels
 * The funtion will print if the given file is set to log at or above this level
 */
#define LOG_ALWAYS(...) do{switch(log_check(__FILE__,__LINE__,LOG_LEVEL_ALWAYS,LOG_LEVEL_FILE)){case 2: fprintf(fd,__VA_ARGS__); case 1: printf(__VA_ARGS__);printf("\n");}}while(0)
#define LOG_ERROR(...) do{switch(log_check(__FILE__,__LINE__,LOG_LEVEL_ERROR,LOG_LEVEL_FILE)){case 2: fprintf(fd,__VA_ARGS__); case 1: printf(__VA_ARGS__);printf("\n");}}while(0)
#define LOG_WARN(...) do{switch(log_check(__FILE__,__LINE__,LOG_LEVEL_WARN,LOG_LEVEL_FILE)){case 2: fprintf(fd,__VA_ARGS__); case 1: printf(__VA_ARGS__);printf("\n");}}while(0)
#define LOG_INFO(...) do{switch(log_check(__FILE__,__LINE__,LOG_LEVEL_INFO,LOG_LEVEL_FILE)){case 2: fprintf(fd,__VA_ARGS__); case 1: printf(__VA_ARGS__);printf("\n");}}while(0)
#define LOG_DEBUG(...) do{switch(log_check(__FILE__,__LINE__,LOG_LEVEL_DEBUG,LOG_LEVEL_FILE)){case 2: fprintf(fd,__VA_ARGS__); case 1: printf(__VA_ARGS__);printf("\n");}}while(0)

/* Initialize the logger module, it then operates from its own task */
void log_init();

/* Internal function to check if a log at level should be printed or not, also prints the log header
 * fname is assumed to be a string literal, as it should be a C-string defined by __FILE__
 * The pointer passed is assumed to be valid in global scope once the calling function returns
 */
int log_check(const char * fname, const int line,log_level_t level,log_level_t flevel);

/* Functions to log data */
void log_data_int(const char * pname, int data);
void log_data_dbl(const char * pname, double data);

/* Call reopen periodically to reopen the log files */
void log_step();

/* Call to generate a new log segment (new csv, new txt) i.e. when changing modes */
void log_segment();

#ifdef __cplusplus
}
#endif

#endif /* _LOG_H_ */