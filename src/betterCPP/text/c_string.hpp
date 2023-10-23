#ifndef betterCPP__text__c_string
#define betterCPP__text__c_string
#include "__base__.hpp"

usize c_string_length(c_string c);
usize c_string_length(const c_string c);
usize c_string_length_with_nil(c_string c);
c_string c_string_clone(c_string src);
bool c_string_equal(c_string a, c_string b);
#endif