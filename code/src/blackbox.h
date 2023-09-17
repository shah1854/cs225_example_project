/**
 * @file letter.h
 * Declaration of the Letter class.
 */

#pragma once

#include <string>

/**
 * Loads an input CSV file and searches it for the presence of a pattern
 * The text is stored as a csv where the first csv column in each row
 * is a size 50 kmer. The pattern can exist as a substring on any line.
 * For the base existence checker, a single match is sufficient. 
 *
 * @param infile The absolute path to the csv containing the input text.
 * @param pattern The text pattern being searched for
 */
bool blackbox_exists(std::string infile, std::string pattern);

/**
 * Loads an input CSV file and searches it for the presence of a pattern
 * The text is stored as a csv where the first csv column in each row
 * is a size 50 kmer. The pattern can exist as a substring on any line.
 * A match is only considered if the pattern is found at least count times
 * 
 * XXX: NOT YET IMPLEMENTED! (See proposed timeline)
 *
 * @param infile The absolute path to the csv containing the input text.
 * @param pattern The text pattern being searched for
 * @param count The number of times the pattern must be found for the file to 'pass'
 */
bool blackbox_count(std::string infile, std::string pattern, unsigned count);