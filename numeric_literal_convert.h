#ifndef NUMERIC_LITERAL_CONVERT_H_
#define NUMERIC_LITERAL_CONVERT_H_

// Struct containing a cstring, and associated length
typedef struct {
  const char   *str;
  const size_t  len;
} cstring;

// Function expects input string representing a number in either Decimal format
// or in Scientific Notation, and returns a c-style string representing the
// same number in decimal format. Zero return code indicates success, non-zero
// indicates error.
// Params:
//   str - [Input] Standard c-style string
//   len - [Input] length of input string
//   output - [Output] pointer to struct containing cstring with decimal
//            representation of the input
// Example:
//  "1.23" -> "1.23"
//  "1E07" -> "10000000.0"
//  "1.2.3" -> ERROR
int convert_numeric_literal(const char *str, const size_t len, cstring *output);

#endif // NUMERIC_LITERAL_CONVERT_H_

