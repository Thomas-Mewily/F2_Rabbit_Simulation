#ifndef betterCPP__core__loop
#define betterCPP__core__loop

#define until(cond) while(!(cond))
#define forever while(true)

#define repeat(_varName, _nbTime) for(usize _varName = 0, nb_time = (usize)(_nbTime); _varName < nb_time; _varName++)
#define repeat_reverse(_varName, _nbTime) for(usize _varName = (usize)(_nbTime)-1, nb_time = (usize)(_nbTime); _varName < nb_time; _varName--)

#define foreach_idx(varname, iterable) repeat(varname, (iterable).length())
#define foreach_idx_reverse(varname, iterable) repeat_reverse(varname, (iterable).length())

// repeat         : for loop from [0, _nbTime[
// repeat_reverse : for loop from ]_nbTime, 0]
#endif