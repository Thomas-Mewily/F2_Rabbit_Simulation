#ifndef betterCPP__simulation__distribution
#define betterCPP__simulation__distribution

#include "__base__.hpp"

struct distribution
{
    array<usize> values;
    usize nb;
    i64 offset;
    fmax step;
    fmax sum;
    usize maxi;

    void inc(fmax val, fmax avg = 0);
    fmax idx_to_val(usize idx);
    usize val_to_idx(fmax val);
    fmax get_min();
    fmax get_max();

    distribution();
    distribution(u64 mini, u64 maxi, fmax step = 1);

    void drop();

    void print();
    void fprint(file* f);

    void print_latex_data();
    void fprint_latex_data(file* f);
};

#endif