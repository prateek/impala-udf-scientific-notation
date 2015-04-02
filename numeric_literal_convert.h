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

namespace {

// Function validates the input string format, and retrieves indices of
// the exponent and decimal characters (if they exist, in the string).
// Params:
//   str - [Input] Standard c-style string
//   len - [Input] length of input string
//   exponent_idx [output]: index of 'E' or 'e' in the string
//   decimal_idx [output]: index of '.' in the string
int validate_input_string(const char *str, const size_t len, int *exponent_idx,
    int *decimal_idx)
{
  if( str == NULL || len == 0){
    return 1;
  }

  *exponent_idx = -1;
  *decimal_idx  = -1;

  for(size_t idx=0, const char *i=str; idx!=len && *i!='\0'; ++idx,++i)
  {
    switch( *i )
    {
      case 'E':
      case 'e': {
                  if( *exponent_idx != -1 ) {
                    return 2;
                  }
                  *exponent_idx = idx;
      } break;

      case '.': {
                  if( *decimal_idx != -1 ) {
                    return 3;
                  }
                  *decimal_idx = idx;
      } break;

      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9': {
                  continue;
      } break;

      default: {
                 return 4;
      } break;
    }
  }

  return 0; //success
}

int convert_numeric_literal(const char *str, const size_t len, cstring *output)
{
  int exponent_idx, decimal_idx;
  int rcode = validate_input_string(str, len, &exponent_idx, &decimal_idx);
  if( rcode != 0 ){
    
  }
}
} // Anonymous Namespace

#endif // NUMERIC_LITERAL_CONVERT_H_

