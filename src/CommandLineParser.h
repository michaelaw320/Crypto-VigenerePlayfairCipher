/*
 * CommandLineParser.h
 *
 *  Created on: 30 Jan 2016
 *      Author: Michael
 */

#ifndef COMMANDLINEPARSER_H_
#define COMMANDLINEPARSER_H_

#include <getopt.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>

/* Flag set by Åe--verboseÅf. */
static int verbose_flag;

static bool ENCRYPT_FLAG = false;
static bool DECRYPT_FLAG = false;
static bool BINARY_MODE = false;
static char* INPUT_FILE;
static char* OUTPUT_FILE;
static char* OPT_ALGO;
static char* OPT_OUTPUT_FORMAT;
static char* KEY;

bool PARSE_PARAM(int argc, char **argv);
bool CHECK_PARAM();
void PRINT_HELP(char *exeName);

#endif /* COMMANDLINEPARSER_H_ */
