
#include <math.h>
#include "__base__.hpp"

fmax mt_real_uniform(fmax a, fmax b)
{
    return mt_real()*(b-a)+a;
}

fmax mt_real()
{
    return mt_genrand_real1();
}

u32 mt_u32(){ return mt_genrand_int32(); }

// [mini, maxi]
u32 mt_u32_uniform(u32 mini, u32 maxi) 
{ 
    if(mini == maxi){ return mini; }
    return mt_u32()%(maxi-mini+1)+mini;
}

fmax mt_neg_exp(fmax mean, fmax rng_val_strictly_positive)
{
    return -mean * log(rng_val_strictly_positive); // zero excluded
}

fmax mt_neg_exp(fmax mean)
{
    return mt_neg_exp(mean, 1-mt_genrand_real2()); // zero excluded
}
