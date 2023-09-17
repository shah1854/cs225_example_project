# Warning

This is a fake proposal. You should only use it as an example of how to structure your own proposal. **Do not copy this proposal.** To help encourage you to think creatively on algorithms of your own interest, note that the code and tests do not match this proposal so if you choose to use KMP as your 'non-covered' algorithm, you will not have a code or data advantage over other students.

## Academic Reference

The algorithm we are proposing to implement is Knuth-Morris-Pratt's exact string matching algorithm (https://epubs.siam.org/doi/10.1137/0206024). 

To assist us in understanding this old and complicated paper, we are using the wikipedia definition of the algorithm's pseudocode (https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm) as well as the textbook whose full PDF can be found in documents.

## Algorithm Summary

When implemented properly, the KMP algorithm is a linear time search algorithm that uses limited preprocessing of the text to produce a table of partial matches, where the values in the table indicate how many characters we can 'skip' to find our next possible match. Once the skip table is produced, the KMP algorithm will then scan the input text for an input pattern in the most efficient way, minimizing total character comparisons.

## Function I/O

As described in our summary, there are two parts to our algorithm. 

1. `std::string preprocess(std::string infile, skipList & table)`
```
@param infile -- the absolute path to the preprocessed txt file
@param table -- a reference to a skipList object that is filled in during preprocessing
@return The input text read in from infile.
```

This function will create a skip table for use in the KMP algorithm. As this is the very first step in our algorithm, we decided to implement it to both build the skip table and read in the file at the same time. Accordingly, we take as input the absolute path to our file of interest and an empty skipList (a class object we will define in our code base). The function will populate the skipList and return the full text as one single string.

Our proposed tests (1 and 2) check that this function will correctly read in a file and correctly populate the skip table. In test 1, we take as input a file containing nothing but the letter 'A' and compare it to a pre-written skip table that we know is correct. In test 2, we do the same for an input file containing the full English alphabet once. Together this proves (on a small scale) that our preprocessing function is correct.

2. `std::vector<unsigned> KMP(std::string text, skipList & table, std::string pattern)`
```
@param infile -- the absolute path to the preprocessed txt file
@param table -- a reference to a skipList object that is filled in during preprocessing
@param pattern -- the string pattern being searched for in the textfile
@return A vector of unsigned integers storing the matching indices of all exact matches for the pattern in our text
```

This function will take as input the text and table produced by preprocessing as well as a pattern of interest. It will then perform the main KMP algorithm and return a collection of unsigned integers as a vector. 

Our proposed test (3) checks that this function will correctly search for a pattern of interest by directly checking that we find all 17 instances of the pattern 'dodos' in our text file. The word 'dodo' and 'dos' are present to make sure we are not accidentally returning partial matches. 

For both of our methods, we will write additional tests as part of the development process. **We understand that using our code output as a means of writing tests doesn't make sense and won't give us points unless we can prove we know the true answer through some other approach like manual calculations.**

## Data Description

Our test datasets were manually constructed so we could guarantee the correctness of our proposed tests. The actual datasets stored in `/data` consist of text copies of our favorite books, though we manually deleted title pages. We additionally replaced all pagebreaks with newlines so that the overall text file is a line separated list of strings. This replacement was done using a Python script (not included in this example proposal but would be included if you were doing it for real).