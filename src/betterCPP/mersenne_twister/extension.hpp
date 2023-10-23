#ifndef mersenne_twister_extension
#define mersenne_twister_extension

#include "__base__.hpp"

void mt_default_init();
fmax mt_real_uniform(fmax a, fmax b);
// [0, 1] 
fmax mt_real();

u32 mt_u32();
u32 mt_u32_uniform(u32 mini, u32 maxi);

fmax mt_neg_exp(fmax mean);
fmax mt_neg_exp(fmax mean, fmax rng_val_strictly_positive);


#endif