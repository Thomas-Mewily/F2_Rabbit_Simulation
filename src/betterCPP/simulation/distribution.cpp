
#include "__base__.hpp"


fmax distribution::idx_to_val(usize idx)
{
    return idx*step+offset;
}

usize distribution::val_to_idx(fmax val)
{
    return (usize)((val - offset)/step);
}

fmax distribution::get_min() { return idx_to_val(0); }
fmax distribution::get_max() { return idx_to_val(values.length()); }

distribution::distribution(u32 mini, u32 maxi, fmax step)
{
    offset = mini;
    u32 precision = (maxi-mini)/step;
    values = array<usize>(precision);
    foreach_idx(i, values){ values[i] = 0; }
    this->step = step;
    nb = 0;
    sum = 0;
    this->maxi = 0;
}

void distribution::inc(fmax val, fmax avg)
{
    unused(avg);
    usize idx = val_to_idx(val);
    if(idx > values.length()){ return; }
    //check(values[idx] == 0);
    maxi = max<usize>(maxi, ++values[idx]);
    nb += 1;
}

void distribution::drop()
{
    values.drop();
    nb = 0;
    offset = 0;
    step = 1;
    sum = 0;
    maxi = 0;
}

void distribution::print(){ fprint(stdout); }
void distribution::fprint(file* f)
{
    fprintf(f, "%" usize_format " values, sum = %" fmax_format "\n", nb, sum);
    fprintf(f, "[%" fmax_format ", %" fmax_format "] with step= %" fmax_format "\n", get_min(), get_max(), step);

    foreach_idx(i, values)
    {
        fprintf(f, "value %s%6.2" fmax_format "%s,  count %s%6" usize_format "%s, %s%6.2" fmax_format " %%%s", COLOR_FOREGROUND_MAGENTA, idx_to_val(i), COLOR_RESET, COLOR_FOREGROUND_YELLOW, values[i], COLOR_RESET, COLOR_FOREGROUND_GREEN, ((fmax)values[i]*(fmax)100)/(fmax)nb, COLOR_RESET);
        usize nb_hash = values[i]*48/maxi;
        fprintf(f, COLOR_FOREGROUND_CYAN" " COLOR_BACKGROUND_CYAN);
        repeat(_, nb_hash){ fprintf(f, "#"); }
        fprintf(f, "%s\n", COLOR_RESET);
    }
    fprintf(f, "\n");
}

void distribution::print_latex_data() { fprint_latex_data(stdout); }
void distribution::fprint_latex_data(file* f)
{
    foreach_idx(i, values)
    {
        fprintf(f, "(%7.4" fmax_format ", %6" fmax_format ") %% %" usize_format " repetitions\n", idx_to_val(i), ((fmax)values[i]*(fmax)100)/(fmax)nb, nb);
    }
}